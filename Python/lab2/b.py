# author: Jingbo Su
# created: 13.05.2022 18:51:54

import io
import os
import sys

if __name__ == '__main__':
  x = int(input())
  y, z = map(int, input().split())
  s = input()
  print (str(x + y + z) + "\n" + s)