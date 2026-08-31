#include <bits/stdc++.h>
using namespace std;

void solve() {
  string word;
  cin >> word;
  int n = word.length();
  string ans = word;
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      string s1 = word.substr(0, i + 1);
      string s2 = word.substr(i + 1, j - i);
      string s3 = word.substr(j + 1);

      reverse(s1.begin(), s1.end());
      reverse(s2.begin(), s2.end());
      reverse(s3.begin(), s3.end());

      string new_word = s1 + s2 + s3;
      if (ans > new_word) {
        ans = new_word;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
