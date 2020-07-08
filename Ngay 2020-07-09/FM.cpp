#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 100005, M = 2000006;
int n, m, a[N], p[M];
int res = 0;

int32_t main(void) {
    FastIO;
    freopen("FM.INP","r",stdin);
    freopen("FM.OUT","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    
    if (n<=1000) {
        for (int i=1; i<n; i++) {
            for (int j=i+1; j<=n; j++) {
                p[a[i]+a[j]]++;
            }
        }
        for (int i=1; i<=m; i++) {
            res += p[i];
        }
    } else {
        sort(a+1,a+1+n);
        for (int i=1;i<=n;i++) {
            int x = m-a[i];
            int p = upper_bound(a+1,a+1+n,x)-a-i-1;
            res += max(0,p);
        }
    }
    cout << res;
    return 0;
}