# author: Jingbo Su
# created: 14.05.2022 08:42:32

import io
import os
import sys
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

if __name__ == '__main__':
  tt = int(input())
  while tt > 0:
    tt -= 1
    # n = int(input())
    # s = input().decode()
    # a = list(map(int, input().split()))
    # sys.stdout.write(" ".join(map(str, a)) + "\n")