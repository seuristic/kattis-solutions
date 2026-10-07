#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> AL;
vector<int> lab, indeg;

int simulate(int startLab) {
  vector<int> deg = indeg;

  queue<int> q[2];

  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) {
      q[lab[i] - 1].push(i);
    }
  }

  int curLab = startLab - 1;
  int switches = 0;
  int processed = 0;

  while (!q[0].empty() || !q[1].empty()) {
    if (q[curLab].empty()) {
      curLab ^= 1;
      ++switches;
    }

    while (!q[curLab].empty()) {
      int u = q[curLab].front();
      q[curLab].pop();

      ++processed;

      for (int v : AL[u]) {
        --deg[v];

        // v becomes available.
        if (deg[v] == 0) {
          q[lab[v] - 1].push(v);
        }
      }
    }
  }

  return switches;
}

void solve() {
  cin >> n >> m;

  AL.assign(n, {});
  lab.resize(n);
  indeg.assign(n, 0);

  for (int i = 0; i < n; ++i) {
    cin >> lab[i];
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;

    --u;
    --v;

    AL[u].push_back(v);
    ++indeg[v];
  }

  int ans = min(simulate(1), simulate(2));

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}
