#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;
using Cell = pair<int, int>;
using State = pair<ll, Cell>;

const ll INF = 1e18;

int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void solve() {
  int h, w;
  cin >> h >> w;

  vector<vector<ll>> grid(h, vector<ll>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> grid[i][j];
    }
  }

  Cell src;
  cin >> src.first >> src.second;

  --src.first, --src.second;

  vector<vector<ll>> dist(h, vector<ll>(w, INF));
  priority_queue<State, vector<State>, greater<State>> pq;

  dist[src.first][src.second] = grid[src.first][src.second];
  pq.push({dist[src.first][src.second], src});

  while (!pq.empty()) {
    auto [d, cell] = pq.top();
    pq.pop();

    if (d != dist[cell.first][cell.second]) continue;

    for (int i = 0; i < 8; ++i) {
      int nr = cell.first + dr[i];
      int nc = cell.second + dc[i];

      if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;

      ll nd = max(d, grid[nr][nc]);

      if (nd < dist[nr][nc]) {
        dist[nr][nc] = nd;
        pq.push({dist[nr][nc], {nr, nc}});
      }
    }
  }

  ll res = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (dist[i][j] < 0) res += -dist[i][j];
    }
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
