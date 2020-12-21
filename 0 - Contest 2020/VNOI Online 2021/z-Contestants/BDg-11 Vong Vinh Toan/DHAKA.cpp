#include <bits/stdc++.h>
#define BIT(x, i) (((x)>>(i))&1)
#define MASK(i) (1<<(i))
#define next _next

using namespace std;
const int N = 1e5+7;
const long long oo = 4e18;

struct state
{
    int u, mask;
};

struct edge
{
    int v;
    long long w;
};

int n, m, k, l;
int type[N], id[N][MASK(5)], cnt = 0;
vector<edge> A[N];
state State[N*MASK(5)];
long long F[N*MASK(5)], ans = oo;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);
    cin>>n>>m>>k>>l;
    for(int i=1; i<=n; i++)
    {
        int num, x; cin>>num;
        while(num--)
        {
            cin>>x;
            type[i] |= MASK(x-1);
        }
    }
    for(int i=1; i<=m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        A[u].push_back({v, w});
        A[v].push_back({u, w});
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<MASK(k); j++)
        {
            id[i][j] = ++cnt;
            F[id[i][j]] = oo;
            State[cnt] = {i, j};
        }
    }
    F[id[1][type[1]]] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
    Q.push({F[id[1][type[1]]], id[1][type[1]]});
    while(Q.size())
    {
        pair<long long, int> tmp = Q.top();
        Q.pop();
        if(F[tmp.second] != tmp.first) continue;
        state x = State[tmp.second];
        for(edge e: A[x.u])
        {
            int next = id[e.v][x.mask | type[e.v]];
            if(F[next] > tmp.first+e.w)
            {
                F[next] = tmp.first+e.w;
                Q.push({F[next], next});
            }
        }
    }
    for(int j=0; j<MASK(k); j++)
    {
        if(__builtin_popcount(j)>=l) ans = min(ans, F[id[n][j]]);
    }
    if(ans >= oo) cout<<-1;
    else cout<<ans;
    return 0;
}
