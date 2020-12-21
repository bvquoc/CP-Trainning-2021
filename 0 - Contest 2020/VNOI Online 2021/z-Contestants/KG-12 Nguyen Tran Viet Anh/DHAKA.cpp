#define TASK "DHAKA"
#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define ENDL "\n"
using namespace std;

const int MAX = 5e5+6;
const int MMSK = (1 << 5)+2;
const int MX = 1e17;

vector<ii> g[MAX];
int d[MAX][MMSK], s[MAX];
int M[MAX], n , m, res=  MX, k,l;

void Dijkstra(){
    int MSK = 1 << k;
    for(int i =1; i<=n; i++) {
        for(int j=0; j<MSK; j++){
            d[i][j] = MX;
        }
    }
    d[1][0] = 0;
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    pq.push(iii(0, ii(1,0)));

    while (!pq.empty()){
        int u = pq.top().se.fi, mask = pq.top().se.se, du = pq.top().fi;
        pq.pop();
        if (d[u][mask] != du) continue;
        for(int i=0; i < g[u].size(); i++){
            int v = g[u][i].se, uv = g[u][i].fi;
            int newMask = mask | M[v];
            if (d[u][mask] + uv < d[v][newMask]){
                d[v][newMask] = du + uv;
                pq.push(iii(du + uv, ii(v, newMask)));
            }
        }
    }
    for(int i=0; i < MSK; i++){
        if (__builtin_popcount(i)>=l) {
            res = min(res, d[n][i]);
        }
    }
    if (res >= MX) cout << -1;
    else cout << res;
}

signed main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	#ifndef ONLINE_JUDGE
	    //freopen("input.txt","r",stdin);
		freopen(TASK".INP","r", stdin);
		freopen(TASK".OUT","w", stdout);
	#endif

    cin >> n >> m >> k >> l;
    for(int i=1; i<=n ;i++){
        cin >> s[i];
        for(int j=1; j<=s[i]; j++){
            int x;
            cin >> x;
            M[i]|= 1 << (x-1);
        }
    }
    for(int i=1; i<=m; i++){
        int u , v, w;
        cin >> u >> v >> w;
        g[u].push_back(ii(w, v));
        g[v].push_back(ii(w, u));
    }

    Dijkstra();
	return 0;
}
