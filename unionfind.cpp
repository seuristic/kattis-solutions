#include <bits/stdc++.h>
using namespace std;

class UnionFind {
  int num_sets;
  vector<int> parent, rank;

public:
  UnionFind(int n) {
    num_sets = n;
    parent.assign(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;
    rank.assign(n, 0);
  }

  int findSet(int x) {
    return parent[x] == x ? x : parent[x] = findSet(parent[x]);
  }

  bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }

  int numDisjointSets() { return num_sets; }

  void unionSet(int x, int y) {
    if (isSameSet(x, y)) return;
    x = findSet(x), y = findSet(y);
    if (rank[x] > rank[y]) swap(x, y);
    parent[x] = y;
    if (rank[x] == rank[y]) ++rank[y];
    --num_sets;
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  while (q--) {
    char op;
    int a, b;
    cin >> op >> a >> b;
    if (op == '=') {
      uf.unionSet(a, b);
    } else {
      cout << (uf.isSameSet(a, b) ? "yes" : "no") << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
