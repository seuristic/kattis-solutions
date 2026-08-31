#include <bits/stdc++.h>
using namespace std;

void solve() {
  int d;
  cin >> d;
  for (int f = 1; f * f <= d; ++f) {
    if (d % f) continue;
    int a = f, b = d / f;
    if ((a ^ b) & 1) continue;
    int n1 = (b - a) / 2, n2 = (a + b) / 2;
    cout << n1 << ' ' << n2 << '\n';
    return;
  }

  cout << "impossible\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
