/**
 *    author: Jingbo Su
 *    created: 12/10/2021
 **/
#include <iostream>

using namespace std;

typedef pair<int, int> PII;
const int maxn = 11;

typedef struct Window {
  // To storage the range of the Window
  PII topLeft, bottomRight;
  Window* next;
  bool vis[maxn][maxn];
  int num;
  Window(PII a, PII b, int n)
      : topLeft(std::move(a)), bottomRight(std::move(b)), num(n) {}

} * LinkedList;

void initList(LinkedList& L) { L->next = nullptr; }

void frontInsertNode(LinkedList& L, LinkedList node) {
  if (L->next) {
    node->next = L->next;
    L->next = node;
  } else {
    L->next = node;
    node->next = nullptr;
  }
}

LinkedList getTheNode(LinkedList& L, LinkedList node) {
  if (L->next) {
    LinkedList t = L;
    while (t->next != node) t = t->next;
    LinkedList s = t->next;
    t->next = s->next;
    node->next = nullptr;
  }
  return node;
}

void rangeTheWindow(LinkedList node) {
  int topX = node->topLeft.first, topY = node->topLeft.second;
  int bottomX = node->bottomRight.first, bottomY = node->bottomRight.second;

  for (int i = topX; i <= bottomX; ++i) {
    for (int j = topY; j <= bottomY; ++j) {
      node->vis[i][j] = true;
    }
  }
}

int main() {
  int m, n;
  cin >> m >> n;
  Window window1({0, 0}, {0, 0}, 0);
  LinkedList L = &window1;
  initList(L);

  for (int i = 1; i <= m; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    auto window = new Window({x1, y1}, {x2, y2}, i);
    rangeTheWindow(window);
    frontInsertNode(L, window);
  }
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    LinkedList t = L->next;
    bool flag = true;
    while (t) {
      if (t->vis[x][y]) {
        cout << t->num << '\n';
        flag = false;
        frontInsertNode(L, getTheNode(L, t));
        break;
      }
      t = t->next;
    }
    if (flag) {
      cout << "IGNORED" << '\n';
      continue;
    }
  }
  return 0;
}
