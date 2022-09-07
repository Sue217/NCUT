/**
 *    author: Jingbo Su
 *    created: 12/10/2021
 **/
#include <iostream>

using namespace std;

typedef struct Node {
  int pwd, num, size;
  Node *next;

  Node(int a, int b) : pwd(a), num(b) {}
} * LinkedList;

void initList(LinkedList &L) {
  L->next = nullptr;
  L->size = 0;
}

// 1,2,..., n
void insertNode(LinkedList &L, LinkedList node) {
  LinkedList p = L;
  while (p->next) p = p->next;
  p->next = node;
  node->next = nullptr;
  L->size++;
}

// This node* is the prev pointer of the target node !!!
int popNode(LinkedList &L) {
  LinkedList s = L->next;
  int res = s->num;
  L->next = s->next;
  s = nullptr;
  delete s;
  return res;
}

int main() {
  int m, n;
  cin >> m >> n;
  Node node1(0, 0);
  LinkedList L = &node1;
  initList(L);
  for (int i = 1; i <= n; ++i) {
    int ps;
    cin >> ps;
    LinkedList node = new Node(ps, i);
    insertNode(L, node);
  }
  LinkedList flag = L->next;
  if (L->size) {
    LinkedList l = L;
    while (l->next) l = l->next;
    // l = rear
    l->next = L->next;
    L = nullptr;
  }
  LinkedList l = flag, p = flag;
  for (int i = 1, k = 1; i <= n; ++i) {
    l = p;
    k = 1;

    if (m == 1) {
      LinkedList t = l;
      while (t->next != l) t = t->next;
      m = t->next->pwd;
      l = t;
    } else {
      while (k < m - 1) {
        l = l->next;
        ++k;
      }
      LinkedList t = l->next;
      m = t->pwd;
    }
    cout << popNode(l) << ' ';
    p = l->next;
  }
  return 0;
}