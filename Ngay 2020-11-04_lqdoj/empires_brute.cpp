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
// #define int long long
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

const int N = 500005;
int n, q_sz, a[N];
struct TQuery {
    int l, r, id;
} q[N];
int q_ans[N];

signed main(void) {
    FastIO;
    freopen("empires.inp","r",stdin);
    freopen("empires.out","w",stdout);
    cin >> n >> q_sz;
    FOR(i,1,n) cin >> a[i];
    // if (n <= 5e3 && q_sz <= 5e3) {
    //     for (int l, r, step = 1; step <= q_sz; step++) {
    //         cin >> l >> r;
    //         int ans = 0, cur_max = -1;
    //         FOR(i,l,r) if (maximize(cur_max,a[i])) ans++;
    //         cout << ans << endl;
    //     }
    //     exit(0);
    // }
    FOR(i,1,q_sz) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q+1, q+1+q_sz, [](const TQuery &A, const TQuery &B) {
        return (A.l < B.l || (A.l == B.l && A.r < B.r));
    });
    
    int cur_ans = 0, cur_max = 0;
    FOR(i, q[1].l, q[1].r) if (maximize(cur_max, a[i])) cur_ans++;
    q_ans[q[1].id] = cur_ans;
    FOR(i, 2, q_sz) {
        int L = q[i].l, R = q[i].r;
        if (q[i].l == q[i-1].r) L = q[i-1].r + 1;
        else cur_ans = cur_max = 0;
        FOR(j, L, R) if (maximize(cur_max, a[j])) cur_ans++;
        q_ans[q[i].id] = cur_ans;
    }

    FOR(i,1,q_sz) cout << q_ans[i] << endl;
    return 0;
}