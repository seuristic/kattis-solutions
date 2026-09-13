#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int rows, cols;
vector<string> grid;
vector<vector<bool>> visited;
int coast_length = 0;

void dfs(int r, int c) {
  visited[r][c] = true;

  for (int i = 0; i < 4; ++i) {
    int nr = r + dr[i];
    int nc = c + dc[i];

    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
      if (grid[nr][nc] == '1') {
        coast_length++;
      } else if (!visited[nr][nc]) {
        dfs(nr, nc);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  if (!(cin >> n >> m)) return 0;

  rows = n + 2;
  cols = m + 2;

  grid.assign(rows, string(cols, '0'));
  visited.assign(rows, vector<bool>(cols, false));

  for (int i = 1; i <= n; ++i) {
    string line;
    cin >> line;
    for (int j = 1; j <= m; ++j) {
      grid[i][j] = line[j - 1];
    }
  }

  dfs(0, 0);

  cout << coast_length << "\n";

  return 0;
}
