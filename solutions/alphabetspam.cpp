#include <bits/stdc++.h>
using namespace std;

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

void solve() {
    str s;
    cin >> s;
    int len = SZ(s);
    int lower = 0, upper = 0;
    int ws = 0, sym = 0;
    FORE(c, s) {
        if (c >= 'a' && c <= 'z') {
            ++lower;
        } else if (c >= 'A' && c <= 'Z') {
            ++upper;
        } else if (c == '_') {
            ++ws;
        } else {
            ++sym;
        }
    }

    cout << fixed << setprecision(7);
    cout << (double)ws / len << ENDL;
    cout << (double)lower / len << ENDL;
    cout << (double)upper / len << ENDL;
    cout << (double)sym / len << ENDL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}