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

const int N = 50004, INF = LLONG_MAX;

int n, w[N], l[N];
int dp[N];

signed main(void) {
    FastIO;
    freopen("RENTLAND.INP","r",stdin);
    freopen("RENTLAND.OUT","w",stdout);
    cin >> n;
    { // Read Input
        ii a[N];
        FOR(i,1,n) {
            cin >> w[i] >> l[i];
            a[i] = {w[i],l[i]};
        }
        sort(a+1,a+1+n);
        FOR(i,1,n) {
            w[i] = a[i].first;
            l[i] = a[i].second;
        }

        bool d[N];
        int wmax = w[n];
        FORD(i,n-1,1) {
            if (w[i] <= wmax) d[i] = 1;
            else wmax = w[i];
        }
        int n1 = 0;
        FOR(i,1,n) {
            if (!d[i])
                l[++n1] = l[i], w[n1] = w[i];
        }
        n = n1;
    }
    FOR(i,1,n) cout << w[i] << ' ' << l[i] << endl;
    
    dp[0] = 0;
    FOR(i,1,n) {

        FOR(j,0,i-1) dp[i] = min(dp[i],dp[j]+w[j+1]*l[i]);
        cout << dp[i] << ' ';
    }
    cout << dp[n];
    
    return 0;
}