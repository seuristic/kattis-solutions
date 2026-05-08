#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int ans = n;
  unordered_map<int, int> index_map;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (index_map.count(x)) {
      ans = min(ans, i - index_map[x]);
    }
    index_map[x] = i;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}
