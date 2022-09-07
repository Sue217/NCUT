/**
 *    author: Jingbo Su
 *    created: 08.08.2022 15:14:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    bool b = false;
    int n = (int) s.size();
    for (int i = 0; i < n; i++) {
      string xs = "";
      if (s[i] == 'b' && !b) {
        cout << s[i];
        b = true;
        continue;
      }
      if (b && s[i] == 'b') {
        xs = s.substr(i + 1, 17);
        reverse(xs.begin(), xs.end());
        cout << 'b' << xs;
        i += 17;
        continue;
      }
      cout << s[i];
    }
    cout << endl;
  }
  return 0;
}
