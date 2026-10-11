#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<int> res, color;
vector<vector<int>> al, el;

void dfs(int u, int p) {
  for (const int& v : al[u]) {
    if (v != p) {
      color[v] = 1 - color[u];
      dfs(v, u);
    }
  }
}

void solve() {
  cin >> n;

  al.assign(n, {});
  el.assign(n, {});
  color.assign(n, -1);
  res.assign(n - 1, 0);

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;

    --u, --v;

    el[i] = {u, v};
    al[u].push_back(v);
    al[v].push_back(u);
  }

  color[0] = 0;
  dfs(0, -1);

  for (int i = 0; i < n - 1; ++i) {
    int u = el[i][0], v = el[i][1];
    if (color[u] == 0 && color[v] == 1) {
      cout << 0 << '\n';
    } else {
      cout << 1 << '\n';
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
