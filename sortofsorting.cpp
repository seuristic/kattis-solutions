#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define F first
#define S second
#define PB push_back
#define ALL(x) begin(x), end(x)
#define SIZE(x) (int)(x).size()

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

constexpr char ENDL = '\n';
constexpr double EPS = 1e-9;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    string x = a.F.substr(0, 2);
    string y = b.F.substr(0, 2);
    if (x == y) return a.S < b.S;
    return x < y;
}

void solve() {
    int n;
    while (true) {
        cin >> n;
        if (!n) break;
        vector<pair<string, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].F;
            a[i].S = i;
        }

        sort(ALL(a), cmp);

        for (const auto& [s, _] : a) {
            cout << s << ENDL;
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