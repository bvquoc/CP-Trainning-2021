#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ll = long long;

const int N = 100005;
int n, a[N];

signed main(void) {
    FastIO;
    freopen("TICHNN.INP","r",stdin);
    freopen("TICHNN.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> a[i];

    sort(a+1,a+1+n);
    long long res = a[1]*a[2]*a[3];
    res = min(res, (ll)a[1]*a[n-1]*a[n]);
    res = min(res, (ll)a[n-2]*a[n-1]*a[n]);

    cout << res;
    return 0;
}