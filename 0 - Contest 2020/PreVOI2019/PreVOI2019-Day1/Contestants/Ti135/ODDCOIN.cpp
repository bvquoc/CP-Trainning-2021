///....DH....///
#include <bits/stdc++.h>
#define task                "ODDCOIN"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)

#define pii                 pair<int, int>
#define ft                  first
#define sd                  second
#define mp                  make_pair

#define pb                  push_back
#define pf                  push_front
#define popb                pop_back
#define popf                pop_front

#define reset(a, x)         memset(a, x, sizeof(a))
#define For(i, s, n, m)     for(int i = s; i <= n; i += m)
#define Ford(i, s, n, m)    for(int i = s; i >= n; i -= m)

using namespace std;

template <typename R, typename D> inline void Min(R &a, D b) {
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b) {
    if(a<b)
        a=b;
}

/** MOD **/                 const long long mod = 1e9 + 7;
/** size of array **/       const int maxn = 55;

int q, a[20] = {0, 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int F[3500005][20], maxt, n, x[maxn], v[maxn];

void preprocess() {
    for(int i = 1; i <= maxt; i++)
        for(int j = 1; j <= n; j++) {
            F[i][j] = INT_MAX;
            for(int k = 1; k <= j; k++) {
                if(i - a[j] >= 0)
                    Min(F[i][j], F[i - a[j]][k] + 1);
                Min(F[i][j], F[i][k]);
            }
            if(F[i][j] == INT_MAX)
                F[i][j] = 0;
        }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    n = 15;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        scanf("%d%d", &x[i], &v[i]);
        Max(maxt, v[i]);
    }
    preprocess();
    for(int i = 1; i <= q; i++) {
        int ans = F[v[i]][n], cnt = 1;
        while(v[i] >= x[i]) {
            Min(ans, F[v[i] - x[i]][n] + cnt);
            v[i] -= x[i];
            cnt++;
        }
        printf("%d\n", ans);
    }
}
