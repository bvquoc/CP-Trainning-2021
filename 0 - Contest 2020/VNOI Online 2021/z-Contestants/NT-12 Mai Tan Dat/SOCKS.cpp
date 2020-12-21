#include <bits/stdc++.h>
using namespace std;
using pii = pair< int, int >;
using ll = long long;

const int N = 1e5 + 7, mod = 1e9 + 7;
int n, q, res;
bool red[N];
vector< int > g[N];

void _sub1() {
    for (int i = 1; i <= n; ++i)
        if (red[i])
            res = 1;
    cout << res << '\n';
    res = 1;
    for (int i = 1; i <= q; ++i)
        cout << res << '\n';
}


int subtree[N];
bool subtreecnt[5];
void _dfs2(int u, int s, int p) {
    subtree[u] = s;
    if (red[u])
        subtreecnt[s] = true;

    for (int v : g[u])
        if (v != p)
            _dfs2(v, s, u);
}

void _sub2() {
    int s;
    for (int i = 1; i <= n; ++i)
        if (g[i].size() == 3)
            s = i;

    for (int i = 0; i <= 2; ++i)
        _dfs2(g[s][i], i, s);
    for (int i = 0; i <= 2; ++i)
        res += subtreecnt[i];
    cout << res / 2 << '\n';
    for (int i = 1; i <= q; ++i) {
        int nred; cin >> nred;
        subtreecnt[ subtree[nred] ] = true;
        res = 0;
        for (int j = 0; j <= 2; ++j)
            res += subtreecnt[j];
        cout << res / 2 << '\n';
    }
}

void _sub3() {

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> red[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool s1 = true, s2 = true;
    int cnt3 = 0;
    for (int i = 1; i <= n ; ++i) {
        if (g[i].size() > 2)
            s1 = false;
        if (g[i].size() > 3)
            s2 = false;
        if (g[i].size() == 3)
            ++cnt3;
    }

    if (s1)
        _sub1();
    else if (s2 && cnt3 == 1)
        _sub2();
    else if (n <= 1000 && q <= 1000)
        _sub3();


    return 0;
}
