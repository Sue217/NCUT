#include <cstdio>
#include <cstdlib>

typedef double Elemtype;

typedef struct LNode {
  Elemtype data;
  struct LNode *next;
  int size;
  int capablity;
} * List;

// visit element: L.Data[i];
// visit element postion: L.last + 1 OR Ptrl -> last + 1;

bool InitList(List L) {  // Initialize the list
  L = nullptr;
  L->size = -1;
  return true;
}

bool DestoryList(List &L) {
  delete L;
  L->capablity = 0;
  return true;
}

bool ClearList(List &L) {
  //...
}

bool ListEmpty(List L) {  // Judge empty
  if (L == nullptr)
    return true;
  else
    return false;
}

int Listlen(List L) {
  LNode *ptr;
  int len = 0;
  while (ptr) {
    ptr = ptr->next;
    ++len;
  }
  return len;
}

Elemtype GetElem(List L, int i, Elemtype &e) {  // Search target's position
  // if(i <= 0)return NULL;
  LNode *ptr = L;
  for (int j = 0; j < i && ptr != nullptr; ++j) ptr = ptr->next;
  e = ptr->data;
  return e;
}

int LocateElem(List L, Elemtype e) {
  LNode *ptr = L;
  for (int j = 0; ptr != nullptr && ptr->data != e; ++j) ptr = ptr->next;
  if (ptr != nullptr)
    return ptr;
  else
    return nullptr;
}

bool ListInsert(List &L, int pos, Elemtype e) {
  if (pos < 1) return false;
  if (pos == 1) {
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = e;
    node->next = L;
  }
  LNode *ptr = L;
  for (int j = 1; j < pos && ptr != nullptr; ++j) ptr = ptr->next;
  if (ptr == nullptr)
    return false;
  else {
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = e;
    node->next = ptr->next;
    ptr->next = node;
    return true;
  }
}

bool ListDelete(List &L, int pos) {
  if (pos < 1) return false;
  LNode *ptr = L;
  for (int j = 1; j < pos; ++j) ptr = ptr->next;
  if (ptr == nullptr)
    return false;
  else {
    LNode *node = ptr->next;
    ptr->next = ptr->next->next;
    node = nullptr;
    free(node);
    return true;
  }
}