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
int n, a[N], res = 0;

signed main(void) {
    FastIO;
    freopen("NUMQUIZ.INP","r",stdin);
    freopen("NUMQUIZ.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
        res = __gcd(res, a[i]);
    }
    res *= n;
    cout << res;
    return 0;
}