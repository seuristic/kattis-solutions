#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int INF = 1e9;

vector<vector<int>> dist, parent;
vector<int> result;

vector<string> parse(string s) {
  vector<string> parsed;
  string filename;
  for (int i = 0; i < int(s.length()); ++i) {
    if (s[i] == ',') {
      for (int j = i - 1; s[j] != ' '; --j) {
        filename += s[j];
      }
      reverse(filename.begin(), filename.end());
      parsed.push_back(filename);
      filename = "";
    }
  }

  for (int j = s.length() - 1; s[j] != ' '; --j) {
    filename += s[j];
  }
  reverse(filename.begin(), filename.end());
  parsed.push_back(filename);

  return parsed;
}

// Alternate implementation of parse function
// vector<string> parse(string s) {
//     stringstream ss(s);
//     string keyword, filename;
//     vector<string> parsed;
//
//     ss >> keyword;
//
//     while (getline(ss, filename, ',')) {
//         size_t start = filename.find_first_not_of(' ');
//         if (start != string::npos) {
//             parsed.push_back(filename.substr(start));
//         }
//     }
//
//     return parsed;
// }

void constructPath(int u, int v) {
  if (u != v) constructPath(u, parent[u][v]);
  result.push_back(v);
}

void solve() {
  result.clear();

  int n;
  cin >> n;

  vector<string> files(n);
  unordered_map<string, int> file_to_node;
  for (int i = 0; i < n; ++i) {
    cin >> files[i];
    file_to_node[files[i]] = i;
  }

  dist.assign(n, vector<int>(n, INF));
  parent.assign(n, vector<int>(n, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      parent[i][j] = i;
    }
  }

  for (int i = 0; i < n; ++i) {
    string filename;
    int k;
    cin >> filename >> k;

    int u = file_to_node[filename];

    while (k--) {
      string line;
      getline(cin >> ws, line);
      auto imported = parse(line);
      for (const string& f : imported) {
        int v = file_to_node[f];
        dist[u][v] = 1;
        parent[u][v] = u;
      }
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          parent[i][j] = parent[k][j];
        }
      }
    }
  }

  int min_cycle_dist = INF, pos = -1;

  for (int i = 0; i < n; ++i) {
    if (dist[i][i] != INF && min_cycle_dist > dist[i][i]) {
      pos = i;
      min_cycle_dist = dist[i][i];
    }
  }

  if (pos == -1) {
    cout << "SHIP IT\n";
    return;
  }

  if (min_cycle_dist == 1) {
    cout << files[pos] << '\n';
    return;
  }

  int mid = -1;
  for (int i = 0; i < n; ++i) {
    if (dist[pos][i] + dist[i][pos] == min_cycle_dist) {
      mid = i;
      break;
    }
  }

  constructPath(pos, mid);
  result.pop_back();

  constructPath(mid, pos);
  result.pop_back();

  for (int node : result) {
    cout << files[node] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
