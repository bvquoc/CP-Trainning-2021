#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define val first
#define id second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 100005;
int n, m, a[N];
ii b[N];
int res = LLONG_MAX;
int p1, p2;

signed main(void) {
    FastIO;
    freopen("ASUMMIN.INP","r",stdin);
    freopen("ASUMMIN.OUT","w",stdout);
    cin >> n >> m;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,m) {
        cin >> b[i].first;
        b[i].second = i;
    }
    
    sort(b+1,b+1+m);
    a[0] = b[0].first = 9000000000000000;
    a[n+1] = b[n+1].first = 9000000000000000;
    FOR(i,1,n) {
        int i1 = lower_bound(b+1,b+1+m,ii(a[i],0))-b;
        int i2 = lower_bound(b+1,b+1+m,ii(-a[i],0))-b;

        if (res > abs(a[i]+b[i1].first)) {
            res = abs(a[i]+b[i1].first);
            p1 = i;
            p2 = b[i1].second;
        }
        if (res > abs(a[i]+b[i2].first)) {
            res = abs(a[i]+b[i2].first);
            p1 = i;
            p2 = b[i2].second;
        }
    }
    cout << p1 << ' ' << p2;
    return 0;
}