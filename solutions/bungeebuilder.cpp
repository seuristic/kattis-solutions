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
constexpr int INF = 1e9 + 5;
constexpr ll LLINF = 1e18;

void solve() {
    int n;
    cin >> n;
    vi h(n);
    FORE(&x, h) {
        cin >> x;
    }

    vi st;
    int minHeight = INF, maxJump = 0;
    REP(i, 0, n - 1) {
        if (st.empty() || st.back() < h[i]) {
            st.push_back(h[i]);
            minHeight = INF;
        } else {
            maxJump = max(maxJump, h[i] - minHeight);
            minHeight = min(minHeight, h[i]);
        }
    }

    minHeight = INF;
    st.clear();
    PER(i, n - 1, 0) {
        if (st.empty() || st.back() < h[i]) {
            st.push_back(h[i]);
            minHeight = INF;
        } else {
            maxJump = max(maxJump, h[i] - minHeight);
            minHeight = min(minHeight, h[i]);
        }
    }

    cout << maxJump << ENDL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}