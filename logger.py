import json
import os
import time
import datetime

class Logger:
    def __init__(self):
        self.log_dir = "./log"
        log_uniquifier = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        log_filename = "RangeTestLog_" + log_uniquifier
        self.log_name = log_filename
        # self.log_handle = open(os.path.join(self.log_dir, self.log_name + ".log"), "w")
    def writeMessage(self, msg):
        log_dict = {}
        log_dict["log_timestamp"] = time.time()
        with open(os.path.join(self.log_dir, self.log_name + ".log"), "a") as log_handler:
            if msg is not None:
                for item in msg:
                    log_dict["payload"] = str(msg)
            else:
                log_dict["payload"] = []
            log_line = json.dumps(log_dict) + "\n"
            log_handler.write(log_line)
            print(1)

    # def close(self):
    #     self.log_handle.close()