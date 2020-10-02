#include <bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=1e5+5;
int n,k,a[nmax],s=0;
int32_t main() {
    freopen("TEAM.INP","r",stdin);
    freopen("TEAM.OUT","w",stdout);
    scanf("%lld%lld", &n, &k);
    for(int i=1;i<=n;++i) {
        scanf("%lld", &a[i]);
        s+=a[i];
    }
    int x=k/s;
    k-=(s*x);
    for(int i=1;i<=n;++i) {
        if(k<a[i])  break;
        k-=a[i];
    }
    printf("%lld", k);
    return 0;
}
