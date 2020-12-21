#include <algorithm>
#include <iostream>
#include <cstdio>
#include <deque>
#include <queue>
#include <cmath>
#include <numeric>
#include <cstring>

using namespace std;

void file(const string FILE = "Test")
{
    freopen((FILE + ".INP").c_str(), "r", stdin);
    freopen((FILE + ".OUT").c_str(), "w", stdout);
}

char __;
template<typename T>
void getUnsign(T &x)
{
    while (__ = getchar(), __ < '0' || __ > '9');

    x = __ - '0';
    while (__ = getchar(), __ >= '0' && __ <= '9')
        x = (x << 3) + (x << 1) + (__ - '0');
}

template<typename T> inline void maximize(T &res, const T &val) { if (res < val) res = val; }
template<typename T> inline void minimize(T &res, const T &val) { if (res > val) res = val; }

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pi;
const int MAXN = 1e5 + 15;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

/// ====*====*====*====*====*====*====*====*====*====*====

int n, m, k, q;
vector<int> C;
vector<int> cnt;
vector<int> paint;
vector<vector<int> > G;

void dfs(int u, int p, int c)
{
    paint[u] = c;
    for (int v : G[u]) if (v != p)
        dfs(v, u, c);
}

int delta = 0;
void add(int c)
{
    if (++cnt[c] == 1)
        ++delta;
}

void rmv(int c)
{
    if (--cnt[c] == 0)
        --delta;
}

void output()
{
    if (delta <= 1)
        cout << 0 << '\n';
    else if (delta == 2)
        cout << 1 << '\n';
    else
        cout << (delta + !cnt[0]) / 2 << '\n';
}

int main()
{
    file("SOCKS");
//    file();
    cin >> n >> q;
    m = n - 1;

    C.resize(n + 1);
    for (int u = 1; u <= n; ++u)
        getUnsign(C[u]);

    G.resize(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        getUnsign(u);
        getUnsign(v);

        G[u].push_back(v);
        G[v].push_back(u);
    }

    k = 0;
    bool isT = false;
    paint.assign(n + 1, 0);
    for (int u = 1; u <= n; ++u)
    {
        if (G[u].size() == 3)
        {
            isT = true;
            for (int v : G[u])
                dfs(v, u, ++k);

            break;
        }
    }

    if (isT == false)
    {
        for (int u = 1; u <= n; ++u)
            if (C[u]) ++delta;

        cout << (delta >= 2) << '\n';
        while (q-->0)
        {
            int p;
            getUnsign(p);
            C[p] ^= 1;

            if (C[p]) ++delta;
            else      --delta;

            cout << (delta >= 2) << '\n';
        }
        return 0;
    }

    cnt.assign(n + 1, 0);
    for (int u = 1; u <= n; ++u)
        if (C[u]) add(paint[u]);

    output();
    while (q-->0)
    {
        int p;
        getUnsign(p);

        if (C[p] ^= 1)
            add(paint[p]);
        else
            rmv(paint[p]);

//        for (int u = 1; u <= n; ++u) cout << C[u] * u << ' '; cout << "| ";
        output();
    }
    return 0;
}

/*
6 6
1 0 0 0 0 1
1 2
2 3
3 4
4 5
5 6
1
6
2
3
4
5

1
0
0
0
1
1
1
*/

/*
4 16
0 0 0 0
2 1
2 3
2 4
1 2 1 3 2 4 3 1 2 3 4 2 4 2 1 3

0
1 0 0 0 | 0
1 2 0 0 | 1
0 2 0 0 | 0
0 2 3 0 | 1
0 0 3 0 | 0
0 0 3 4 | 1
0 0 0 4 | 0
1 0 0 4 | 1
1 2 0 4 | 1
1 2 3 4 | 2
1 2 3 0 | 1
1 0 3 0 | 1
1 0 3 4 | 2
1 2 3 4 | 2
0 2 3 4 | 1
0 2 0 4 | 1

*/
