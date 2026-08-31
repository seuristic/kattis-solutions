#include <bits/stdc++.h>
using namespace std;

const int N = 12;

void solve() {
  int k;
  cin >> k;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }

  int cnt = 0;
  for (int i = 1; i < N - 1; ++i) {
    for (int j = i; j < N - 1; ++j) {
      int min_val = *min_element(a.begin() + i, a.begin() + j + 1);
      if (min_val > a[i - 1] && min_val > a[j + 1]) {
        ++cnt;
      }
    }
  }

  cout << k << ' ' << cnt << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
