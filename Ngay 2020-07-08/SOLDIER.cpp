#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 100005;
int n, a[N], psum[N];

int32_t main(void) {
    FastIO;
    freopen("SOLDIER.INP","r",stdin);
    freopen("SOLDIER.OUT","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for (int i=1; i<=n; i++) {
        psum[i] = psum[i-1]+a[i];
    }
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        int p = lower_bound(a+1,a+1+n,x)-a;
        if (p>n) p=n;
        cout << p << ' ' << psum[p] << '\n';
    }
    return 0;
}