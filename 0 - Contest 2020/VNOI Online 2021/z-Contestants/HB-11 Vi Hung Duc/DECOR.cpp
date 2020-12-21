//  MASTER VI HUNG DUC
#include <bits/stdc++.h>

using namespace std;

// Data Type

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll > mll;
typedef unordered_map<ll, ll> umll;

// Funtions

#define fi first
#define se second
#define pb push_back
#define upper upper_bound
#define lower lower_bound
#define memset(a, x) memset(a, x, sizeof(a))
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio()

// Shortcut
#define TASK "DECOR"
#define sz(x) int(x.size())
#define ALL(v) v.begin(), v.end()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FORD(i, r, l) for (int i = r; i >= l; i--)
#define FORTYPE(type, i, l, r) for (type i = l; i <= r; i++)
#define FODTYPE(type, i, r, l) for (type i = r; i >= l; i--)

// BIT

#define BIT(x, i) (((x) >> (i)) & 1)
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)

// EDIT

constexpr ll maxn = 1e6 + 5;
constexpr ll MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFL = 1e18;
constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

//o - o - o - o - o - o - o - o - o - MAIN - o - o - o - o - o - o - o - o - o

int n, m, k;
string s;

void sub1(string s) {
    s += '0';
    pii kq;
    bool ok = 0;
    int l, r, res = 0, ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '1') {
            if (!ok) l = i;
            ans++; ok = 1;
        }
        else {
            if (ans > res) {
                res = ans;
                r = i - 1;
                kq = {l, r};
            }
            ans = 0;
            ok = 0;
        }
    }
    if (kq.first == 0 && kq.second == 0) cout << -1;
    else cout << kq.first + 1 << ' ' << kq.second + 1;
}
int main() {
    fast;
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin >> n >> m >> k >> s;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
    }
    if (m == 0 && k == 0) sub1(s);
    else cout << -1;
}

