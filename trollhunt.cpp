#include <bits/stdc++.h>
using namespace std;

void solve() {
  int b, k, g;
  cin >> b >> k >> g;
  int groups = k / g;
  cout << ceil(1.0 * (b - 1) / groups) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
