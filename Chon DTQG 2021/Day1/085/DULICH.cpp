#include <bits/stdc++.h>
using namespace std;

int n,m,a[1000][1000],b[1000],i,j,u,v,c,d[1000],Min,dem;
bool kt[1000],L[1000];

void DD(int x)
{
    for(int y=1;y<=n;y++)
        if(kt[y]&&a[y][x]!=1000000000)
            {
                kt[y]=false;
                DD(y);
            }
}

bool LT(int k)
{
    for(j=1;j<=n;j++)
        if(a[j][k]!=1000000000)
    {
        memset(kt,true,n+1);
        int t=a[j][k];
        a[j][k]=1000000000;
        a[k][j]=1000000000;
        DD(j);
        a[j][k]=t;
        a[k][j]=t;
        if(kt[k]==false) return true;
    }
    return false;
}

int main()
{
    freopen("DULICH.INP","r",stdin);
    freopen("DULICH.OUT","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        a[i][j]=1000000000;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>c;
        if(a[u][v]>c)
        {
            a[u][v]=c;
            a[v][u]=c;
        }
    }
    for(i=1;i<=n;i++)
        {
            L[i]=LT(i);
            if(L[i])
                dem++;
        }
        if(dem==0)
            cout<<"0";
            else cout<<"1";
    return 0;
}
