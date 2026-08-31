#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define F first
#define S second
#define PB push_back
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
#define REP(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
using str = string;

constexpr char ENDL = '\n';
constexpr double EPS = 1e-9;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

int dir[] = {0, -1, 0, 1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<str> grid(n);
    REP(i, 0, n - 1) {
        cin >> grid[i];
    }

    int ringId = 0;
    vii next;
    while (true) {
        ++ringId;
        next.clear();
        REP(i, 0, n - 1) {
            REP(j, 0, m - 1) {
                if (grid[i][j] != 'T') continue;
                REP(k, 0, 3) {
                    int r = i + dir[k];
                    int c = j + dir[k + 1];
                    if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '.' || grid[r][c] == ringId + '0' - 1) {
                        next.PB({i, j});
                        break;
                    }
                }
            }
        }

        if (SZ(next) == 0) break;

        for (auto [r, c] : next) {
            grid[r][c] = ringId + '0';
        }
    }

    REP(i, 0, n - 1) {
        REP(j, 0, m - 1) {
            if (ringId < 10) {
                if (grid[i][j] == '.') {
                    cout << "..";
                } else {
                    cout << "." << int(grid[i][j] - '0');
                }
            } else {
                if (grid[i][j] == '.') {
                    cout << "...";
                } else if (int(grid[i][j] - '0') < 10) {
                    cout << ".." << int(grid[i][j] - '0');
                } else {
                    cout << "." << int(grid[i][j] - '0');
                }
            }
        }
        cout << ENDL;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}