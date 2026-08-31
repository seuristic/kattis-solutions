#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll l, d, n;
  cin >> l >> d >> n;

  if (n == 0) {
    cout << (l - 12) / d + 1 << '\n';
    return;
  }

  vector<ll> pos(n);
  for (ll& p : pos) cin >> p;

  sort(pos.begin(), pos.end());

  ll res = (pos[0] - 6) / d + 1;
  for (int i = 1; i < n; ++i) {
    res += (pos[i] - pos[i - 1]) / d;
  }
  res += (l - 6 - pos.back()) / d;

  cout << res - n << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
