#include <bits/stdc++.h>
using namespace std;

struct Point {
  long long x, y;
};

long long encode(long long a, long long b) { return (long long)((a << 31) + b); }

void solve() {
  int n;
  cin >> n;
  vector<Point> points(n);
  unordered_set<long long> point_set, next_present;
  for (auto& [x, y] : points) {
    cin >> x >> y;
    point_set.insert(encode(x, y));
  }

  int result = 0;
  for (auto& [x, y] : points) {
    long long key = encode(x, y);
    if (next_present.count(key)) continue;
    next_present.insert(key);

    vector<pair<int, int>> possible_dist = {
        {2018, 0},
        {-2018, 0},
        {0, 2018},
        {0, -2018},
        {1680, 1118},
        {1680, -1118},
        {-1680, 1118},
        {-1680, -1118},
        {1118, 1680},
        {1118, -1680},
        {-1118, 1680},
        {-1118, -1680}};

    for (auto [dx, dy] : possible_dist) {
      long long key2 = encode(x + dx, y + dy);
      if (point_set.count(key2) && !next_present.count(key2)) { ++result; }
    }
  }

  cout << result << endl;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}
