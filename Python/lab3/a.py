# author: Jingbo Su
# created: 17.05.2022 09:09:56

import io
import os
import sys
import requests
from bs4 import BeautifulSoup
import bs4

def get(url):
  try:
    re = requests.get(url, timeout = 30)
    re.raise_for_status()
    re.encoding = re.apparent_encoding
    html = re.text
  except:
    html = "Fail"
  return html

def fill(a, html):
  soup = BeautifulSoup(html, 'html.parser')
  data = soup.tbody.contents
  for t in data:
    if isinstance(t, bs4.element.Tag):
      tds = t.find_all('td')
      a.append([tds[0].div.string, 
      tds[1].find(name = 'a', attrs = {'class': 'name-cn'}).string, 
      tds[2].get_text(), tds[3].get_text(), 
      tds[4].string, tds[5].string])
    else:
      pass

def printf(a, n):
  col = "{0:{6}^0}\t{1:{6}^10}\t{2:{6}^10}\t{3:{6}^10}\t{4:{6}^10}\t{5:{6}^10}\t"
  print(col.format('rank','大学名称','省市','类型','Total score','School Level',chr(12288)))
  for i in range(n):
    x = a[i]
    print(col.format(str(x[0]).strip(), str(x[1]).strip(), str(x[2]).strip(), str(x[3]).strip(), str(x[4]).strip(), str(x[5]).strip(), chr(12288)))

if __name__ == '__main__':
  a = []
  url = str(input())
  html = get(url)
  fill(a, html)
  n = int(input())
  print("\n" + "[" + str(url[-4:]) + ":]\n")
  printf(a, n)
