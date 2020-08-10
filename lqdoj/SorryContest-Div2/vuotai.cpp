// http://lqdoj.edu.vn/problem/vuotai
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
int n, k, a[N];
int res = 1;

signed main(void) {
    FastIO;
    cin >> n >> k;
    FOR(i,1,n) {
        cin >> a[i];
        res += a[i];
    }

    sort(a+1,a+1+n);
    int i1 = upper_bound(a+1,a+1+n,k)-a;
    int i2 = lower_bound(a+1,a+1+n,k)-a;
    int r1 = INF, r2 = INF;
    if (i1<=n) r1 = res - a[i1] + max(0LL,a[i1]-k); 
    if (i2<=n) r2 = res - a[i2] + max(0LL,a[i2]-k);
    if (i1<=n && i2<=n) res = min(r1,r2);
    else res -= a[n];
    cout << res;
    return 0;
}