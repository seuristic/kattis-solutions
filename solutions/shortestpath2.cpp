#include <bits/stdc++.h>

#include <set>
using namespace std;

using ll = long long;
using str = string;

const int INF = 1e9;

struct Edge {
  int u, v, t0, P, d;
};

void solve() {
  int n, m, q, s;
  while (cin >> n >> m >> q >> s && (n || m || q || s)) {
    vector<vector<Edge>> al(n);
    for (int i = 0; i < m; ++i) {
      Edge e;
      cin >> e.u >> e.v >> e.t0 >> e.P >> e.d;
      al[e.u].push_back(e);
    }

    vector<int> dist(n, INF);
    set<pair<int, int>> pq;

    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
      pq.insert({dist[i], i});
    }

    while (!pq.empty()) {
      auto [du, u] = *pq.begin();
      pq.erase(pq.begin());

      for (const Edge& e : al[u]) {
        int dist_v = 0;
        if (e.P == 0) {
          if (du > e.t0) continue;
          dist_v = e.d + e.t0;
        } else {
          int curr = max(du, e.t0);
          if (du > e.t0) {
            curr = e.t0 + e.P * ((curr - e.t0 + e.P - 1) / e.P);
          }
          dist_v = curr + e.d;
        }

        if (dist_v >= dist[e.v]) continue;
        pq.erase(pq.find({dist[e.v], e.v}));
        dist[e.v] = dist_v;
        pq.insert({dist[e.v], e.v});
      }
    }

    while (q--) {
      int node;
      cin >> node;
      if (dist[node] == INF) cout << "Impossible\n";
      else cout << dist[node] << '\n';
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
