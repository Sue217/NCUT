/**
 *    author: Jingbo Su
 *    created: 05.09.2022 10:30:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    int n = (int) s.size();
    string xs = "";
    for (int i = 0; i < n; i++) {
      if (s[i] == 'b') {
        xs = s.substr(i + 2, 7);
        for (int j = 0; j < (int) xs.size(); j++) {
          xs[j] ^= 1;
        }
        cout << "b0" + xs + ";" << '\n';
        break;
      }
      cout << s[i];
    }
  }
  return 0;
}
