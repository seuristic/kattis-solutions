#include <bits/stdc++.h>
using namespace std;

void solve() {
  int k, n, m;
  cin >> k >> n >> m;

  map<int, vector<tuple<int, int, int>>> flights;

  for (int i = 0; i < m; ++i) {
    int u, v, d, z;
    cin >> u >> v >> d >> z;
    flights[d].push_back({u, v, z});
  }

  vector<vector<int>> arrivals(n + 1, vector<int>(k + 1));

  for (int i = 0; i < k * n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    arrivals[b][a] += c;
  }

  vector<int> avail(k + 1);

  for (int day = 1; day <= n; ++day) {
    for (int airport = 1; airport <= k; ++airport) {
      avail[airport] += arrivals[day][airport];
    }

    vector<int> incoming(k + 1);

    for (auto& [u, v, cap] : flights[day]) {
      if (avail[u] < cap) {
        cout << "suboptimal\n";
        return;
      }

      avail[u] -= cap;
      incoming[v] += cap;
    }

    for (int airport = 1; airport <= k; ++airport) {
      avail[airport] += incoming[airport];
    }
  }

  cout << "optimal\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
