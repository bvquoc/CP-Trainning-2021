#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define endl '\n'
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    } else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    } else return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

int n, q;
int block;
const int N = 20000007;
struct interval { int l, r, id; };

interval query[N];
int cnt[N];
int a[N], res[N];
vector <int> b;

void compress(vector<int> &a) {
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    for (int &x: a) {
        x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    }
}

signed main() {
    FastIO;
    freopen("empires.inp","r",stdin);
    freopen("empires.out","w",stdout);
    cin >> n >> q;
    if (n <= 5e3 && q <= 5e3) {
        FOR(i,1,n) cin >> a[i];
        for (int l, r, step = 1; step <= q; step++) {
            cin >> l >> r;
            int ans = 0, cur_max = -1;
            FOR(i,l,r) if (maximize(cur_max,a[i])) ans++;
            cout << ans << endl;
        }
        exit(0);
    }

    b.resize(n);
    for (int &x: b) cin >> x;
    compress(b);
    a[1] = b[0];
    FOR(i,1,n-1) {
        if (b[i] < b[i-1]) a[i+1] = a[i];
        else a[i+1] = a[i] + 1;
    }
    block = sqrt(n);
    FOR(i, 1, q) {
        cin >> query[i].l >> query[i].r;
        query[i].id = i;
    }
    sort(query + 1, query + 1 + q, [](const interval &a, const interval &b) {
        if (a.l/block != b.l/block) return a.l<b.l; else return a.r<b.r;
    });
    int currentL = 2, currentR = 1, dem = 0;
    FOR(i, 1, q) {
        while (currentL < query[i].l) {
            cnt[a[currentL]]--;
            if (cnt[a[currentL]] == 0) dem--;
            currentL++;
        }
        while (currentL > query[i].l) {
            currentL--;
            cnt[a[currentL]]++;
            if (cnt[a[currentL]] == 1) dem++;
        }
        while (currentR < query[i].r) {
            currentR++;
            cnt[a[currentR]]++;
            if (cnt[a[currentR]] == 1) dem++;
        }
        while (currentR > query[i].r) {
            cnt[a[currentR]]--;
            if (cnt[a[currentR]] == 0) dem--;
            currentR--;
        }
        res[query[i].id] = dem;
    }
    FOR(i, 1, q) cout << res[i] << endl;
    return 0;
}