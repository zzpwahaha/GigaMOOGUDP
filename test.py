import socket
import time
timeout = 1.02
port = 804
host = '192.168.7.179'
dest = (host, int(port))
bufferSize  = 1024
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, 0)
sock.settimeout(timeout)

maxchannels = 64
numchannels = 56
dacs = [0,1,2,3]

# DAC0, channel 0, amp 100, freq 130MHz, phase 0 deg
tosend = bytearray.fromhex(f"120200006c5555555ffff000")
sock.sendto(tosend, dest)
msg, addr = sock.recvfrom(bufferSize)
print(f"Message from Client:{msg.hex()}\nClient IP Address:{addr}")

time.sleep(1)
#terminate
tosend = bytearray.fromhex(f"32000000")
sock.sendto(tosend, dest)
msg, addr = sock.recvfrom(bufferSize)
print(f"Message from Client:{msg.hex()}\nClient IP Address:{addr}")
