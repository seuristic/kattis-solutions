#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;
using Coord = pair<int, int>;

const int N = 8, M = 8;
const int INF = 1e9;

int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

void solve() {
  str pos;
  cin >> pos;

  Coord start = {pos[1] - '1', pos[0] - 'a'};
  queue<Coord> q;
  vector<vector<int>> dist(N, vector<int>(N, INF));

  q.push(start);
  dist[start.first][start.second] = 0;

  int max_dist = -INF;

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    for (int i = 0; i < M; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (nr < 0 || nr >= N || nc < 0 || nc >= N || dist[nr][nc] != INF)
        continue;

      dist[nr][nc] = dist[r][c] + 1;
      max_dist = max(max_dist, dist[nr][nc]);
      q.push({nr, nc});
    }
  }

  vector<str> res;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (dist[i][j] == max_dist) {
        char file_pos = char('a' + j);
        char rank_pos = char('1' + i);
        res.push_back(str{file_pos, rank_pos});
      }
    }
  }

  sort(res.begin(), res.end(), [&](const str& a, const str& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] > b[1];
  });

  cout << max_dist << ' ';
  for (const str& s : res) {
    cout << s << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
