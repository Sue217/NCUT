# author: subobo
# created: 13.05.2022 09:42:10

import io
import os
import sys
import math

def isFlower(x):
  y = str(x)
  all = 0
  s = len(y)
  for z in y:
    all += math.pow(int(z), s)
  if all == x:
    return True
  else:
    return False

def flower(x):
  ok = True
  for y in range (100, x + 1):
    if isFlower(y):
      print(y)
      ok = False
  if (ok):
    print("None")

if __name__ == '__main__':
  x = int(input())
  if isFlower(x):
    print("YES")
  else:
    print("NO")
  flower(x)
