#include <bits/stdc++.h>

using namespace std;
const int nmax=1e5+5;
int n,a[nmax],b[nmax],res=0;

int32_t main() {
    freopen("IQ.INP","r",stdin);
    freopen("IQ.OUT","w",stdout);
    scanf("%d", &n);
    for(int i=1;i<=n;++i)   scanf("%d", &a[i]);
    for(int i=1;i<=n;++i)   scanf("%d", &b[i]);
    sort(a+1,a+1+n,greater<int>());
    sort(b+1,b+1+n,greater<int>());
    int j=1;
    for(int i=1;i<=n;++i) {
        int l=j,r=n;
        while(l<=r) {
            int mid=(l+r)/2;
            if(b[i]>a[mid]) r=mid-1;
            else l=mid+1;
        }
        while(a[l]>=b[i])   ++l;
        if(l>n) break;
        j=l+1;
        ++res;
    }
    printf("%d", res);
    return 0;
}
