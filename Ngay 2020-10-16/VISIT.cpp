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
using ll = long long;
using ld = long double;

const int N = 200005;
int n, x[N], y[N];
int l[N], r[N];

signed main() {
    FastIO;
    freopen("VISIT.INP","r",stdin);
    freopen("VISIT.OUT","w",stdout);
    cin >> n;
    l[0] = r[0] = 1;
    FOR(i,1,n) {
        cin >> l[i] >> r[i];
        y[i] = x[i-1] + (r[i]-l[i]) + abs(l[i-1]-l[i]);
        y[i] = min(y[i], y[i-1] + (r[i]-l[i]) + abs(r[i-1]-l[i]));
        x[i] = x[i-1] + r[i] - l[i] + abs(l[i-1]-r[i]);
        x[i] = min(x[i], y[i-1] + r[i] - l[i] + abs(r[i-1]-r[i]));
    }

    int res= min(n-r[n]+y[n]+n-1, n-l[n]+x[n]+n-1);
    cout << res;
    return 0;
}