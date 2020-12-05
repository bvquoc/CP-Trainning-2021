/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, adj, b) for(int i=(adj); i<=(b); i++)
#define FORD(i, adj, b) for(int i=(adj); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define sz(adj) (int(adj.size()))
#define BIT(adj, i) (((adj) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(adj, i) ((adj) | MASK(i))
#define turnOFF(adj, i) ((adj) & (~MASK(i)))
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
#define sqr(x) ((x)*(x))
#define endl '\n'
// #define int long long
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    }
    return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    }
    return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

/*
(\_/)
( •_•)
/ >?? */

const int N = 1003;
int n, m, t_max, w[N];
int res[N];
vector <int> adj[N], visited;
bool mark[N];

void Grrr() {
    priority_queue < ii, vector<ii>, greater<ii> > q;
	q.push(ii(0,1));
	mark[1] = true;
	while(q.size()) {
        visited.clear();
		int t = q.top().first;
		if (t > t_max) break;
		while(q.size() && q.top().first == t) {
			int u = q.top().second; q.pop();
			res[u]++;
			visited.push_back(u);
            for (int v : adj[u]) if (!mark[v]) {
                mark[v] = true;
                q.push(ii(t + w[v], v));
            }
		}
        for (int x: visited) mark[x] = false;
	}
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("DOG.INP","r",stdin);
    freopen("DOG.OUT","w",stdout);
    #endif
    cin >> n;
    FOR(i,1,n) cin >> w[i];
    cin >> m;
    REP(i,m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cin >> t_max;

    Grrr();

    FOR(i,1,n) cout << res[i] << endl;

    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}