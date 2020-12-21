#include <bits/stdc++.h>
#define ii pair<long long, int>
#define iii pair<int, ii>
using namespace std;
const int oo = 1e9 + 213872;
const int maxN = 1e5 + 2;

long long d[maxN][64], b[maxN];
vector<ii> a[maxN];
long long n, m, k, l;
void dijkstra()
{
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    for(int i = 1; i <= n; i++)
    for(int j = 0; j < 32; j++)
        d[i][j] = oo;

    d[1][b[1]] = 0;
    pq.push(iii(0LL, ii(b[1], 1LL)));
    while(pq.size())
    {
        int u = pq.top().second.second;
        int du = pq.top().first;
        int bit = pq.top().second.first;
        pq.pop();
        if(du != d[u][bit]) continue;
        for(int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if(d[v][bit | b[v]] > d[u][bit] + uv){
                d[v][bit | b[v]] = d[u][bit] + uv;
                pq.push({d[v][bit | b[v]],{bit | b[v], v}});
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; i++)
    {
        b[i] = 0;
        int j, x;
        cin >> j;
        while(j--){
            cin >> x;
            b[i] = b[i] | (1 << x);
        }
    }
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    dijkstra();
    long long res = oo;
    for(int i = 0 ; i < 32; i++)
    {
        int cnt = 0, j = i;
        while(j != 0){
            if(j & 1) cnt++;
            j >>= 1;
        }
        if(cnt >= l) res = min(res, d[n][i]);
    }
    if(res != oo)
        cout<<res;
    else cout<<"-1";
}
