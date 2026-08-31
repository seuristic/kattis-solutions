#include <bits/stdc++.h>
using namespace std;

#define LSOne(x) ((x) & -(x))

class FenwickTree {
  vector<long long> ft;

public:
  FenwickTree(int m) { ft.assign(m + 1, 0); }

  long long rsq(int i) {
    long long sum = 0;
    for (; i; i -= LSOne(i)) {
      sum += ft[i];
    }
    return sum;
  }

  void update(int i, long long v) {
    for (; i < int(ft.size()); i += LSOne(i)) {
      ft[i] += v;
    }
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  FenwickTree ft(n);
  while (q--) {
    char op;
    cin >> op;
    if (op == '+') {
      int i;
      long long v;
      cin >> i >> v;
      ft.update(i + 1, v);
    } else {
      int i;
      cin >> i;
      cout << ft.rsq(i) << '\n';
    }
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
