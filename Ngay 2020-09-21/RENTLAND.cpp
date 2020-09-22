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
int n; ii a[N];
int M[N][65];
vector < vector<int> > f;

void RMQ() {
    FOR(i,1,n) M[i][0] = a[i].second;
    for (int k=1; (1<<k)<=n; k++)
        for (int i=1; i+(1<<k)-1<=n; i++)
            M[i][k] = max(M[i][k-1], M[i+(1<<(k-1))][k-1]);
}
int getmax(int u, int v) {
    int k = log2(v-u+1);
    return max(M[u][k], M[v-(1<<k)+1][k]);
}

int dp(int l, int r) {
    if (f[l][r] != INF) return f[l][r];
    int cur = a[r].first*getmax(l,r);
    if (l == r) return a[l].first*a[l].second;
    FOR(j,l,r-1) {
        cur = min(cur,dp(l,j)+dp(j+1,r));
    }
    return f[l][r] = cur;
}

void init_DP() {
    f.assign(n+2,vector<int> (n+2,INF));
}

signed main(void) {
    FastIO;
    freopen("RENTLAND.INP","r",stdin);
    freopen("RENTLAND.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> a[i].first >> a[i].second;
    sort(a+1,a+1+n);
    RMQ();
    init_DP();
    cout << dp(1,n);
    return 0;
}