#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dir[] = {0, -1, 0, 1, 0};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    string row;
    cin >> row;

    for (int j = 0; j < int(row.length()); ++j) {
      grid[i][j] = row[j] - '0';
    }
  }

  queue<pair<int, int>> q;
  vector<vector<int>> dist(n, vector<int>(m, -1));

  q.push({0, 0});
  dist[0][0] = 0;

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    if (r == n - 1 && c == m - 1) {
      cout << dist[r][c] << '\n';
      return;
    }

    int k = grid[r][c];

    for (int i = 0; i < 4 && k > 0; ++i) {
      int nr = r + k * dir[i];
      int nc = c + k * dir[i + 1];

      if (nr < 0 || nr >= n || nc < 0 || nc >= m || dist[nr][nc] != -1)
        continue;

      dist[nr][nc] = dist[r][c] + 1;
      q.push({nr, nc});
    }
  }

  cout << -1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
