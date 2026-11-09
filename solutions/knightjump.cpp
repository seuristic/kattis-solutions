#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;
using Coord = pair<int, int>;

const Coord DEST = {0, 0};
const int INF = 1e9;
const int M = 8;

int dr[M] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[M] = {1, 2, 2, 1, -1, -2, -2, -1};

void solve() {
  int n;
  cin >> n;

  Coord src;
  vector<string> board(n);
  for (int i = 0; i < n; ++i) {
    cin >> board[i];

    for (int j = 0; j < n; ++j) {
      if (board[i][j] == 'K') {
        src = {i, j};
      }
    }
  }

  if (src == DEST) {
    cout << "0\n";
    return;
  }

  queue<Coord> q;
  vector<vector<int>> dist(n, vector<int>(n, INF));

  q.push(src);
  dist[src.first][src.second] = 0;

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    for (int i = 0; i < M; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == '#' ||
          dist[nr][nc] != INF)
        continue;

      dist[nr][nc] = dist[r][c] + 1;

      if (nr == DEST.first && nc == DEST.second) {
        cout << dist[nr][nc] << '\n';
        return;
      }

      q.push({nr, nc});
    }
  }

  cout << "-1\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
