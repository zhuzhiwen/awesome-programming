#!/usr/bin/python
# -*- coding: utf-8 -*-

import socket

SERVER_ADDR = ("::1", 8889)
BUFSIZE = 1024

cs = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)

while True:
    sdata = input("> ")
    if not sdata:
        break
    cs.sendto(sdata.encode(), SERVER_ADDR)
    rdata, raddr = cs.recvfrom(BUFSIZE)
    print("%s" % rdata.decode())