#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 100005;
int n, a[N], psum[N];

int32_t main(void) {
    FastIO;
    freopen("SQUARE.INP","r",stdin);
    freopen("SQUARE.OUT","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        psum[i] = psum[i-1]+a[i];
    }
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        int p = lower_bound(psum+1,psum+1+n,x)-psum;
        if (p>n) p = -1;
        cout << p << endl;
    }
    return 0;
}