#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k;
int a[100005];
int s=0;
int32_t main() {
    freopen("TEAM.INP","r",stdin);
    freopen("TEAM.OUT","w",stdout);
    scanf("%lld%lld", &n, &k);
    for (int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
        s+=a[i];
    }
    if (s==0) {
        printf("%lld", k);
        return 0;
    }
    k=k%s;
    int i=1;
    while (k>=a[i]) {
        k-=a[i];
        i++;
    }
    printf("%lld", k);
    return 0;
}
