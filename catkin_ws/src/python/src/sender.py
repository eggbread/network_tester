#!/usr/bin/env python3
from socket import *
import argparse
import pickle
import time
import threading

def decode_msg(packet):
    return pickle.loads(packet)

def encode_msg(in_message):
    return pickle.dumps(in_message)

class HEARTBEAT:
    def __init__(self, id):
        self.value="heart_beat"
        self.id = id
    
class ACK:
    def __init__(self, id):
        self.id = id

class SOCK:
    def __init__(self, id, addr):
        self.ip, self.port = addr.split(":")
        self.port = int(self.port)
        self.comp_ip = ""
        self.comp_port = 0
        self.id = id

        self.sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
        self.sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
        self.sock.setsockopt(SOL_SOCKET, SO_BROADCAST, 1)

    def send_msg(self, msg, addr):
        self.sock.sendto(
            encode_msg(msg),
            addr
        )
    
    def run(self):
        while True:
            self.send_msg(HEARTBEAT(1), (self.ip, self.port))
            print("SEND HEARTBEAT")
            time.sleep(1)
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-a", "--address", type=str)
    args = parser.parse_args()
    print("==========Python Sender Network Tester==========")
    print("Address :" + args.address)

    sock = SOCK(1, args.address)
    sock.run()