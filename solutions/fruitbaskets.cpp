#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
long long small = 0;

void f(int start, long long curr) {
  if (curr >= 200) return;

  small += curr;

  for (int i = start; i < n; ++i) {
    f(i + 1, curr + a[i]);
  }
}

void solve() {
  cin >> n;
  a.resize(n);
  for (int& x : a) cin >> x;

  f(0, 0);

  long long sum = accumulate(a.begin(), a.end(), 0LL);
  long long total = sum * (1LL << (n - 1));
  cout << total - small << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
