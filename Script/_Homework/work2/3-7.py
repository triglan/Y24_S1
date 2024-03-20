import time
while(True):
    print(chr(ord('A') + int(time.time())%26))
    time.sleep(1)