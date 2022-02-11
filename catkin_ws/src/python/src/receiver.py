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
        self.sock.bind(('', self.port))

        receive_thread = threading.Thread(target=self.receive_msg, daemon=True)
        receive_thread.start()
        receive_thread.join()

    def receive_msg(self):
        while True:
            time.sleep(0.1)
            try:
                data, addr = self.sock.recvfrom(1024)
                msg = decode_msg(data)
                if msg.__class__.__name__ == "HEARTBEAT":
                    if msg.id != self.id:
                        self.comp_ip, self.comp_port = addr
                        print(f"Receive HEARTBEAT from {self.comp_ip}:{self.comp_port}")
                        
            except Exception as e:
                print(e)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-a", "--address", type=str)
    args = parser.parse_args()
    print("==========Python Receiver Network Tester==========")
    print("Address :" + args.address)

    sock = SOCK(2, args.address)