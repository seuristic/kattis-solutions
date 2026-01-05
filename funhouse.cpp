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

void solve() {
    int w, l;
    int cnt = 0;
    while (cin >> w >> l && w && l) {
        ++cnt;
        vector<str> grid(l);
        REP(i, 0, l - 1)
        cin >> grid[i];

        ii dir, coord;
        REP(j, 1, w - 2) {
            if (grid[0][j] == '*') {
                dir = {1, 0};
                coord = {0, j};
            }
        }
        REP(i, 1, l - 2) {
            if (grid[i][w - 1] == '*') {
                dir = {0, -1};
                coord = {i, w - 1};
            }
        }
        REP(j, 1, w - 2) {
            if (grid[l - 1][j] == '*') {
                dir = {-1, 0};
                coord = {l - 1, j};
            }
        }
        REP(i, 1, l - 2) {
            if (grid[i][0] == '*') {
                dir = {0, 1};
                coord = {i, 0};
            }
        }

        while (true) {
            coord.F += dir.F;
            coord.S += dir.S;
            if (coord.F == 0 || coord.F == l - 1 || coord.S == 0 || coord.S == w - 1) {
                grid[coord.F][coord.S] = '&';
                break;
            }
            coord = coord;
            if (grid[coord.F][coord.S] == '/') {
                swap(dir.F, dir.S);
                dir.F *= -1;
                dir.S *= -1;
            } else if (grid[coord.F][coord.S] == '\\') {
                swap(dir.F, dir.S);
            }
        }

        cout << "HOUSE " << cnt << ENDL;
        REP(i, 0, l - 1) {
            cout << grid[i] << ENDL;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}