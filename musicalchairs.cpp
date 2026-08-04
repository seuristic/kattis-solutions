#include <bits/stdc++.h>
using namespace std;

int f(int n, int k) {
  if (n == 1) return 0;
  return (f(n - 1, k) + k) % n;
}

void solve() {
  int n, k;
  cin >> n >> k;
  cout << f(n, k) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
