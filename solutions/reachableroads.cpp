#include <bits/stdc++.h>
using namespace std;

using ll = long long;

enum { UNVISITED = -1, VISITED = -2 };

vector<vector<int>> adj;
vector<int> dfs_num;

void dfs(int u) {
  dfs_num[u] = VISITED;

  for (int v : adj[u]) {
    if (dfs_num[v] == UNVISITED) {
      dfs(v);
    }
  }
}

void solve() {
  int m, r;
  cin >> m >> r;

  adj.assign(m, {});
  dfs_num.assign(m, UNVISITED);

  while (r--) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int cc = 0;

  for (int u = 0; u < m; ++u) {
    if (dfs_num[u] == UNVISITED) {
      dfs(u);
      ++cc;
    }
  }

  cout << cc - 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
