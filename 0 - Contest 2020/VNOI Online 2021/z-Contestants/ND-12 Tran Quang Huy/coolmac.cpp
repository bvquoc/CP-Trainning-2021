#include <bits/stdc++.h>
#define N 100002
using namespace std;
struct pt { int l,r; };
pt a[N];
int n,m,l,r,i,vt,kq,mi,x;
bool cmp(pt a,pt b)
{
    return a.l<b.l;
}
int main()
{
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i].l>>a[i].r;
    cin>>m;
    mi=round(1e5);
    for(i=1;i<=m;i++)
    {
        cin>>x;
        mi=min(mi,x);
    }
    sort(a+1,a+n+1,cmp);
    vt=mi-1; kq=0;
    for(i=1;i<=n;i++)
    {
     //   cerr<<a[i].l<<'\n';
        if(a[i].l<=vt)
            r=max(r,a[i].r);
        else
        {
            if(a[i].l>r+1) { cout<<-1; return 0; }
            vt=r; r=a[i].r; kq++;
        }
    }
    if(r<round(1e5)) { cout<<-1; return 0; }
    cout<<kq;
}
