#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const signed N = 1000006;
int m, n, a[N], b[N];

signed main(void) {
    FastIO;
    freopen("PNIGHT.INP","r",stdin);
    freopen("PNIGHT.OUT","w",stdout);
    int T; cin >> T;
    while (T--) {
        cin >> m >> n;
        FOR(i,1,m) cin >> a[i];
        FOR(i,1,n) cin >> b[i];
        if (m>n) {
            cout << "No\n";
            continue;
        }

        sort(a+1,a+1+m);
        sort(b+1,b+1+n);
        int cnt = 0;
        FOR(i,1,m) {
            if (cnt >= n) break;
            if (a[i]<=b[cnt+1]) break;
            cnt++;
        }
        if (cnt == m) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}