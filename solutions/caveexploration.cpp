#include <bits/stdc++.h>
using namespace std;

using ll = long long;

enum { UNVISITED = -1, VISITED = -2 };

int n, m, dfs_cnt;
vector<vector<pair<int, int>>> al;
vector<int> dfs_num, dfs_low, dfs_parent;
vector<bool> is_bridge;

void dfs(int u) {
  dfs_num[u] = dfs_low[u] = ++dfs_cnt;

  for (auto [v, id] : al[u]) {
    if (dfs_num[v] == UNVISITED) {
      dfs_parent[v] = u;

      dfs(v);

      if (dfs_low[v] > dfs_num[u]) is_bridge[id] = true;

      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else if (v != dfs_parent[u]) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

int dfs2(int u) {
  dfs_num[u] = VISITED;

  int ans = 1;

  for (auto [v, id] : al[u]) {
    if (dfs_num[v] == UNVISITED && !is_bridge[id]) {
      ans += dfs2(v);
    }
  }

  return ans;
}

void solve() {
  cin >> n >> m;

  al.assign(n, {});
  dfs_num.assign(n, UNVISITED);
  dfs_low.assign(n, 0);
  dfs_cnt = 0;
  is_bridge.assign(m, false);
  dfs_parent.assign(n, -1);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;

    al[u].push_back({v, i});
    al[v].push_back({u, i});
  }

  dfs(0);

  dfs_num.assign(n, UNVISITED);

  cout << dfs2(0) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
