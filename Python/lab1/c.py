# author: Jingbo Su
# created: 12.05.2022 22:07:43

import io
import os
import sys
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

if __name__ == '__main__':
  s = input().decode('utf-8')
  xs = s [::-1]
  if s == xs:
    print(True)
  else:
    print(False)