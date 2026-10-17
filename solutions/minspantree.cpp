#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Edge = tuple<ll, int, int>;

void solve() {
  int n, m;
  while (cin >> n >> m && (n || m)) {
    vector<vector<pair<int, int>>> al(n);
    vector<int> visited(n);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;

      al[u].push_back({v, w});
      al[v].push_back({u, w});
    }

    ll mst_cost = 0;
    vector<pair<int, int>> mst_edges;

    pq.push({0, 0, 0});

    while (!pq.empty()) {
      auto [w, u, v] = pq.top();
      pq.pop();

      if (visited[v]) continue;
      visited[v] = 1;

      mst_cost += w;

      if (u != v) {
        mst_edges.push_back({u, v});
      }

      for (const auto& [node, weight] : al[v]) {
        if (!visited[node]) {
          pq.push({weight, v, node});
        }
      }
    }

    if (int(mst_edges.size()) < n - 1) {
      cout << "Impossible\n";
      continue;
    }

    for (auto& [u, v] : mst_edges) {
      if (u > v) swap(u, v);
    }

    sort(mst_edges.begin(), mst_edges.end());

    cout << mst_cost << '\n';
    for (const auto& [u, v] : mst_edges) {
      cout << u << ' ' << v << '\n';
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
