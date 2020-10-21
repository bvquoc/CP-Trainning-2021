// http://lqdoj.edu.vn/problem/lexipath/
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 100005;
int n, m, s, t;
vector <int> adj[N];
int trace[N]; bool mark[N];
vector <int> lexipath;

void dfs(int u, int t) {
    mark[u] = true;
    if (mark[t]) return;
    for (int v: adj[u]) {
        if (!mark[v]) {
            trace[v] = u;
            dfs(v,t);
        }
    }
}

vector<int> getPath(int t) {
    vector <int> ans;
    ans.push_back(t);
    int X = t;
    while (trace[X] != X) {
        ans.push_back(trace[X]);
        X = trace[X];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

signed main(void) {
    FastIO;
    freopen("lexipath.inp","r",stdin);
    freopen("lexipath.out","w",stdout);
    cin >> n >> m >> s >> t;
    FOR(i,1,m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FOR(i,1,n) {
        trace[i] = i;
        sort(adj[i].begin(),adj[i].end()); 
    }
    dfs(s,t);
    lexipath = getPath(t);
    for (int x: lexipath) cout << x << ' ';
    return 0;
}