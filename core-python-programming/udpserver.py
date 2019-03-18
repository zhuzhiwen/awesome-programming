#!/usr/bin/python
# -*- coding: utf-8 -*-

import socket
import time

BUFSIZE = 1024
ADDR = ("::1", 8889)    # use IPv6 address

ss = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
ss.bind(ADDR)
print("wait for udp message...")
while True:
    rdata, caddr = ss.recvfrom(BUFSIZE)
    print("recv data:", rdata)
    sdata = "[%s]: %s" % (time.ctime(), rdata.decode())
    ss.sendto(sdata.encode(), caddr)

ss.close()