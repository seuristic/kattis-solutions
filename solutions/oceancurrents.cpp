#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    string row;
    cin >> row;
    for (int j = 0; j < m; ++j) {
      grid[i][j] = row[j] - '0';
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int rs, cs, rd, cd;
    cin >> rs >> cs >> rd >> cd;

    --rs, --cs, --rd, --cd;

    deque<pair<int, int>> dq;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dq.push_front({rs, cs});
    dist[rs][cs] = 0;

    while (!dq.empty()) {
      auto [r, c] = dq.front();
      dq.pop_front();

      for (int i = 0; i < 8; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

        int w = grid[r][c] != i;
        if (dist[nr][nc] == -1 || dist[nr][nc] > dist[r][c] + w) {
          dist[nr][nc] = dist[r][c] + w;
          if (w == 0) dq.push_front({nr, nc});
          else dq.push_back({nr, nc});
        }
      }
    }

    cout << dist[rd][cd] << '\n';
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
