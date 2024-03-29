import numpy as np
num_ch = 12

for ch in np.arange(num_ch):
    print(f'set DAC0 {ch:} 100 {50+ch*2:} 0')

for ch in np.arange(num_ch):
    print(f'setmove 0 DAC0 {ch} 0 0 100 1 {100+ch*2:} 1 0')
for ch in np.arange(num_ch):
    print(f'setmove 1 DAC0 {ch} 0 0 100 1 {120+ch*2:} 1 0')
for ch in np.arange(num_ch):
    print(f'setmove 2 DAC0 {ch} 0 0 100 1 {100+ch*2:} -1 0')
for ch in np.arange(num_ch):
    print(f'setmove 3 DAC0 {ch} 0 0 0.01 -1 {50+ch*2:} -1 0')