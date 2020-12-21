#include <bits/stdc++.h>
#define TASK "SOCKS"
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READFILE freopen(TASK".INP","r",stdin)
#define WRITEFILE freopen(TASK".OUT","w",stdout)
#define For(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define ENDL '\n'
#define fi first
#define se second
#define ii pair <int,int>
#define debug(x) cout << #x << '=' << x << ENDL
using namespace std;
const int maxn = 100100, oo=10000000;
const int li=100000;
vector<int> a[maxn];
int dem=0,w[maxn];
bool b[maxn];
int n,q,la,res=0,root;
void xtree(){
    if (dem>1) cout << 1 << ENDL;
    else cout << 0 << ENDL;
    For(i,1,q){
        int u;
        cin >> u;
        if (w[u]==1) {
            w[u]=0;
            dem--;
        } else{
            w[u]=1;
            dem++;
        }
        if (dem>1) cout << 1 << ENDL;
        else cout << 0 << ENDL;
    }
}
void dfs(int u){
    b[u]=true;
    for (int v : a[u]) if (!b[v]) dfs(v);
}
void ttree(){
    cout << "TREEE" << root << ENDL;
    debug(dem);
    For(i,1,n) b[i]=false;
    b[root]=true;
    dfs(a[root][1]);
    dfs(a[root][2]);
    For(i,1,n) if (b[i]) cout << 1 << ' ';
    else cout << 0 << ' ';
    cout << ENDL;
    int dems=0,demd=0;
    For(i,1,n){
        if (w[i]==1){
            if (b[i]) demd++;
            else dems++;
        }
    }
    if (dem<=1) cout << 0 << ENDL;
    else{
        if ((demd>0) && (dems>0)) cout << 2 << ENDL;
        else cout << 1 << ENDL;
    }
    For(i,1,q){
        int u;
        cin >> u;
        if (w[u]==1) {
            w[u]=0;
            if (b[u]) demd--;
            else dems--;
            dem--;
        } else{
            w[u]=1;
            if (b[u]) demd++;
            else dems++;
            dem++;
        }
        debug(dem);
        debug(demd);
        debug(dems);
        if (dem<=1) cout << 0 << ENDL;
        else{
            if ((demd>0) && (dems>0)) cout << 2 << ENDL;
            else cout << 1 << ENDL;
            }
    }

}
signed main()
{
  FAST;
  #ifndef ONLINE_JUDGE
    READFILE;
    WRITEFILE;
  #endif
  cin >> n >> q;
  For(i,1,n){
      cin >> w[i];
      if (w[i]==1) dem++;
  }
  For(i,1,n-1){
    int u,v;
    cin >> u >> v;
    a[u].pb(v);
    a[v].pb(u);
  }
  int d3=0,dl=0;
  For(i,1,n){
    if (a[i].size()>2){
        if (a[i].size()==3) {
            d3++;
            root=i;
        }
        else dl++;
    }
    else if (a[i].size()==1) la=i;
  }
  if (dl==0){
    if (d3==0) xtree();
    else if (d3==1) ttree();
  }
  return 0;
}

