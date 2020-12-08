#include<bits/stdc++.h>
#define maxc 9999
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define repn(i,b,a) for (int i=b;i>=a;--i)
#define duyet(l,se) for(__typeof(se.begin())l=se.begin();l!=se.end();++l)
#define ll int
#define fl  double
#define pb push_back
using namespace std;
string s;
char x;
ll n,dau,cuoi,trc,vt;

    void gen()
    {srand((int)time(0));
     cout<<15<<'\n';
     rep(i,1,15)cout<<rand()%10000<<' '<<rand()%100000000<<'\n';
    }
     ll tinh(string phu)
     {ll le=phu.size()-1 ,mo=0,dong=0;
      ///cout<<phu<<'\n';
      rep(i,0,le)
      {
       if(phu[i]=='(')mo++;
       if(phu[i]==')'){if(mo>0)mo--;else dong++;}
      }
      return (dong+mo);
     }
     void trau()
     {string xau[9999];
      rep(i,1,n)
    {
     cin>>x;
     if(x=='C'){cin>>vt;if(s[vt]==')')s[vt]='('; else s[vt]=')'; }
     else if(x=='Q'){ cin>>dau>>cuoi;  cout<<tinh(s.substr(dau,cuoi-dau+1))<<'\n';}///cout<<dau<<cuoi<<'\n';
      else if(x=='U'){cin>>trc;s=xau[trc-1];}
      xau[i]=s;
    }
     }
     void nhanh()
     {
      rep(i,1,n)
    {
     cin>>x;
     if(x=='C'){cin>>vt;if(s[vt]==')')s[vt]='('; else s[vt]=')'; }
     else if(x=='Q'){ cin>>dau>>cuoi;  cout<<tinh(s.substr(dau,cuoi-dau+1))<<'\n';}///cout<<dau<<cuoi<<'\n';
    }
     }
int main()
{
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;s=' '+s;
    ll m=s.size();
    cin.ignore();
    cin>>n;
    if(n*m<=5000000)trau();
    else nhanh();

}

