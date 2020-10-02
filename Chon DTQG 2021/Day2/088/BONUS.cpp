#include <bits/stdc++.h>
#define int long long

using namespace std;

int s=0;
int n, r, k;
int a[1005][1005];
int x[100005], y[100005];
bool cx[1005][1005];
int da[1005][1005], dd[1005][1005], g[1005][1005];
int res=0;
void subt() {
    s=0;
    for (int i=1; i<=k; i++) {
        for (int u=x[i]; u<=min(x[i]+r-1, n); u++)
            for (int v=y[i]; v<=min(y[i]+r-1, n); v++)
                cx[u][v]=true;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (cx[i][j])
                s+=a[i][j];
        }
    }
    printf("%lld", s);
}
int32_t main() {
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    scanf("%lld%lld%lld", &n, &r, &k);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            scanf("%lld", &a[i][j]);
    for (int i=1; i<=k; i++) {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    if (n<=50 && k<=5) {
        subt();
        return 0;
    }
    for (int i=1; i<=k; i++) {
        int l=min(n+1, y[i]+r);
        dd[x[i]][y[i]]=(r-1);
        da[x[i]][l]=-(r-1);
        g[x[i]][y[i]]++;
        g[x[i]][l]--;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n+1; j++) {
            s+=g[i][j];
            if (s>0)
                res+=a[i][j];
            if (dd[i][j]!=0) {
                g[i+1][j]++;
                dd[i+1][j]=max(dd[i+1][j], dd[i][j]-1);
            }
            if (da[i][j]!=0) {
                g[i+1][j]--;
                da[i+1][j]=min(da[i+1][j], da[i][j]+1);
            }
        }
    }
    printf("%lld", res);
    return 0;
}
