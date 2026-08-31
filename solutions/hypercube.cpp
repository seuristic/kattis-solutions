#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define SZ(x) (int)(x).size()
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define FORE(x, a) for (auto x : (a))

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

ll findIndex(str& s) {
    ll val = s[0] - '0';
    REP(i, 0, SZ(s) - 2) {
        if (s[i] == '1') {
            s[i + 1] = (s[i + 1] == '1' ? '0' : '1');
        }
        val = (val << 1) | (s[i + 1] - '0');
    }
    return val;
}

void solve() {
    int n;
    str a, b;
    cin >> n >> a >> b;
    ll x = findIndex(a);
    ll y = findIndex(b);
    cout << (y - x - 1) << ENDL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}