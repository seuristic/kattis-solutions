#include <bits/stdc++.h>
using namespace std;

constexpr int N = 4;

void solve() {
  vector<string> puzzle(N);
  for (string& row : puzzle) {
    cin >> row;
  }

  int ans = 0;
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < N; ++c) {
      if (puzzle[r][c] == '.') continue;
      const int pos = puzzle[r][c] - 'A';
      ans += abs(r - pos / N) + abs(c - pos % N);
    }
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
