#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9 + 7;

pair<long long, long long> findToken(long long prev_hash, char ch) {
  long long a = 7 * 31;
  long long b = 7 * ch;
  long long c = (a * prev_hash + b) % M;
  for (long long i = 1; i < 100; ++i) {
    long long h = i * 10000000;
    long long token = ((h - c) % M + M) % M;
    if (token < 1000000000) {
      return {h, token};
    }
  }

  return {-1, -1};
}

void solve() {
  long long prev_hash;
  cin >> prev_hash;

  auto [h1, t1] = findToken(prev_hash, 'a');
  auto [h2, t2] = findToken(h1, 'a');
  cout << "a " << t1 << '\n';
  cout << "a " << t2 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
