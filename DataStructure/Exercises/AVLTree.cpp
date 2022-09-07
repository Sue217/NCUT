/**
 * 	  title:   AVL-Tree
 *    author:  BOBLT
 *    created: December/2021
 **/
#include <bits/stdc++.h>

using namespace std;

// ********************* PUBLIC OPERATIONS ****************************
// void insert(x)        --> Insert x
// void remove(x)        --> Remove x (unimplemented)
// bool contains(x)      --> Return true if x is present
// typename findMax()    --> Return largest item
// typename findMin()    --> Return smallest item
// boolean empty()     --> Return true if empty; else false
// void clear()      --> Remove all items
// void print()          --> Print tree in sorted order
// ********************* PRIVATE OPERATIONS ***************************
// void insert(x, root)
// void remove(x, root)
// void balance(root)
// avlNode* findMin(root) const
// avlNode* findMax(root) const
// bool contains(x, root)
// void clear(root)
// void print(root)
// avlNode* clone(root)
// int height(root)
// void rotateWithLeftChild(root)
// void rotateWithRightChild(root)
// void doubleWithLeftChild(root)
// void doubleWithRightChild(root)
// ******************************************************************

template <typename T>
class avltree {
 public:
  avltree() : root(nullptr) {}
  avltree(const avltree& rhs) : root(nullptr) { root = clone(rhs.root); }
  ~avltree() { clear(); }

  avltree& operator=(const avltree& rhs) {
    auto& cpy = rhs;
    swap(*this, cpy);
    return *this;
  }

  const T& findMin() {
    if (empty()) {
      exit(0);
    }
    return findMin(root)->element;
  }
  const T& findMax() {
    if (empty()) {
      exit(0);
    }
    return findMax(root)->element;
  }

  bool empty() const { return root == nullptr; }
  void clear() {
    if (!empty()) {
      clear(root);
    }
  }

 private:
  struct avlNode {
    T element;
    avlNode* left;
    avlNode* right;
    int height;

    avlNode() = default;
    avlNode(const T& elem)
        : element(elem), left(nullptr), right(nullptr), height(0) {}
    avlNode(const T& elem, avlNode* l, avlNode* r, int h)
        : element(elem), left(l), right(r), height(h) {}
  };
  avlNode* root;

  static const int ALLOWED_IMBALANCE = 1;

  int height(avlNode* rt) { return rt ? rt->height : -1; }

  void balance(avlNode*& rt) {
    if (!rt) {
      return;
    }

    if (height(rt->left) - height(rt->right) > ALLOWED_IMBALANCE) {
      if (height(rt->left->left) >= height(rt->left->right)) {
        rotateWithLeftChild(rt);
      } else {
        doubleWithLeftChild(rt);
      }
    } else if (height((rt->right)) - height(rt->left) > ALLOWED_IMBALANCE) {
      if (height(rt->right->right) >= height(rt->right->left)) {
        rotateWithRightChild(rt);
      } else {
        doubleWithRightChild(rt);
      }
    }
    rt->height = max(height(rt->left), height(rt->right)) + 1;
  }

  void clear(avlNode* rt) {
    if (!rt) {
      return;
    } else {
      clear(rt->left);
      clear(rt->right);
      delete rt;
    }
    rt = nullptr;
  }

  void print(avlNode* rt) {
    if (!rt) {
      return;
    }
    // root-left-right preOrder
    cout << rt->element << " ";
    print(rt->left);
    print(rt->right);
  }

  void insert(const T& x, avlNode* rt) {
    if (!rt) {
      rt = new avlNode(x);
    } else if (x < rt->element) {
      insert(x, rt->left);
    } else if (x > rt->element) {
      insert(x, rt->right);
    }
    balance(rt);
  }
  void remove(const T& x, avlNode* rt) {
    if (!rt) {
      return;
    }
    if (x < rt->element) {
      remove(x, rt->left);
    } else if (x > rt->element) {
      remove(x, rt->right);
    } else if (!rt->left and !rt->right) {
      auto& re = rt->element;
      re = findMin(rt->right)->element;
      remove(re, rt->right);
    } else {
      auto& old = rt;
      rt = !(rt->left) ? rt->left : rt->right;
      delete old;
    }
    balance(rt);
  }

  avlNode* findMin(avlNode* rt) {
    if (!rt) {
      return nullptr;
    }
    if (!rt->left) {
      return rt;
    }
    return findMin(rt->left);
  }
  avlNode* findMax(avlNode* rt) {
    if (!rt) {
      return nullptr;
    }
    if (!rt->right) {
      return rt;
    }
    return findMax(rt->right);
  }

  bool find(const T x, avlNode* rt) {
    if (!rt) {
      return false;
    } else if (rt->element == x) {
      return true;
    } else if (rt->element < x) {
      return find(x, rt->right);
    } else if (rt->element > x) {
      return find(x, rt->left);
    }
  }

  // Right rotate
  void rotateWithLeftChild(avlNode*& rt1) {
    auto rt2 = rt1->left;
    rt1->left = rt2->right;
    rt2->right = rt1;
    rt1->height = max(height(rt1->left), height(rt1->right)) + 1;
    rt2->height = max(height(rt2->left), rt1->height) + 1;
    rt1 = rt2;
  }
  // Left rotate
  void rotateWithRightChild(avlNode*& rt1) {
    auto rt2 = rt1->right;
    rt1->right = rt2->left;
    rt2->left = rt1;
    rt1->height = max(height(rt1->left), height(rt1->right)) + 1;
    rt2->height = max(height(rt2->right), rt1->height) + 1;
    rt1 = rt2;
  }
  void doubleWithLeftChild(avlNode*& rt) {
    rotateWithRightChild(rt->left);
    rotateWithLeftChild(rt);
  }
  void doubleWithRightChild(avlNode*& rt) {
    rotateWithLeftChild(rt->right);
    rotateWithRightChild(rt);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}