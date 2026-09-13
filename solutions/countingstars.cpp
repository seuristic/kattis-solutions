#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;

vector<string> img;

int dir[] = {0, -1, 0, 1, 0};

void dfs(int r, int c) {
  img[r][c] = '*';

  for (int i = 0; i < 4; ++i) {
    int nr = r + dir[i];
    int nc = c + dir[i + 1];

    if (nr >= 0 && nr < n && nc >= 0 && nc < m && img[nr][nc] == '-') {
      dfs(nr, nc);
    }
  }
}

void solve() {
  int tc = 1;
  while (cin >> n >> m) {
    img.assign(n, "");

    for (int i = 0; i < n; ++i) {
      cin >> img[i];
    }

    int ans = 0;

    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        if (img[r][c] == '-') {
          dfs(r, c);
          ++ans;
        }
      }
    }

    cout << "Case " << tc++ << ": " << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
