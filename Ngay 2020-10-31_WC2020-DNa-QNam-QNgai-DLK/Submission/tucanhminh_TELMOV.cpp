#include <bits/stdc++.h>
#define fname "TELMOV"
#define bug(x) cerr << (#x) << " = " << (x) << endl
#define ll long long
#define REP0(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define REP1(i, n) for(int i = 1, _n = (n); i <= _n; ++i)
#define REPB0(i, n) for(int i = (n) - 1; i >= 0; --i)
#define REPB1(i, n) for(int i = (n); i > 0; --i)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORB(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define ARR0(a, n) {cerr <<(#a)<< ": ["; REP0(i, n) cerr<< ' ' << a[i] <<','; cerr<<']'<<endl;}
#define ARR1(a, n) {cerr <<(#a)<< ": ["; REP1(i, n) cerr<< ' ' << a[i] <<','; cerr<<']'<<endl;}
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
inline void bugp(const pair<T, V> &x) {cerr << '{' << x.X << ", " << x.Y << '}' << endl;}
template<typename T, typename U, typename V>
inline void bugpp(const pair<T, pair<U, V> > &x) {cerr << '{' << x.X << ", {" << x.Y.X << ", " << x.Y.Y << "}}" << endl;}
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, int> li;
typedef pair<ll, ii> lii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 10001, K = 11, INF = 2000000001;
int n;
vector<ii> G[N];

void dijkstra(int s, int d[])
{
    fill(d + 1, d + n + 1, INF);
    d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, s});
    int u, du;
    while(pq.size()) {
        u = pq.top().Y;
        du = pq.top().X;
        pq.pop();
        if(du != d[u]) continue;
        for(ii &v : G[u])
            if(d[v.Y] > du + v.X)
                pq.push({d[v.Y] = du + v.X, v.Y});
    }
}
void BFS(int s, int d[])
{
    fill(d + 1, d + n + 1, INF);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    int u;
    while(q.size()) {
        u = q.front();
        q.pop();
        for(ii &v : G[u]) {
            if(d[v.Y] > d[u] + 1) {
                d[v.Y] = d[u] + 1;
                q.push(v.Y);
            }
        }
    }
}

int main()
{
    //freopen("input", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int m, u, v, t, p, l, k;
    cin >> n >> m >> p >> l >> k;
    while(m--) {
        cin >> u >> v >> t;
        G[u].pb({t, v});
        G[v].pb({t, u});
    }
    if(!k) {
        static int d[N];
        dijkstra(1, d);
        cout << d[n];
    }
    else if(n <= 300) {
        static int dis[303][303];
        REP1(i, n) BFS(i, dis[i]);
        int C[303][303];
        memset(C, 0, sizeof C);
        REP1(i, n) for(ii &j : G[i]) C[i][j.Y] = j.X;
        static int d[K][N];
        dijkstra(1, d[0]);
        REP1(x, k) {
            fill(d[x] + 1, d[x] + n + 1, INF);
            d[x][1] = 0;
            priority_queue<ii, vector<ii>, greater<ii> > pq;
            pq.push({0, 1});
            int u, du, cost;
            while(pq.size()) {
                u = pq.top().Y;
                du = pq.top().X;
                pq.pop();
                if(du != d[x][u]) continue;
                REP1(v, n) {
                    cost = INF;
                    if(C[u][v]) cost = min(cost, du + C[u][v]);
                    if(dis[u][v] <= l) cost = min(cost, d[x - 1][u] + p);
                    if(cost != INF && d[x][v] > cost)
                        pq.push({d[x][v] = cost, v});
                }
            }
        }
        cout << d[k][n];
    }
	return 0;
}
