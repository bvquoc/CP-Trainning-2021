#include<bits/stdc++.h>
using namespace std;
int lt(int x, int k)
{
    if(k==0) return 1;
    if(k==1) return x;
    int t=lt(x, k/2);
    if(k%2) return t*t*x;
    return t*t;
}
int a[20], Q, X, T;
const int oo=2e9;
int f[20][40005], g[20][40005], p[20];
int main ()
{
    freopen("ODDCOIN.inp", "r", stdin);
    freopen("ODDCOIN.out", "w", stdout);
    int sl=0;
    for(int i=0; i<=4; i++) {
        int t=lt(10, i);
        a[++sl]=1*t;
        a[++sl]=3*t;
        a[++sl]=5*t;
    }
    scanf("%d", &Q);
    while(Q--) {
        scanf("%d%d", &X, &T);
        a[++sl]=X;
        sort(a+1, a+sl+1);
        for(int i=1; i<=sl; i++) {
            p[i]=0;
            for(int j=1; j<=40000; j++) f[i][j]=oo, g[i][j]=0;
        }
        int u=lower_bound(a+1, a+sl+1, T)-a-1;
        p[u]=T/a[u];
        for(int i=1; i<=p[u]; i++) f[u][i]=i, g[u][i]=a[u]*i;
        for(int i=u-1; i>=1; i--) {
            if(T/a[i]<=40000) f[i][T/a[i]]=T/a[i], g[i][T/a[i]]=(T/a[i])*a[i], p[i]=T/a[i];
            for(int j=u; j>i; j--)
            for(int nhanj=1; nhanj<=p[j]; nhanj++) if(f[j][nhanj]<oo)
            for(int nhan=1; nhan<=(T-g[j][nhanj])/a[i]; nhan++) {
                if(f[i][nhan]>f[j][nhanj]+(T-g[j][nhanj])/a[i]) {
                    f[i][nhan]=f[j][nhanj]+nhan;
                    g[i][nhan]=nhan*a[i]+g[j][nhanj];
                    p[i]=max(p[i], (T-g[j][nhanj])/a[i]);
                }
            }
        }
        int ans=oo;
        for(int i=1; i<=u; i++)
        for(int j=1; j<=p[i]; j++) if(g[i][j]==T) {
            ans=min(ans, f[i][j]);
        }
        printf("%d\n", ans);
        int pos=0;
        for(int i=1; i<=sl; i++) if(a[i]==X) {pos=i; break;}
        for(int i=pos; i<sl; i++) a[i]=a[i+1];
        --sl;
    }
}
