#include <bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,demm=0,b[100009],i,bien,j,dem,t,v,vt,c[100009];
struct Q
{
    long long l,r;
};
Q a[100009];
bool cmp(const Q x, const Q y)
{
    return (x.l<y.l || (x.l==y.l && x.r<y.r));
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    cin>>m;
    for (i=1;i<=m;i++)
        cin>>a[i].l>>a[i].r;
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>c[i];
    sort(c+1,c+1+n);
    sort(a+1,a+1+m,cmp);
    v=c[1];vt=1;
    while (v<100000)
    {
        t=INT_MIN;
        bien=0;
        for (j=vt;j<=m;j++)
        {
            if (a[j].l<=v && a[j].r>=v)
            {
                bien=1;
                t=max(t,a[j].r);
            }
            else
            {
                if (a[j].l>v)
                {
                    vt=j;
                    break;
                }
            }
        }
        if (vt==m)
            demm++;
        if (bien==0 || demm>=5)
        {
            cout<<-1;
            return 0;
        }
        v=t;
        dem++;
    }
    cout<<dem;
    return 0;
}
