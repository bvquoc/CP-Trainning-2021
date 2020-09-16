#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

const int N = 100005;
int n, x[N], k, res = 0;

signed main(void) {
    FastIO;
    freopen("GATHER.INP","r",stdin);
    freopen("GATHER.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) 
    cin >> x[i];

    sort(1+x, 1+x+n);
    k = x[(n/2)+(n%2)];
    FOR(i,1,n) res += abs(k-x[i]);
    cout << res;
    return 0;
}