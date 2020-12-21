#include <bits/stdc++.h>
#define TASK "DHAKA"
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READFILE freopen(TASK".INP","r",stdin)
#define WRITEFILE freopen(TASK".OUT","w",stdout)
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define ENDL '\n'
#define debug(x) cout<<#x<<" = "<<x<<ENDL
#define fi first
#define se second
#define ever (;true;)
#define all(x) x.begin(),x.end()
#define sz(a) ((int)(a).size())
#define ms(a,x) memset(a,x,sizeof(a))
#define lamtron(a) (floorf((float)a+0.6f))
#define int long long
using namespace std;
typedef vector <int> vi;
typedef vector <vi> vii;
typedef pair <int,int> ii;
typedef vector <ii> vpi;
typedef pair <int,ii> iii;
const int maxn = 100100;
const int oo=10000000000;

vector<ii> a[maxn];
int n, m, k, l, t, minn=oo;
int d[maxn],s[maxn];
bool b[maxn];
void dij() {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i++)
        d[i] = oo;
    d[1] = 0;
    pq.push(ii(0, 1));

    while (pq.size()) {
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();
        if (du != d[u])
            continue;
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].fi;
            int uv = a[u][i].se;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}
bool ok(int x){
    int res=0;
    For(i,1,k) if ((x >> (i-1)) & 1) res++;
    return res>=l;
}
void dfs(int u, int sta, int dw){
    if (u==n) {
        if ((ok(sta)) && (dw<minn)) minn=dw;
    }
    else{
    b[u]=true;
    For(i,0,a[u].size()-1){
        int v=a[u][i].fi;
        int uv=a[u][i].se;
        if (!b[v]) dfs(v,sta | s[v],dw+uv);
    }
    b[u]=false;
    }
}

signed main()
{
  FAST;
  #ifndef ONLINE_JUDGE
    READFILE;
    WRITEFILE;
  #endif
  cin >> n >> m >> k >> l;
  For(i,1,n) s[i]=0;
  int tam=0;
  For(i,1,n){
    int u;
    cin >> u;
    For(j,1,u){
        int v;
        cin >> v;
        s[i]=(1 << v-1) | s[i];
    }
    tam=tam | s[i];
  }
  int res=0;
  For(i,1,k) if ((tam >> (i-1)) & 1) res++;
  if (res<l) {
    cout << -1;
    exit(0);
  }
  For(i,1,m){
    int u,v,w;
    cin >> u >> v >> w;
    a[u].pb(ii(v,w));
    a[v].pb(ii(u,w));
  }
  if (l==0) {
    dij();
    cout << d[n];
    exit(0);
  }
  dfs(1,s[1],0);
  if (minn==oo) cout << -1;
  else cout << minn;
  return 0;
}
