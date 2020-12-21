#include <bits/stdc++.h>
#define debug(x) cerr << #x << "=" << x << endl;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define task "DHAKA"
using namespace std;
const int MaxN = 100001;
const long long oo = 1e18;
int n, m, k, l, x[11], e[11];
long long d1[MaxN], dn[MaxN], d[MaxN], a[11][MaxN], ans = oo;
vector<int> t[MaxN], only;
set<int> melon;
vector<pair<int, long long>> f[MaxN];
void dijkstra()
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for (int i=1; i<=n; i++)
    {
        d[i] = oo;
    }
    d[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        long long c = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d[u] != c) continue;
        for (int i=0; i<f[u].size(); i++)
        {
            int v = f[u][i].first;
            long long w = f[u][i].second;
            if (d[v] > d[u]+w)
            {
                d[v] = d[u]+w;
                pq.push({d[v], v});
            }
        }
    }
}
void dijkstra1()
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for (int i=1; i<=n; i++)
    {
        d1[i] = oo;
    }
    d1[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        long long c = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d1[u] != c) continue;
        for (int i=0; i<f[u].size(); i++)
        {
            int v = f[u][i].first;
            long long w = f[u][i].second;
            if (d1[v] > d1[u]+w)
            {
                d1[v] = d1[u]+w;
                pq.push({d1[v], v});
            }
        }
    }
}
void dijkstran()
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for (int i=1; i<=n; i++)
    {
        dn[i] = oo;
    }
    dn[n] = 0;
    pq.push({0, n});
    while (!pq.empty())
    {
        long long c = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (dn[u] != c) continue;
        for (int i=0; i<f[u].size(); i++)
        {
            int v = f[u][i].first;
            long long w = f[u][i].second;
            if (dn[v] > dn[u]+w)
            {
                dn[v] = dn[u]+w;
                pq.push({dn[v], v});
            }
        }
    }
}
void check()
{
    if (x[1]==0 || x[n]==0) return;
    int cnt = 0;
    for (int i=1; i<=n; i++)
    {
        if (x[i] == 1) e[++cnt] = i;
    }
//    for (int i=1; i<=cnt; i++)
//    {
//        cout << e[i] << " ";
//    }
//    cout << '\n';
    do
    {
//        for (int i=1; i<=cnt; i++)
//        {
//            cout << e[i] << " ";
//        }
//        cout << '\n';
//        long long tmp = 0;
//        for (int i=1; i<cnt; i++)
//        {
//            tmp += a[e[i]][e[i+1]];
//        }
//        cout << tmp << '\n';
        bool has_road = true;
        melon.clear();
        long long tmp = 0;
        for (int i=1; i<cnt; i++)
        {
            if (a[e[i]][e[i+1]] == 0)
            {
                has_road = false;
                break;
            }
            tmp += a[e[i]][e[i+1]];
        }
//        cout << tmp << " ";
        if (tmp > ans) continue;
        if (!has_road) continue;
        for (int i=1; i<=cnt; i++)
        {
            for (int j=0; j<t[e[i]].size(); j++)
            {
                melon.insert(t[e[i]][j]);
            }
        }
        if (melon.size() >= l)
        {
            ans = min(ans, tmp);
//            if (ans > tmp)
//            {
//                for (int i=1; i<=cnt; i++)
//                {
//                    cout << e[i] << " ";
//                }
//                cout << "      " << melon.size();
//                cout << '\n';
//            }
        }
    }
    while (next_permutation(e+2, e+cnt));
}
void backtrack(int i)
{
    for (int j=0; j<=1; j++)
    {
        x[i] = j;
        if (i == n) check();
        else backtrack(i+1);
    }
}
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> l;
    if (l == 0)
    {
        for (int i=1; i<=n; i++)
        {
            int tmp;
            cin >> tmp;
            for (int j=1; j<=tmp; j++)
            {
                int tmp1;
                cin >> tmp1;
                t[i].push_back(tmp1);
            }
        }
        for (int i=1; i<=m; i++)
        {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            f[u].push_back({v, w});
            f[v].push_back({u, w});
        }
        dijkstra();
        if (d[n] != oo) cout << d[n];
        else cout << -1;
        return 0;
    }
    if (k == 1)
    {
        if (l > k)
        {
            cout << -1;
            return 0;
        }
        for (int i=1; i<=n; i++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
            {
                int tmp1;
                cin >> tmp1;
                only.push_back(i);
            }
        }
        for (int i=1; i<=m; i++)
        {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            f[u].push_back({v, w});
            f[v].push_back({u, w});
        }
        dijkstra1();
        dijkstran();
//        for (int i=1; i<=n; i++)
//        {
//            cout << d1[i] << " " << dn[i] << '\n';
//        }
        for (int i=0; i<only.size(); i++)
        {
            ans = min(ans, d1[only[i]]+dn[only[i]]);
        }
        if (ans != oo) cout << ans;
        else cout << ans;
        return 0;
    }
    if (n <= 10)
    {
        for (int i=1; i<=n; i++)
        {
            int tmp;
            cin >> tmp;
            for (int j=1; j<=tmp; j++)
            {
                int tmp1;
                cin >> tmp1;
                t[i].push_back(tmp1);
            }
        }
        for (int i=1; i<=m; i++)
        {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            a[u][v] = a[v][u] = w;
        }
//        for (int i=1; i<=n; i++)
//        {
//            if (!t[i].empty())
//            {
//                cout << i << " ";
//                for (int j=0; j<t[i].size(); j++)
//                {
//                    cout << t[i][j] << " ";
//                }
//                cout << '\n';
//            }
//        }
//        for (int i=1; i<=n; i++)
//        {
//            for (int j=1; j<=n; j++)
//            {
//                cout << a[i][j] << " ";
//            }
//            cout << '\n';
//        }
        backtrack(1);
        if (ans != oo) cout << ans;
        else cout << -1;
        return 0;
    }
    cout << -1;
#ifdef dungctb
    cerr << "Time collapse : " << fixed << setprecision(3) << 1.000*clock()/CLOCKS_PER_SEC;
#endif // dungctb

    return 0;
}
