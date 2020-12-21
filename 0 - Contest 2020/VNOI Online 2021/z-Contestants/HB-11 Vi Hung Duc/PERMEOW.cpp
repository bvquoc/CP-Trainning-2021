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
#define TASK "PERMEOW"
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
constexpr ll MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFL = 1e18;
constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

//o - o - o - o - o - o - o - o - o - MAIN - o - o - o - o - o - o - o - o - o

int n;
vector<int> a;
vector<int> b;
vector<int> T;
void add(ll &result) {
    result++;
    if (result >= MOD) result -= MOD;
}

void sub1() {
    ll res = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) add(res);
        }
    }
    cout << res;
}

long long query(int u) {
    long long sum = 0;
    for (; u > 0; u -= (u & (-u))) sum += T[u];
    return sum;
}

void update(int u, int val) {
    for (; u <= n; u += (u & (-u))) T[u] += val;
}

int main() {
    fast;
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    bool s1 = 1;
    cin >> n;
    a.assign(n + 1, 0);
    b.assign(n + 1, 0);

    FOR(i, 1, n) {
        cin >> a[i];
    }

    FOR(i, 1, n) {
        cin >> b[i];
        if (a[i] != b[i]) s1 = 0;
    }

    if (s1) sub1();
    else {
        ll result = 0;
        do {
            ll res = 0;
            vector<int> tmp = a;
            T.assign(n+1, 0);
            sort(tmp.begin() + 1, tmp.end());
            for (int i = 1; i <= n; i++)
                a[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
            for (int i = n; i > 0; i--)
            {
                res += query(a[i]);
                update(a[i], 1);
            }
            result += res;
            if (a == b) break;
        }while(next_permutation(a.begin() + 1, a.end()));
        cout << result;
    }
}
