#include <bits/stdc++.h>
using namespace std;

int a, b, e, p;
vector<vector<int>> al, reach;

void dfs(int u, int src) {
  for (int v : al[u]) {
    if (reach[src][v]) continue;

    reach[src][v] = 1;
    dfs(v, src);
  }
}

void solve() {
  cin >> a >> b >> e >> p;

  al.assign(e, {});
  reach.assign(e, vector<int>(e, 0));

  for (int i = 0; i < p; ++i) {
    int u, v;
    cin >> u >> v;
    al[u].push_back(v);
  }

  for (int u = 0; u < e; ++u) {
    dfs(u, u);
  }

  int ans_a = 0, ans_b = 0, ans_not_b = 0;

  for (int u = 0; u < e; ++u) {
    int before = 0, after = 0;

    for (int v = 0; v < e; ++v) {
      if (reach[u][v]) ++after;
      if (reach[v][u]) ++before;
    }

    if (after >= e - a) ++ans_a;
    if (after >= e - b) ++ans_b;
    if (before >= b) ++ans_not_b;
  }

  cout << ans_a << '\n';
  cout << ans_b << '\n';
  cout << ans_not_b << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
