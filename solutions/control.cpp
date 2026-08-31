#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 5e5 + 5;

class UnionFind {
  int num_sets;
  vector<int> p, rank, set_size;

public:
  UnionFind(int n) {
    num_sets = n;
    p.assign(n, 0);
    for (int i = 0; i < n; ++i) p[i] = i;
    rank.assign(n, 0);
    set_size.assign(n, 1);
  }

  int findSet(int x) { return p[x] == x ? x : p[x] = findSet(p[x]); }

  bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }

  int numDisjointSets() { return num_sets; }

  int sizeOfSet(int x) { return set_size[findSet(x)]; }

  void unionSet(int x, int y) {
    if (isSameSet(x, y)) return;
    x = findSet(x), y = findSet(y);
    if (rank[x] > rank[y]) swap(x, y);
    if (rank[x] == rank[y]) ++rank[y];
    p[x] = y;
    set_size[y] += set_size[x];
    --num_sets;
  }
};

void solve() {
  int n;
  cin >> n;
  UnionFind uf(MX);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    unordered_map<int, int> cnt;
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      ++cnt[uf.findSet(x)];
    }
    bool valid = true;
    for (auto [rep, sz] : cnt) {
      if (sz != uf.sizeOfSet(rep)) {
        valid = false;
        break;
      }
    }
    if (valid) {
      ++ans;
      int first_rep = cnt.begin()->first;
      for (auto [rep, sz] : cnt) {
        uf.unionSet(first_rep, rep);
      }
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
