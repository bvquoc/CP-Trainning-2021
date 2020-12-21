#include <bits/stdc++.h>
#define TASK "GIFT11"
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
#define x first
#define y second
#define ever (;true;)
#define all(x) x.begin(),x.end()
#define sz(a) ((int)(a).size())
#define ms(a,x) memset(a,x,sizeof(a))
#define lamtron(a) (floorf((float)a+0.6f))
#define chusothapphan(a) setprecision(a+1)
#define hoanvi(a,start,stop) next_permutation(a+start,a+stop)
#define odd(a) a%2==1
#define vi vector <int>
#define vvi vector <vi>
#define ii pair <int,int>
#define vii vector <ii>
#define vvii vector <vii>
#define iii pair <int,ii>
 
using namespace std;
 
const int MaxN = 2020;
const long long modulo = 998244353;
int t,n,i,j,m,d;
int card[MaxN],l[MaxN],a[MaxN];
vii value(MaxN);
signed main()
{
  FAST;
  // #ifndef ONLINE_JUDGE
    READFILE;
    WRITEFILE;
  // #endif
  cin>>t;
  For(i,1,t)
  {
    long long ans=0;
    cin>>n;
    For(j,1,n)
    {
      cin>>card[j];
      value[j].x=0;
      value[j].y=0;
      m=card[j];
      d=0;
      while(m>0)
      {
        d++;
        if (odd(d)) 
        {
          value[j].x+=m%10;
          value[j].y-=m%10;
        }
        else
        {
          value[j].x-=m%10;
          value[j].y+=m%10;
        }  
        m/=10;
      }
      l[j]=d;
    }
    For(j,1,n) a[j]=j;
    do
    {
      d=0;
      int p=0;
      For(j,1,n)
      {
        if (odd(p)) d+=value[a[j]].x;
        else d+=value[a[j]].y;
        p+=l[a[j]];
      }
      if (d%11==0)
      {
        ans++;
        ans%=modulo;
      }
    } 
    while (hoanvi(a,1,n+1));
    cout<<ans<<ENDL;
  }
  return 0;
}