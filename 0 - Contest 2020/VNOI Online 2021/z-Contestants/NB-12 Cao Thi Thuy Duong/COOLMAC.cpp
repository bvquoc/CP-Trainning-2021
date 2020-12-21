#include <bits/stdc++.h>
#define N 100005
#define ft first
#define sc second
using namespace std;
typedef pair<int,int> ii;
ii s[N];
int m,n,dem,c,d,x,k,kt;
int l[N],r[N],a[N];
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
                s[i].ft=l[i];
                s[i].sc=r[i];
            }
    sort(s+1,s+1+m);
    cin>>n;
    k=1e7;
    for (int i=1; i<=n; i++) {cin>>a[i];k=min(k,a[i]);}
    int d1;
    for (int i=1; i<=m; i++)
    {
        if (s[i].second>=k)
        {
            d1=d;
            c=s[i].second;
            break;
        }
    }
    if (c<k) cout<<"-1";
    else
    {
        x=0;
        dem=1;
        kt=0;
        for (int  i=d1+1; i<=m; i++)
           {
               if (s[i].ft<=c && s[i].sc >x)
                  {
                     kt=1;
                     d=i;
                     x=s[i].sc;
                   }
               else
                 if  (s[i].ft>c)
                  {
                         ++dem;
                         if (kt==0) break;
                         if (kt==1 && s[i].first<=x)
                         {
                             ++dem;
                             c=s[d].second;
                             if (c>=100000) break;
                             x=0;
                             kt=0;
                         }
                         else
                        if (s[i].first<x)
                         {
                             kt=0;
                             break;
                         }
                   }
           }
        if (c!=x)
        {
            ++dem;
            c=x;
            if (x<100000)
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

