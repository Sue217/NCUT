#include <iostream>
using namespace std;

struct BTNode {
  int val;
  BTNode* left;
  BTNode* right;
  BTNode(int data) {
    this->val = data;ß
    this->left = nullptr;
    this->right = nullptr;
  }
};

class BTree {
 public:
  BTNode* head;
  BTNode* createTree();

  void preTraversal(BTNode* head);
  void inTraversal(BTNode* head);
  void posTraversal(BTNode* head);
};
BTNode* BTree::createTree() {
  BTNode* p1 = new BTNode(1);
  BTNode* p2 = new BTNode(2);
  BTNode* p3 = new BTNode(3);
  BTNode* p4 = new BTNode(4);
  BTNode* p5 = new BTNode(5);
  BTNode* p6 = new BTNode(6);
  BTNode* p7 = new BTNode(7);

  p1->left = p2;
  p1->right = p3;
  p2->left = p4;
  p2->right = p5;
  p3->left = p6;
  p3->right = p7;
  head = p1;

  return p1;
}
void BTree::preTraversal(BTNode* head) {
  if (head == nullptr) return;
  cout << head->val << ' ';

  preTraversal(head->left);
  preTraversal(head->right);
}
void BTree::inTraversal(BTNode* head) {
  if (head == nullptr) return;
  inTraversal(head->left);
  cout << head->val << ' ';

  inTraversal(head->right);
}
void BTree::posTraversal(BTNode* head) {
  if (head == nullptr) return;
  posTraversal(head->left);
  posTraversal(head->right);

  cout << head->val << ' ';
}

int main() {
  BTree bTree;
  bTree.createTree();

  // recursive
  cout << "=====recursive=====" << '\n';
  cout << "--- preTraversal ---" << '\n';
  bTree.preTraversal(bTree.head);
  puts("");
  cout << "--- inTraversal ---" << '\n';
  bTree.inTraversal(bTree.head);
  puts("");
  cout << "--- posTraversal ---" << '\n';
  bTree.posTraversal(bTree.head);
  puts("");

  return 0;
}