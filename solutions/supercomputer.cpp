#include <bits/stdc++.h>
using namespace std;

#define LSOne(x) ((x) & (-x))

class FenwickTree {
private:
  vector<int> ft;
  vector<bool> a;

public:
  FenwickTree(int m) : ft(m + 1, 0), a(m + 1, false) {}

  void update(int i) {
    int val = (a[i] ? -1 : 1);
    a[i] = !a[i];
    for (; i < (int)ft.size(); i += LSOne(i)) {
      ft[i] += val;
    }
  }

  int rsq(int i) {
    int sum = 0;
    for (; i; i -= LSOne(i)) {
      sum += ft[i];
    }
    return sum;
  }

  int rsq(int l, int r) { return rsq(r) - rsq(l - 1); }
};

void solve() {
  int n, k;
  cin >> n >> k;
  FenwickTree ft(n + 1);
  while (k--) {
    char ch;
    cin >> ch;
    if (ch == 'F') {
      int i;
      cin >> i;
      ft.update(i);
    } else {
      int l, r;
      cin >> l >> r;
      cout << ft.rsq(l, r) << endl;
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
