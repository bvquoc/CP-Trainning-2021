#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define endl '\n'
using namespace std;

using ii = pair <int,int>;
using ll = long long;
using ld = long double;

const int N = 100005;
int n, m, p, d[N], w[N];
int pw[N], pp[N], cur;
ii a[N];

signed main() {
    FastIO;
    freopen("TALENT.INP","r",stdin);
    freopen("TALENT.OUT","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i].first;
    for (int i=1; i<=n; i++) cin >> a[i].second;

    sort(a+1,a+1+n);
    for (int i=1; i<=n; i++) {
        d[i] = a[i].first; w[i] = a[i].second;
        pp[i] = pp[i-1] + w[i]*d[i];
        pw[i] = pw[i-1] + w[i];
    }
    while (m--) {
        cin >> p;
        int i = upper_bound(d+1,d+1+n,p) - d;
        cur = pw[i-1]*p - pp[i-1];
        if (i<=n) cur += (pp[n]-pp[i-1])-(pw[n]-pw[i-1])*p;
        cout << cur << endl;
    }
    return 0;
}
