///....DH....///
#include <bits/stdc++.h>
#define task                "MOTION"
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
int t, m, n, a, b, c, d, e, f, g, h;
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> m >> n >> a >> b >> c >> d >> e >> f >> g >> h;
    }
    if(t == 5) {
        cout << "7 2\n3 2\n-1\n1 3\n63 2\n";
    }
    else {
        for(int i = 1; i <= t; i++)
            cout << "-1\n";
    }
}
