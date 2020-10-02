#include <bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=1e5+5;
int n,m,res,s1[nmax],s2[nmax];
struct pack {int d,w;}a[nmax];

bool cmp(pack &A, pack &B) {return A.d<B.d;}

void init() {
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;++i) {
        s1[i]=s1[i-1]+(a[i].w)*(a[i].d);
        s2[i]=s2[i-1]+a[i].w;
    }
}

void solve() {
    for(int i=1;i<=m;++i) {
        int p;
        scanf("%lld", &p);
        int l=1,r=n;
        while(l<=r) {
            int mid=(l+r)/2;
            if(a[mid].d>p)    r=mid-1;
            else l=mid+1;
        }
        --l;
        res=-s1[l]+s2[l]*p;
        res+=((s1[n]-s1[l])-(s2[n]-s2[l])*p);
        printf("%lld\n", res);
    }
}

int32_t main() {
    freopen("TALENT.INP","r",stdin);
    freopen("TALENT.OUT","w",stdout);
    scanf("%lld%lld", &n, &m);
    for(int i=1;i<=n;++i)   scanf("%lld", &a[i].d);
    for(int i=1;i<=n;++i)   scanf("%lld", &a[i].w);
    init();
    solve();
    return 0;
}
