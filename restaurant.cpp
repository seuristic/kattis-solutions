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
    int n;
    while (cin >> n && n > 0) {
        int p1 = 0, p2 = 0;
        while (n--) {
            str op;
            int m;
            cin >> op >> m;
            if (op == "DROP") {
                cout << "DROP 1 " << m << ENDL;
                p1 += m;
            } else if (p2 >= m) {
                cout << "TAKE 2 " << m << ENDL;
                p2 -= m;
            } else {
                if (p2 > 0) {
                    cout << "TAKE 2 " << p2 << ENDL;
                    m -= p2;
                }
                cout << "MOVE 1->2 " << p1 << ENDL;
                cout << "TAKE 2 " << m << ENDL;
                p2 = p1 - m;
                p1 = 0;
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