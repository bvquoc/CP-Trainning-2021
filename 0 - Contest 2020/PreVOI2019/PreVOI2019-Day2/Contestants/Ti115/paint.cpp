#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair< int, int > ii;

const int inf = 1e9;

const int N = 1000000 + 5;

int n, ans[N], prf[30], pter[30], lmao[N], mx[30];

vector< int > color[30], hihi[30];

vector< ii > graph[30], state[30];

bool vis[N], used[N];

int dfs(int u, int times) {
    int it = lower_bound(graph[u].begin(), graph[u].end(), mp(times + 1, -1)) - graph[u].begin();
    if(it == graph[u].size()) return u;
    else {
        int v = graph[u][it].se, ntimes = graph[u][it].fi, res;
        if(hihi[u][it] == -1) {
            res = dfs( v, ntimes );
            hihi[u][it] = res;
        }
        else
            res = hihi[u][it];
        return res;
    }
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    freopen("paint.inp", "r", stdin);
    freopen("paint.out", "w", stdout);
    cin >> n;
    if(n <= 10000) {
        string s;
        while(n--) {
            int type;
            cin >> type;
            if(type == 1) {
                char ch;
                cin >> ch;
                s += ch;
            }
            else {
                char cha, chb;
                cin >> cha >> chb;
                if(cha == chb) continue;
                for(int i = 0; i < (int)(s.length()); i++) {
                    if(s[i] == cha)
                        s[i] = chb;
                }
            }
        }
        cout << s;
        exit(0);
    }
    for(int i = 1; i <= n; i++) {
        int type; char a, b, c;
        cin >> type;
        if(type == 1) {
            cin >> c;
            int ch = (int)( c - 'a' );
            color[ ch ].pb(i);
            lmao[i] = ch;
            ans[i] = ch;
            used[i] = 1;
        }
        else {
            cin >> a >> b;
            int cha = (int)( a - 'a' ), chb = (int)( b - 'a' );
            if(cha == chb) continue;
            mx[cha] = max(mx[cha], i);
            graph[ cha ].pb( mp( i, chb ) );
            hihi[cha].pb(-1);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(used[i] && !vis[i]) {
            int sum = dfs( lmao[i], i );
            ans[i] = sum;
            vis[i] = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(used[i])
            cout << (char)( ans[i] + 'a' );
    }
}

