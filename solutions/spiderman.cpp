#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9;

int n, min_height;
string ans;
vector<int> heights;
int memo[45][1005];
char choice[45][1005];

int f(int ind, int curr) {
  if (ind == n) {
    if (curr == 0) return 0;
    return INF;
  }

  int& ans = memo[ind][curr];

  if (ans != -1) return ans;

  ans = INF;

  int up = max(curr + heights[ind], f(ind + 1, curr + heights[ind]));

  if (ans > up) {
    ans = up;
    choice[ind][curr] = 'U';
  }

  if (curr >= heights[ind]) {
    int down = f(ind + 1, curr - heights[ind]);

    if (ans > down) {
      ans = down;
      choice[ind][curr] = 'D';
    }
  }

  return ans;
}

void solve() {
  cin >> n;

  heights.assign(n, 0);
  min_height = INF;

  for (int& h : heights) cin >> h;

  memset(memo, -1, sizeof memo);
  memset(choice, 0, sizeof choice);

  if (f(0, 0) == INF) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  int curr = 0;
  string ans;

  for (int i = 0; i < n; ++i) {
    char c = choice[i][curr];

    ans += c;

    if (c == 'U') curr += heights[i];
    else curr -= heights[i];
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
