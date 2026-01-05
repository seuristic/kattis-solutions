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

bool cmp(pair<str, str> a, pair<str, str> b) {
    if (a.F == b.F) return a.S < b.S;
    return a.F > b.F;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<str, str>> a(n, {"", ""});
    int maxLen = 0;
    REP(i, 0, n - 1) {
        str p, classes, t;
        cin >> p >> classes >> t;
        a[i].S = p.substr(0, SZ(p) - 1);
        stringstream ss(classes);
        string c;
        while (getline(ss, c, '-')) {
            str val = "0";
            if (c == "upper") {
                val = "2";
            } else if (c == "middle") {
                val = "1";
            }
            a[i].F += val;
        }
        maxLen = max(maxLen, SZ(a[i].F));
    }

    REP(i, 0, n - 1) {
        reverse(ALL(a[i].F));
        a[i].F += str(maxLen - SZ(a[i].F), '1');
    }

    sort(ALL(a), cmp);

    REP(i, 0, n - 1) {
        cout << a[i].S << ENDL;
    }
    REP(i, 0, 29) {
        cout << "=";
    }
    cout << ENDL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}