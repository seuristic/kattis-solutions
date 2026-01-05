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
constexpr int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int& x : a) {
        cin >> x;
    }

    vi pmax(n, -INF), smin(n, INF);
    for (int i = 1; i < n; ++i) {
        pmax[i] = max(pmax[i - 1], a[i - 1]);
        smin[n - i - 1] = min(smin[n - i], a[n - i]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (pmax[i] < a[i] && a[i] < smin[i]) {
            ++ans;
        }
    }

    cout << ans << ENDL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}