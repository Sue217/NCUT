# author: subobo
# created: 13.05.2022 08:38:38

import io
import os
import sys
from random import randint
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

if __name__ == '__main__':
  f = open("./test.txt", "w")
  tt = 336
  while tt > 0:
    dig = randint(48, 57)
    CC = randint(65, 90)
    cc = randint(97, 122)
    rand = randint(1, 3)
    if rand % 3 == 0:
      f.write(chr(dig))
    elif rand % 3 == 1:
      f.write(chr(CC))
    else:
      f.write(chr(cc))
    tt -= 1
  f.close()