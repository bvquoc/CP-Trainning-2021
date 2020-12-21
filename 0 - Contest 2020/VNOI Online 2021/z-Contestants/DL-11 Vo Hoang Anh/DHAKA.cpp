#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <deque>
#include <queue>

using namespace std;

char __;
template<typename T>
void getSigned(T &x)
{
    while (__ = getchar(), __ != '-' && (__ < '0' || __ > '9'));
    bool sign(__ == '-');
    if (sign) __ = getchar();

    x = __ - '0';
    while (__ = getchar(), __ >= '0' && __ <= '9')
        x = (x << 3) + (x << 1) + (__ - '0');

    if (sign) x = -x;
}

void file(const string FILE = "Test")
{
    freopen((FILE + ".INP").c_str(), "r", stdin);
    freopen((FILE + ".OUT").c_str(), "w", stdout);
}

template<typename T> inline void maximize(T &res, const T &val) { if (res < val) res = val; }
template<typename T> inline void minimize(T &res, const T &val) { if (res > val) res = val; }
/// ====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====

#define all(x) (x).begin(), (x).end()
typedef pair<int, int> pi;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m, k, l;
vector<vector<pi> > G;
vector<int> T;

int readGraph()
{
    cin >> n >> m >> k >> l;

    T.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        int s;
        getSigned(s);

        for (int j = 0; j < s; ++j)
        {
            int x;
            getSigned(x);

            T[i] |= (1 << (x - 1));
        }
    }

    G.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        getSigned(u);
        getSigned(v);
        getSigned(w);

        G[u].push_back(pi(v, w));
        G[v].push_back(pi(u, w));
    }
}

struct Node
{
    ll d;
    int u;
    int mask;
    Node (int u, ll d, int mask)
    : u(u), d(d), mask(mask) {}

    bool operator < (const Node &other) const
    {
        return d > other.d;
    }
};

vector<vector<ll> > dist;
void dijkstra(int s = 1)
{
    dist.assign(n + 1, vector<ll>(1 << k, +LINF));
    dist[s].assign(1 << k, 0);

    priority_queue<Node> S;
    S.push(Node(s, 0, 0));
    while (S.size())
    {
        ll d = S.top().d;
        int u = S.top().u;
        int mask = S.top().mask;
        S.pop();

        for (const pi &e : G[u])
        {
            int v = e.first;
            int w = e.second;
            int newmask = mask | T[v];
            if (dist[v][newmask] > d + w)
            {
                dist[v][newmask] = d + w;
                S.push(Node(v, dist[v][newmask], newmask));
            }
        }
    }
}

int main()
{
    file("DHAKA");
    readGraph();
    dijkstra();

    ll res = +LINF;
    int lim = (1 << k);
    for (int mask = 0; mask < lim; ++mask)
        if (__builtin_popcount(mask) >= l)
            minimize(res, dist[n][mask]);

    cout << (res >= +LINF ? -1 : res);
    return 0;
}

/*
6 6 2 2
0
1 1
0
1 1
1 1
0
1 2 1
2 3 2
1 4 2
4 5 2
5 6 1
3 6 1


-1
*/

/*
6 6 2 2
0
1 1
0
1 1
1 2
0
1 2 1
2 3 2
1 4 2
4 5 2
5 6 1
3 6 1


5
*/

/*
6 6 2 2
0
1 1
0
0
1 2
0
1 2 1
2 3 2
1 4 2
4 5 2
5 6 1
3 6 1


6
*/
