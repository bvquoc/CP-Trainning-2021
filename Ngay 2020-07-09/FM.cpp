#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

const int N = 2000006;
int n, m, a[N];
int res = 0;

int32_t main(void) {
    FastIO;
    freopen("FM.INP","r",stdin);
    freopen("FM.OUT","w",stdout);
    scanf("%lld%lld", &n, &m);
    for (int i=1; i<=n; i++) {
        scanf("%lld",&a[i]);
    }
    
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) {
        int p = upper_bound(a+1+i,a+1+n,m-a[i])-a-i-1;
        if (p<=0) break;
        res += p;
    }
    printf("%lld",res);
    return 0;
}