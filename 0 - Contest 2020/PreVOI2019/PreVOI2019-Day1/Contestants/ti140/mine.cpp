#include<bits/stdc++.h>
#define maxc 999999
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define repn(i,b,a) for (int i=b;i>=a;--i)
#define duyet(l,se) for(__typeof(se.begin())l=se.begin();l!=se.end();++l)
#define ll int
#define fl  double
#define pb push_back
using namespace std;
 ll n,m,a[maxc],dem;

    void kt(ll ch)
    {bitset<20>bi(ch);bitset<20>phu(ch);
       ll sl=3;
       repn(i,2*n-1,0)
       {
        ///cout<<bi[i]<<' ';cout<<i<<j<<endl;
         if(bi[i]==1)
        {
         rep(j,i+1,2*n-1)if(bi[j]==0){bi[j]=1;if(abs(a[i+1]-a[j+1])<=m){sl--;break;}}
        }
       }
      ///cout<<phu<<' '<<sl<<endl;
      if(sl==0)dem++;
    }
    void sub1(ll v)
    {
     rep(ch,1,1<<v)
     {
      bitset<20>bi(ch);
      ///cout<<bi<<' '<<ch<<'\n';
      if(bi.count()==n)kt(ch);
      }
      cout<<dem;
     }


int main()
{
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    rep(i,1,2*n)
    {
     cin>>a[i];
    }
    if(n<=20)sub1(2*n);
    ///bitset<6>bi(11);
    ///cout<<bi;
    kt(13);
}

