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
    int n, k;
    cin >> n >> k;
    vi st{0};
    int pos = 0;
    while (k--) {
        str f;
        cin >> f;
        if (f == "undo") {
            int m;
            cin >> m;
            while (m--) {
                st.pop_back();
            }
            pos = st.back();
        } else {
            int jump = stoi(f);
            jump = (n + jump % n) % n;
            pos = (pos + jump) % n;
            st.push_back(pos);
        }
    }
    cout << pos << ENDL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}