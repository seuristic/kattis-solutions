#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define F first
#define S second
#define PB push_back
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define SZ(x) (int)(x).size()
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)

using namespace std;
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

int findAns(vi cntA, vi cntB) {
    int iA = 0;
    int iB = 100;

    int worst = 0;

    bool broken = false;
    while (true) {
        while (cntA[iA] == 0) {
            iA++;
            if (iA > 100) {
                broken = true;
                break;
            }
        }
        while (!broken && cntB[iB] == 0) {
            iB--;
            if (iB < 0) {
                broken = true;
                break;
            }
        }

        if (broken) break;

        worst = max(worst, iA + iB);

        int m = min(cntA[iA], cntB[iB]);
        cntA[iA] -= m;
        cntB[iB] -= m;
    }

    return worst;
}

void solve() {
    int n;
    cin >> n;
    vi cntA(101, 0), cntB(101, 0);

    REP(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        ++cntA[a];
        ++cntB[b];
        cout << findAns(cntA, cntB) << ENDL;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}