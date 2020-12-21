#include <bits/stdc++.h>
using namespace std;
int n,q,dem,m;
int dd[500005],a[500005],b[500005];
int main()
{
    freopen("SOCKS.inp","r",stdin);
    freopen("SOCKS.out","w",stdout);
    cin>>n>>q;
    for (int i=1; i<=n; i++) dd[i]=0;
    dem=0;
    for (int i=1; i<=n; i++)
         {
           cin>>dd[i];
           if (dd[i]==1) ++dem;
         }
     if (dem>=2) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    for (int i=1; i<=n-1; i++) cin>>a[i]>>b[i];
    for (int i=1; i<=q; i++)
    {
        cin>>m;
        if (dd[m]==0)++dem;
        ++dd[m];
        if (dem>=2) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }

}
