import socket

IP = "localhost"
PORT = 5000

# create an INET, STREAMing socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# now connect to the web server on port 80 - the normal http port
print("Connecting to server at {}:{}".format(IP, PORT))
try:
    s.connect((IP, PORT))
except ConnectionRefusedError:
    print(
        "Failed to connect to the server! Is it started? Have you changed the port?"
    ) 
else:
    print("Success!")
