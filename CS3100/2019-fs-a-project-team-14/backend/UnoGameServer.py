import json
import socket
import time
from random import randint
from struct import pack, unpack

HOST = "127.0.0.1"
PORT = 8000


def recv_json(server_socket):
    header = server_socket.recv(8)
    size = unpack("<I", header[4:8])[0]
    if not (header.startswith(b"JSON")):
        raise "Invalid JSON format (Missive)"
    if size < 0 or size > 1024 * 1024:
        raise "Incoming JSON is too large: " + str(size)
    # read incoming size from socket, then remove the trailing newline
    body = server_socket.recv(size)[:-1]
    # parse into json
    return json.loads(body)


def send_json(server_socket, msg_payload):
    if msg_payload[-1] != "\n":
        msg_payload += "\n"
    prefix = "JSON".encode("utf-8")
    size = pack("<I", len(msg_payload))
    message = msg_payload.encode("utf-8")
    server_socket.sendall(prefix + size + message)

    return recv_json(server_socket)


class Client(object):
    def __init__(self, player_id, server_socket):
        super().__init__()
        self.player_id = player_id
        self.server_socket = server_socket

    def recv_json(self):
        return recv_json(self.server_socket)

    def waitForMM(self):
        data = json.dumps(
            {
                "messageType": "connect",
                "data": {
                    "game": "default",
                    "clientType": "client",
                    "configuration": {"id": self.player_id},
                },
            }
        )
        json_response = send_json(self.server_socket, data)
        while json_response.get("messageType") != "connect":
            if json_response.get("messageType") == "error":
                raise Exception(json_response.get("data"))
            if json_response.get("messageType") == "response":
                print("Message:", json_response.get("data"))
                json_response = recv_json(self.server_socket)

        print("Connect:", json_response.get("data"))

    def sendGSInit(self):
        game_connect_payload = json.dumps(
            {
                "messageType": "client-info",
                "data": {"clientInfo": {"id": self.player_id}},
            }
        )
        gs_response = send_json(self.server_socket, game_connect_payload)
        print("GS Init response", gs_response)
        messageType = gs_response.get("messageType")
        messageData = gs_response.get("data")
        if messageType == "error":
            raise Exception(messageData)
        else:
            print("{}: {}".format(messageType, messageData))
            return gs_response

    def updateState(self, state):
        game_state_payload = json.dumps(
            {"messageType": "game-state", "data": {"state": state}}
        )
        gs_response = send_json(self.server_socket, game_state_payload)
        print("update response", gs_response)
        messageType = gs_response.get("messageType")
        messageData = gs_response.get("data")
        if messageType == "error":
            raise Exception(messageData)
        elif messageType == "game-state":
            print("game-state:", messageData)

    def finish(self):
        game_finish_payload = json.dumps({"messageType": "game-finished"})
        gs_response = send_json(self.server_socket, game_finish_payload)
        print("finished response", gs_response)
        messageType = gs_response.get("messageType")
        messageData = gs_response.get("data")
        if messageType == "error":
            raise Exception(messageData)
        elif messageType == "game-finished":
            print("game-finish", messageData)


def main():
    with socket.socket() as s:
        player_id = str(randint(0, 9))

        # Connect to matchmaking server
        s.connect((HOST, PORT))

        client = Client("player-" + player_id, s)
        try:
            client.waitForMM()
            time.sleep(1)
            init_response = client.sendGSInit()
            # What is my ID given to me by the game server
            my_client_id = init_response["data"]["id"]
            # Am I the lobby leader in this match? If so, I need to send the
            # initial state
            my_lobby_leader = False

            # We should receive a 'client-info' message for each client we
            # connect. We are going to assume there are only 2 clients and hard
            # code this for the sake of example, but you should dynamically
            # determine how many clients are connected. Dynamically this can be
            # done with the client-list message or some other method.
            client_infos = [client.recv_json(), client.recv_json()]

            # See if I am the lobby leader by iterating through all of the
            # connected clients, and seeing if my id matches the lobby leaders
            # id. We will attempt to change this to make this easier in the
            # future, but for backwards compatibility we will leave this for now
            for client_info in client_infos:
                client_id = client_info["data"]["id"]
                is_lobby_leader = client_info["data"]["isLobbyLeader"]

                if my_client_id == client_id and is_lobby_leader:
                    my_lobby_leader = True

            # If you are the lobby leader, you need to send the initial state
            if my_lobby_leader:
                print("I am the lobby leader")
                client.updateState({"test": "I AM ZE LOBBY LEADER"})
                # Now we are going to wait for a message from not the lobby
                # leader
                print("[LOBBY LEADER] response", client.recv_json())
            # Otherwise, you need to wait for the initial state to be sent
            else:
                print("[REGULAR CLIENT] recieved", client.recv_json())
                # Now, send a message back to the lobby leader to simulate a
                # back and forth
                client.updateState(
                    {"test": "HELLO", "list": ["Activating", "My", "Cheat", "Codes"]}
                )

            # Finish the game
            client.finish()
            print("finish", client.recv_json())
        except Exception as e:
            print("Error:", e)
            return
        print("done")
        return


if __name__ == "__main__":
    main()
