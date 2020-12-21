#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
ii s[100005];
int m,n,dem,c,d,mx,mn,kt;
int l[100005],r[100005],a[100005];
int main()
{
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    cin>>m;
    for (int i=1; i<=m; i++)
            {
                cin>>l[i]>>r[i];
                s[i].first=l[i];
                s[i].second=r[i];
            }
    sort(s+1,s+1+m);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+1+n);
    d=1;
    c=s[1].second;
    mn=a[1];
    int d1;
    for (int i=1; i<=m; i++)
    {
        if (s[i].second>=mn)
        {
            d1=d;
            c=s[i].second;
            break;
        }
    }
    if (c<mn) cout<<"-1";
    else
    {
        mx=0;
        dem=1;
        kt=0;
        for (int  i=d1+1; i<=m; i++)
           {
               if (s[i].first<=c && s[i].second >mx)
                  {
                     kt=1;
                     d=i;
                     mx=s[i].second;
                   }
               else
                 if  (s[i].first>c)
                  {
                         ++dem;
                         if (kt==0) break;
                         if (kt==1 && s[i].first<=mx)
                         {
                             ++dem;
                             c=s[d].second;
                             if (c>=100000) break;
                             mx=0;
                             kt=0;
                         }
                         else
                        if (s[i].first<mx)
                         {
                             kt=0;
                             break;
                         }
                   }
           }
        if (c!=mx)
        {
            ++dem;
            c=mx;
            if (mx<100000)
                {
                       kt=0;
                }
        }
        if (kt==1 && c>=100000)
        {
            cout<<dem<<endl;
        }
         else cout<<"-1";
    }
}
