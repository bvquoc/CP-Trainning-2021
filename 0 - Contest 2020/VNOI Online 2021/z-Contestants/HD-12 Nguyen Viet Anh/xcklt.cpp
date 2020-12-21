#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a, b) for(int i = a; i >= b; i--)
#define ll long long
#define N 505
#define x first
#define y second
#define ii pair <int, int>
#define iii pair <int, ii>
#define mode (int) 1000000007
#define inf (ll) 2e18

using namespace std;

char a[N], b[N], c[N], ans[N];
int m, n, k, cnt = 0;
int ab[N][N], ac[N][N], bc[N][N];
int f[5005][N];


void err() {
    puts("TRETRAU");
    exit(0);
}

bool ok() {
    FOR(i, 1, cnt)
        FOR(j, 1, k)
            f[i][j] = 0;
    FOR(i, 1, cnt)
        FOR(j, 1, k) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if(ans[i] == c[j])
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    if(f[cnt][k] == k)
        return false;
    return true;
}

void sub1() {
    if(m != 1 || n != 1 || k != 1)
        return;
    if(a[1] == c[1] || b[1] == c[1])
        err();
    if(a[1] == b[1]) {
        printf("%c", a[1]);
        return;
    }
    printf("%c%c", a[1], b[1]);
    exit(0);
}

void sub2() {
    FOR(i, 1, k)
        if(c[i] != c[1])
            return;
    int need = k, now = 0;
    FOR(i, 1, m)
        if(a[i] == c[1])
            now++;
    FOR(i, 1, n)
        if(b[i] == c[1])
            now++;
    if(now >= need)
        err();
    int u = m, v = n;
    while(u > 0 || v > 0) {
        if(u > 0 && v > 0 && a[u] == b[v] && ab[u][v] == ab[u - 1][v - 1] + 1) {
            ans[++cnt] = a[u];
            u--, v--;
            continue;
        }
        if(u > 0 && ab[u][v] == ab[u - 1][v]) {
            ans[++cnt] = a[u];
            u--;
            continue;
        }
        if(v > 0 && ab[u][v] == ab[u][v - 1]) {
            ans[++cnt] = b[v];
            v--;
            continue;
        }
    }
    printf("%d\n", cnt);
    REP(i, cnt, 1)
        printf("%c", ans[i]);
    exit(0);
}

void sub3() {
    int u = m, v = n;
    while(u > 0 || v > 0) {
        if(u > 0 && v > 0 && a[u] == b[v] && ab[u][v] == ab[u - 1][v - 1] + 1) {
            ans[++cnt] = a[u];
            u--, v--;
            continue;
        }
        if(u > 0 && ab[u][v] == ab[u - 1][v]) {
            ans[++cnt] = a[u];
            u--;
            continue;
        }
        if(v > 0 && ab[u][v] == ab[u][v - 1]) {
            ans[++cnt] = b[v];
            v--;
            continue;
        }
    }
    reverse(ans + 1, ans + cnt + 1);
    if(ok()) {
        printf("%d\n", cnt);
        FOR(i, 1, cnt)
            printf("%c", ans[i]);
    } else err();
    exit(0);
}

int main() {
    //freopen("main.inp", "r", stdin);
    freopen("xcklt.inp", "r", stdin);
    freopen("xcklt.out", "w", stdot);
    scanf("%s ", a + 1);
    scanf("%s ", b + 1);
    scanf("%s ", c + 1);
    m = strlen(a + 1);
    n = strlen(b + 1);
    k = strlen(c + 1);
    FOR(i, 1, m)
        FOR(j, 1, n) {
            ab[i][j] = max(ab[i - 1][j], ab[i][j - 1]);
            if(a[i] == b[j])
                ab[i][j] = max(ab[i][j], ab[i - 1][j - 1] + 1);
        }
    FOR(i, 1, n)
        FOR(j, 1, k) {
            bc[i][j] = max(bc[i - 1][j], bc[i][j - 1]);
            if(b[i] == c[j])
                bc[i][j] = max(bc[i][j], bc[i - 1][j - 1] + 1);
        }
    FOR(i, 1, m)
        FOR(j, 1, k) {
            ac[i][j] = max(ac[i - 1][j], ac[i][j - 1]);
            if(a[i] == c[j])
                ac[i][j] = max(ac[i][j], ac[i - 1][j - 1] + 1);
        }
    if(ac[m][k] == k) err();
    if(bc[n][k] == k) err();
    sub1();
    sub2();
    sub3();
}
