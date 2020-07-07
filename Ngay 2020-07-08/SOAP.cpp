#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 100005;
int n, a[N];

int32_t main(void) {
    FastIO;
    freopen("SOAP.INP","r",stdin);
    freopen("SOAP.OUT","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        int p = lower_bound(a+1,a+1+n,x)-a;
        cout << p-1 << '\n';
    }
    
    return 0;
}