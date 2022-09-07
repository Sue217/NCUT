# author: subobo
# created: 13.05.2022 09:05:21

import os
import sys
import random

def main():
  import io 
  with io.open("./test.txt", "w") as f1:
    for i in range(0, 1000):
      c = chr(random.randint(1, 122))
      f1.write(c)
  f1.close()
  import io 
  with io.open("./test.txt", "r") as f2:
    s = f2.read()
  xs = ""
  dig = 0
  CC = 0
  cc = 0
  for c in s:
    oo = ord(c)
    if oo in range(48, 58):
      dig += 1
      xs += c
    elif oo in range(65, 91):
      CC += 1
      xs += c
    elif oo in range(97, 122):
      cc += 1
      xs += chr(ord(c) - 32)
  f2.close()
  tot = dig + CC + cc
  sys.stdout.write("the rate of Digit is: ")
  print(round(dig / tot, 3))
  sys.stdout.write("the rate of Upper is: ")
  print(round(CC / tot, 3))
  sys.stdout.write("the rate of Lower is: ")
  print(round(cc / tot, 3))
  import io 
  with io.open("./test_copy.txt", "w") as f3:
    f3.write(xs)
  f3.close()

main()
