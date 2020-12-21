#include <bits/stdc++.h>
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define pb push_back
#define pii pair<int,int>
#define ppi pair<pii,int>
#define fi first
#define se second
#define bit(x,i) ((x>>i)&1)
#define onbit(x,i) (x|(1<<i))
using namespace std;

const int N = 1e5+5;

int n, m, k, l, A[N];
vector<pii> ke[N];
int d[N][35];

main()
{
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> l;
    forinc(i,1,n)
    {
        int s; cin >> s;
        while(s--)
        {
            int a; cin >> a;
            A[i] = onbit(A[i], a-1);
        }
    }
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].pb({v, w});
        ke[v].pb({u, w});
    }
    memset(d,127,sizeof d);
    int inf = d[0][0];
    priority_queue<ppi,vector<ppi>,greater<ppi> > heap;
    heap.push({{d[1][A[1]]=0, A[1]}, 1});
    while(!heap.empty())
    {
        int dmin = heap.top().fi.fi;
        int mask = heap.top().fi.se;
        int u = heap.top().se;
        heap.pop();
        if(u == n && __builtin_popcount(mask) >= l)
            return cout << dmin, 0;
        if(dmin > d[u][mask]) continue;
        for(pii i : ke[u])
        {
            int v = i.fi, c = i.se + dmin;
            int _mask = (mask | A[v]);
            if(d[v][_mask] > c) heap.push({{d[v][_mask] = c, _mask}, v});
        }
    }
    cout << -1;
}
