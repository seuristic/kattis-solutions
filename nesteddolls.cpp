#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int m;
  cin >> m;
  vector<pair<int, int>> dim(m);
  for (int i = 0; i < m; ++i) {
    cin >> dim[i].first >> dim[i].second;
  }

  sort(dim.begin(), dim.end(), [](const auto& x, const auto& y) {
    if (x.first == y.first) return x.second > y.second;
    return x.first < y.first;
  });

  int k = 0;
  vector<int> lnis(m);
  for (int i = 0; i < m; ++i) {
    int pos = upper_bound(lnis.begin(), lnis.begin() + k, -dim[i].second) -
              lnis.begin();
    lnis[pos] = -dim[i].second;
    if (pos == k) ++k;
  }

  cout << k << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
