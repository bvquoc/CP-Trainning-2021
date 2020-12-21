#include<bits/stdc++.h>
using namespace std;
#define fasty ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define fori(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,a,b) for(int i=a;i>=b;--i)
#define forv(x,y) for(auto &x:y)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){ return rng()%(r-l+1)+l;}
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define getbit(i,x) ((x>>i)&1ll)
#define tatbit(i,x) (x&~(1ll<<i))
#define batbit(i,x) (x|(1ll<<i))
#define gg exit(0);

const int maxn = 5e5 + 10;
int a[maxn],n,q;
vector<int> ke[maxn];

void sub1()
{
    int dem=0;
    fori(i,1,n) dem+=a[i];
    if(dem>0) cout<<1<<"\n";
    fori(i,1,q)
    {
        int x;cin>>x;
        a[x] = 1-a[x];
        dem+=(a[x]==1 ? 1 : -1);
        cout<<(dem>0 ? 1 : 0)<<"\n";
    }
}

int dep[maxn],pd[maxn][25],st[maxn],ed[maxn],it;
void dfs(int u,int pr)
{
    st[u] = ++it;
    fori(i,1,log2(n)) pd[u][i] = pd[pd[u][i-1]][i-1];
    forv(v,ke[u]) if(v!=pr)
    {
        pd[v][0] = u;
        dep[v] = dep[u] + 1;
        dfs(v,u);
    }
    ed[u] = it;
}

int lca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    int del = dep[u] - dep[v];
    ford(i,log2(n),0) if(getbit(i,del))
    u = pd[u][i];
    if(u==v) return u;
    ford(i,log2(n),0) if(pd[u][i]!=pd[v][i])
    u = pd[u][i],v = pd[v][i];
    return pd[u][0];
}

bool anc(int u,int v) {return st[u]<=st[v] && ed[u]>=ed[v];}
bool cmp(int u, int v) {return make_pair(st[u],ed[u]) < make_pair(st[v],ed[v]);}

void xaycay()
{
   vector<int> node;
   node.clear();
   fori(i,1,n) if(a[i]) node.pb(i);
   sort(all(node),cmp);
   int len = node.size();
   fori(i,1,len-1)
   node.pb(lca(node[i],node[i-1]));
   sort(all(node)),node.erase(unique(all(node)),end(node));
   sort(all(node),cmp);

   vector<int> deg(n+5,0);
   stack<int> s;
   while(!s.empty()) s.pop();
   forv(v,node)
   {
      while(!s.empty() && !anc(s.top(),v)) s.pop();
      if(!s.empty()) deg[v]++,deg[s.top()]++;
      s.push(v);
   }
   int res=0;
   fori(i,1,n) if(deg[i]==1) res++;
   cout<<(res+1)/2<<"\n";
}
void sub3()
{
   dfs(1,0);
   xaycay();
   while(q--)
   {
       int x;cin>>x;
       a[x] = 1 - a[x];
       xaycay();
   }
}
void nhap()
{
   fasty;
   #define task "socks"
   if(fopen(task".inp","r"))
   {
       freopen(task".inp","r",stdin);
       freopen(task".out","w",stdout);
   }
}
main()
{
    nhap();
   cin>>n>>q;
   fori(i,1,n) cin>>a[i];
   fori(i,1,n-1)
   {
       int u,v;cin>>u>>v;
       ke[u].pb(v),ke[v].pb(u);
   }
   if(n<=1000 && q<=1000) sub3();
   int res=0,ok=0;
   fori(i,1,n) if(ke[i].size()>2) {ok=i;break;}
   if(!ok) sub1();

}
// xay lai cay
//==> dem so la/2;
