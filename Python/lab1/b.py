# author: Jingbo Su
# created: 12.05.2022 22:02:23

import io
import os
import sys
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

if __name__ == '__main__':
  ls = [1, 2, 3, 4, 3, 2, 3, 1]
  dic = {}
  for x in ls:
    dic[x] = x
  for x in dic:
    print(x)
