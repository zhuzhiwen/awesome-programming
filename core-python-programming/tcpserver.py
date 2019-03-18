#!/usr/bin/python
# -*- coding: utf-8 -*-

import socket
import time

HOST = 'localhost'
PORT = 8888
BUFSIZE = 1024

ss = socket.socket()
# ss.setsockopt()
ss.bind((HOST, PORT))
ss.listen(1)

while True:
    print("waiting for connection...")
    cs, addr = ss.accept()    # accept a new connect
    print("...connected from:", addr)

    while True:
        data = cs.recv(BUFSIZE).decode()
        if not data:
            break
        print("recv", data)
        send_data = "[%s]: %s" % (time.ctime(), data)
        cs.send(send_data.encode())
    cs.close()
ss.close()
