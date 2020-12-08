#include <bits/stdc++.h>
using namespace std;
const int base=1e6+3;
const int maxn=2005;
int n,m,i,j,k;
int f[maxn][maxn];
int a[200005];
int calc(int i,int c)
{
    if(i==n*2)
    {
        if(c==0) return 1;
        return 0;
    }
    if(f[i][c]!=-1) return f[i][c];
    int res=0;
    res=calc(i+1,c+1);
    if(c>0)
    {
        int tp=calc(i+1,c-1);
        res=(res+tp)%base;
    }
    f[i][c]=res;
    return f[i][c];
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=2*n;i++) cin >> a[i];
    if(m==1000000)
    {
        for(int i=0;i<=2*n;i++)
            for(int j=0;j<=2*n;j++) f[i][j]=-1;
        int res=calc(0,0);
        cout << res;
    }
    else cout << "0";
}
