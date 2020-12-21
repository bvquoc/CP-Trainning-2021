#include <bits/stdc++.h>
#define name "DECOR"
#define mk make_pair
#define pb push_back
#define ll long long
#define pll pair<ll ,ll>
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
#define pii pair<int,int>
using namespace std;
const int maxn=5e5+7;
int n,m, k;
pii a[maxn];
char st[maxn];
void enter()
{
     cin>>n>> m>>k;
    for(int i=1;i<=n;i++)
        cin>> st[i];
     for(int i=1;i<=m;i++)
     {
         int x, y;
         cin>> x>>y;
         a[i]=mk(x,y);
     }
}
void sub1()
{
    int res=0; int cnt=0;
    for(int i=1;i<=n;i++ )
        if(st[i]=='1')
            cnt++;
        else
        {
            res=max(res, cnt); cnt=0;
        }
        if(res==0) res=-1;
        cout<<res; exit(0);
}
void sub2()
{
    vector<int> d(maxn,0);
    for(int i=1;i<=n;i++)
        d[i]=d[i-1]+(st[i]-'0');
        if(k>=n ) {cout<< n; exit(0);}
        if(n==0 ){cout<<-1; exit(0);}
   int res=k;
    for(int i=k+1;i<=n;i++)
    {
        int fl=d[i]+k;
        if(fl>=i) res=max(res, i);
        else
        {
            fl=fl-d[i-k-1]; res=max(res, fl);
        }

    }
    cout<<res;
}
int main()
{
     ios;
    freopen(name".INP","r",stdin);
  freopen(name".OUT","w",stdout);
  enter();
  if(m==0 && k==0) sub1();
  else
  {
       sub2();
  }

    return 0;
}
