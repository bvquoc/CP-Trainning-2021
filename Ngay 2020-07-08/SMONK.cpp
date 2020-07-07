#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 100005;
int n, a[N];

int32_t main(void) {
    FastIO;
    freopen("SMONK.INP","r",stdin);
    freopen("SMONK.OUT","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int q; cin >> q;
    while (q--)
    {
        int k, x;
        cin >> k >> x;
        if (k == 0) {
            int p = lower_bound(a+1,a+1+n,x)-a;
            if (p>n) p = 0;
            else {
                p = n-p+1;
            }
            cout << p << '\n';
        } else {
            int p = upper_bound(a+1,a+1+n,x)-a;
            if (p>n) p = 0;
            else {
                p = n-p+1;
            }
            cout << p << '\n';
        }
    }
    
    return 0;
}