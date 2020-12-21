#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a, b) for(int i = a; i >= b; i--)
#define ll long long
#define N 500005
#define x first
#define y second
#define ii pair <int, int>
#define iii pair <ll, ii>
#define mode (int) 1000000007
#define inf (ll) 2e18

using namespace std;

int n, m, x[N], ok = 0;
char s[N];
ll a[N], LCM[N], GCD[N];
vector <iii> q, p;

ll lcm(ll a, ll b) {
    return 1ll * a * b / __gcd(a, b);
}

void xuli() {
    if(q.size()) {
        for(auto &i : q) {
            int u = i.y.x, v = i.y.y;
            ll w = i.x;
            if(__gcd(x[u], x[v]) != w)
                return;
        }
    }
    if(p.size()) {
        for(auto &i : p) {
            int u = i.y.x, v = i.y.y;
            ll w = i.x;
            if(lcm(x[u], x[v]) != w)
                return;
        }
    }
    ok = 1;
}

void thu(int k) {
    if(k > n) {
        xuli();
        return;
    }
    FOR(i, 1, 100) {
        x[k] = i;
        thu(k + 1);
    }
}

void sub1() {
    ok = 0;
    thu(1);
    if(ok)
        putchar('Y');
    else
        putchar('N');
}

void sub2() {
    for(auto &i : q) {
        int u = i.y.x, v = i.y.y;
        ll w = i.x;
        if(__gcd(a[u], a[v]) != w) {
            putchar('N');
            return;
        }
    }
    putchar('Y');
}

void sub3() {
    FOR(i, 2, n - 1) {
        if(LCM[i] % GCD[i - 1]) {
            putchar('N');
            return;
        }
        if(LCM[i] < GCD[i - 1]) {
            putchar('N');
            return;
        }
        if(LCM[i - 1] < GCD[i]) {
            putchar('N');
            return;
        }
    }
    putchar('Y');
}

int main() {
    //freopen("main.inp", "r", stdin);
    freopen("gcdlcm.inp", "r", stdin);
    freopen("gcdlcm.out", "w", stdout);
    int task, t;
    scanf("%d %d ", &task, &t);
    while(t--) {
        scanf("%d %d ", &n, &m);
        FOR(i, 1, n)
            a[i] = 1;
        FOR(i, 1, n)
            LCM[i] = GCD[i] = 1;
        q.clear(), p.clear();
        FOR(i, 1, m) {
            scanf("%s ", s + 1);
            if(s[1] == 'G') {
                int u, v;
                ll w;
                scanf("%d %d %lld ", &u, &v, &w);
                q.push_back(iii(w, ii(u, v)));
                a[u] = lcm(a[u], w);
                a[v] = lcm(a[v], w);
                GCD[u] = w;
                LCM[u] = lcm(LCM[u], w);
            } else {
                int u, v;
                ll w;
                scanf("%d %d %lld ", &u, &v, &w);
                p.push_back(iii(w, ii(u, v)));
                LCM[u] = lcm(LCM[u], w);
            }
        }
        if(n <= 3) sub1();
        else if(p.size() == 0) sub2();
        else sub3();
    }
}
