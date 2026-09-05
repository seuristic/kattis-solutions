#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 9901;

int n;
vector<int> g;
ll memo[15][1 << 10];

ll func(int u, int mask) {
  if (mask == (1 << n) - 1) return g[u] & 1;

  ll& ans = memo[u][mask];

  if (ans != -1) return ans;

  ans = 0;

  for (int v = 0; v < n; ++v) {
    if (mask & (1 << v)) continue;
    if (g[u] & (1 << v)) {
      ans += func(v, mask | (1 << v));
      ans %= MOD;
    }
  }

  return ans;
}

void solve() {
  int f;
  cin >> n >> f;

  g.assign(n, (1 << n) - 1);

  while (f--) {
    int u, v;
    cin >> u >> v;

    --u, --v;

    g[u] ^= 1 << v;
    g[v] ^= 1 << u;
  }

  for (int i = 0; i < n; ++i) {
    g[i] ^= (1 << i);
  }

  memset(memo, -1, sizeof memo);

  cout << func(0, 1) * 4951 % MOD << '\n';
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
