#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dir[] = {0, -1, 0, 1, 0};

const int MAX_SIZE = 2000 + 5;

void solve() {
  int p1, p2, a, s;
  while (cin >> p1 && p1) {
    vector<vector<int>> grid(MAX_SIZE, vector<int>(MAX_SIZE, 0));
    vector<vector<int>> dist(MAX_SIZE, vector<int>(MAX_SIZE, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < p1; ++i) {
      cin >> a >> s;
      grid[a][s] = 1;
      dist[a][s] = 0;
      q.push({a, s});
    }

    cin >> p2;
    for (int i = 0; i < p2; ++i) {
      cin >> a >> s;
      grid[a][s] = 2;
    }

    bool found = false;

    while (!q.empty() && !found) {
      auto [a, s] = q.front();
      q.pop();

      for (int i = 0; i < 4; ++i) {
        int new_a = a + dir[i];
        int new_s = s + dir[i + 1];

        if (new_a < 0 || new_a >= MAX_SIZE || new_s < 0 || new_s >= MAX_SIZE ||
            dist[new_a][new_s] != -1) {
          continue;
        }

        dist[new_a][new_s] = dist[a][s] + 1;
        q.push({new_a, new_s});

        if (grid[new_a][new_s] == 2) {
          cout << dist[new_a][new_s] << '\n';
          found = true;
          break;
        }
      }
    }
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
