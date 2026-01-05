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
#include <sstream>
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
#define RALL(x) rbegin(x), rend(x)
#define SZ(x) (int)(x).size()
#define REP(i, a, b) for (int i = (a); i <= (b); i++)
#define PER(i, a, b) for (int i = (a); i >= (b); i--)

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
    int n;
    while (cin >> n && n) {
        bitset<32> b;
        unordered_set<int> known;
        REP(i, 0, n - 1) {
            str s;
            cin >> s;
            int x, y;
            if (s == "SET") {
                cin >> x;
                b.set(x);
                known.insert(x);
            } else if (s == "CLEAR") {
                cin >> x;
                b.reset(x);
                known.insert(x);
            } else if (s == "AND") {
                cin >> x >> y;
                if (known.count(x) && known.count(y)) {
                    b[x] = (b[x] && b[y]);
                } else if ((known.count(x) && !b[x]) || (known.count(y) && !b[y])) {
                    b.reset(x);
                    known.insert(x);
                } else if (known.count(x)) {
                    known.erase(x);
                }
            } else if (s == "OR") {
                cin >> x >> y;
                if (known.count(x) && known.count(y)) {
                    b[x] = (b[x] || b[y]);
                } else if ((known.count(x) && b[x] == 1) || (known.count(y) && b[y] == 1)) {
                    b.set(x);
                    known.insert(x);
                } else if (known.count(x)) {
                    known.erase(x);
                }
            }
        }
        PER(i, 31, 0) {
            if (known.count(i)) {
                cout << b[i];
            } else {
                cout << '?';
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