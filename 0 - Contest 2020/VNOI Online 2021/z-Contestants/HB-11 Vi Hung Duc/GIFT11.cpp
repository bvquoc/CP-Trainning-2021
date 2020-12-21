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

// Shortcut
#define TASK "GIFT11"
#define sz(x) int(x.size())
#define ALL(v) v.begin(), v.end()
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
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
constexpr ll MOD = 998244353;
constexpr int INF = 1e9;
constexpr ll INFL = 1e18;
constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

//o - o - o - o - o - o - o - o - o - MAIN - o - o - o - o - o - o - o - o - o

int t, n;
struct st
{
    string ss;
    ll le, chan;
    st(){}
    st(string _ss, ll l, ll c) {
        ss = _ss; le = l; chan = c;
    }

    void ou() {
        cout << ss << ' ' << le << ' ' << chan << '\n';
    }
};

st a[2005];

void add(ll &res) {
    res++;
    if (res >= MOD) res -= MOD;
}
void sub1() {
    ll res = 0;
    vector<int> v(n + 1);
    FOR(i, 1, n) v[i] = i;

    do {
        bool c = 1;
        int length = 0;
        ll suml = 0, sumc = 0;

        FOR(x, 1, n) {
            int i = v[x];
            if (c) {
                suml += a[i].le;
                sumc += a[i].chan;
                if ((length + sz(a[i].ss)) % 2){
                    c = 0;
                    length += sz(a[i].ss);
                }
                else length += sz(a[i].ss);
            }
            else {
                suml += a[i].chan;
                sumc += a[i].le;
                if ((length + sz(a[i].ss)) % 2 == 0){
                    c = 1;
                    length += sz(a[i].ss);
                }
                else length += sz(a[i].ss);
            }
        }

        if (abs(suml - sumc) % 11 == 0) add(res);
    }while(next_permutation(v.begin() + 1, v.end()));
    cout << res << '\n';
}

void sub2() {
    ll res = 1;
    ll suml = 0, sumc = 0;
    FOR(i, 1, n)
    {
        suml += a[i].le;
        sumc += a[i].chan;
    }
    if (abs(suml - sumc) % 11 == 0) {
        FOR(i, 1, n) {
            res = res * i % MOD;
        }
        cout << res << '\n';
    } else cout << 0 << '\n';
}

int main() {
    fast;
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin >> t;
    string tmp;
    while (t--) {
        cin >> n;
        bool s2 = 1;

        FOR(i, 1, n) {
            cin >> tmp;
            if (sz(tmp) & 1) s2 = 0;
            ll l = 0, c = 0;
            for (int i = 0; i < sz(tmp); i++) {
                if (i & 1) c += tmp[i] - 48;
                    else l += tmp[i] - 48;
            }
            a[i] = st(tmp, l, c);
        }
        if (s2) sub2();
            else sub1();
    }
}
