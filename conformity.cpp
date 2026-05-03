#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  unordered_map<long long, int> hm;
  for (int i = 0; i < n; ++i) {
    vector<long long> courses(5);
    for (int j = 0; j < 5; ++j) {
      cin >> courses[j];
    }
    sort(courses.begin(), courses.end());
    long long k = 0;
    for (int j = 0; j < 5; ++j) {
      k = k * 1000LL + courses[j];
    }
    ++hm[k];
  }

  int popular_comb = 0;
  for (auto& t : hm) {
    popular_comb = max(popular_comb, t.second);
  }

  int count = 0;
  for (auto& t : hm) {
    if (t.second == popular_comb) {
      ++count;
    }
  }

  cout << count * popular_comb << endl;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}
