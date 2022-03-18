import requests
import sys, os
from PyQt5.QtWidgets import *
from PyQt5.QtCore import QThread, pyqtSignal, pyqtSlot, QDate, QTime, Qt, QTimer
from bs4 import BeautifulSoup
from collections import deque
import argparse
import numbers, math
import pickle
from socket import *
from logger import Logger


class MasterHandler(QThread):
    getDataSignal = pyqtSignal(object)

    def __init__(self, ip, port):
        super().__init__()
        self.sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
        self.sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
        self.sock.setsockopt(SOL_SOCKET, SO_BROADCAST, 1)
        self.sock.bind((ip, port))
    def run(self):
        while True:
            data, arr = self.sock.recvfrom(1024)
            if data:
                self.getDataSignal.emit([pickle.loads(data), arr])


class EditWidget(QWidget):
    def __init__(self, parent):
        super().__init__()
        self.initUI()
        self.parent = parent

    def initUI(self):
        latLabel = QLabel("Lat")
        self.latle = QLineEdit(self)
        self.latBtn = QPushButton("Set")
        self.latBtn.clicked.connect(self.latChanged)

        lonLabel = QLabel("Lon")
        self.lonle = QLineEdit(self)
        self.lonBtn = QPushButton("Set")
        self.lonBtn.clicked.connect(self.lonChanged)

        mainLayout = QHBoxLayout()
        mainLayout.addWidget(latLabel)
        mainLayout.addWidget(self.latle)
        mainLayout.addWidget(self.latBtn)
        mainLayout.addWidget(lonLabel)
        mainLayout.addWidget(self.lonle)
        mainLayout.addWidget(self.lonBtn)
        self.setLayout(mainLayout)

    def latChanged(self):
        if self.latle.isEnabled():
            self.latle.setEnabled(False)
            self.latBtn.setText("Undo")
            self.parent.lat = float(self.latle.text())
        else:
            self.latle.setEnabled(True)
            self.latBtn.setText("Set")

    def lonChanged(self):
        if self.lonle.isEnabled():
            self.lonle.setEnabled(False)
            self.lonBtn.setText("Undo")
            self.parent.lon = float(self.lonle.text())
        else:
            self.lonle.setEnabled(True)
            self.lonBtn.setText("Set")


class MainWindow(QMainWindow):
    def __init__(self, serverIp, ip, port, id, password):
        super(MainWindow, self).__init__()
        self.windowWidth = 920
        self.windowHeight = 900
        self.statusBar().showMessage(
            f"Start time : {QDate.currentDate().toString(Qt.ISODate)} {QTime.currentTime().toString(Qt.DefaultLocaleLongDate)}")
        self.setCentralWidget(NetworkConfigure(serverIp, ip, port, id, password))
        self.setWindowTitle('Network Configure')
        self.setGeometry(50, 50, self.windowWidth, self.windowHeight)
        self.show()


class NetworkConfigure(QWidget):
    def __init__(self, serverIp, ip, port, id, password):
        super().__init__()
        self.statusUrl = f"http://{serverIp}/cgi-bin/webif/status-rf.sh"
        self.connectionUrl = f'http://{serverIp}/cgi-bin/webif/getradio.sh'
        self.session = requests.Session()
        self.session.auth = (id, password)
        self.lat = 0
        self.lon = 0

        self.logger = Logger()

        self.receivedBytesLabel = QLabel()
        self.receivePacketsLabel = QLabel()
        self.transmitBytesLabel = QLabel()
        self.transmitPacketsLabel = QLabel()
        self.connectionTableWidget = QTableWidget()
        self.connections = {}

        self.generalStatus = self.getGeneralStatus()

        self.handler = MasterHandler(ip, port)
        self.handler.start()
        self.handler.getDataSignal.connect(self.getDataFromSlave)
        # self.handler_thread = QThread()
        # self.handler.moveToThread(self.handler_thread)
        # self.handler_thread.start()
        self.initUI()
        self.connectionUpdateTimer = QTimer(self)
        self.connectionUpdateTimer.setInterval(2000)
        self.connectionUpdateTimer.timeout.connect(self.updateConnectionInfo)
        self.updateConnectionInfo()
        self.connectionUpdateTimer.start()
    def initUI(self):
        mainLayout = QVBoxLayout()
        statusLayout = QGridLayout()
        statusLayout.addWidget(QLabel("General Status"), 0, 0)
        statusLayout.addWidget(QLabel("MAC Address"), 1, 0)
        statusLayout.addWidget(QLabel("Operation Mode"), 1, 1)
        statusLayout.addWidget(QLabel("Mesh ID"), 1, 2)
        statusLayout.addWidget(QLabel("Bandwidth"), 1, 3)
        statusLayout.addWidget(QLabel("Frequency"), 1, 4)
        statusLayout.addWidget(QLabel("Tx Power"), 1, 5)
        statusLayout.addWidget(QLabel("Encryption Type"), 1, 6)

        statusLayout.addWidget(QLabel(str(self.generalStatus[0])), 2, 0)
        statusLayout.addWidget(QLabel(str(self.generalStatus[1])), 2, 1)
        statusLayout.addWidget(QLabel(str(self.generalStatus[2])), 2, 2)
        statusLayout.addWidget(QLabel(str(self.generalStatus[3])), 2, 3)
        statusLayout.addWidget(QLabel(str(self.generalStatus[4])), 2, 4)
        statusLayout.addWidget(QLabel(str(self.generalStatus[5])), 2, 5)
        statusLayout.addWidget(QLabel(str(self.generalStatus[6])), 2, 6)

        statusLayout.addWidget(QLabel("Traffic Status"), 3, 0)
        statusLayout.addWidget(QLabel("Receive Bytes"), 4, 0)
        statusLayout.addWidget(QLabel("Receive Packets"), 4, 1)
        statusLayout.addWidget(QLabel("Transmit Bytes"), 4, 2)
        statusLayout.addWidget(QLabel("Transmit Packets"), 4, 3)

        statusLayout.addWidget(self.receivedBytesLabel, 5, 0)
        statusLayout.addWidget(self.receivePacketsLabel, 5, 1)
        statusLayout.addWidget(self.transmitBytesLabel, 5, 2)
        statusLayout.addWidget(self.transmitPacketsLabel, 5, 3)

        columnLabels = ["MAC Address", "Tx Mod (MIMO)", "Rx Mod (MIMO)", "SNR (dB)", "RSSI (dBm)", "Avg RSSI (dBm)",
                        "Distance (m)"]
        self.connectionTableWidget.setColumnCount(len(columnLabels))
        self.connectionTableWidget.setRowCount(5)
        self.connectionTableWidget.setHorizontalHeaderLabels(columnLabels)
        self.connectionTableWidget.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)

        mainLayout.addLayout(statusLayout)
        connectionInfoGroupBox = QGroupBox("Connection Info")
        layout = QVBoxLayout()
        w = QWidget()
        w.setFixedHeight(280)
        layout.addWidget(w)
        connectionInfoGroupBox.setLayout(layout)
        mainLayout.addWidget(self.connectionTableWidget)
        mainLayout.addWidget(connectionInfoGroupBox)
        settingsWidgetGroupBox = QGroupBox("Settings")
        layout = QVBoxLayout()
        self.editWidget = EditWidget(self)
        layout.addWidget(self.editWidget)
        settingsWidgetGroupBox.setLayout(layout)
        mainLayout.addWidget(settingsWidgetGroupBox)
        self.setLayout(mainLayout)

    def isCoordinateSet(self):
        return self.lat and self.lon

    def getGeneralStatus(self):
        # session = requests.Session()
        # session.auth = ("admin", "episci1@")
        response = self.session.get(self.statusUrl)
        if response.status_code == 200:
            html = response.text
            soup = BeautifulSoup(html, "html.parser")
            temp = soup.select_one(".odd")
            return temp.find_all('td')
        else:
            print(response.status_code)

    def updateConnectionInfo(self):
        # session = requests.Session()
        # session.auth = ("admin", "episci1@")
        response = self.session.get(self.connectionUrl)
        if response.status_code == 200:
            radieInfo = response.text.split("\n")
            trafficStatusValues = radieInfo[0].split(",")
            self.receivedBytesLabel.setText(str(trafficStatusValues[0]))
            self.receivePacketsLabel.setText(str(trafficStatusValues[1]))
            self.transmitBytesLabel.setText(str(trafficStatusValues[2]))
            self.transmitPacketsLabel.setText(str(trafficStatusValues[3]))
            if len(radieInfo) > 2:
                for i in range(1, len(radieInfo) - 1):
                    adjValues = radieInfo[i].split(",")
                    if str(adjValues[0]) not in self.connections:
                        self.connections[str(adjValues[0])] = adjValues[1:-2]
                        self.connections[str(adjValues[0])][3] = 0
                        self.connections[str(adjValues[0])][4] = deque(maxlen=5)
                    else:
                        for j in range(1, 4):
                            self.connections[str(adjValues[0])][j - 1] = adjValues[j]
                    self.connections[str(adjValues[0])][4].append(int(adjValues[4]))
            self.logger.writeMessage(self.connections)
            self.updateConnectionTable()
        else:
            print(response.status_code)

    def updateConnectionTable(self):
        for i, conn in enumerate(self.connections):
            self.connectionTableWidget.setItem(i, 0, QTableWidgetItem(str(conn)))
            for j in range(1, 4):
                self.connectionTableWidget.setItem(i, j, QTableWidgetItem(str(self.connections[conn][j - 1])))
            rssiQ = self.connections[conn][4]
            self.connectionTableWidget.setItem(i, 4, QTableWidgetItem(str(rssiQ[len(rssiQ) - 1])))
            if len(rssiQ) == 5:
                self.connectionTableWidget.setItem(i, 5, QTableWidgetItem(str(sum(rssiQ) // 5)))
            else:
                self.connectionTableWidget.setItem(i, 5, QTableWidgetItem("---"))
            if self.isCoordinateSet() and len(self.connections[conn]) > 4:
                self.connectionTableWidget.setItem(i, 6, QTableWidgetItem(str(self.connections[conn][3])))

    @pyqtSlot(object)
    def getDataFromSlave(self, in_message):
        connectionInfo, addr = in_message
        posLla, data_raw = connectionInfo
        sender = str(data_raw["sender"])
        data = data_raw["payload"].split("\n")
        for d in data[1:]:
            # slaveInfo = d.split(",")
            if sender in self.connections:
                if self.isCoordinateSet():
                    self.connections[sender][3] = \
                        get_harversion_distance(self.lat, self.lon, posLla[0] * 1e-7, posLla[1] * 1e-7)


def get_harversion_distance(lat1, lon1, lat2, lon2, round_decimal_digits=1):
    if lat1 is None or lon1 is None or lat2 is None or lon2 is None:
        return None
    assert isinstance(lat1, numbers.Number) and -90 <= lat1 <= 90
    assert isinstance(lat1, numbers.Number) and -90 <= lat1 <= 90
    assert isinstance(lon2, numbers.Number) and -180 <= lon2 <= 180
    assert isinstance(lon2, numbers.Number) and -180 <= lon2 <= 180

    R = 6371.0072

    dlat = math.radians(lat1 - lat2)
    dlon = math.radians(lon1 - lon2)

    haversine_dlat = math.sin(dlat / 2.0) ** 2
    haversine_dlon = math.sin(dlon / 2.0) ** 2

    y = haversine_dlat + math.cos(math.radians(lat1)) * math.cos(math.radians(lat2)) * haversine_dlon
    x = 2 * math.asin(math.sqrt(y))
    
    return round(x * R * 1000, round_decimal_digits)

def check_sits(hostName):
    response = os.system("ping -c 1 " + hostName)
    if response == 0:
        Netstatus = "Network Active"
    else:
        Netstatus = "Network Error"
    return Netstatus


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('serverIp', type=str)
    parser.add_argument('ip', type=str)
    parser.add_argument('port', type=int)
    parser.add_argument('id', type=str)
    parser.add_argument('password', type=str)
    args = parser.parse_args()
    app = QApplication(sys.argv)
    widget = MainWindow(args.serverIp, args.ip, args.port, args.id, args.password)
    sys.exit(app.exec_())
