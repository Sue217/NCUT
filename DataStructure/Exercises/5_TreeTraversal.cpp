/**
 *    author: Jingbo Su
 *    created: 09/11/2021
 **/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  char val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(char ch) : val(ch), left(nullptr), right(nullptr) {}
  TreeNode(char ch, TreeNode* left, TreeNode* right)
      : val(ch), left(left), right(right) {}
};

class Tree {
 public:
  TreeNode* buildTree(vector<char>& preorder, vector<char>& inorder) {
    for (int i = 0; i < (int)inorder.size(); ++i) {
      pos[inorder[i]] = i;
    }
    return build(preorder, inorder, 0, (int)preorder.size() - 1, 0,
                 (int)inorder.size() - 1);
  }
  TreeNode* build(vector<char>& preorder, vector<char>& inorder, int pl, int pr,
                  int il, int ir) {
    if (pl > pr) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[pl]);
    int k = pos[root->val];
    root->left =
        build(preorder, inorder, pl + 1, pl + 1 + k - 1 - il, il, k - 1);
    root->right =
        build(preorder, inorder, pl + 1 + k - 1 - il + 1, pr, k + 1, ir);
    return root;
  }
  vector<char> postorderTraversal(TreeNode* root) {
    if (!root) {
      return {};
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    res.emplace_back(root->val);

    return res;
  }

 private:
  unordered_map<char, int> pos;
  vector<char> res;
};

int main() {
  vector<char> preorder, inorder;
  string pres, ins;
  getline(cin, pres);
  getline(cin, ins);
  for (auto& i : pres) {
    preorder.emplace_back(i);
  }
  for (auto& j : ins) {
    inorder.emplace_back(j);
  }
  Tree tree;
  TreeNode* root = tree.buildTree(preorder, inorder);
  vector<char> res = tree.postorderTraversal(root);
  for_each(res.begin(), res.end(), [](const char& ch) { cout << ch; });
  cout << endl;
  return 0;
}