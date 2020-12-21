#include <bits/stdc++.h>
using namespace std;
int n,m,k,res,dem,gt[5005],d[5005],c[5005],f[5005],l,r;
char x;
int main()
{
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    cin>>n>>m>>k;
    res=0;
    for (int i=1; i<=n; i++)
    {
        d[i]=0;
        c[i]=0;
    }
    dem=1;
    gt[dem]=0;
    f[0]=0;
    l=1;
    r=1;
    for (int i=1; i<=n; i++)
     {
        cin>>x;
        if (x=='1')
          {
              f[i]=f[i-1];
              c[f[i]]=i;
           }
        else
          if (x=='0')
           {
               ++dem;
                f[i]=f[i-1]+1;
               gt[dem]=f[i];
               c[f[i]]=i;
               d[f[i]]=i;
           }
     }
     res=0;
     l=1;
     r=1;
     for (int i=1; i<=dem; i++)
     {
         if (gt[i]-k>=0)
                     {
                         if (res>c[gt[i]]-d[gt[i]-k])
                         {
                             l=d[gt[i]-k];
                             r=c[gt[i]];
                         }
                     }
         if  (gt[i]-k<0)
                    {
                        res=max(res,c[gt[i]]);
                        r=c[gt[i]];
                    }
     }
     cout<<l<<" "<<r<<endl;
}
