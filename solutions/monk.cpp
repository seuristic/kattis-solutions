#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<pair<double, double>> a, d;

double calcDist(double time, char type) {
  const auto& v = (type == 'a') ? a : d;
  double dist = 0;
  double prev_ch = 0, prev_ct = 0;
  for (const auto& [ch, ct] : v) {
    if (time >= ct) {
      dist = ch;
    } else {
      dist += (1.0 * (ch - prev_ch) / (ct - prev_ct)) * (time - prev_ct);
      break;
    }
    prev_ch = ch, prev_ct = ct;
  }

  return dist;
}

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    double h, t;
    cin >> h >> t;
    if (i) h += a[i - 1].first, t += a[i - 1].second;
    a.push_back({h, t});
  }

  for (int i = 0; i < m; ++i) {
    double h, t;
    cin >> h >> t;
    if (i) h += d[i - 1].first, t += d[i - 1].second;
    d.push_back({h, t});
  }

  double low = 0, high = a.back().second;
  while (fabs(high - low) > 1e-6) {
    double mid = (low + high) / 2.0;
    double h1 = calcDist(mid, 'a');
    double h2 = calcDist(mid, 'd');
    if (h1 + h2 < a.back().first) {
      low = mid;
    } else {
      high = mid;
    }
  }

  cout << setprecision(6) << fixed << low << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
