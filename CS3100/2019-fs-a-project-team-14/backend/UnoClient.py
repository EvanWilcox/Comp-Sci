from Deck import Deck
from Card import Card
from Player import Player
from Game import Game
from NetworkClient import recv_json, send_json, Client
import socket
import json
from random import randint, choice
import time
import sys
import jsonpickle


'''
This script requires at least one command line argument to ru, numPlayers.
Run this script as:

    python3 UnoClient.py <numPlayers>

    or

    python3 UnoClient.py <numPlayers> <playerID>

If no playerID is provided a random number will be generated.
'''

HOST = "127.0.0.1"
PORT = 8000


def main():
    with socket.socket() as s:
        #get numPlayers from command line argument
        numPlayers = int(sys.argv[1])

        # get playerName from command line argument
        if len(sys.argv) < 3:
            playerName = str(randint(0, 9))
        else:
            playerName = sys.argv[2]

        # establish connection with game server
        s.connect((HOST, PORT))
        client = Client(playerName, s)

        try:
            client.waitForMM()

            # get all client info
            time.sleep(1)
            init_response = client.sendGSInit()
            print(init_response)
            players = []

            # Get ID given from game server
            myClientID = init_response["data"]["id"]

            clientInfos = []
            # get client info from other players
            for i in range(numPlayers):
                x = client.recv_json()
                clientInfos.append(x)

            amLobbyLeader = False

            # Check if I am lobby leader
            for clientInfo in clientInfos:
                clientID = clientInfo["data"]["id"]
                players.append(Player(clientID, clientID))
                isLobbyLeader = clientInfo["data"]["isLobbyLeader"]

                if myClientID == clientID and isLobbyLeader:
                    amLobbyLeader = True
                    #print("I Am Lobby Leader.")

            message = None
            # send initial state if Lobby Leader
            if amLobbyLeader:
                game = Game(players)
                client.updateState({"game": jsonpickle.encode(game)})
                print(jsonpickle.encode(game).replace("None", "null"))
                message = {"messageType": "game-state", "data": {"state": {"game": jsonpickle.encode(game)}}}
                # recieve initial state
            else:
                message = client.recv_json()
                print(str(message["data"]["state"]["game"]).replace("None", "null"))
            #print("Recieved Initial State")

            # game loop
            while True:

                # if message is game-state
                if message["messageType"] == "game-state":
                    game = jsonpickle.decode(message["data"]["state"]["game"])
                    # send state to front end
                    #print(jsonpickle.encode(game))
                    # check if its my turn
                    if game.currentPlayer.PlayerID == myClientID:
                        doneWithTurn  = False
                        while (not doneWithTurn):
                            # get action from frontend
                            userinput = input()
                            decodedaction = json.loads(userinput)
                            action = []
                            if (decodedaction["action"] == 1):
                                color = None
                                if (decodedaction["card"]["details"] == "wild" or decodedaction["card"]["details"] == "draw4" or decodedaction["card"]["details"] == "drawUntil"):
                                    color = decodedaction["color"]
                                action = [decodedaction["action"], Card(decodedaction["card"]["color"], decodedaction["card"]["num"] , decodedaction["card"]["isSpecial"] , decodedaction["card"]["details"] ), decodedaction["pile"], color]
                                doneWithTurn = True
                            elif (decodedaction["action"] == 0):
                                action = [0]

                            game.performAction(action)

                            # check if winner
                            if game.finished:
                                # disconnect clients
                                client.updateState({"gameWinner": myClientID})
                                print( {"gameWinner": myClientID} )
                                client.finish()
                                exit()

                            else:
                                # update state
                                client.updateState({"game": jsonpickle.encode(game)})
                                print(str(jsonpickle.encode(game)).replace("None", "null"))
                                #print("Updating Game State")
                            if (game.currentPlayer.PlayerID == myClientID):
                                doneWithTurn = False


                elif message["messageType"] == "random-data":
                    data = message["data"]

                # if message is disconnect
                elif message["messageType"] == "disconnect":
                    # exit game loop
                    break

                # if message is game-finished
                elif message["messageType"] == "game-finished":
                    # exit game loop
                    break

                # recieve new message
                message = client.recv_json()
                print(str(message["data"]["state"]["game"]).replace("None", "null"))
                #print("Recieved Message")

        except Exception as e:
            pass
            print("Error:", e)


if __name__ == "__main__":
    main()
