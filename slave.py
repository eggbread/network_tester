import pickle, time, requests, threading
import sys, os
from socket import *
from pymavlink import mavutil
from bs4 import BeautifulSoup
import numpy as np
import argparse


class SlaveHandler:
    def __init__(self, serverIp, ip, port):
        self.connectionUrl = f'http://{serverIp}/cgi-bin/webif/getradio.sh'
        self.statusUrl = f"http://{serverIp}/cgi-bin/webif/status-rf.sh"
        self.sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
        self.sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
        self.sock.setsockopt(SOL_SOCKET, SO_BROADCAST, 1)
        self.masterIp = ip
        self.masterPort = port

        self.posLla = np.array([0,0,0])
        self.generalStatus = self.getGeneralStatus()

        px4_thread = threading.Thread(target=self.getCurrentPos, daemon=True)
        px4_thread.start()
        # self.sock.bind((ip, port))

    def getGeneralStatus(self):
        session = requests.Session()
        session.auth = ("admin", "episci1@")
        response = session.get(self.statusUrl)
        if response.status_code == 200:
            html = response.text
            soup = BeautifulSoup(html, "html.parser")
            temp = soup.select_one(".odd")
            return temp.find_all('td')
        else:
            print(response.status_code)

    def getConnectionInfo(self):
        session = requests.Session()
        session.auth = ("admin", "episci1@")
        response = session.get(self.connectionUrl)
        if response.status_code == 200:
            return {
                "sender": self.generalStatus[0].get_text(),
                "payload": response.text
            }
        else:
            print(response.status_code)

    def getCurrentPos(self):
        px4_sock = mavutil.mavlink_connection(
            'udpin:localhost:{}'.format(14540),
            planner_format=False,
            notimestamps=True,
            robust_parsing=True
        )
        while True:
            packet_from_px4 = px4_sock.recv()
            if packet_from_px4:
                message_from_px4 = px4_sock.mav.parse_char(packet_from_px4)
                if message_from_px4.get_type() == "GLOBAL_POSITION_INT":
                    self.posLla = [
                        message_from_px4.lat,
                        message_from_px4.lon,
                        message_from_px4.alt
                    ]
    def run(self):
        while True:
            try:
                connectionInfo = self.getConnectionInfo()
                self.sock.sendto(
                    pickle.dumps([self.posLla, connectionInfo]),
                    (self.masterIp, self.masterPort)
                )
                print("SEND")
            except Exception as e:
                print(e)
            time.sleep(1)
if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('serverIp', type=str)
    parser.add_argument('ip', type=str)
    parser.add_argument('port', type=int)
    args = parser.parse_args()
    handler = SlaveHandler(args.serverIp, args.ip, args.port)
    handler.run()