#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

int n, m, l, k;
vector<int> v[100005];
vector<pii> adj[100005];
vector<ll> d[15];

void dijkstra(int i, vector<ll> &d)
{
    d.resize(n+5, 1e18);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    d[i] = 0;
    pq.push(pii(d[i], i));
    while(!pq.empty()){
        ll u = pq.top().second, w = pq.top().first;
        pq.pop();
        if(w != d[u]) continue;
        for(pii v: adj[u]){
            if(d[v.first] > w + v.second){
                d[v.first] = w + v.second;
                pq.push(pii(d[v.first], v.first));
            }
        }
    }
}

int main()
{
    freopen("DHAKA.INP", "r", stdin);
    freopen("DHAKA.OUT", "w", stdout);
    cin >> n >> m >> k >> l;

    for(int i = 1; i <= n; i++){
        int s; cin >> s;
        for(int j = 1; j <= s; j++){
            int x; cin >> x;
            v[i].push_back(x);
        }
    }

    for(int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back(pii(y, w));
        adj[y].push_back(pii(x, w));
    }

    if(l == 0){
        dijkstra(1, d[1]);
        cout << (d[1][n] == 1e18? -1: d[1][n]);
    }
    else if(l == 1 && k <= 1){
        ll res = 1e18;
        dijkstra(1, d[1]);
        dijkstra(n, d[2]);
        for(int i = 1; i <= n; i++){
            if(v[i].size() != 0){
                res = min(res, d[1][i] + d[2][i]);
            }
        }
        cout << (res == 1e18? -1: res);
    }
    else cout << "-1";
    return 0;
}
