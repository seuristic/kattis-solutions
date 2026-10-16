#include <bits/stdc++.h>
using namespace std;

using ll = long long;

enum { UNVISITED = -1, VISITED = -2 };

int n, m;
vector<vector<int>> al;
vector<int> dfs_num, ts;

void dfs(int u) {
  dfs_num[u] = VISITED;

  for (int v : al[u]) {
    if (dfs_num[v] == UNVISITED) {
      dfs(v);
    }
  }

  ts.push_back(u);
}

void solve() {
  cin >> n >> m;

  al.assign(n, {});
  dfs_num.assign(n, UNVISITED);
  ts.clear();

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;

    --x, --y;

    al[x].push_back(y);
  }

  for (int u = 0; u < n; ++u) {
    if (dfs_num[u] == UNVISITED) {
      dfs(u);
    }
  }

  dfs_num.assign(n, UNVISITED);
  reverse(ts.begin(), ts.end());

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (dfs_num[ts[i]] == UNVISITED) {
      ++ans;
      dfs(ts[i]);
    }
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
