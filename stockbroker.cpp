#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MAX_SHARES = 100000;

void solve() {
  ll n;
  cin >> n;
  ll money = 100;
  for (ll i = 0, curr, prev; i < n; ++i) {
    cin >> curr;
    if (i > 0 && prev < curr) {
      ll shares = min(MAX_SHARES, money / prev);
      money += shares * (curr - prev);
    }
    prev = curr;
  }

  cout << money << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
