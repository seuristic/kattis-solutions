#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  long long n;
  cin >> n;
  vector<long long> res;
  for (long long i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i - 1);
      if (i != n / i) {
        res.push_back((n / i) - 1);
      }
    }
  }

  sort(res.begin(), res.end());

  for (long long& x : res) {
    cout << x << ' ';
  }
  cout << '\n';
}
