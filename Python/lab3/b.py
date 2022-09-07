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

def info1(a, html):
  soup = BeautifulSoup(html, 'html.parser')
  data = soup.tbody.contents
  for t in data:
    if isinstance(t, bs4.element.Tag):
      info = t.find_all('td')
      a.append([info[0].div.string, 
      info[1].find(name = 'a', attrs = {'class': 'name-cn'}).string, 
      info[2].get_text(), info[3].get_text(), 
      info[4].string, info[5].string])
    else:
      pass

def info2(b, html):
  soup = BeautifulSoup(html, 'html.parser')
  data = soup.div.contents
  for t in data:
    if isinstance(t, bs4.element.Tag) and t.find(name = 'div', attrs = {'id': 'stockcodelist'}):
      info = t.find_all('a')
      for x in info:
        b.append(x.get_text())
      '''
      try:
        b.append([t.find(name = 'a', attrs = {'target': '_black'}).get_text()])
      except:
        print("Attr Error\n", b)
      '''
    else:
      pass

def printf(a, b, n):
  col = "{0:{7}^0}\t{1:{7}^10}\t{2:{7}^10}\t{3:{7}^10}\t{4:{7}^7}\t{5:{7}^7}\t{6:{7}^6}\t"
  print(col.format('rank','大学名称','省市','类型','Total Score','School Level', 'Stock Code', chr(12288)))
  for i in range(n):
    x = a[i]
    y = b[i + 1]
    s = ""
    for c in y:
      if c.isdigit():
        s += c
    print(col.format(str(x[0]).strip(), str(x[1]).strip(), str(x[2]).strip(), str(x[3]).strip(), str(x[4]).strip(), str(x[5]).strip(), str(s), chr(12288)))

if __name__ == '__main__':
  a = []
  b = []
  school_url = str(input())
  school_html = get(school_url)
  info1(a, school_html)
  n = int(input())
  stock_url = str(input())
  stock_html = get(stock_url)
  info2(b, stock_html)
  print("\n" + "[" + str(school_url[-4:]) + ":]\n")
  printf(a, b, n)

''' test1
https://www.shanghairanking.cn/rankings/bcur/2022
30
http://www.cgedt.com/stockcode/hushi.asp

'''

''' test2
https://www.shanghairanking.cn/rankings/bcur/2020
8
http://www.cgedt.com/stockcode/shenshi.asp

'''