
#include <bits/stdc++.h>
using namespace std;

using State = tuple<int, int, int>;

int dir[] = {-1, 0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  priority_queue<State, vector<State>, greater<State>> pq;

  for (int i = 0; i < n; ++i) {
    dist[i][0] = grid[i][0];
    pq.push({dist[i][0], i, 0});
  }

  while (!pq.empty()) {
    auto [d, r, c] = pq.top();
    pq.pop();

    if (d != dist[r][c]) continue;

    if (c == m - 1) {
      cout << d << '\n';
      return 0;
    }

    for (int i = 0; i < 4; ++i) {
      int nr = r + dir[i];
      int nc = c + dir[i + 1];

      if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

      int nd = max(d, grid[nr][nc]);

      if (nd < dist[nr][nc]) {
        dist[nr][nc] = nd;
        pq.push({nd, nr, nc});
      }
    }
  }

  return 0;
}
