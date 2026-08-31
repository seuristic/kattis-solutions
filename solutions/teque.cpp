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
    cin >> n;
    deque<int> firstHalf, secondHalf;
    REP(i, 0, n - 1) {
        str op;
        int val;
        cin >> op >> val;
        if (op == "push_back") {
            secondHalf.push_back(val);
        } else if (op == "push_front") {
            firstHalf.push_front(val);
        } else if (op == "push_middle") {
            firstHalf.push_back(val);
        } else if (val < SZ(firstHalf)) {
            cout << firstHalf[val] << ENDL;
        } else {
            cout << secondHalf[val - SZ(firstHalf)] << ENDL;
        }

        if (SZ(firstHalf) < SZ(secondHalf)) {
            firstHalf.push_back(secondHalf.front());
            secondHalf.pop_front();
        } else if (SZ(firstHalf) == 2 + SZ(secondHalf)) {
            secondHalf.push_front(firstHalf.back());
            firstHalf.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}