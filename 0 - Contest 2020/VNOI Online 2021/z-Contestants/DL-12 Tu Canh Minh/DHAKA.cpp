#include <bits/stdc++.h>
#define fname "DHAKA"
#define cerr if(0)cerr
#define bug(x) cerr << (#x) << " = " << (x) << endl
#define bug01(x) cerr << "binary(" << (#x) << ") = " << bitset<16>((x)) << endl
#define BUG cerr << "PASSED AT LINE " << __LINE__ << endl
#define ll long long
#define REP0(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define REP1(i, n) for(int i = 1, _n = (n); i <= _n; ++i)
#define REPB0(i, n) for(int i = (n) - 1; i >= 0; --i)
#define REPB1(i, n) for(int i = (n); i > 0; --i)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORB(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define ARR0(a, n) {cerr << (#a) << ": ["; REP0(i, n) cerr << ' ' << a[i] << ','; cerr << ']' << endl;}
#define ARR1(a, n) {cerr << (#a) << ": ["; REP1(i, n) cerr << ' ' << a[i] << ','; cerr << ']' << endl;}
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define LB lower_bound
#define UB upper_bound
#define X first
#define Y second

using namespace std;
template<typename T, typename V>
void bugp(const pair<T, V> &x) {cerr << '{' << x.X << ", " << x.Y << '}' << endl;}
template<typename T, typename U, typename V>
void bugpp(const pair<T, pair<U, V> > &x) {cerr << '{' << x.X << ", {" << x.Y.X << ", " << x.Y.Y << "}}" << endl;}
template<typename T>
bool maximize(T &x, const T &y) {if(x < y) {x = y; return 1;} return 0;}
template<typename T>
bool minimize(T &x, const T &y) {if(x > y) {x = y; return 1;} return 0;}
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, int> li;
typedef pair<ll, ii> lii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
const int N = 100001, K = 5;
const ll INF = (ll)1e18;
int n, k, watermelon[N];
ll d[N][1 << K];
vii G[N];

void dijkstra(int src)
{
    fill(&d[0][0], &d[0][0] + sizeof(d)/sizeof(ll), INF);
    REP0(msk, 1 << k) if((msk & watermelon[src]) == msk) d[src][msk] = 0;
    priority_queue<lii, vector<lii>, greater<lii> > pq;
    REP0(msk, 1 << k) if((msk & watermelon[src]) == msk) pq.push({0, {src, msk}});
    while(pq.size()) {
        int u = pq.top().Y.X;
        int msk = pq.top().Y.Y;
        ll du = pq.top().X;
        pq.pop();
        if(du != d[u][msk]) continue;
        int new_msk;
        for(const ii &v : G[u]) {
//            REP0(mskp, 1 << k) {
//                if((mskp & watermelon[v.Y]) == mskp) {
//                    new_msk = msk | mskp;
//                    if(minimize(d[v.Y][new_msk], du + v.X))
//                        pq.push({d[v.Y][new_msk], {v.Y, new_msk}});
//                }
//            }
            new_msk = msk | watermelon[v.Y];
            if(minimize(d[v.Y][new_msk], du + v.X))
                 pq.push({d[v.Y][new_msk], {v.Y, new_msk}});
        }
    }
}

int main()
{
	freopen(fname".INP", "r", stdin);
    freopen(fname".OUT", "w", stdout);
    //freopen("input", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
    int m, l;
    cin >> n >> m >> k >> l;
    REP1(i, n) {
        int s, a;
        cin >> s;
        while(s--) {
            cin >> a;
            watermelon[i] |= (1 << (a - 1));
        }
    }
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb({w, v});
        G[v].pb({w, u});
    }
    dijkstra(1);
    ll ans = INF;
    REP0(msk, 1 << k) if(__builtin_popcount(msk) >= l) minimize(ans, d[n][msk]);
    if(ans == INF) cout << -1;
    else cout << ans;
	return 0;
}
