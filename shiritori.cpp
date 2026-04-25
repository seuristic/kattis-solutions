#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string curr, prev;
  unordered_set<string> word_set;
  for (int i = 0; i < n; ++i) {
    cin >> curr;
    if (prev.length() > 0 &&
        (curr[0] != prev.back() || word_set.find(curr) != word_set.end())) {
      if (i % 2 == 0) {
        cout << "Player 1 lost" << endl;
      } else {
        cout << "Player 2 lost" << endl;
      }
      return;
    }

    prev = curr;
    word_set.insert(curr);
  }

  cout << "Fair Game" << endl;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}
