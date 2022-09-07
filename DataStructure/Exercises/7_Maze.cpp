/**
 *    author: Jingbo Su
 *    created: 07/12/2021
 **/
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const int inf = 0x3f3f3f3f;
  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m)), d(n, vector<int>(m, inf));
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }

  function<int(int, int)> Dfs = [&](int x, int y) {
    if (x >= n - 1 and y >= m - 1) {
      vis[x][y] = false;
      return 1;
    }
    vis[x][y] = true;
    int paths = 0;
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx >= 0 and xx < n and yy >= 0 and yy < m and !g[xx][yy] and
          !vis[xx][yy]) {
        paths += Dfs(xx, yy);
      }
    }
    vis[x][y] = false;
    return paths;
  };

  function<int(int, int)> Bfs = [&](int x0, int y0) {
    d[x0][y0] = 0;
    queue<pii> q;
    q.push(make_pair(x0, y0));
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      int x = t.first, y = t.second;
      vis[x][y] = true;
      for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 and xx < n and yy >= 0 and yy < m and !g[xx][yy] and
            !vis[xx][yy]) {
          d[xx][yy] = min(d[xx][yy], d[x][y] + 1);
          q.push(make_pair(xx, yy));
        }
      }
    }
    return d[n - 1][m - 1];
  };

  int tot = Dfs(0, 0);
  cout << tot << '\n';
  if (!tot) {
    cout << "NoPath" << '\n';
  } else {
    cout << Bfs(0, 0);
  }

  return 0;
}