/**Yatogami**/
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FFOR(i, a, b) for(int i = a; i < b; i++)
#define DFOR(i, b, a) for(int i = b; i >= a; i--)
#define fi first
#define se second
#define mp make_pair
#define vi vector < int >
#define pb push_back
#define taskname "DHAKA"
#define MAXN 100004
#define oo 10000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
int n, m, k, l;
vi melon[MAXN];
vector < pair < int, ll > > adj[MAXN];
ll d[204][204], f[MAXN][40], d1[MAXN], dn[MAXN];
bool kt[14], kt1[10];
int x[14], bit[MAXN];
ll ans;
void input() {
    cin >> n >> m >> k >> l;
    FOR(i, 1, n) {
        int s;
        cin >> s;
        FOR(j, 1, s) {
            int val;
            cin >> val;
            melon[i].pb(val);
        }
    }
    FOR(i, 1, m) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
}

void djk1(int u) {
    FOR(i, 1, n) d[u][i] = oo;
    FOR(i, 1, u - 1) d[u][i] = d[i][u];
    d[u][u] = 0;
    priority_queue < pll, vector < pll >, greater < pll > > h;
    h.push({0, u});
    pll top;
    while(h.empty() == 0) {
        top = h.top();
        h.pop();
        if(top.fi > d[u][top.se]) continue;
        int cur = top.se;
        ll val = top.fi;
        for(auto p : adj[cur])
            if(val + p.se < d[u][p.fi]) {
                if(p.fi < u) continue;
                d[u][p.fi] = val + p.se;
                h.push({val + p.se, p.fi});
            }
    }
}

void getans(int N) {
    ll sp = 0;
    FOR(i, 1, k) kt1[i] = false;
    for(auto i : melon[1]) kt1[i] = true;
    FFOR(i, 1, N) {
        sp += d[x[i]][x[i + 1]];
        if(d[x[i]][x[i + 1]] == oo) return;
        for(auto j : melon[x[i + 1]])
            kt1[j] = true;
    }
    int cnt = 0;
    FOR(i, 1, k)
        cnt += (kt1[i] == true);
    if(cnt >= l) ans = min(ans, sp);
}

void shv(int i) {
    FOR(j, 2, n)
        if(kt[j] == true) {
            kt[j] = false;
            x[i] = j;
            if(j == n) getans(i);
            else shv(i + 1);
            kt[j] = true;
        }
}

void sub1() {
    if(n > 10) return;
    FOR(i, 1, n) djk1(i);
    FOR(i, 1, n) kt[i] = true;
    ans = oo;
    x[1] = 1;
    shv(2);
    if(ans == oo) ans = -1;
    cout << ans;
    exit(0);
}

void djk2() {
    FOR(i, 1, n) d1[i] = oo;
    d1[1] = 0;
    priority_queue < pll, vector < pll >, greater < pll > > h;
    h.push({0, 1});
    pll top;
    while(h.empty() == 0) {
        top = h.top();
        h.pop();
        if(top.fi > d1[top.se]) continue;
        int cur = top.se;
        ll val = top.fi;
        for(auto p : adj[cur])
            if(val + p.se < d1[p.fi]) {
                d1[p.fi] = val + p.se;
                h.push({val + p.se, p.fi});
            }
    }
}

void sub2() {
    int N = 0;
    FOR(i, 1, k) kt1[i] = false;
    for(auto i : melon[1]) kt1[i] = true;
    for(auto i : melon[n]) kt1[i] = true;
    FOR(i, 1, k) N += (kt1[i] == true);
    if(l > N) return;
    djk2();
    ans = d1[n];
    if(ans == oo) ans = -1;
    cout << ans;
    exit(0);
}

void djk3() {
    FOR(i, 1, n) dn[i] = oo;
    dn[n] = 0;
    priority_queue < pll, vector < pll >, greater < pll > > h;
    h.push({0, n});
    pll top;
    while(h.empty() == 0) {
        top = h.top();
        h.pop();
        if(top.fi > dn[top.se]) continue;
        int cur = top.se;
        ll val = top.fi;
        for(auto p : adj[cur])
            if(val + p.se < dn[p.fi]) {
                dn[p.fi] = val + p.se;
                h.push({val + p.se, p.fi});
            }
    }
}

void sub3() {
    if(k > 1) return;
    djk2(); djk3();
    ans = oo;
    FOR(i, 2, n - 1)
        if(melon[i].empty() == 0)
            ans = min(ans, d1[i] + dn[i]);
    if(ans == oo) ans = -1;
    cout << ans;
    exit(0);
}

struct state {
    int cur, val;
    ll sp;
};
struct cmph {
    bool operator() (state x, state y) {
        return x.sp > y.sp;
    }
};

int batbit(int x, int k) {
    return x | (1 << k);
}

void djk4() {
    int lm = (1 << k) - 1;
    FOR(i, 1, n) FOR(j, 0, lm) f[i][j] = oo;
    FOR(i, 1, n) {
        bit[i] = 0;
        for(auto j : melon[i])
            bit[i] = batbit(bit[i], j - 1);
    }
    int u = bit[1];
    f[1][u] = 0;
    priority_queue < state, vector < state >, cmph > h;
    h.push({1, u, 0});
    state top;
    while(h.empty() == 0) {
        top = h.top();
        h.pop();
        if(top.sp > f[top.cur][top.val]) continue;
        int cur = top.cur;
        int val = top.val;
        ll sp = top.sp;
        if(cur == n) return;
        for(auto p : adj[cur]) {
            u = val;
            for(auto i : melon[p.fi])
                u = batbit(u, i - 1);
            if(sp + p.se < f[p.fi][u]) {
                f[p.fi][u] = sp + p.se;
                h.push({p.fi, u, sp + p.se});
            }
        }
    }
}

void sub4() {
    int lm = (1 << k) - 1;
    djk4();
    ans = oo;
    FOR(i, 0, lm)
        if(__builtin_popcount(i) >= l)
            ans = min(ans, f[n][i]);
    if(ans == oo) ans = -1;
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    input();
    sub1();
    sub2();
    sub3();
    sub4();
    return 0;
}
