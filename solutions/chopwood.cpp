#include <bits/stdc++.h>

#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int vert = n + 1;
  vector<int> v(n), freq(vert + 1);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    ++freq[v[i]];
  }

  if (v.back() != vert) {
    cout << "Error\n";
    return;
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1; i <= vert; ++i) {
    if (freq[i] == 0) {
      pq.push(i);
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (pq.empty()) {
      cout << "Error\n";
      return;
    }

    int x = pq.top();
    pq.pop();
    ans.push_back(x);

    if (--freq[v[i]] == 0) {
      pq.push(v[i]);
    }
  }

  for (int x : ans) {
    cout << x << endl;
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
