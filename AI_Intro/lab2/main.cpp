/**
 *    author: Jingbo Su
 *    created: 28.04.2022
 **/
#include <bits/stdc++.h>

using namespace std;

//! d(u) + f(u) ≤ d(u) + g(u) = h(u)
//! x = cc / 3
//! y = cc % 3

static constexpr int N = 9;

class Solution {
 public:
  Solution(vector<int>&, vector<int>&);
  int f(vector<int>&);
  void Bfs(vector<int>&);
  void getAnswer();

 private:
  vector<int> start;
  vector<int> finish;
  vector<int> position;
  map<vector<int>, pair<vector<int>, string>> prev;
};

Solution::Solution(vector<int>& a, vector<int>& b) {
  start.resize(N);
  finish.resize(N);
  position.resize(N);
  start = a;
  finish = b;
  for (int i = 0; i < N; i++) {
    position[finish[i]] = i;
  }
}

int Solution::f(vector<int>& status) {
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (status[i] != 0) {
      int cc = position[status[i]]; // position of each element in `target`
      ans += (int) (abs(i / 3 - cc / 3) + abs(i % 3 - cc % 3));
    }
  }
  return ans;
}

void Solution::Bfs(vector<int>& start) {
  priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> s;
  s.emplace(f(start), start);
  map<vector<int>, int> dist;
  dist[start] = 0;
  array<int, 4> dx{-1, 0, 1, 0};
  array<int, 4> dy{0, 1, 0, -1};
  array<string, 4> ops{"Up", "Right", "Down", "Left"};
  while (!s.empty()) {
    auto t = s.top();
    s.pop();
    if (t.second == finish) return;
    vector<int> now(t.second);
    vector<int> old(t.second);
    int zero = 0;
    for (int i = 0; i < N; i++) {
      if (now[i] == 0) {
        zero = i;
        break;
      }
    }
    int x = zero / 3;
    int y = zero % 3;
    int dd = dist[now];
    for (int i = 0; i < 4; i++) {
      now = old;
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (0 <= xx && xx < 3 && 0 <= yy && yy < 3) {
        swap(now[x * 3 + y], now[xx * 3 + yy]);
        if (dist.count(now) == 0 || dd + 1 < dist[now]) {
          dist[now] = dd + 1;
          prev[now] = make_pair(old, ops[i]);
          s.emplace(dist[now] + f(now), now);
        }
      }
    }
  }
}

void Solution::getAnswer() {
  if (prev.size() == 0) {
    cout << "No need to move!" << endl;
    return;
  }
  vector<string> ans;
  while (finish != start) {
    ans.push_back(prev[finish].second);
    finish = prev[finish].first;
  }
  reverse(ans.begin(), ans.end());
  cout << "Operation(s):" << endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << "Step #" << i + 1 << ": " << ans[i] << endl;
  }
}

int main() {
  vector<int> start(N);
  vector<int> finish(N);
  cout << "Enter start state:" << endl;
  for (int i = 0; i < N; i++) {
    cin >> start[i];
  }
  cout << "Enter target state:" << endl;
  for (int i = 0; i < N; i++) {
    cin >> finish[i];
  }
  int rvs1 = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (start[i] != 0 && start[j] != 0 && start[j] < start[i]) {
        rvs1 += 1;
      }
    }
  }
  int rvs2 = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (finish[i] != 0 && finish[j] != 0 && finish[j] < finish[i]) {
        rvs2 += 1;
      }
    }
  }
  if (rvs1 % 2 != rvs2 % 2) {
    cout << "No Solution..." << endl;
    return 0;
  }
  Solution sol(start, finish);
  sol.Bfs(start);
  sol.getAnswer();
  cerr << "running time: " << clock() / 1000 << " ms" << endl;
  return 0;
}