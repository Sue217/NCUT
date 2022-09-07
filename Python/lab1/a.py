# author: Jingbo Su
# created: 12.05.2022 21:59:37

import io
import os
import sys
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

if __name__ == '__main__':
  s = set((1, 2, 3, 4, 3, 2, 3, 1))
  print(s)