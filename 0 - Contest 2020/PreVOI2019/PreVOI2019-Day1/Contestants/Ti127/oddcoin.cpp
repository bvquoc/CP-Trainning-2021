#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>

using namespace std;

const ll oo = 1e18;
ll c[20]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
queue <ll> Q;
ll f[200005],tmp,tam,t,x,q,res,tamres,tamt;
priority_queue < pll , vector< pll > , greater< pll > > pq;
map <ll , ll> dd;
map <ll , ll>  :: iterator it;

inline ll read()
{ ll s = 0, t = 1; char c = getchar();
while( !isdigit(c) ) { if( c == '-' ) t = -1; c = getchar();
} while( isdigit(c) ) s = s * 10 + c - 48, c = getchar();
return s * t; }
inline void Write(ll x){ if (x>9) Write(x/10); putchar(x%10+48); }

inline void sub()
{
    memset(f,-1,sizeof(f));

    while (!Q.empty()) Q.pop();

    Q.push(0);
    f[0]=0;
    while (!Q.empty())
    {
        tmp = Q.front(); Q.pop();

        for (ll i=1;i<=16;++i)
        {
           tam = tmp + c[i];
           if (tam > t) continue;
           if (f[tam]==-1 || f[tam]>f[tmp] + 1)
           {
               Q.push(tam);
               f[tam]=f[tmp] + 1;
           }
        }
        if (f[t]!=-1) break;
    }
    tamres+=f[t];
}

int main()
{
    freopen("oddcoin.inp","r",stdin); freopen("oddcoin.out","w",stdout);
    q = read();

    while (q--)
    {
       res=oo; tamres=0;
       x = read(); t = read();
       c[16]=x;
       if (x<=10000 && t<=100000) {sub(); Write(tamres); putchar('\n'); continue;}

       tamres=t / 100000;
       tamres *= 2;
       tamt=t;
       t=t % 100000;
       sub();

       res=tamres;

       if (tamt >= 2 * x)
       {
         t=tamt;
         tamres=t / (2 * x);
         tamres *= 2;
         t=t % (2 * x);
         if (t<=100000) {sub();} else if (t>0) tamres=oo;
       }

       res=min(res,tamres);

       if (tamt >= x)
       {
           t=tamt;
           tamres=t / x;
           t=t % x;
           if (t<=100000) {sub();} else if (t>0) tamres=oo;
       }

       res=min(res,tamres);

       Write(res); putchar('\n');
    }

    return 0;
}
