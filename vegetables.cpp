#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Node {
  ld piece;
  int index;
  int piece_count;

  bool operator<(const Node& other) const { return piece < other.piece; }
};

void solve() {
  ld t;
  int n;
  cin >> t >> n;
  vector<ld> a(n);
  priority_queue<Node> pq;
  ld mn = numeric_limits<ld>::max();
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pq.push({a[i], i, 1});
    mn = min(mn, a[i]);
  }

  for (int cuts = 0; cuts < 500; ++cuts) {
    ld mx = pq.top().piece;

    if (mn / mx + 1e-12L >= t) {
      cout << cuts << '\n';
      return;
    }

    Node curr = pq.top();
    pq.pop();
    ++curr.piece_count;
    curr.piece = a[curr.index] / curr.piece_count;
    mn = min(mn, curr.piece);
    pq.push(curr);
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
