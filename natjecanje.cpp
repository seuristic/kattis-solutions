#include <bits/stdc++.h>
using namespace std;

int n, s, r;

int f(int ind, int d_mask, int r_mask) {
  if (ind == n) return __builtin_popcount(d_mask);

  int ans = f(ind + 1, d_mask, r_mask);
  if ((r_mask & (1 << ind))) {
    if (d_mask & (1 << ind)) {
      ans = min(ans, f(ind + 1, d_mask ^ (1 << ind), r_mask ^ (1 << ind)));
    }
    if (ind > 0 && (d_mask & (1 << (ind - 1)))) {
      ans =
          min(ans, f(ind + 1, d_mask ^ (1 << (ind - 1)), r_mask ^ (1 << ind)));
    }
    if (ind < n - 1 && (d_mask & (1 << (ind + 1)))) {
      ans =
          min(ans, f(ind + 1, d_mask ^ (1 << (ind + 1)), r_mask ^ (1 << ind)));
    }
  }

  return ans;
}

void solve() {
  cin >> n >> s >> r;
  int d_mask = 0, r_mask = 0;
  for (int i = 0; i < s; ++i) {
    int ind;
    cin >> ind;
    --ind;
    d_mask |= 1 << ind;
  }
  for (int i = 0; i < r; ++i) {
    int ind;
    cin >> ind;
    --ind;
    r_mask |= 1 << ind;
  }

  cout << f(0, d_mask, r_mask) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
