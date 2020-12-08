#include<bits/stdc++.h>
#define maxc 1000999
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define repn(i,b,a) for (int i=b;i>=a;--i)
#define duyet(l,se) for(__typeof(se.begin())l=se.begin();l!=se.end();++l)
#define ll int
#define fl  double
#define pb push_back
using namespace std;
ll n,loai;
ll cha[maxc],me[36];
char color[maxc],x,y;
    void trau()
    {rep(i,1,n)color[i]='.';
      rep(tt,1,n)
     {
      cin>>loai;
      if(loai==1){cin>>x;rep(i,1,n)if(color[i]=='.'){color[i]=x;break;}}
      else  {cin>>x>>y;rep(i,1,n)if(color[i]==x)color[i]=y;}
     }
     rep(i,1,n)if(color[i]!='.')cout<<color[i];
    }


    void nhanh()
    {ll cs=0;rep(i,1,n)color[i]='.';
     vector<ll>vec[100];
     rep(tt,1,n)
     {cin>>loai;
      if(loai==1){cin>>x;vec[x-'a'+1].pb(++cs);}
      else {cin>>x>>y;
      duyet(i,vec[x-'a'+1]){ll v=*i;vec[y-'a'+1].pb(v);}
      vec[x-'a'+1].clear();
      }
     }

     rep(i,'a'-'a'+1,'z'-'a'+1)
     {
         duyet(l,vec[i]){ll v=*l; color[v]=(char)(i+'a'-1);} ///cout<<v<<endl;}///
     }
     rep(i,1,n)if(color[i]!='.')cout<<color[i];
    }
int main()
{
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   cin>>n;
   if(n<=10000)trau();
   else nhanh();
}

