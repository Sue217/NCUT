from random import random

for i in range(16384):
  res = ''
  for j in range(4):
    rand = int(random() * 16)
    n = ''
    if rand < 10:
      n = str(rand)
    else:
      k = rand - 10
      n = chr(ord('A') + k)

    rand = int(random() * 16)
    m = ''
    if rand < 10:
      m = str(rand)
    else:
      k = rand - 10
      m = chr(ord('A') + k)

    res = res + n
    res = res + m
    if j < 3:
      res = res + ' '

  print(res)
