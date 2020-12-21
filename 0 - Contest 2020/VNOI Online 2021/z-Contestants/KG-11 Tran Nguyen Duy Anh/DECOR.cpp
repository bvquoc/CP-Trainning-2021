#include <bits/stdc++.h>
#define TASK "DECOR"
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
#define odd(a) (a&1)
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
 
const int MaxN = 500100;
int a[MaxN];
vii b(MaxN);
int n,m,k,c;
char s;
signed main()
{
  FAST;
  //#ifndef ONLINE_JUDGE
    READFILE;
    WRITEFILE;
  //#endif
  cin>>n>>m>>k;
  c=0;
  For(i,1,n)
  {
    cin>>s;
    if (s=='0') a[i]=0;
    else 
    {  
      a[i]=1;
      c++;
    }  
  }
  For(i,1,m)
    cin>>b[i].fi>>b[i].se;
  if (c==0)
  {
    if (k==0) cout<<-1;
    else cout<<1<<" "<<k;
    return 0;
  }  
  if (m==0)
  {
    int p=0;
    int d=0;
    For(i,1,n)
    {
      if (n-i+1<=d) break;
      int j=i;
      int c=0;
      while ((a[j]==1 || c<k) && (j<n))
      {
        if (a[j]==0 && c<k)
        {
          c++;
          j++;
        }  
        else j++;
      }  
      if (a[j]==0 && c>=k) j--;
      if (j-i+1>d)
      {
        p=i;
        d=j-i+1;
      }
    }
    if (d==0) cout<<-1;
    else cout<<p<<" "<<p+d-1;
    return 0;
  }  
  return 0;
}