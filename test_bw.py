import socket

timeout = 1.02
port = 804
host = '192.168.7.179'
dest = (host, int(port))
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, 0)
sock.settimeout(timeout)

maxchannels = 64
numchannels = 64
dacs = [0,1,2,3]

MHz = 223696213.33333333333333333333333

# ~ tosend = bytearray.fromhex("120200006C24C8C35D89D80032000000")
# ~ sock.sendto(tosend, dest)
# ~ tosend = bytearray.fromhex("120200086C24C8C35D89D80032000000")
# ~ sock.sendto(tosend, dest)
# ~ tosend = bytearray.fromhex("120200106C24C8C35D89D80032000000")
# ~ sock.sendto(tosend, dest)
# ~ tosend = bytearray.fromhex("120200186C24C8C35D89D80032000000")
# ~ sock.sendto(tosend, dest)
# ~ for i in range(65536):
  # ~ tosend = bytearray.fromhex(f"1202{i:04x}6C24C8C35D89D80032000000")
  # ~ sock.sendto(tosend, dest)

#this one is good for using the scope
#gives ~9mV PP into 50 ohms out of J11
#freq is 130 MHz
# ~ tosend = bytearray.fromhex("120200006C24C8C35D89D80032000000")
# ~ sock.sendto(tosend, dest)

#this one is good for ILA
# ~ tosend = bytearray.fromhex("120200000000C8C35D89D80032000000")
# ~ sock.sendto(tosend, dest)


#this can be used to turn a few outputs on to look at on the scope
# ~ for dac in dacs:

  # ~ for i in range(maxchannels):
    # ~ tosend = bytearray.fromhex(f"1202{(dac*maxchannels+i):04x}000000000000000032000000")
    # ~ sock.sendto(tosend, dest)

  # ~ #use all channels for larger scope signal
  # ~ #gives 200 mV PP into 50 ohms out of J11
  # ~ #freq is 130 MHz
  # ~ for i in range(numchannels):
    # ~ tosend = bytearray.fromhex(f"1202{(dac*maxchannels+i):04x}6C24C8C35D89D80032000000")
    # ~ sock.sendto(tosend, dest)

  # ~ #48 channels = 400 mV PP into 50 ohms


# ~ #frequency one (~130 MHz)
# ~ #some test pattern for longer packets
# ~ p=0
# ~ tosendstring = ""
# ~ for dac in dacs:
  # ~ for i in range(maxchannels):
    # ~ #each fragment is 12 bytes
    # ~ tosendstring += f"1202{(dac*maxchannels+i):04x}0000000000000000"
    # ~ p+=1
    # ~ if p == 85:
      # ~ tosend = bytearray.fromhex(tosendstring)
      # ~ sock.sendto(tosend, dest)
      # ~ tosendstring=""
      # ~ p=0
  # ~ if p > 0:
    # ~ tosend = bytearray.fromhex(tosendstring)
    # ~ sock.sendto(tosend, dest)
    # ~ tosendstring = ""
  # ~ #use all channels for larger scope signal
  # ~ #gives 200 mV PP into 50 ohms out of J11
  # ~ #freq is 130 MHz
  # ~ for i in range(maxchannels):
    # ~ #each fragment is 12 bytes
    # ~ tosendstring += f"1202{(dac*maxchannels+i):04x}6C24C8C35D89D800"
    # ~ p+=1
    # ~ if p == 85:
      # ~ tosend = bytearray.fromhex(tosendstring)
      # ~ sock.sendto(tosend, dest)
      # ~ tosendstring=""
      # ~ p=0
  # ~ if p > 0:
    # ~ tosend = bytearray.fromhex(tosendstring)
    # ~ sock.sendto(tosend, dest)
    # ~ tosendstring = ""

  # ~ for i in range(numchannels):
    # ~ tosend = bytearray.fromhex(f"1202{(dac*maxchannels+i):04x}6C24C8C35D89D800")
    # ~ sock.sendto(tosend, dest)

# ~ #terminate
# ~ tosend = bytearray.fromhex(f"32000000")
# ~ sock.sendto(tosend, dest)






#frequency two (~14.55 MHz)
#some test pattern for longer packets
p=0
tosendstring = ""
for dac in dacs:
  for i in range(maxchannels):
    #each fragment is 12 bytes
    tosendstring += f"1202{(dac*maxchannels+i):04x}0000000000000000"
    p+=1
    if p == 85:
      tosend = bytearray.fromhex(tosendstring)
      sock.sendto(tosend, dest)
      tosendstring=""
      p=0
  if p > 0:
    tosend = bytearray.fromhex(tosendstring)
    sock.sendto(tosend, dest)
    tosendstring = ""
  #use all channels for larger scope signal
  #gives 200 mV PP into 50 ohms out of J11
  #freq is 130 MHz
  for i in range(maxchannels):
    #each fragment is 12 bytes
    tosendstring += f"1202{(dac*maxchannels+i):04x}0C24C8C35D89D800"
    p+=1
    if p == 85:
      tosend = bytearray.fromhex(tosendstring)
      sock.sendto(tosend, dest)
      tosendstring=""
      p=0
  if p > 0:
    tosend = bytearray.fromhex(tosendstring)
    sock.sendto(tosend, dest)
    tosendstring = ""

  for i in range(numchannels):
    tosend = bytearray.fromhex(f"1202{(dac*maxchannels+i):04x}0C24C8C35D89D800")
    sock.sendto(tosend, dest)

#terminate
tosend = bytearray.fromhex(f"32000000")
sock.sendto(tosend, dest)
