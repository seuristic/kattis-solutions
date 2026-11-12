#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int INF = 1e9;

struct Edge {
  int u, v, w;
};

vector<vector<pair<int, int>>> al;
vector<bool> invalid;

void dfs(int u) {
  invalid[u] = true;

  for (const auto& [v, w] : al[u]) {
    if (!invalid[v]) {
      dfs(v);
    }
  }
}

void solve() {
  int n, m, q, s;
  while ((cin >> n >> m >> q >> s) && (n || m || q || s)) {
    al.assign(n, {});
    invalid.assign(n, false);

    while (m--) {
      int u, v, w;
      cin >> u >> v >> w;
      al[u].push_back({v, w});
    }

    vector<int> dist(n, INF);
    dist[s] = 0;

    for (int i = 0; i < n - 1; ++i) {
      bool modified = false;

      for (int u = 0; u < n; ++u) {
        if (dist[u] == INF) continue;

        for (const auto& [v, w] : al[u]) {
          if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            modified = true;
          }
        }
      }

      if (!modified) break;
    }

    for (int u = 0; u < n; ++u) {
      if (dist[u] == INF) continue;

      for (const auto& [v, w] : al[u]) {
        if (dist[u] + w < dist[v]) {
          dfs(u);
        }
      }
    }

    while (q--) {
      int u;
      cin >> u;

      if (dist[u] == INF) cout << "Impossible\n";
      else if (invalid[u]) cout << "-Infinity\n";
      else cout << dist[u] << '\n';
    }

    cout << '\n';
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
