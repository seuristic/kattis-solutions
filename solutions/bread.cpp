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

ll inv = 0;

void merge(vi& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vi L(n1), R(n2);
    REP(i, 0, n1 - 1) {
        L[i] = a[l + i];
    }
    REP(i, 0, n2 - 1) {
        R[i] = a[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 || j < n2) {
        if (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                a[k++] = L[i++];
            } else {
                inv += n1 - i;
                a[k++] = R[j++];
            }
        } else if (i < n1) {
            a[k++] = L[i++];
        } else if (j < n2) {
            a[k++] = R[j++];
        }
    }
}

void mergeSort(vi& a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n), c(n);
    REP(i, 0, n - 1) {
        cin >> a[i];
    }
    REP(i, 0, n - 1) {
        cin >> b[i];
        c[b[i] - 1] = i;
    }

    REP(i, 0, n - 1) {
        a[i] = c[a[i] - 1];
    }

    inv = 0;
    mergeSort(a, 0, n - 1);

    cout << ((inv & 1) ? "Impossible" : "Possible") << ENDL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}