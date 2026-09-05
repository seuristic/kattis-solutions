#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9;

int n;
vector<int> coins;

int g(int rem) {
  int cnt = 0;

  while (rem > 0) {
    int ind = upper_bound(coins.begin(), coins.end(), rem) - coins.begin();
    --ind;

    int c = rem / coins[ind];

    rem -= coins[ind] * c;
    cnt += c;
  }

  return cnt;
}

void solve() {
  cin >> n;
  coins.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }

  int limit = coins[n - 2] + coins[n - 1];

  vector<int> dp(limit + 1, INF);
  dp[0] = 0;

  for (int x = 2; x < limit; ++x) {
    for (int& c : coins) {
      if (x >= c) {
        dp[x] = min(dp[x], 1 + dp[x - c]);
      }
    }
  }

  for (int x = limit - 1; x > 1; --x) {
    if (g(x) > dp[x]) {
      cout << "non-canonical\n";
      return;
    }
  }

  cout << "canonical\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
