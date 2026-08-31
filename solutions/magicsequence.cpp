#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define SZ(x) (int)(x).size()
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)

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

void radix_sort(vector<int>& a) {
    int n = SZ(a);
    int b = 1 << 16;
    vi cnt(b, 0), tmp(n);
    REP(i, 0, n - 1) {
        ++cnt[a[i] & (b - 1)];
    }
    REP(i, 1, b - 1) {
        cnt[i] += cnt[i - 1];
    }
    PER(i, n - 1, 0) {
        tmp[--cnt[a[i] & (b - 1)]] = a[i];
    }

    fill(ALL(cnt), 0);
    REP(i, 0, n - 1) {
        ++cnt[tmp[i] >> 16];
    }
    REP(i, 1, b - 1) {
        cnt[i] += cnt[i - 1];
    }
    PER(i, n - 1, 0) {
        a[--cnt[tmp[i] >> 16]] = tmp[i];
    }
}

void solve() {
    int n;
    cin >> n;
    ll a, b, c;
    cin >> a >> b >> c;
    ll x, y;
    cin >> x >> y;

    vector<int> nums(n);
    nums[0] = a;
    REP(i, 1, n - 1) {
        nums[i] = (nums[i - 1] * b + a) % c;
    }

    radix_sort(nums);

    ll result = 0;
    REP(i, 0, n - 1) {
        result = (result * x + (ll)nums[i]) % y;
    }

    cout << result << ENDL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}