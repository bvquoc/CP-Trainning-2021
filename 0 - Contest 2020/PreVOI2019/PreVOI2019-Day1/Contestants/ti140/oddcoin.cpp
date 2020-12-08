#include<bits/stdc++.h>
#define maxc 1999999
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define repn(i,b,a) for (int i=b;i>=a;--i)
#define duyet(l,se) for(__typeof(se.begin())l=se.begin();l!=se.end();++l)
#define ll long int
#define fl  double
#define pb push_back
using namespace std;
const ll ma=3*1e9;
ll f[maxc],cost[22],gan[22];
ll q,x,t,phu;
bool dd[maxc];

    ll sol(ll t)
    {
     rep(i,1,t)
     {f[i]=ma;
      rep(j,1,16)
      { if(i<cost[j])continue;
        if(f[i-cost[j]]==0&&i>cost[j])continue;
        f[i]=min(f[i],f[i-cost[j]]+1);
      }
     }
     return f[t];
     rep(i,0,t)f[i]=0;
    }
    ll tham(ll val)
    {ll dem=0;sort(cost+1,cost+1+16);
      if(val<=100000){dem+=sol(val);return dem;}
     while(val>0)
     {
      repn(i,16,1)if(val>=cost[i]){val-=cost[i];dem++;break;}
      if(val<=100000){dem+=sol(val);return dem;}
     }
     return dem;
    }
    void gen()
    {srand((int)time(0));
     cout<<15<<'\n';
     rep(i,1,15)cout<<rand()%10000<<' '<<rand()%100000000<<'\n';
    }
int main()
{
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cost[1]=1;cost[2]=3;cost[3]=5;cost[4]=10;cost[5]=30;
    cost[6]=100;cost[7]=300;cost[8]=500;cost[9]=1000;cost[10]=3000;cost[11]=5000;
    cost[12]=10000;cost[13]=30000;cost[14]=50000;cost[15]=50;
    rep(i,1,15)dd[cost[i]]=1;
    dd[0]=1;
    rep(i,1,15)gan[i]=cost[i];
     cin>>q;
    rep(tt,1,q)
    {
     cin>>x>>t;
     rep(i,1,15)cost[i]=gan[i];
     if(dd[x]==0&&x<=t)cost[16]=x;else cost[16]=ma;
     phu=ma; if(x<=t)phu=min(phu,min(tham(t-x)+1,tham(t)));else phu=tham(t);
     cout<<phu<<endl;
    }
    ///gen();
}

