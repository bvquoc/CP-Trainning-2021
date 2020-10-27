#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define SUM(l,r) psum[r]-psum[l-1]
#define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

const int N = 1000006, INF = LLONG_MAX;
int n, k, a[N], psum[N];
int L[N], R[N], res = INF;

signed main(void) {
    FastIO;
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    cin >> n >> k;
    FOR(i,1,n) {
        cin >> a[i];
        psum[i] = psum[i-1]+a[i];
    }
    FORD(i,n-k+1,1) R[i] = max(R[i+1], SUM(i,i+k-1));
    FOR(i,k+1,n-k+1) L[i] = max(L[i-1], SUM(i-k,i-1));
    
    FOR(i,1,n-k+1) {
        int l = L[i], r = R[i+k], cur = SUM(i,i+k-1);
        if (cur >= max(l,r)) res = min(res, max(l,r));
    }

    cout << res;
    return 0;
}