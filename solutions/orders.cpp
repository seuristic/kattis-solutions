#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<int> menu;
int memo[30005][105];

int f(int cost, int i) {
  if (cost == 0) return 1;
  if (i == n || cost < 0) return 0;
  int& ans = memo[cost][i];
  if (ans != -1) return ans;
  return ans = min(2, f(cost, i + 1) + f(cost - menu[i], i));
}

void print_orders(int cost) {
  vector<int> ans;

  int i = 0;

  while (cost > 0) {
    if (memo[cost][i + 1] == 1) ++i;
    else {
      ans.push_back(i + 1);
      cost -= menu[i];
    }
  }

  for (const int& x : ans) cout << x << ' ';
  cout << '\n';
}

void solve() {
  cin >> n;
  menu.assign(n, 0);
  for (int i = 0; i < n; ++i) cin >> menu[i];
  int m;
  cin >> m;
  memset(memo, -1, sizeof memo);
  for (int i = 0; i < m; ++i) {
    int cost;
    cin >> cost;
    int ans = f(cost, 0);
    if (ans < 1) cout << "Impossible\n";
    else if (ans > 1) cout << "Ambiguous\n";
    else print_orders(cost);
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
