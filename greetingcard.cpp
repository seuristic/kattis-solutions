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

ll encode(ii p) {
    return ((ll)p.first << 31) | p.second;
}

void solve() {
    int n;
    cin >> n;
    vii points(n);
    unordered_set<ll> pset, hset;
    REP(i, 0, n - 1) {
        cin >> points[i].first >> points[i].second;
        pset.insert(encode(points[i]));
    }

    int result = 0;
    FORE(p, points) {
        ll k = encode(p);
        if (hset.count(k)) continue;
        hset.insert(k);
        int dx = 1680, dy = 1118;
        REP(l, 0, 1) {
            REP(i, 0, 3) {
                int x = p.first, y = p.second;
                if (i & 1) {
                    y -= dy;
                } else {
                    y += dy;
                }
                if (i & 2) {
                    x -= dx;
                } else {
                    x += dx;
                }
                ll k_new = encode({x, y});
                if (pset.count(k_new) && !hset.count(k_new)) {
                    ++result;
                }
            }
            swap(dx, dy);
        }
        dx = 2018, dy = 0;
        REP(l, 0, 1) {
            REP(i, 0, 1) {
                int x = p.first, y = p.second;
                if (l & 1) {
                    if (i & 1) {
                        y -= dy;
                    } else {
                        y += dy;
                    }
                } else {
                    if (i & 1) {
                        x -= dx;
                    } else {
                        x += dx;
                    }
                }
                ll k_new = encode({x, y});
                if (pset.count(k_new) && !hset.count(k_new)) {
                    ++result;
                }
            }
            swap(dx, dy);
        }
    }

    cout << result << ENDL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}