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

str s;

void solve() {
    getline(cin, s);
    list<char> l;
    auto it = l.begin();
    FORE(&c, s) {
        if (c == '[') {
            it = l.begin();
        } else if (c == ']') {
            it = l.end();
        } else if (c == '<') {
            if (SZ(l) > 0 && it != l.begin()) {
                it = l.erase(--it);
            }
        } else {
            l.insert(it, c);
        }
    }

    it = l.begin();
    while (it != l.end()) {
        cout << *it;
        ++it;
    }
    cout << ENDL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    getline(cin, s);
    while (tc--) solve();
}