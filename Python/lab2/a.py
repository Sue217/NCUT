# author: subobo
# created: 13.05.2022 09:01:27

import io
import os
import sys
import random

def main():
  f = open("./test.txt", "w")
  for i in range(0, 1000):
    c = chr(random.randint(1, 122))
    f.write(c)
  f.close()
  f = open("./test.txt", "r")
  s = f.read()
  xs = ""
  dig = 0
  CC = 0
  cc = 0
  for c in s:
    if c.isdigit():
      dig += 1
      xs += c
    elif c.isupper():
      CC += 1
      xs += c
    elif c.islower():
      cc += 1
      xs += chr(ord(c) - 32)
  f.close()
  tot = dig + CC + cc
  sys.stdout.write("the rate of Digit is: ")
  print(round(dig / tot, 3))
  sys.stdout.write("the rate of Upper is: ")
  print(round(CC / tot, 3))
  sys.stdout.write("the rate of Lower is: ")
  print(round(cc / tot, 3))
  f = open("./test_copy.txt", "w")
  f.write(xs)
  f.close()

main()
