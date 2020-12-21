#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a, b) for(int i = a; i >= b; i--)
#define ll long long
#define N 300005
#define x first
#define y second
#define ii pair <int, int>
#define iii pair <int, ii>
#define mode (int) 1000000007
#define inf (int) 2e9

using namespace std;

int n, m, Lmin = inf, Lmax = 100000, cnt = 0;
ii r[N];
int t[N], f[N], bit[N], d[N];

void update(int u, int val) {
    while(u > 0) {
        bit[u] = min(bit[u], val);
        u -= u & -u;
    }
}

int get(int u) {
    int ans = inf;
    while(u <= cnt) {
        ans = min(ans, bit[u]);
        u += u & -u;
    }
    return ans;
}

void sub1() {
    FOR(i, 1, n)
        f[i] = inf;
    FOR(i, 1, n)
        if(r[i].x <= Lmin && r[i].y >= Lmin)
            f[i] = 1;
    FOR(i, 1, n)
        FOR(j, 1, i - 1)
            if(r[j].x <= r[i].x && r[i].x <= r[j].y)
                f[i] = min(f[i], f[j] + 1);
    int ans = inf;
    FOR(i, 1, n)
        if(r[i].y == Lmax)
            ans = min(ans, f[i]);
    if(ans == inf) puts("-1");
    else printf("%d ", ans);
}

void sub2() {
    FOR(i, 1, n) {
        d[++cnt] = r[i].x;
        d[++cnt] = r[i].y;
    }
    d[++cnt] = Lmin;
    d[++cnt] = Lmax;
    sort(d + 1, d + cnt + 1);
    cnt = unique(d + 1, d + cnt + 1) - d - 1;
    Lmin = lower_bound(d + 1, d + cnt + 1, Lmin) - d;
    Lmax = lower_bound(d + 1, d + cnt + 1, Lmax) - d;
    FOR(i, 1, n) {
        r[i].x = lower_bound(d + 1, d + cnt + 1, r[i].x) - d;
        r[i].y = lower_bound(d + 1, d + cnt + 1, r[i].y) - d;
    }
    FOR(i, 1, cnt)
        bit[i] = inf;
    FOR(i, 1, n)
        f[i] = inf;
    FOR(i, 1, n) {
        if(r[i].x <= Lmin && r[i].y >= Lmin) {
            f[i] = 1;
            update(r[i].y, f[i]);
        }
    }
    FOR(i, 1, n) {
        f[i] = min(f[i], get(r[i].x) + 1);
        update(r[i].y, f[i]);
    }
    int ans = inf;
    FOR(i, 1, n)
        if(r[i].y == Lmax)
            ans = min(ans, f[i]);
    if(ans == inf) puts("-1");
    else printf("%d ", ans);
}

int main() {
    //freopen("main.inp", "r", stdin);
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);
    scanf("%d ", &n);
    FOR(i, 1, n)
        scanf("%d %d ", &r[i].x, &r[i].y);
    sort(r + 1, r + n + 1);
    scanf("%d ", &m);
    FOR(i, 1, m) {
        scanf("%d ", &t[i]);
        Lmin = min(Lmin, t[i]);
    }
    if(n <= 5000) sub1();
    else sub2();
}
