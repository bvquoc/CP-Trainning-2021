#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int>    vi;
typedef pair<int, int> pi;
typedef vector<ll>     vll;
typedef pair<ll, int>  pli;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

template<typename T> void maximize(T &res, T val) { if (res < val) res = val; }
template<typename T> void minimize(T &res, T val) { if (res > val) res = val; }

int n, pos;
vector<vi> a;
vector<int> used;
vector<int> match;
bool dfs(int u, int lim)
{
    if (used[u] == pos) return false;
    used[u] = pos;

    for (int v = 1; v <= n; ++v)
    {
        if (a[u][v] < lim) continue;
        if (match[v] == 0 || dfs(match[v], lim))
        {
            match[v] = u;
            return true;
        }
    }

    return false;
}

bool solve(int lim)
{
    vector<int> order(n);
    iota(all(order), 1);
    random_shuffle(all(order));
    
    used.assign(n + 1, 0);    
    match.assign(n + 1, 0);

    pos = 0;    
    for (int x : order)
    {
        ++pos;
        bool ok = dfs(x, lim);
        if (!ok) return false;
    }

    return true;
}

int main()
{
    srand(time(NULL));
    cin >> n;

    a.assign(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    int res = 0;
    for (int l = 0, r = +1e9; l <= r; )
    {
        int m = (l + r) >> 1;
        if (solve(m))
        {
            res = m;
            l = m + 1;
        }
        else 
            r = m - 1;
    }

    cout << res;
    return 0;
}