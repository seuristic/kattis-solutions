#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> k(n);
  for (int& x : k) cin >> x;

  int start = 0, remaining = n;
  for (int i = 0; i < n - 1; ++i) {
    int j, steps = (k[start] - 1) % remaining;
    for (j = start; steps > 0; j = (j + 1) % n) {
      if (k[j] == 0) continue;
      steps--;
    }
    while (k[j] == 0) j = (j + 1) % n;
    k[j] = 0;
    while (k[j] == 0) j = (j + 1) % n;
    start = j;
    --remaining;
  }
  cout << start + 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
