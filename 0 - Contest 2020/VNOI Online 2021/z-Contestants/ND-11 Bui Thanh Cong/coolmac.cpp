#include<bits/stdc++.h>
#define ii pair<long,long>
#define x first
#define y second
using namespace std;
const long o=1e5+5;
long m,n,l=o,r;
ii a[o];
int main()
{
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>m;
    for(long i=1;i<=m;i++)
        cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+m);

    cin>>n;
    for(long i=1;i<=n;i++)
    {
        long g; cin>>g;
        l=min(l,g);
    }

    r=100000;
    long i=1,mx=-1,sl=0;
    while(l<=r)
    {
        while(i<=m && a[i].x<=l)
        {
            mx=max(mx,a[i].y);
            i++;
        }
        if(mx<l)
        {
            cout<<-1;
            return 0;
        }
        l=mx+1; sl++;
    }
    cout<<sl;
    return 0;
}
