#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int INF = 1e9;

vector<vector<pair<int, int>>> al;
vector<bool> visited;

void dfs(int u) {
  visited[u] = true;

  for (const auto& [v, w] : al[u]) {
    if (!visited[v]) {
      dfs(v);
    }
  }
}

void solve() {
  int n;
  while (cin >> n && (n != -1)) {
    al.assign(n, {});
    visited.assign(n, false);

    for (int u = 0; u < n; ++u) {
      int w, m;
      cin >> w >> m;
      while (m--) {
        int v;
        cin >> v;

        --v;

        al[u].push_back({v, w});
      }
    }

    vector<int> dist(n, -INF);
    dist[0] = 100;

    for (int i = 0; i < n - 1; ++i) {
      bool modified = false;

      for (int u = 0; u < n; ++u) {
        if (dist[u] == -INF) continue;

        for (const auto& [v, w] : al[u]) {
          if (dist[u] + w > 0 && dist[u] + w > dist[v]) {
            dist[v] = dist[u] + w;
            modified = true;
          }
        }
      }

      if (!modified) break;
    }

    for (int u = 0; u < n; ++u) {
      if (dist[u] == -INF) continue;

      for (const auto& [v, w] : al[u]) {
        if (dist[u] + w > 0 && dist[u] + w > dist[v]) {
          dfs(u);
        }
      }
    }

    bool reached = (dist[n - 1] > 0 || visited[n - 1]);
    cout << (reached ? "winnable" : "hopeless") << '\n';
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
