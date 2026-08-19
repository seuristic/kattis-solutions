#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> v1(n), v2(n);
  for (int i = 0; i < n; ++i) {
    cin >> v1[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> v2[i];
  }

  sort(v1.begin(), v1.end());
  sort(v2.rbegin(), v2.rend());

  ll res = 0;
  for (int i = 0; i < n; ++i) {
    res += v1[i] * v2[i];
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
