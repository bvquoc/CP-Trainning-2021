#include <bits/stdc++.h>
#define Task "DHAKA"
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define FOR(i, a, b) for(int i = a; i <=b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define pii pair<int, int>
using namespace std;
const int maxn = 100005;
vector<int> vv[maxn];
vector<pii> a[maxn];
int n, m, k, l, dd[maxn], tr[maxn], c[505][505];
ll d[maxn], ans = 1e18;
void IJK(int s)
{
    fill(d + 1, d + n +1, 1e18);
    priority_queue<pair<ll, int>> pq;
    d[s] = 0;
    pq.push({-d[s], s});
    while( !pq.empty() )
    {
        int u = pq.top().S;
        ll l  = pq.top().F;
        l *= -1;
        pq.pop();
        if ( l > d[u] ) continue;
        for(int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].F;
            int w = a[u][i].S;
            if ( d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({-d[v], v});
            }
        }
    }
}
void truyvet(int t)
{
    ll tong = 0;
    int hh = 0;
    vector<int> f;
    while (t > -1)
    {
        if ( t == 1 || t == n) hh++;
        int z = tr[t];
        tong += c[t][z];
        //cout << t <<" " << vv[t].size() <<"\n";
        for(auto x : vv[t])
        {
            if ( dd[x] == 0 )
            {
                dd[x] = 1;
                f.pb(x);
            }
        }
        t = z;
    }
   // cout <<"\n";
    int dem  = 0;
    for(int x : f)
    {
        dem++;
        dd[x] = 0;
    }
    if ( dem >= l && tong < ans && hh == 2) ans = tong;
}
void DFS(int u)
{
    for(int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i].F;
        if ( tr[v] == 0)
        {
            tr[v] = u;
            if ( v == n )
            {
                truyvet(v);
            }
            else
                DFS(v);
            tr[v] = 0;
        }
    }
}
void sub4()
{
    FOR(i, 1, n)
    {
        tr[i] = -1;
        DFS(i);
        tr[i] = 0;
    }
    if ( ans == 1e18 ) ans = -1;
    cout << ans;
}
int main()
{
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL), cout.tie(NULL);
    if(fopen(Task".inp", "r"))
    {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m >> k >> l;
    FOR(i, 1, n)
    {
        int z;
        cin >> z;
        FOR(j, 1, z)
        {
            int x;
            cin >> x;
            vv[i].pb(x);
        }
        //cout << vv[i].size() <<" ";
    }
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].pb({v, w});
        a[v].pb({u, w});
        c[u][v] = c[v][u] = w;
    }
    if ( l == 0 )
    {
        IJK(1);
        if ( d[n] == 1e18)
        {
            cout <<  -1;
        }
        else cout << d[n];
        return 0;
    }
    if ( n <=100 && m <= 100)
        sub4();
	return 0;
}
