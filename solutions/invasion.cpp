#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;
using State = pair<int, int>;

const int INF = 1e9;

void solve() {
  int n, m, a, k;
  while (cin >> n >> m >> a >> k && (n || m || a || k)) {
    vector<vector<pair<int, int>>> al(n);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;

      --u, --v;

      al[u].push_back({v, w});
      al[v].push_back({u, w});
    }

    vector<int> dist(n, INF);

    int ans = 0;

    while (a--) {
      int b;
      cin >> b;

      --b;

      if (dist[b] != INF && dist[b] >= k) --ans;
      dist[b] = 0;

      priority_queue<State, vector<State>, greater<State>> pq;
      pq.push({dist[b], b});

      while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : al[u]) {
          if (d + w >= dist[v]) continue;

          if (dist[v] == INF && d + w >= k) ++ans;
          else if (dist[v] != INF && dist[v] >= k && d + w < k) --ans;

          dist[v] = d + w;
          pq.push({dist[v], v});
        }
      }

      cout << ans << '\n';
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
