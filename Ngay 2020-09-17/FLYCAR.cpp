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

const int N = 402, INF = LLONG_MAX;

int n, k, h[N];
int psum[N], f[N][N], M[N][N];

int s(int l, int r) {
    if (l>r) return INF;
    return psum[r]-psum[l-1];
}
void init_dp() {
    FOR(i,0,N-1) FOR(j,0,N-1) f[i][j] = INF;
    FOR(i,0,k) f[0][i] = 0;
    
    int cur_max = -INF, cur_sum = 0;
    FOR(i,0,n) {
        cur_max = max(h[i],cur_max);
        cur_sum += h[i];
        f[i][0] = i*cur_max - cur_sum;
    }

    // RMQ
    FOR(i,1,n) M[i][0] = h[i];
    for (int k=1; (1<<k)<=n; k++)
        for (int i=1; i+(1<<k)-1<=n; i++)
            M[i][k] = max(M[i][k-1], M[i+(1<<(k-1))][k-1]);
}

int Max(int u, int v) {
    int k = log2(v-u+1);
    return max(M[u][k], M[v-(1<<k)+1][k]);
}

int dp(int n, int k) {
    if (f[n][k] != INF) return f[n][k];
    int cur = INF;
    FOR(j,0,n-1) {
        cur = min(cur, dp(j,k-1) + (n-j)*Max(j+1,n) - s(j+1,n));
    }
    return f[n][k] = cur;
}

signed main(void) {
    FastIO;
    freopen("FLYCAR.INP","r",stdin);
    freopen("FLYCAR.OUT","w",stdout);
    cin >> n >> k;
    FOR(i,1,n) {
        cin >> h[i];
        psum[i] = psum[i-1]+h[i];
    }
    
    init_dp();
    cout << dp(n,k);
    return 0;
}