#include <bits/stdc++.h>

using namespace std;
int n,m,x,y,a[100005],mins=1e9,dem=0;
int main()
{
    ios::sync_with_stdio(0);
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x>>y;
        for (int j=x;j<=y;j++)
            a[j]=i;
    }
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>x;
        mins=min(x,mins);
    }
    sort(a+mins,a+1+100000);
    for (int i=mins;i<=1e5;i++)
    {
        if (a[i]==0) {cout<<"-1";return 0;}
        if (a[i]!=a[i-1]) dem++;
    }
    cout<<dem;
    return 0;
}
