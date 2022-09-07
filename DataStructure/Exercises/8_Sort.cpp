/**
 *    author: Jingbo Su
 *    created: 07/12/2021
 **/
#include <bits/stdc++.h>

using namespace std;

void insertSort(vector<int>& v, int& comp, int& move) {
  vector<int> cp;
  cp.emplace_back(0);
  for (auto i : v) {
    cp.emplace_back(i);
  }
  int n = (int)v.size();
  for (int i = 2, j = 0; i <= n; ++i) {
    if (++comp and cp[i] < cp[i - 1]) {
      cp[0] = cp[i];
      cp[i] = cp[i - 1];
      for (j = i - 2; ++comp and cp[0] < cp[j]; --j) {
        cp[j + 1] = cp[j];
        ++move;
      }
      cp[j + 1] = cp[0];
      move += 3;
    }
  }
}

void bubbleSort(vector<int>& v, int& comp, int& move) {
  int n = (int)v.size();
  for (int i = n - 1; ~i; --i) {
    bool ok = true;
    for (int j = 0; j < i; ++j) {
      if (++comp and v[j] > v[j + 1]) {
        ok = false;
        swap(v[j], v[j + 1]);
        move += 3;
      }
    }
    if (ok) {
      break;
    }
  }
}

void quickSort(vector<int>& v, int l, int r, int& comp, int& move) {
  if (l >= r) {
    return;
  }
  auto partition = [&](int l, int r) -> int {
    int v0 = v[l];
    while (l < r) {
      while (l < r and ++comp and v[r] >= v0) {
        --r;
      }
      v[l] = v[r];
      while (l < r and ++comp and v[l] <= v0) {
        ++l;
      }
      v[r] = v[l];
      move += 2;
    }
    v[l] = v0;
    move += 2;
    return l;
  };
  int pivotloc = partition(l, r);
  quickSort(v, l, pivotloc - 1, comp, move);
  quickSort(v, pivotloc + 1, r, comp, move);
}

void selectSort(vector<int>& v, int& comp, int& move) {
  int n = (int)v.size();
  auto selectMinElem = [&](int l, int r) -> int {
    int res = l;
    for (int i = l + 1; i <= r; ++i) {
      if (++comp and v[i] < v[res]) {
        res = i;
      }
    }
    return res;
  };
  for (int i = 0; i < n; ++i) {
    int k = selectMinElem(i, n - 1);
    if (i != k) {
      swap(v[i], v[k]);
      move += 3;
    }
  }
}

void mergeSort(vector<int>& v, vector<int>& t, int l, int r, int& comp,
               int& move) {
  if (l >= r) {
    return;
  }
  int md = (l + r) >> 1;
  mergeSort(v, t, l, md, comp, move);
  mergeSort(v, t, md + 1, r, comp, move);
  int i = l, j = md + 1;
  while (i <= md and j <= r) {
    ++comp;
    if (v[i] <= v[j]) {
      t.emplace_back(v[i++]);
    } else {
      t.emplace_back(v[j++]);
    }
  }
  while (i <= md) {
    t.emplace_back(v[i++]);
  }
  while (j <= r) {
    t.emplace_back(v[j++]);
  }
  ++move;
  for (int i = l, j = 0; i <= r; ++i, ++j) {
    ++move;
    v[i] = t[j];
  }
  t.clear();
}

void print(vector<int> v) {
  for (auto i : v) {
    cerr << i << " ";
  }
  cerr << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> seq(n), t;
  for (auto& i : seq) {
    cin >> i;
  }

  int comp = 0, move = 0;
  vector<int> cp1(seq.begin(), seq.end());
  insertSort(cp1, comp, move);
  cout << comp << " " << move << " ";

  comp = 0, move = 0;
  vector<int> cp2(seq.begin(), seq.end());
  bubbleSort(cp2, comp, move);
  cout << comp << " " << move << " ";

  comp = 0, move = 0;
  vector<int> cp3(seq.begin(), seq.end());
  quickSort(cp3, 0, n - 1, comp, move);
  cout << comp << " " << move << " ";

  comp = 0, move = 0;
  vector<int> cp4(seq.begin(), seq.end());
  selectSort(cp4, comp, move);
  cout << comp << " " << move << " ";

  comp = 0, move = 0;
  vector<int> cp5(seq.begin(), seq.end());
  mergeSort(cp5, t, 0, n - 1, comp, move);
  cout << comp << " " << move + 1 << " ";

  return 0;
}