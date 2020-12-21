#include <bits/stdc++.h>
#define maxn 500005
#define MOD 1000000007
#define task "SOCKS"
#define pii pair<int, int>
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
const ll MM = 1ll * MOD * MOD;
int n, q, c[maxn];
vector<int> ke[maxn], red;
void Input(){
    cin >> n >> q;
    for (int x, i=1; i<=n; ++i){
        cin >> c[i];
        if (c[i]) red.pb(i);
    }
    for (int u, v, i=1; i<n; ++i){
        cin >> u >> v;
        ke[u].pb(v); ke[v].pb(u);
    }
}
/*int p[20][maxn], h[maxn], in[maxn], out[maxn], dem = 0;
void DFS(int u){
    in[u] = ++dem;
    for (int i=1; i<=19; ++i) p[i][u] = p[i-1][p[i-1][u]];
    for (int v : ke[u]) if (v != p[0][u]){
        p[0][v] = u;
        h[v] = h[u] + 1;
        DFS(v);
    }
    out[u] = dem;
}
int t[maxn], par, root[maxn];
void Update(int x){ for (; x; x -= x&-x) t[x]++; }
int Get(int x){ int res = 0; for (; x<=n; x += x&-x) res += t[x]; return res; }
int get_root(int u){
    return root[u] < 0 ? u : root[u] = get_root(root[u]);
}
pii M[maxn];
void Init(){
    p[0][1] = 0; h[1] = 1;
    DFS(1);
    for (int i=1; i<=n; ++i) root[i] = -1;
    if (red.size()) par = red[0];
    for (int i=1; i<red.size(); ++i){
        int u = red[i];
        int lca = LCA(par, u);
        if (par == lca)
    }
}
void Solve(){

}*/
void Sub1(){
    cout << (red.size() >= 2) << "\n";
    for (int x, i=1; i<=q; ++i){
        cin >> x;
        if (!c[x]) c[x] = 1, red.pb(x);
        cout << (red.size() >= 2) << "\n";
    }
    exit(0);
}
int dd[maxn];
void DFS(int u, int par, int id){
    dd[u] = id;
    for (int v : ke[u]) if (v != par) DFS(v, u, id);
}
void Sub2(){
    int s = 0;
    for (int i=1; i<=n; ++i) if (ke[i].size() == 3) s = i;
    bool used[4];
    for (int i=1; i<=3; ++i) DFS(ke[s][i-1], s, i), used[i] = 0;
    int cnt = 0;
    if (red.size())
        for (auto x : red) if (x != s) cnt += (used[dd[x]] == 0), used[dd[x]] = 1;
    if (red.size()>= 2) cout << (cnt > 2 ? 2 : 1) << "\n";
    else cout << 0 << "\n";
    for (int x, i=1; i<=q; ++i){
        cin >> x;
        if (!c[x]){
            c[x] = 1; red.pb(x);
            if (x != s) cnt += (used[dd[x]] == 0), used[dd[x]] = 1;
        }
        if (red.size() >= 2) cout << (cnt > 2 ? 2 : 1) << "\n";
        else cout << 0 << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    Input();
    int cnt = 0;
    for (int i=1; i<=n; ++i) cnt += (ke[i].size() <= 2);
    if (cnt == n) Sub1();
    if (cnt == n-1) Sub2();
    //Init();
    //Solve();
    return 0;
}
