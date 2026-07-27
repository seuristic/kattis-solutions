#include <bits/stdc++.h>
using namespace std;

void solve() {
  int test = 0;
  int n;
  while (cin >> n) {
    ++test;
    cout << "Case " << test << ":\n";

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> ss;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ss.push_back(a[i] + a[j]);
      }
    }

    sort(ss.begin(), ss.end());

    int m;
    cin >> m;
    while (m--) {
      int q;
      cin >> q;
      auto index = lower_bound(ss.begin(), ss.end(), q) - ss.begin();
      int ans_index;
      if (index == (int)ss.size()) ans_index = index - 1;
      else if (index == 0) ans_index = index;
      else {
        if (abs(q - ss[index]) < abs(q - ss[index - 1])) {
          ans_index = index;
        } else {
          ans_index = index - 1;
        }
      }

      cout << "Closest sum to " << q << " is " << ss[ans_index] << ".\n";
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
