#include <bits/stdc++.h>
#define int long long
#define Task "DHAKA"
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

const int N = 1e5 + 5;

int n, m, k, l;
int a[N];
vii g[N];

void init(){
    FAST;
    READFILE;
    WRITEFILE;
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; ++i){
        int s;
        cin >> s;
        while (s--){
            int w;
            cin >> w;
            a[i] = a[i] | (1 << (w - 1));
        }
    }
    while (m--){
        int u, v, c;
        cin >> u >> v >> c;
        g[u].pb(ii(c, v));
        g[v].pb(ii(c, u));
    }
}

void Dijkstra(){
    int ans = oo;
    priority_queue < iii, viii, greater < iii > > q;
    int kk = 1 << k;
    vvi d(n + 10, vi(kk, oo));
    d[1][a[1]] = 0;
    q.push(iii(0, ii(a[1], 1)));
    while (q.size()){
        int u = q.top().Y.Y;
        int du = q.top().X;
        int state = q.top().Y.X;
        q.pop();
        if (du != d[u][state]) continue;
        if (u == n && __builtin_popcount(state) >= l) ans = min(ans, du);
        for (int i = 0; i < (int) g[u].size(); ++i){
            int v = g[u][i].Y;
            int c = g[u][i].X;
            int nstate = state | a[v];
            if (d[v][nstate] > du + c){
                d[v][nstate] = du + c;
                q.push(iii(d[v][nstate], ii(nstate, v)));
            }
        }
    }
    if (ans >= 1e15) cout << -1;
    else cout << ans;
}

signed main(){
    init();
    Dijkstra();
    return 0;
}

