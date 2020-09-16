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

int n, m;

signed main(void) {
    FastIO;
    freopen("PARKING.INP","r",stdin);
    freopen("PARKING.OUT","w",stdout);
    cin >> n >> m;
    int k = n/2 + n%2, h = m/2 + m%2;
    int res = k*h;
    cout << res;
    return 0;
}