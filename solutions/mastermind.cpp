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

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int r = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            a[i] = '#';
            ++r;
        }
    }

    vi fa(26), fb(26);
    for (int i = 0; i < n; ++i) {
        if (a[i] != '#') {
            ++fa[a[i] - 'A'];
            ++fb[b[i] - 'A'];
        }
    }

    for (int i = 0; i < 26; ++i) {
        s += min(fa[i], fb[i]);
    }

    cout << r << ' ' << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}