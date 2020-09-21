#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 100005, INF = LLONG_MAX;
int n; ii a[N];

signed main(void) {
    FastIO;
    freopen("CMAX.INP","r",stdin);
    freopen("CMAX.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> a[i].first >> a[i].second;
    int q, x, ans; 
    cin >> q;
    while (q--) {
        cin >> x;
        ans = -INF;
        FOR(i,1,n) {
            ans = max(ans,a[i].first*x + a[i].second);
        }
        cout << ans << endl;
    }
    return 0;
}