#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb pop_back
#define pf push_front
#define ef pop_front

using namespace std;

const ll mod = 1000003;
stack <ll> s;
vector <ll> vec;
ll n,m,res,a[200005],b[101],dem,vt,t[1001],tam;
stack <ll> S;

struct _
{
    ll id,tg;
};

deque < ll > dq;

ll Count(ll tt)
{
   ll res = 0;
   for (ll i=0;i<2*n;++i)
   if ( (tt & (1 << i)) !=0) res++;
   return res;
}

inline ll read()
{ ll s = 0, t = 1; char c = getchar();
while( !isdigit(c) ) { if( c == '-' ) t = -1; c = getchar();
} while( isdigit(c) ) s = s * 10 + c - 48, c = getchar();
return s * t; }
inline void Write(ll x){ if (x>9) Write(x/10); putchar(x%10+48); }

inline void sub1()
{
    ll res=0;
    for (ll tt=0;tt< (1 << 2*n );++tt)
    if (Count(tt) == n)
    {
      for (ll i=0;i<2*n;++i)
          if (( tt & (1 << i)) !=0) b[i]=1; else b[i]=0;

      dem=0; vt=0;
      while (!dq.empty()) dq.pop_back();

      for (ll i=0;i<2*n;++i)
      {
         if (!dq.empty())
         {
           tam = dq.front();
           if (a[i] - t[tam] > m) break;
         }

         if (b[i]==1)
         {
             dem++;
             vt++;
             dq.push_back(vt);
             t[vt]=a[i];
         } else
         {
             if (!dq.empty()) dq.pop_back();
             dem--;
         }
         if (dem<0) break;
      }

      if (dem==0) res++;
    }

    Write(res);
}

int main()
{
    freopen("mine.inp","r",stdin); freopen("mine.out","w",stdout);
    n = read(); m = read();
    for (ll i=1; i<=2*n; ++i) a[i-1]=read();

    {sub1(); return 0;}

    return 0;
}
