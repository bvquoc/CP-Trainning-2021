#include <bits/stdc++.h>
#define int long long
#define Task "DECOR"
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

const int N = 5e5 + 5;

int n, m, k;
string ss;
vi g[N];
int cur = 0;
int Max[N];
int lab[N];
int vs[N];
int cnt[N];

void init(){
    FAST;
    READFILE;
    WRITEFILE;
    cin >> n >> m >> k;
    cin >> ss;
    ss = ' ' + ss;
    while (m--){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void bfs(int s){
    int cnt = 0;
    queue < int > q;
    q.push(s);
    vs[s] = 1;
    while (q.size()){
        int u = q.front();
        q.pop();
        lab[u] = cur;
        if (ss[u] == '1') ++cnt;
        for (int i = 0; i < (int) g[u].size(); ++i){
            int v = g[u][i];\
            if (vs[v]) continue;
            vs[v] = 1;
            q.push(v);
        }
    }
    Max[cur] = cnt;
}

ii MAX(ii x, ii y){
    if (x.Y - x.X != y.Y - y.X){
        if (x.Y - x.X > y.Y - y.X) return x;
        return y;
    }
    if (x.X < y.X) return x;
    return y;
}

signed main(){
    init();
    for (int i = 1; i <= n; ++i){
        if (vs[i] == 0){
            ++cur;
            bfs(i);
        }
    }
    ii ans = ii(0, 0);
    for (int l = 1, r = 1; r <= n; ++r){
        if (cnt[lab[r]] < Max[lab[r]]) ++cnt[lab[r]];
        else{
            while (k == 0 && l <= r){
                if (cnt[lab[l]] > Max[lab[l]]) ++k;
                --cnt[lab[l]];
                ++l;
            }
            ++cnt[lab[r]];
            --k;
        }
        ans = MAX(ans, ii(l, r));
    }
    if (ans == ii(0, 0)) cout << -1;
    else cout << ans.X << " " << ans.Y;
    return 0;
}

