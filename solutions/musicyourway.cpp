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
#define REP(i, a, b) for (int i = (a); i <= (b); i++)

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

int currIndex = -1;

bool cmp(vector<str> a, vector<str> b) {
    return a[currIndex] < b[currIndex];
}

void solve() {
    vector<str> allAttr;
    unordered_map<str, int> attrMap;
    string line, attr;
    getline(cin, line);
    stringstream ss(line);
    int attrLen = 0;
    while (ss >> attr) {
        attrMap[attr] = attrLen;
        allAttr.PB(attr);
        ++attrLen;
    }

    int n;
    cin >> n;
    vector<vector<str>> data(n, vector<str>(attrLen));
    REP(i, 0, n - 1) {
        REP(j, 0, attrLen - 1) {
            cin >> data[i][j];
        }
    }

    int m;
    cin >> m;
    REP(i, 0, m - 1) {
        cin >> attr;
        currIndex = attrMap[attr];
        stable_sort(ALL(data), cmp);
        REP(j, 0, attrLen - 1) {
            cout << allAttr[j] << " \n"[j == attrLen - 1];
        }
        REP(j, 0, n - 1) {
            REP(k, 0, attrLen - 1) {
                cout << data[j][k] << " \n"[k == attrLen - 1];
            }
        }
        if (i < m - 1) cout << ENDL;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}