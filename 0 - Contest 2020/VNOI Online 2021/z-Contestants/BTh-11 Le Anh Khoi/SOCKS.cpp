#include <bits/stdc++.h>

using namespace std;

int n, q, deg[500005], sub = -1, cnt = 0, a[500005], best, res[5];
vector<int> adj[500005];

bool dfs(int u, int p)
{
    if(a[u] == 1) return 1;
    for(int v: adj[u]){
        if(v != p)
            return(v, u);
    }
}

int main()
{
    freopen("SOCKS.INP", "r", stdin);
    freopen("SOCKS.OUT", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt += a[i];
    }
    for(int i = 1; i <= n-1; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++; deg[y]++;
        if(deg[x] == 3) best = x;
        if(deg[y] == 3) best = y;
    }

    sort(deg+1, deg+1+n);
    if(deg[n] <= 2){
        cout << (cnt>=2) << "\n";
        for(int i = 1; i <= q; i++){
            int x; cin >> x;
            if(a[x] == 1){
                cnt--;
                a[x] = 0;
            }
            else{
                cnt++;
                a[x] = 1;
            }
            cout << (cnt>=2) << "\n";
        }
    }
    else if(deg[n] <= 3 && deg[n-1] <= 2){
        cnt = 0;
        for(int i = 0; i < 3; i++)
            cnt += dfs(adj[best][i], best);
        cout << cnt << "\n";
        for(int i = 1; i <= q; i++){
            int x; cin >> x;
            if(a[x] == 1) a[x] = 0;
            else a[x] = 1;
            cnt = 0;
            for(int i = 0; i < 3; i++){
                cnt += dfs(adj[best][i], best);
            }
            cout << (cnt == 0? cnt: cnt-1) << "\n";
        }
    }
    return 0;
}
