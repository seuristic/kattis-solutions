#include <bits/stdc++.h>
using namespace std;

class UnionFind {
  int next_node;
  vector<int> p, rank, set_size, id;
  vector<long long> set_sum;

public:
  UnionFind(int n) {
    p.resize(n);
    rank.assign(n, 0);
    set_size.assign(n, 1);
    set_sum.resize(n);
    id.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = set_sum[i] = id[i] = i;
    }
    next_node = n;
  }

  int findSet(int x) { return p[x] == x ? x : p[x] = findSet(p[x]); }

  bool isSameSet(int x, int y) { return findSet(id[x]) == findSet(id[y]); }

  int sizeOfSet(int x) { return set_size[findSet(id[x])]; }

  void unionSet(int x, int y) {
    int px = findSet(id[x]), py = findSet(id[y]);

    if (px == py) return;

    if (rank[px] > rank[py]) swap(px, py);

    p[px] = py;
    set_size[py] += set_size[px];
    set_sum[py] += set_sum[px];

    if (rank[px] == rank[py]) ++rank[py];
  }

  void moveToSet(int x, int y) {
    if (isSameSet(x, y)) return;
    int px = findSet(id[x]), py = findSet(id[y]);
    --set_size[px];
    set_sum[px] -= x;

    int new_node = next_node++;
    set_size.push_back(1);
    set_sum.push_back(x);
    rank.push_back(0);

    p.push_back(py);
    ++set_size[py];
    set_sum[py] += x;

    id[x] = new_node;
  }

  long long sumOfSet(int x) { return set_sum[findSet(id[x])]; }
};

void solve() {
  int n, m;
  while (cin >> n >> m) {
    UnionFind uf(n + 1);
    while (m--) {
      int q;
      cin >> q;
      int x, y;
      if (q == 1) {
        cin >> x >> y;
        uf.unionSet(x, y);
      } else if (q == 2) {
        cin >> x >> y;
        uf.moveToSet(x, y);
      } else {
        cin >> x;
        cout << uf.sizeOfSet(x) << ' ' << uf.sumOfSet(x) << endl;
      }
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
