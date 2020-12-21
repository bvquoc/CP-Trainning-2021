#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define eb emplace_back

#define FORU(i, a, b) for(__typeof(b) i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(__typeof(a) i = (a); i >= (b); --i)

#define Fast_IO ios_base::sync_with_stdio(false); cin.tie(0);

#define PROB "SOCKS"
void Fi(){
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp", "r", stdin);
        freopen(PROB".out", "w", stdout);
    }
}

const int N = 5e5 + 1;
vector<int> adj[N];
int a[N], deg[N];
int max_deg, cnt, d3, ct[3];
map<int, int> hs, rhs;
int dm = -1;

int par[N];
int root(int v){
    return (par[v] < 0 ? v : par[v] = root(par[v]));
}
void unionn(int x, int y){
    if((x = root(x)) == (y = root(y))) return;
    if(-par[x] < -par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

void dfs(int u, int p){
    for(int v: adj[u]) if(v != p){
        if(u != d3) unionn(u, v);
        dfs(v, u);
    }
}

int main(){
    Fast_IO;
    Fi();
    int n, q; cin >> n >> q;
    FORU(i, 1, n){
        cin >> a[i];
        par[i] = -1;
        cnt += a[i];
    }
    FORU(i, 1, n - 1){
        int u, v; cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
        ++deg[u]; ++deg[v];
        max_deg = max(max_deg, deg[u]);
        max_deg = max(max_deg, deg[v]);
        if(deg[u] == 3) d3 = u;
        if(deg[v] == 3) d3 = v;
    }
    if(max_deg == 3) dfs(d3, 0);
    FORU(i, 1, n) if(par[i] < 0 && i != d3){
        hs[++dm] = i;
        rhs[i] = dm;
    }
    FORU(i, 1, n) if(a[i]) ++ct[rhs[root(i)]];
    while(q--){
        int x; cin >> x;
        cnt += (a[x] ? -1 : +1);
        ct[rhs[root(x)]] += (a[x] ? -1 : +1);
        a[x] = !a[x];
        if(max_deg == 2){
            if(cnt == 1) cout << "0\n";
            else cout << "1\n";
        } else if(max_deg == 3){
            if(cnt == 1) cout << "0\n";
            else{
                int tmp = (ct[0] != 0) + (ct[1] != 0) + (ct[2] != 0);
                cout << max(1, tmp - 1) << "\n";
            }
        }
    }
    return 0;
}
