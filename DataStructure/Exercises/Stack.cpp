#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct SNode *Stack;
struct SNode {
  int Data;
  SNode *next;
};

Stack CreatStack(Stack S) {
  S = (SNode *)malloc(sizeof(struct SNode));
  S->next = nullptr;
  return S;
}

bool isEmpty(Stack S) {
  if (S->next == nullptr)
    return true;
  else
    return false;
}

void Push(int item, Stack &S) {
  struct SNode *Item = (SNode *)malloc(sizeof(SNode));
  Item->Data = item;
  Item->next = S->next;
  S->next = Item;
}

int Pop(Stack &S) {
  struct SNode *FirstNode = (SNode *)malloc(sizeof(SNode));
  if (isEmpty(S))
    return -1;
  else {
    FirstNode = S->next;
    S->next = FirstNode->next;
    int Item = FirstNode->Data;
    free(FirstNode);
    return Item;
  }
}
