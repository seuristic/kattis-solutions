#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, last_time;
  cin >> n >> last_time;
  unordered_map<int, vector<int>> groups;
  for (int i = 0; i < n; ++i) {
    int c, t;
    cin >> c >> t;
    groups[t].push_back(c);
  }

  int res = 0;
  priority_queue<int> pq;
  for (int t = last_time - 1; t >= 0; --t) {
    for (const auto& cash : groups[t]) {
      pq.push(cash);
    }
    if (pq.size() > 0) {
      res += pq.top();
      pq.pop();
    }
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
