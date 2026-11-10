#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;
using Coord = pair<ll, ll>;

const ll INF = 1e18;

ll findDist(Coord c1, Coord c2) {
  ll x1 = c1.first, x2 = c2.first;
  ll y1 = c1.second, y2 = c2.second;
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve() {
  int n;
  cin >> n;

  vector<Coord> coord(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> coord[i].first >> coord[i].second;
  }

  cin >> coord[0].first >> coord[0].second;
  cin >> coord[n + 1].first >> coord[n + 1].second;

  n += 2;

  vector<int> p(n, -1);
  vector<ll> dist(n, INF);
  set<pair<ll, int>> pq;

  dist[0] = 0;
  for (int i = 0; i < n; ++i) {
    pq.insert({dist[i], i});
  }

  while (!pq.empty()) {
    auto [d, u] = *pq.begin();
    pq.erase(pq.begin());

    for (int v = 1; v < n; ++v) {
      ll new_dist = findDist(coord[u], coord[v]);
      if (dist[u] + new_dist >= dist[v]) continue;

      pq.erase(pq.find({dist[v], v}));
      p[v] = u;
      dist[v] = dist[u] + new_dist;
      pq.insert({dist[v], v});
    }
  }

  vector<int> ans;
  int curr = n - 1;
  while (1) {
    curr = p[curr];
    if (curr == 0) break;
    ans.push_back(curr);
  }

  reverse(ans.begin(), ans.end());

  for (int x : ans) {
    cout << x - 1 << '\n';
  }

  if (ans.empty()) cout << "-\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
