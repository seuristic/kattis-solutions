#include <bits/stdc++.h>
using namespace std;

void solve() {
  string word;
  set<string> wset;
  while (cin >> word) {
    wset.insert(word);
  }
  set<string> comp_words;
  for (string w : wset) {
    for (string w2 : wset) {
      if (w == w2) continue;
      comp_words.insert(w + w2);
      comp_words.insert(w2 + w);
    }
  }

  for (string w : comp_words) {
    cout << w << endl;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}
