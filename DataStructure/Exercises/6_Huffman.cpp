/**
 *    author: Jingbo Su
 *    created: 09/11/2021
 **/
#include <bits/stdc++.h>

using namespace std;

struct HuffTreeNode {
  int num;
  int val;
  int flag;
  HuffTreeNode* left;
  HuffTreeNode* right;

  HuffTreeNode() = default;
  explicit HuffTreeNode(HuffTreeNode* node)
      : num(node->num),
        val(node->val),
        flag(node->flag),
        left(node->left),
        right(node->right) {}
  HuffTreeNode(int x, int v, int f)
      : num(x), val(v), flag(f), left(nullptr), right(nullptr) {}
};

typedef pair<int, int> pii;
typedef pair<int, string> pis;
priority_queue<pis, vector<pis>, greater<pis> > resHeap;

// decode Huffman code
void decode(HuffTreeNode* root, string s) {
  if (!root) {
    return;
  }
  if (~root->flag) {
    resHeap.push(make_pair(root->num, s));
  }

  decode(root->left, s + '0');
  decode(root->right, s + '1');
}

// encode Huffman Tree
vector<HuffTreeNode*> encode(const vector<pii>& HuffNodes) {
  // priority_queue<HuffTreeNode*, vector<HuffTreeNode* >, Compare > heap;
  vector<HuffTreeNode*> heap;
  int n = (int)HuffNodes.size();

  // initialize the Huffman Tree Nodes
  heap.reserve(HuffNodes.size());
  for (auto& huff : HuffNodes) {
    heap.emplace_back(new HuffTreeNode(huff.first, huff.second, 0));
  }
  // sort(heap.begin(), heap.end(), [](HuffTreeNode* ha, HuffTreeNode* hb)
  // {return ha->val < hb->val;});

  // encode Huffman Tree
  while (heap.size() > 1) {
    auto Min = min_element(
        heap.begin(), heap.end(),
        [](HuffTreeNode* ha, HuffTreeNode* hb) { return ha->val < hb->val; });
    auto lt = heap.at(Min - heap.begin());
    heap.erase(Min);
    Min = min_element(
        heap.begin(), heap.end(),
        [](HuffTreeNode* ha, HuffTreeNode* hb) { return ha->val < hb->val; });
    auto rt = heap.at(Min - heap.begin());
    heap.erase(Min);

    if (lt->num > rt->num) {
      swap(lt, rt);
    }

    // HuffTreeNode* hlt = new HuffTreeNode(heap.top()); heap.pop();
    // HuffTreeNode* hrt = new HuffTreeNode(heap.top()); heap.pop();

    auto Top = new HuffTreeNode(++n, lt->val + rt->val, -1);
    Top->left = lt;
    Top->right = rt;
    heap.emplace_back(Top);
  }

  return heap;
}

int main() {
  int n;
  cin >> n;
  vector<pii> HuffNodes;

  for (int i = 1; i <= n; ++i) {
    int val;
    cin >> val;
    HuffNodes.emplace_back(make_pair(i, val));
  }
  auto resVec = encode(HuffNodes);
  decode(resVec.front(), "");
  // resVec stores the Huffman codes of each vertex
  while (!resHeap.empty()) {
    cout << resHeap.top().second << '\n';
    resHeap.pop();
  }

  return 0;
}