#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insert(int val, Node* root) {
  if (!root) return new Node(val);
  if (val < root->val) root->left = insert(val, root->left);
  else root->right = insert(val, root->right);
  return root;
}

Node* build(vector<int>& a) {
  Node* root = nullptr;
  for (const int& x : a) root = insert(x, root);
  return root;
}

bool isSame(Node* root1, Node* root2) {
  if (!root1 && !root2) return true;
  if (!root1 || !root2) return false;
  return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<Node*> uniq_trees;
  for (int i = 0; i < n; ++i) {
    vector<int> a(k);
    for (int j = 0; j < k; ++j) {
      cin >> a[j];
    }

    Node* root = build(a);
    bool is_existing = false;
    for (Node* tree : uniq_trees) {
      if (isSame(tree, root)) {
        is_existing = true;
        break;
      }
    }

    if (!is_existing) uniq_trees.push_back(root);
  }

  cout << uniq_trees.size() << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
