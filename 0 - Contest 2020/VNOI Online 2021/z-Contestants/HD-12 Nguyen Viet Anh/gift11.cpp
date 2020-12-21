#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a, b) for(int i = a; i >= b; i--)
#define ll long long
#define N 3005
#define x first
#define y second
#define ii pair <int, int>
#define iii pair <int, ii>
#define mode (int) 998244353
#define inf (ll) 2e18

using namespace std;

int n, ans = 0;
int a[N], p[N], sC[N], sL[N];
int gt[N];
int f[N][N][15];

int power(int a, int b) {
    if(b == 0) return 1;
    int t = power(a, b/2);
    t = (1ll * t * t) % mode;
    if(b & 1) t = (1ll * t * a) % mode;
    return t;
}

vector <int> get(int val) {
    vector <int> dg;
    if(val == 0)
        dg.push_back(val);
    while(val) {
        dg.push_back(val % 10);
        val /= 10;
    }
    reverse(dg.begin(), dg.end());
    return dg;
}

void prepare() {
    int M = N - 5;
    gt[0] = 1;
    FOR(i, 1, M)
        gt[i] = (1ll * gt[i - 1] * i) % mode;
}

bool okC() {
    FOR(i, 1, n) {
        vector <int> dg = get(a[i]);
        if(dg.size() & 1) return false;
    }
    return true;
}

bool okL() {
    FOR(i, 1, n) {
        vector <int> dg = get(a[i]);
        if(dg.size() % 2 == 0) return false;
    }
    return true;
}

void xuli() {
    int sum = 0;
    int id = 1;
    FOR(i, 1, n) {
        vector <int> dg = get(a[p[i]]);
        for(auto &v : dg) {
            id++;
            if(id & 1) sum = (sum + v) % 11;
            else sum = (sum - v + 11) % 11;
        }
    }
    if(sum % 11 == 0)
        ans = (ans + 1) % mode;
}

void sub1() {
    ans = 0;
    FOR(i, 1, n)
        p[i] = i;
    do {
        xuli();
    } while(next_permutation(p + 1, p + n + 1));
    printf("%d\n", ans);
}

void sub2() {
    int sum = 0, id = 0;
    FOR(i, 1, n) {
        vector <int> dg = get(a[i]);
        if(dg.size() & 1) return;
        for(auto &v : dg) {
            id++;
            if(id & 1) sum = (sum + v) % 11;
            else sum = (sum - v + 11) % 11;
        }
    }
    if(sum % 11 == 0)
        printf("%d\n", gt[n]);
    else printf("%d\n", 0);
}

void sub3() {
    int remain = (n + 1)/2;
    FOR(i, 1, n)
        FOR(j, 0, remain)
            FOR(k, 0, 10) f[i][j][k] = 0;
    f[0][0][0] = 1;
    FOR(i, 1, n)
        FOR(j, 0, remain)
            FOR(k, 0, 10) {
                int pre = (k - sL[i] + sC[i] + 11) % 11;
                f[i][j][k] = f[i - 1][j][pre];
                if(j > 0) {
                    pre = (k + sL[i] - sC[i] + 11) % 11;
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][pre]) % mode;
                }
            }
    int ans = f[n][remain][0];
    ans = (1ll * ans * gt[remain] * gt[remain]) % mode;
    if(n & 1)
        ans = (1ll * ans * power(remain, mode - 2)) % mode;
    printf("%d ", ans);
}

void solve() {
    scanf("%d ", &n);
    FOR(i, 1, n)
        scanf("%d ", &a[i]);
    FOR(i, 1, n) {
        vector <int> dg = get(a[i]);
        int id = 0;
        sL[i] = sC[i] = 0;
        for(auto &v : dg) {
            id++;
            if(id & 1)
                sL[i] = (sL[i] + v) % 11;
            else sC[i] = (sC[i] + v) % 11;
        }
    }
    if(n <= 8) sub1();
    else if(okC()) sub2();
    else sub3();
}

int main() {
    //freopen("main.inp", "r", stdin);
    freopen("gift11.inp", "r", stdin);
    freopen("gift11.out", "w", stdout);
    int t;
    scanf("%d ", &t);
    prepare();
    while(t--)
        solve();
}
