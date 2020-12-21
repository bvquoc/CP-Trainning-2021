#include <bits/stdc++.h>

using namespace std;
int n,m,l=1e5;
struct po
{
    int x,y;
}a[100001],f[100001];
bool SS(po a,po b)
{
    if (a.y>b.y)return 1;
    if (a.y<b.y)return 0;
    return (a.x<b.x);
}
int main()
{
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    cin>>m;
    for (int i=1;i<=m;i++)
        cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+m,SS);
    cin>>n;
    int k;
    for (int i=1;i<=n;i++)
    {
        cin>>k;
        l=min(l,k);
    }
    if (a[1].y<1e5)cout<<-1;
    else
    {
        int d=1;
        int t=1;
        bool kt=true;
        for (int i=2;kt&&a[t].x>l&&i<=m;i++)
            if (a[t].x>a[i].x)
            {
                    d++;
                    if (a[t].x>a[i].y+1)kt=false;
                    t=i;
                    
            }
        if (a[t].x>l||kt==false)cout<<-1;
        else
            cout<<d;
    }
    return 0;
}
