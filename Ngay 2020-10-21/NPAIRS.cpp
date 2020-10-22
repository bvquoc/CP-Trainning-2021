#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

ll a, b, c, d, res;

signed main(void) {
    FastIO;
    freopen("NPAIRS.INP","r",stdin);
    freopen("NPAIRS.OUT","w",stdout);
    cin >> a >> b >> c >> d;
    res = abs(a*d - b*c) - __gcd(a,c) - __gcd(b,d) + 1;
    cout << res;
    return 0;
}