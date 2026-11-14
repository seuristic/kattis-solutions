#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

struct Point {
  double x, y;
};

struct Edge {
  int u, v;
};

const double INF = 1e18;
const double EPS = 1e-9;

double findDist(const Point& p1, const Point& p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return sqrt(dx * dx + dy * dy);
}

void solve() {
  int n;
  while (cin >> n && n > 0) {
    vector<Point> points(n);
    vector<vector<double>> am(n, vector<double>(n, INF));

    for (int i = 0; i < n; ++i) {
      cin >> points[i].x >> points[i].y;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      double w = findDist(points[u], points[v]);
      am[u][v] = am[v][u] = w;
    }

    for (int i = 0; i < n; ++i) {
      am[i][i] = 0;
    }

    vector<Edge> possible_edges;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (am[i][j] == INF) {
          possible_edges.push_back({i, j});
        }
      }
    }

    vector<vector<double>> dist = am;

    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (dist[i][k] == INF || dist[k][j] == INF) continue;

          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    double old_sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (dist[i][j] != INF) old_sum += dist[i][j];
      }
    }

    double new_sum = old_sum;
    Edge new_edge = {-1, -1};

    for (const Edge& e : possible_edges) {
      auto w = findDist(points[e.u], points[e.v]);
      double u = e.u, v = e.v;
      double curr_sum = 0;

      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          double d = dist[i][j];

          if (dist[i][u] != INF && dist[v][j] != INF) {
            d = min(d, dist[i][u] + w + dist[v][j]);
          }

          if (dist[i][v] != INF && dist[u][j] != INF) {
            d = min(d, dist[i][v] + w + dist[u][j]);
          }

          if (d != INF) curr_sum += d;
        }
      }

      if (curr_sum - new_sum < EPS) {
        new_sum = curr_sum;
        new_edge = e;
      }
    }

    cout << fixed << setprecision(8);

    if (new_edge.u == -1) {
      cout << "no addition reduces " << old_sum << '\n';
    } else {
      cout << "adding " << new_edge.u << ' ' << new_edge.v << " reduces "
           << old_sum << " to " << new_sum << '\n';
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
