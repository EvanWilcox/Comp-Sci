import socket

IP = "localhost"
PORT = 5000
TIMEOUT = 10

# create an INET, STREAMing socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# now connect to the web server on port 80 - the normal http port
s.bind((IP, PORT))
# become a server socket
s.listen()
print("Listening on {}:{}".format(IP, PORT))
try:
    s.settimeout(TIMEOUT)
    (clientsocket, address) = s.accept()
except (socket.timeout):
    print("Failed due to timeout! Start me again!")
else:
    print("Success!")