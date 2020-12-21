#include <bits/stdc++.h>
#define TASK "COOLMAC"
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READFILE freopen(TASK".INP","r",stdin)
#define WRITEFILE freopen(TASK".OUT","w",stdout)
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define oo 1e18
#define ENDL '\n'
#define debug(x) cout<<#x<<" = "<<x<<ENDL
#define fi first
#define se second
#define ever (;true;)
#define all(x) x.begin(),x.end()
#define sz(a) ((int)(a).size())
#define ms(a,x) memset(a,x,sizeof(a))
#define lamtron(a) (floorf((float)a+0.6f))
#define chusothapphan(a) setprecision(a+1)
#define hoanvi(a,start,stop) next_permutation(a+start,a+stop)
#define vi vector <int>
#define vvi vector <vi>
#define ii pair <int,int>
#define vii vector <ii>
#define vvii vector <vii>
#define iii pair <int,ii>
 
using namespace std;
 
const int MaxN = 100000;
vii cool(MaxN);
bool sortbysecdesc(const ii &a,const ii &b)
{
  return a.se>b.se;
}
signed main()
{
  FAST;
  // #ifndef ONLINE_JUDGE
    READFILE;
    WRITEFILE;
  // #endif
  int n,m,c,minc,ans;
  ans=0;
  bool kt=false;
  cin>>n;
  For(i,0,n-1)
  {
    cin>>cool[i].fi>>cool[i].se;
    if (cool[i].se==MaxN) kt=true;
  }
  if (!kt)
  {
    cout<<-1;
    return 0;
  }
  minc=MaxN;
  cin>>m;
  For(i,1,m)
  {
    cin>>c;
    minc=min(minc,c);
  }
  sort(cool.begin(),cool.end(),sortbysecdesc);
  c=MaxN+1;
  int i=-1;
  while(c>minc && i<n)
  {
    int j=i+1;
    int p=i;
    int q=MaxN+1;
    while ((cool[j].se>=c || cool[j].se==MaxN) && (j<n))
    {
      if (cool[j].fi<=q)
      {
        p=j;
        q=cool[j].fi;
      }
      j++;
    }
    if (p==i)
    {
      cout<<-1;
      return 0;
    }
    i=p;
    ans++;
    c=q;
  }
  if (c>minc) cout<<-1;
  else cout<<ans;
  return 0;
}