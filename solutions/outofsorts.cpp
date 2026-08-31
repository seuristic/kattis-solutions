#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n, m, a, c, x0;
  cin >> n >> m >> a >> c >> x0;
  vector<long long> x(n + 1);
  x[0] = x0;
  for (int i = 1; i <= n; ++i) {
    x[i] = (a * x[i - 1] + c) % m;
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int left = 1, right = n;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (i < left || right < i) break;
      if (x[mid] == x[i]) {
        ++ans;
        break;
      } else if (x[mid] < x[i]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
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
