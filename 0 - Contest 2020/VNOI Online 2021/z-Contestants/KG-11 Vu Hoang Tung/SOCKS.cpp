#include <bits/stdc++.h>
#define int long long
#define Task "SOCKS"
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READFILE freopen(Task".INP", "r", stdin)
#define WRITEFILE freopen(Task".OUT", "w", stdout)
#define pb push_back
#define mp make_pair
#define oo 1e18
#define ENDL '\n'
#define debug(x) cout << #x << " = " << x << ENDL
#define X first
#define Y second
#define ever (;true;)
#define all(x) x.begin(), x.end()

using namespace std;

typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < vvi > vvvi;
typedef pair < int, int > ii;
typedef vector < ii > vii;
typedef vector < vii > vvii;
typedef pair < int, ii > iii;
typedef vector < iii > viii;

const int N = 7;

int n, q;
int red[N];
int lv[N];
vi a[N];
vi g[N];
int p[N];
int h[N];
int ans = 0;
vi r;
int root = 0;
int pos = 0;
int cnt = 0;

void init(){
    FAST;
    READFILE;
    WRITEFILE;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        int w;
        cin >> w;
        if (w == 1){
            r.pb(i);
            if (root == 0) root = i;
        }
    }
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
}

bool cmp(int x, int y){
    return h[x] > h[y];
}

void dfs(int u){
    for (int i = 0; i < a[u].size(); ++i){
        int v = a[u][i];
        if (v != p[u]){
            h[v] = h[u] + 1;
            p[v] = u;
            g[u].pb(v);
            dfs(v);
        }
    }
}

void Union(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    while (u != v){
        ++lv[u];
        u = p[u];
        ++lv[u];
    }
    if (u == v) return;
    while (u != v){
        ++lv[u];
        ++lv[v];
        u = p[u];
        v = p[u];
        ++lv[u];
        ++lv[u];
    }
    --lv[u];
    pos = 0;
}

void process(int u){
    if (red[u] == 1) return;
    ++cnt;
    while (red[u] == 0){
        red[u] = 1;
        ++lv[u];
        u = p[u];
        ++lv[u];
    }
    if (cnt == 0){
        ans = 0;
        return;
    }
    else if (cnt == 1){
        ans = 1;
        lv[root] = 1;
        return;
    }
    if (lv[u] % 2 == 0) return;
    if (pos == 0){
        pos = u;
        ++ans;
    }
    else{
        Union(u, pos);
    }
}

void build_graph(int root){
    red[root] = 1;
    h[root] = 1;
    dfs(root);
    ans;
}

signed main(){
    init();
    if (root != 0){
        build_graph(root);
    }
    for (int i = 0; i < r.size(); ++i){
        int u = r[i];
        process(u);
    }
    cout << ans << ENDL;
    while (q--){
        int u;
        cin >> u;
        if (root == 0){
            root = u;
            build_graph(u);
        }
        process(u);
        cout << ans << ENDL;
    }
    return 0;
}

