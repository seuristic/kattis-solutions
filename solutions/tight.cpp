#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int k, n;
ld memo[105][11];

ld f(int len, int d) {
  if (len == n) return 1;

  ld& ans = memo[len][d];

  if (ans != -1) return ans;

  ans = 0;

  for (int new_d = 0; new_d <= k; ++new_d) {
    if (d == k + 1 || abs(new_d - d) < 2) {
      ans += f(len + 1, new_d);
    }
  }

  return ans;
}

void solve() {
  while (cin >> k >> n) {
    for (auto& row : memo) {
      fill(begin(row), end(row), -1.0L);
    }

    ld res = f(0, k + 1);
    ld total = powl(k + 1, n);
    cout << setprecision(9) << fixed << 100.0 * res / total << '\n';
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
