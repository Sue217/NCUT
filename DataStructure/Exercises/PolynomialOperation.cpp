#include <iostream>
#include <vector>
using namespace std;

const int N = 2005;
class List1 {
 public:
  int coe[N];
  int idx[N];
};
class List2 {
 public:
  int coe[N];
  int idx[N];
};

vector<int> res;
vector<int> tmp;
List1 list1;
List2 list2;
int a[N];
void add(vector<int> tmp) {
  int i;
  int cur = 0, sum = 0;
  for (i = 1; i < tmp.size(); i += 2) {
    a[tmp[i]] += tmp[i - 1];
    cur = max(tmp[i], cur);
  }
  for (int i = cur; i >= 0; i--) sum += a[i];
  if (sum == 0) {
    printf("0 0");
    return;
  }
  int fl = 0;
  while (a[fl++] == 0)
    ;
  fl--;
  for (int i = cur; i >= fl; i--) {
    if (a[i] == 0) continue;
    printf("%d %d", a[i], i);
    if (i != fl) cout << ' ';
  }
  return;
}
void mult(vector<int> kk, int m, int n) {
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      kk.push_back(list1.coe[i] * list2.coe[j]);
      kk.push_back(list1.idx[i] + list2.idx[j]);
    }
  }
  add(kk);
}

int main() {
  int m, n;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> list1.coe[i] >> list1.idx[i];
    tmp.push_back(list1.coe[i]);
    tmp.push_back(list1.idx[i]);
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> list2.coe[i] >> list2.idx[i];
    tmp.push_back(list2.coe[i]);
    tmp.push_back(list2.idx[i]);
  }
  mult(res, m, n);
  cout << '\n';

  add(tmp);
  return 0;
}