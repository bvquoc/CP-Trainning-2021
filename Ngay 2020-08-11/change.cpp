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

const int N = 5003, INF = INT_MAX;
int n, a[N], b[N];
int f[N][N];

void init_dp() {
    sort(b+1,b+1+n);
    FOR(i,1,n) FOR(j,1,n) f[i][j] = INF;
    f[1][1] = abs(a[1]-b[1]);
    FOR(j,2,n) f[1][j] = min(abs(a[1]-b[j]),f[1][j-1]);
    FOR(i,2,n) f[i][1] = abs(a[i]-b[1]) + f[i-1][1];
}
int dp(int i, int j) {
    if (f[i][j]!=INF) return f[i][j];
    int cur = min(dp(i,j-1),dp(i-1,j)+abs(a[i]-b[j]));
    f[i][j] = cur;
    return cur;
}

signed main(void) {
    FastIO;
    freopen("change.inp","r",stdin);
    freopen("change.out","w",stdout);
    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
        b[i] = a[i];
    }
    
    init_dp();
    cout << dp(n,n);
    return 0;
}