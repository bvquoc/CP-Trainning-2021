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
#define TASK "COOLMAC"
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

constexpr ll maxn = 1e5 + 5;
constexpr ll MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFL = 1e18;
constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

//o - o - o - o - o - o - o - o - o - MAIN - o - o - o - o - o - o - o - o - o

struct cl
{
    int l, r;
    cl(){}
    cl(int _l, int _r) {
        l = _l, r = _r;
    }
    void getInformation() {
        cin >> l >> r;
    }
    void ou() {
        cout << l << ' ' << r << '\n';
    }
} clothes[maxn];

int m, n;
int mmin = maxn;
int un, on = -1;

void solve() {
    sort(clothes + 1, clothes + m + 1, [](cl &a, cl &b)
         {
             return a.l < b.l;
         });
    un = clothes[1].l;
    if (un > mmin || on < 100000) cout << -1;
    {
        on = clothes[1].r;
        deque<cl> q;
        q.push_back(clothes[1]);
        FOR(i, 2, m) {
            if (clothes[i].l > q.front().l && clothes[i].r < q.front().r) continue;
            else if (clothes[i].l < q.back().l && clothes[i].r > q.back().r) {
                    while (clothes[i].l < q.back().l && clothes[i].r > q.back().r) {
                        on = max(on, clothes[i].r);
                        q.pop_back();
                    }
                    q.push_front(clothes[i]);
            }
            else if ((clothes[i].l <= q.front().r && clothes[i].r > q.front().r) || clothes[i].l - q.front().r == 1){
                    q.push_front(clothes[i]);
                    on = max(on, clothes[i].r);
            }
        }
        if (on >= 100000 && un <= mmin) cout << q.size();
        else cout << -1;
    }
}

void process() {
    bool ok = 0;
    cin >> m;
    FOR(i, 1, m) {
        clothes[i].getInformation();
        if (clothes[i].l <= mmin && clothes[i].r >= 100000) ok =1;
        on = max(on, clothes[i].r);
    }

    cin >> n;
    FOR (i, 1, n) {
        int tmp;
        cin >> tmp;
        mmin = min(mmin, tmp);
    }

    //cout << mmin;
    if (ok) cout << 1;
    else solve();
}

int main() {
    fast;
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    process();
}
