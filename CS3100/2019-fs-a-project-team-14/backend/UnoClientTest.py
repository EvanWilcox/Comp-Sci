from NetworkClient import recv_json, send_json, Client
import socket
import json
from random import randint
import time
import sys
import msvcrt
import traceback
import threading
import copy
from Game import Game
from Deck import Deck
from queue import Queue
from Player import Player
import jsonpickle

HOST = "127.0.0.1"
PORT = 8000

class ConnectionThread(threading.Thread):
    def __init__(self, queue, args=(), kwargs=None):
        threading.Thread.__init__(self, args=(), kwargs=None)
        self.queue = queue
        self.daemon = True

    def run(self):
        with socket.socket() as s:
            minPlayers = 3
            player_id = str(randint(0, 9))
            # Connect to matchmaking server
            s.connect((HOST, PORT))

            client = Client("player-" + player_id, s)

            client.waitForMM()
            time.sleep(1)
            init_response = client.sendGSInit()
            # What is my ID given to me by the game server
            my_client_id = init_response["data"]["id"]
            # Am I the lobby leader in this match? If so, I need to send the
            # initial state
            my_lobby_leader = False
            print("MY ID IS: ", my_client_id)
            # We should receive a 'client-info' message for each client we
            # connect. We are going to assume there are only 2 clients and hard
            # code this for the sake of example, but you should dynamically
            # determine how many clients are connected. Dynamically this can be
            # done with the client-list message or some other method.
            client_infos = []
            player_list = []
            for i in range(minPlayers):
                msg = client.recv_json()
                print(msg)
                client_infos.append(msg)
                player = Player(msg['data']['clientInfo']['id'], msg['data']['id'])
                player_list.append(player)

            print(player_list)
            other_player_id = None
            # See if I am the lobby leader by iterating through all of the
            # connected clients, and seeing if my id matches the lobby leaders
            # id. We will attempt to change this to make this easier in the
            # future, but for backwards compatibility we will leave this for now
            for client_info in client_infos:
                client_id = client_info["data"]["id"]
                is_lobby_leader = client_info["data"]["isLobbyLeader"]
                if (client_id != my_client_id):
                    other_player_id = client_id
                if my_client_id == client_id and is_lobby_leader:
                    my_lobby_leader = True

            deck = None


            # If you are the lobby leader, you need to send the initial state
            if my_lobby_leader:
                print("I am the lobby leader")
                deck = Deck()
                client.updateState({"turn": other_player_id, 'turn_counter': 10, 'sender': my_client_id, 'deck': jsonpickle.encode(deck)})

                # Now we are going to wait for a message from not the lobby
                # leader

            # Otherwise, you need to wait for the initial state to be sent
            else:
                print("[REGULAR CLIENT] recieved initial game state", client.recv_json())
                # Now, send a message back to the lobby leader to simulate a
                # back and forth
            message = client.recv_json()
            while(message['messageType'] == 'client-info'):
                print(message)
                message = client.recv_json()

            #message = client.recv_json()
            print("Initial state from lobby leader is: ", message)
            print(message['data']['state']['turn_counter'])

            isMyTurn = False
            turn = message['data']['state']['turn']
            turn_counter = message['data']['state']['turn_counter']


            turnTaken = False
            myLastMessage = {}
            oldtime = time.time()
            # Infinite loop until disconnection
            while (message['messageType'] != 'disconnect'):
                # Here is where we parse each message and update our known information
                if (message['messageType'] == 'game-state'):

                    print("Game state has changed: ", end="")
                    print(message, flush=True)

                    # Useful to save if its my turn so we dont have to make a comparison at every iteration
                    if (message['data']['state']['turn'] == my_client_id):
                        isMyTurn = True
                    else:
                        turnTaken = False
                        isMyTurn = False

                    turn = message['data']['state']['turn']
                    turn_counter = message['data']['state']['turn_counter']
                    deck = jsonpickle.decode(message['data']['state']['deck'])

                elif (message['messageType'] == 'random-data'):
                    pass

                if (not self.queue.empty()):
                    val = self.queue.get()
                    if val == "take turn":
                        self.queue.put(val)
                    elif val == "help":
                        print("isMyTurn: ", isMyTurn)
                        print("turn: ", turn)
                        print("turn_counter: ", turn_counter)
                        print("turnTaken: ", turnTaken)
                        print("deck: ", deck)

                if(isMyTurn and not turnTaken and not self.queue.empty()):
                    val = self.queue.get()
                    print(val)
                    if (val == "take turn"):
                        myLastMessage = {"turn": other_player_id, 'turn_counter': turn_counter-1, 'sender': my_client_id, 'deck': jsonpickle.encode(deck)}
                        client.updateState(
                            myLastMessage
                        )
                        print("TAKING MY TURN", turn_counter-1)
                        turnTaken = True
                    else:
                        client.sendRandomData({"changed": False})
                elif(isMyTurn and turnTaken):
                    print("They must not have received my message. :( Sending again.")
                    client.updateState(myLastMessage)
                else:
                    pass
                    #client.sendRandomData({"changed": False})



                message = client.recv_json()
                print("", end="", flush=True)

            # Finish the game
            client.finish()
            print("finish", client.recv_json())

            print("done")

if __name__ == '__main__':
    q = Queue()
    mythread = ConnectionThread(q)
    mythread.start()
    message = ""
    while message != "no":
        message = input()
        mythread.queue.put(message)
        time.sleep(1)
        print("", end="", flush=True)
