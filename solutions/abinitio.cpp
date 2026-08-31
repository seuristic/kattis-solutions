#include <bits/stdc++.h>
using namespace std;

constexpr long long MOD = 1e9 + 7;

void solve() {
  int vertices, edges, queries;
  cin >> vertices >> edges >> queries;
  vector<vector<bool>> am(vertices, vector<bool>(vertices, 0));
  for (int i = 0; i < edges; ++i) {
    int a, b;
    cin >> a >> b;
    am[a][b] = 1;
  }

  bool transpose_flag = 0, compliment_flag = 0;
  while (queries--) {
    int type, x, y;
    cin >> type;
    switch (type) {
      case 1:
        for (int i = 0; i < vertices; ++i) {
          am[i].push_back(compliment_flag);
        }
        am.push_back(vector<bool>(vertices + 1, compliment_flag));
        am[vertices][vertices] = 0;
        ++vertices;
        break;
      case 2:
        cin >> x >> y;
        if (transpose_flag) swap(x, y);
        am[x][y] = !compliment_flag;
        break;
      case 3:
        cin >> x;
        for (int i = 0; i < vertices; ++i) {
          am[i][x] = am[x][i] = compliment_flag;
        }
        am[x][x] = 0;
        break;
      case 4:
        cin >> x >> y;
        if (transpose_flag) swap(x, y);
        am[x][y] = compliment_flag;
        break;
      case 5: transpose_flag ^= 1; break;
      default: compliment_flag ^= 1;
    }
  }

  if (transpose_flag) {
    for (int i = 0; i < vertices; ++i) {
      for (int j = 0; j < i; ++j) {
        swap(am[i][j], am[j][i]);
      }
    }
  }

  if (compliment_flag) {
    for (int i = 0; i < vertices; ++i) {
      for (int j = 0; j < vertices; ++j) {
        if (i != j) am[i][j] = !am[i][j];
        else am[i][j] = 0;
      }
    }
  }

  vector<long long> p(vertices + 1);
  p[0] = 1;
  for (int i = 1; i <= vertices; ++i) {
    p[i] = (p[i - 1] * 7) % MOD;
  }

  cout << vertices << endl;
  for (int i = 0; i < vertices; ++i) {
    long long h = 0;
    int outdegree = 0;
    for (int j = 0; j < vertices; ++j) {
      if (am[i][j]) {
        h = (h + j * p[outdegree]) % MOD;
        ++outdegree;
      }
    }
    cout << outdegree << ' ' << h << endl;
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
