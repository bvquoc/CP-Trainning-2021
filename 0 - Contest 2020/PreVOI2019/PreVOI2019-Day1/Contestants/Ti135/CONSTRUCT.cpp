///....DH....///
#include <bits/stdc++.h>
#define task                "CONSTRUCT"
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
/** size of array **/       const int maxn = 200005;

int q, n, m, id, l, r;
long long a[maxn], s[maxn], k;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    scanf("%d", &q);
    while(q--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            s[i] = s[i - 1] + max(a[i] - a[i - 1], 0ll);
        }
        for(int i = 1; i <= m; i++) {
            scanf("%d", &id);
            if(id == 2) {
                scanf("%d%d", &l, &r);
                printf("%lld\n", s[r] - s[l] + a[l]);
            }
            else {
                scanf("%d%d%lld", &l, &r, &k);
                for(int j = l; j <= r; j++) {
                    a[j] += k;
                    s[j] = s[j - 1] + max(a[j] - a[j - 1], 0ll);
                }
                s[r + 1] = s[r] + max(a[r + 1] - a[r], 0ll);
            }
        }
    }
}
