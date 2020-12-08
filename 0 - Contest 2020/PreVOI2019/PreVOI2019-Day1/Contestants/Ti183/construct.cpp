#include <bits/stdc++.h>

using namespace std;
long long a[1000005],kq,l,r,k,tt,n,m,T;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    cin>>T;
    while (T--)
    {
       cin>>n>>m;
       for (int i=1;i<=n;++i) cin>>a[i];
       for (int ev=1;ev<=m;++ev)
       {
           cin>>tt;
           if (tt==1)
           {
               cin>>l>>r>>k;
               for (int i=l;i<=r;++i) a[i]+=k;
           }
           else
           {
               cin>>l>>r;

               kq=a[l];
               for (int i=l+1;i<=r;++i)
               {
                   if (a[i]<=a[i-1]) continue;
                   kq+=a[i]-a[i-1];
               }
               cout<<kq<<'\n';

           }
       }

    }
    return 0;
}
