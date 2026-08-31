#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> t(n), l(m);
  for (ll& x : t) cin >> x;
  for (ll& x : l) cin >> x;

  sort(t.begin(), t.end());
  sort(l.begin(), l.end());

  int i = 0, j = 0;
  int ans = 0;
  while (i < n && j < m) {
    if (t[i] <= l[j]) {
      ++ans;
      ++i, ++j;
    } else {
      ++j;
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
