#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  for (int i = 0, j; i < n; ++i) {
    for (j = i + 1; j < n; ++j) {
      if (a[j - 1] + 1 != a[j]) break;
    }
    if (j - i > 2) {
      cout << a[i] << '-' << a[j - 1] << ' ';
      i = j - 1;
    } else cout << a[i] << ' ';
  }
  cout << endl;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}
