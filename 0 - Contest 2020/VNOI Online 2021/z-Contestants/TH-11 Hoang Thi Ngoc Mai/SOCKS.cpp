#include <bits/stdc++.h>

using namespace std;

#define N 500005

int n, q, p[N];
vector < int > a[N];

void read()
{
    cin >> n >> q;
    int u, v;
    for(int i = 1; i <= n; i ++)
        cin >> p[i];
    for(int i = 1; i <= n - 1; i ++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void solve()
{
    int x, cnt = 0;
    if(p[x] == 0)
        p[x] = 1;
    for(int i = 1; i <= n; i ++)
        if(p[i] == 1)
            cnt ++;
    cout << cnt - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SOCKS.INP", "r", stdin);
    freopen("SOCKS.OUT", "w", stdout);
    read();
    while(q --)
    {
        solve();
    }
    return 0;
}
