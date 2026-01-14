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
    int k, n;
    cin >> k >> n;
    int ky, kp;
    cin >> ky >> kp;
    vii a{{ky, kp}};
    REP(i, 0, n + k - 3) {
        int y, p;
        cin >> y >> p;
        a.push_back({y, p});
    }

    sort(ALL(a));

    priority_queue<int> pq;
    REP(i, 0, k - 1) {
        pq.push(a[i].second);
    }
    if (pq.top() == kp) {
        cout << a[0].first << ENDL;
        return;
    }
    pq.pop();

    REP(i, k, n + k - 2) {
        pq.push(a[i].second);
        if (pq.top() == kp) {
            cout << a[i].first << ENDL;
            return;
        }
        pq.pop();
    }

    cout << "unknown" << ENDL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}