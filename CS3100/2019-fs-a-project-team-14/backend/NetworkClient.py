import json
import socket
from struct import pack, unpack

'''
Networking tools used for connecting to the matchmaking server and the frontend client.
'''

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
    #print("PAYLOAD:",end=" ")
    #print(msg_payload)
    if msg_payload[-1] != "\n":
        msg_payload += "\n"
    prefix = "JSON".encode("utf-8")
    try:
        size = pack("<I", len(msg_payload))
    except Exception as error:
        #print("Unable to pack, invalid size.")
        #print("Payload", end=" ")
        #print(msg_payload)
        #print("Closed successfully")
        #print(error)
        raise SystemError
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
                #print("Message:", json_response.get("data"))
                json_response = recv_json(self.server_socket)

        #print("Connect:", json_response.get("data"))

    def sendGSInit(self):
        game_connect_payload = json.dumps(
            {
                "messageType": "client-info",
                "data": {"clientInfo": {"id": self.player_id}},
            }
        )
        gs_response = send_json(self.server_socket, game_connect_payload)
        #print("GS Init response", gs_response)
        messageType = gs_response.get("messageType")
        messageData = gs_response.get("data")
        if messageType == "error":
            raise Exception(messageData)
        else:
            #print("{}: {}".format(messageType, messageData))
            return gs_response

    def updateState(self, state):
        game_state_payload = json.dumps(
            {"messageType": "game-state", "data": {"state": state}}
        )
        gs_response = send_json(self.server_socket, game_state_payload)
        ##print("update response", gs_response)
        messageType = gs_response.get("messageType")
        messageData = gs_response.get("data")
        if messageType == "error":
            raise Exception(messageData)
        elif messageType == "game-state":
            #print("game-state:", messageData)
            pass

    def sendRandomData(self, data):
        game_state_payload = json.dumps(
            {"messageType": "random-data", "data": data}
        )
        gs_response = send_json(self.server_socket, game_state_payload)
        ##print("update response", gs_response)
        messageType = gs_response.get("messageType")
        messageData = gs_response.get("data")
        if messageType == "error":
            raise Exception(messageData)
        elif messageType == "game-state":
            #print("game-state:", messageData)
            pass

    def finish(self):
        game_finish_payload = json.dumps({"messageType": "game-finished"})
        gs_response = send_json(self.server_socket, game_finish_payload)
        #print("finished response", gs_response)
        messageType = gs_response.get("messageType")
        messageData = gs_response.get("data")
        if messageType == "error":
            raise Exception(messageData)
        elif messageType == "game-finished":
            #print("game-finish", messageData)
            pass
