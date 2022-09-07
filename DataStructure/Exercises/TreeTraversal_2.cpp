/**
 *    author: sujb
 *    created: 23.12.2021 20:40:54
 **/
#include <bits/stdc++.h>

using namespace std;

struct treeNode {
  char val;
  treeNode* left;
  treeNode* right;
  treeNode() : val(0), left(nullptr), right(nullptr) {}
  treeNode(char c) : val(c), left(nullptr), right(nullptr) {}
  treeNode(char c, treeNode* left, treeNode* right)
      : val(c), left(left), right(right) {}
};
class Solution {
 public:
  treeNode* buildTree(vector<char>& inorder, vector<char>& postorder) {
    int n = (int)inorder.size();
    for (int i = 0; i < n; ++i) {
      pos[inorder[i]] = i;
    }
    return build(inorder, postorder, 0, n - 1, 0, n - 1);
  }
  treeNode* build(vector<char> inorder, vector<char> postorder, int il, int ir,
                  int pl, int pr) {
    if (il > ir or pl > pr) {
      return nullptr;
    }
    auto root = new treeNode(postorder[pr]);
    auto k = pos[root->val];
    root->left = build(inorder, postorder, il, k - 1, pl, pl + k - 1 - il);
    root->right =
        build(inorder, postorder, k + 1, ir, pl + k - 1 - il + 1, pr - 1);
    return root;
  }
  vector<char> preorder(treeNode* root) {
    if (!root) {
      return res;
    }
    res.emplace_back(root->val);
    preorder(root->left);
    preorder(root->right);
    return res;
  }

 private:
  unordered_map<int, int> pos;
  vector<char> res;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s1, s2;
  cin >> s1 >> s2;
  vector<char> inorder, postorder;
  for (auto s : s1) {
    inorder.emplace_back(s);
  }
  for (auto s : s2) {
    postorder.emplace_back(s);
  }
  Solution sol;
  auto root = sol.buildTree(inorder, postorder);
  vector<char> res = sol.preorder(root);
  for (auto i : res) {
    cout << i;
  }
  cout << '\n';
  return 0;
}
