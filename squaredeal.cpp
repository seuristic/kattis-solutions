#include <bits/stdc++.h>
using namespace std;

void solve() {
  vector<pair<int, int>> rect(3);
  for (auto& [h, w] : rect) {
    cin >> h >> w;
  }

  vector<int> pos = {0, 1, 2};

  do {
    for (int mask = 0; mask < (1 << 3); ++mask) {
      vector<pair<int, int>> curr = rect;
      for (int i = 0; i < 3; ++i) {
        curr[i] = rect[pos[i]];
        if (mask & (1 << i)) {
          swap(curr[i].first, curr[i].second);
        }
      }

      auto [h1, w1] = curr[0];
      auto [h2, w2] = curr[1];
      auto [h3, w3] = curr[2];
      bool cond1 = h1 + h2 + h3 == w1 && w1 == w2 && w2 == w3;
      bool cond2 = h1 + h2 == h3 && w1 == w2 && w1 + w3 == h3;
      if (cond1 || cond2) {
        cout << "YES\n";
        return;
      }
    }
  } while (next_permutation(pos.begin(), pos.end()));

  cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
