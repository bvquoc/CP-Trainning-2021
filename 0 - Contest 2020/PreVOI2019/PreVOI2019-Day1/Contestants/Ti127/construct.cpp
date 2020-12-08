#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=100001,oo=1e9+7;
ll h[N],a[N],t,dau,Min,res,n,m,tt,l,r,k;

inline ll read()
{ ll s = 0, t = 1; char c = getchar();
while( !isdigit(c) ) { if( c == '-' ) t = -1; c = getchar();
} while( isdigit(c) ) s = s * 10 + c - 48, c = getchar();
return s * t; }
inline void Write(ll x){ if (x>9) Write(x/10); putchar(x%10+48); }

void sub()
{
    t = 0; res=0;
    for (ll i=l;i<=r;++i)
    {  h[i]=a[i]; t+=a[i];}

    h[r+1]=0;
    while (t > 0)
    {
      dau=l; Min = h[l];

      for (ll i=l;i<=r+1;++i)
      {
         if (h[i]==0)
         {
             for (ll j=dau;j<i;++j)
             {
                t-=Min;
                h[j]-=Min;
             }
             res+=Min;
             dau=i+1;
             Min=0;
         } else
         {if (Min==0) Min=h[i]; else Min=min(Min,h[i]);}
      }
    }

    Write(res); putchar('\n');
}

int main()
{
    freopen("construct.inp","r",stdin); freopen("construct.out","w",stdout);
    t = read();
    h[0]=0; a[0]=0;
    while (t--)
    {
       n = read(); m = read();
       for (ll i=1;i<=n;++i) a[i] = read();

       for (ll sl=1;sl<=m;++sl)
       {
         tt = read();
         if (tt == 1)
         {
             l = read(); r = read(); k = read();
             for (ll i=l;i<=r;++i) a[i]+=k;
         } else
         {
           l = read(); r = read();
           sub();
         }
       }
    }

    return 0;
}
