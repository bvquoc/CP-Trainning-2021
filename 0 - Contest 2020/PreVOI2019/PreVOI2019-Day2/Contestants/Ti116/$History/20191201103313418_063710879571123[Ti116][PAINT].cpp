#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<int, int> ii;
typedef pair<ii, ii> iv;

const int maxn = 1000005;

ii b[maxn];
iv a[maxn];

int n, m, k[maxn], d[maxn], t[maxn];

bool ok(int i, int j) {
    return (b[j].x >= a[i].x.x && b[j].x <= a[i].y.x
         && b[j].y >= a[i].x.y && b[j].y <= a[i].y.y);
}

void sub1() {
        for(int i = 1; i <= n; ++ i) {
            int res = 0;
            for(int j = 1; j <= m; ++ j) d[j] = 0;
            for(int j = 1; j <= m; ++ j)
                if(ok(i,j)) {
                    int u = lower_bound(t+1, t+m+1, k[j]) - t;
                    if(!d[u]) res ++; d[u] = 1;
                }
            printf("%d\n", res);
        }
}

void Solve() {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++ i)
            scanf("%d %d %d %d", &a[i].x.x, &a[i].x.y, &a[i].y.x, &a[i].y.y);
        for(int i = 1; i <= m; ++ i)
            scanf("%d %d %d", &b[i].x, &b[i].y, &k[i]),
            t[i] = k[i];

        sort(t+1, t+m+1);
        sub1();
}

#define task "PAINT"
int main() {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
        Solve();
}
