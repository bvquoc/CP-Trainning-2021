#include <bits/stdc++.h>
#define maxn 10005
#define maxk 105

using namespace std;

int n, k, a[maxn];
int f[maxn][maxk];
int x[maxn];

int main() {
    freopen("kmult.inp","r",stdin);
    freopen("kmult.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%d",a+i);
        a[i]=(a[i] % k+k) %k;
    }
    memset(f,0,sizeof(f));
    f[1][a[1]]=1;
    for(int i=2;i<=n;i++) for(int j=0;j<k;j++)
    if (f[i-1][j]!=0) {
        f[i][(j+a[i])%k]=1;
        f[i][((j-a[i])%k+k)%k]=-1;
    }
    if (f[n][0]==0) printf("0"); else {
        printf("1\n");
        int j=0;
        for(int i=n;i>=2;i--) {
            x[i]=f[i][j];
            if (f[i][j]==1) j=((j-a[i])%k+k)%k;
            else j=(j+a[i])%k;
        }
        for(int i=2;i<=n;i++)
            if (x[i]==1) printf("+"); else printf("-");
    }
}
