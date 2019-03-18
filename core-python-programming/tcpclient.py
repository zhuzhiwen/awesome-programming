#!/usr/bin/python
# -*- coding: utf-8 -*-

import socket

HOST = 'localhost'
PORT = 8888
BUFSIZE = 1024

cs = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
cs.connect((HOST, PORT))

while True:
    data = input(">")
    # data = "hello, i am zhuzhiwen"
    if not data:
        break
    cs.send(data.encode())
    recv_data = cs.recv(BUFSIZE).decode()
    if not recv_data:
        break
    print(recv_data)

cs.close()