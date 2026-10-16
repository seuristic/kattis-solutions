#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll nCr(int n, int r) {
  cout << n << ' ' << r << '\n';
  if (r < 0 || r > n) return 0;
  if (r > n - r) r = n - r;

  ll res = 1;
  for (int i = 1; i <= r; ++i) {
    res = (__int128_t)res * (n - i + 1) / i;
  }
  return res;
}

int a, b, e, p;
vector<vector<int>> al;
vector<int> indeg;

void solve() {
  cin >> a >> b >> e >> p;

  al.assign(e, {});
  indeg.assign(e, 0);

  for (int i = 0; i < p; ++i) {
    int u, v;
    cin >> u >> v;

    ++indeg[v];
    al[u].push_back(v);
  }

  int ans_a = -1, ans_b = -1;
  queue<int> q;

  for (int u = 0; u < e; ++u) {
    if (indeg[u] == 0) {
      q.push(u);
    }
  }

  int promoted = 0;
  while (!q.empty()) {
    int qsize = q.size();
    if (promoted + qsize == a) ans_a = promoted + qsize;
    else if (promoted + qsize > a) ans_a = promoted;
    if (promoted + qsize == b) {
      ans_b = promoted + qsize;
      break;
    } else if (promoted + qsize > b) {
      ans_b = promoted;
      break;
    }
    promoted += qsize;
    while (qsize--) {
      int u = q.front();
      q.pop();
      for (int v : al[u]) {
        if (--indeg[v] == 0) {
          q.push(v);
        }
      }
    }
  }

  cout << ans_a << '\n';
  cout << ans_b << '\n';
  cout << e - ans_b << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
