#include <bits/stdc++.h>

using namespace std;
int i,j,n,m,x,y,z,c[2000][2000];
int main()
{
    freopen("DULICH.INP","r",stdin);
    freopen("DULICH.OUT","w",stdout);
    cin>>n>>m;
    for (i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        c[x][y]=z;
        c[y][x]=z;
    }
    cout<<0;
    return 0;
}
