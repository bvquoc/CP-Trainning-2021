#include <bits/stdc++.h>
#define TASK "SOCKS"
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
 
const int MaxN = 100100;
int sock[MaxN],mark[MaxN];
vvi tree(MaxN);
vi d1(MaxN),d2(MaxN),d3(MaxN);
int n,m,q,u,v,s,subtask,s1,s2,s3,s0,e;
void dfs(int u,int check)
{
  mark[u]=1;
  For(i,0,sz(tree[u])-1)
    if(mark[tree[u][i]]==0)
    {
      if(s0==u) e=i+1;
      else e=check;
      if (sock[tree[u][i]]==1)
      {
        if (e==1) s1++;
        if (e==2) s2++;
        if (e==3) s3++;
      }
      dfs(tree[u][i],e);
    }
  mark[u]=0;
}
int noiday()
{
  if (s==0 || s==1) return 0;
  if (subtask==1) return 1;
  if (subtask==2)
  {
    s1=0;
    s2=0;
    s3=0;
    dfs(s0,1);
    e=0;
    if (s1>0) e++;
    if (s2>0) e++;
    if (s3>0) e++;
    if (e==1 || e==2) return 1;
    if (e==3) return 2;
  }  
  e=0;
  For(i,1,n)
    if(sz(tree[i])==1 && sock[i]==1) e++;
  if (e==0) e=s;    
  return lamtron(e/2);  
}
signed main()
{
  FAST;
  // #ifndef ONLINE_JUDGE
    READFILE;
    WRITEFILE;
  // #endif
  cin>>n>>q;
  For(i,1,n)
  {
    cin>>sock[i];
    s+=sock[i];
  }
  For(i,1,n-1)
  {
    cin>>u>>v;
    tree[u].pb(v);
    tree[v].pb(u);
  }  
  subtask=s1=s2=0;
  For(i,1,n)
  {
    if (sz(tree[i])==1 || sz(tree[i])==2) s1++;
    if (sz(tree[i])==3) s2++;
  }  
  if (s1==n && s2==0) subtask=1;
  if (s2==1 && s1+s2==n) subtask=2;
  if (s2>1 && s1+s2==n) subtask=3;
  if (s1+s2!=n) subtask=3;
  if (subtask==2)
  {
    s0=1;
    while(sz(tree[s0])!=3) s0++;
  }
  cout<<noiday()<<ENDL;
  For(t,1,q)
  {
    cin>>m;
    if (sock[m]==0)
    {
      sock[m]=1;
      s++;
    }
    else
    {
      sock[m]=0;
      s--;
    }
    cout<<noiday()<<ENDL;
  }
  return 0;
}