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

const signed N = 100005;
int n, k, a[N];
int res = 0;

signed main(void) {
    FastIO;
    freopen("SEQ.INP","r",stdin);
    freopen("SEQ.OUT","w",stdout);
    cin >> n >> k;
    FOR(i,1,n) cin >> a[i];
    sort(a+1,a+1+n);
    FOR(i,1,n-k) res += a[i];
    cout << res;
    return 0;
}