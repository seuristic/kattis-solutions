#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int R, S, K;
  cin >> R >> S >> K;

  vector<string> ss(R);
  vector<vector<int>> pref(R + 1, vector<int>(S + 1, 0));
  for (int r = 0; r < R; ++r) {
    cin >> ss[r];
    for (int c = 0; c < S; ++c) {
      if (ss[r][c] == '*') ++pref[r][c];
    }
  }

  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < S; ++c) {
      if (r > 0) pref[r][c] += pref[r - 1][c];
      if (c > 0) pref[r][c] += pref[r][c - 1];
      if (r > 0 && c > 0) pref[r][c] -= pref[r - 1][c - 1];
    }
  }

  int best_count = -1;
  int best_r = -1, best_c = -1;

  for (int r = 0; r < R - K + 1; ++r) {
    for (int c = 0; c < S - K + 1; ++c) {
      int count = pref[r + K - 2][c + K - 2] - pref[r][c + K - 2] -
                  pref[r + K - 2][c] + pref[r][c];
      if (count > best_count) {
        best_count = count;
        best_r = r;
        best_c = c;
      }
    }
  }

  cout << best_count << '\n';
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < S; ++c) {
      if (r == best_r || r == best_r + K - 1) {
        if (c > best_c && c < best_c + K - 1) {
          cout << '-';
        } else if (c == best_c || c == best_c + K - 1) {
          cout << '+';
        } else {
          cout << ss[r][c];
        }
      } else if (c == best_c || c == best_c + K - 1) {
        if (r > best_r && r < best_r + K - 1) cout << '|';
        else cout << ss[r][c];
      } else {
        cout << ss[r][c];
      }
    }
    cout << '\n';
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
