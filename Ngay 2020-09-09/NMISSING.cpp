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
using ld = long double;

const int N = 100005;
int n, a[N];
int res;

signed main(void) {
    FastIO;
    freopen("NMISSING.INP","r",stdin);
    freopen("NMISSING.OUT","w",stdout);
    signed T; cin >> T;
    while (T--) {
        cin >> n;
        FOR(i,1,n) cin >> a[i];
        sort(a+1,a+1+n);
        res = 2;
        FOR(i,1,n) {
            if (res <= a[i]) res += 2;
        }
        cout << res << endl;
    }
    return 0;
}