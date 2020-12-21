#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair< long long, int >;
using pii = pair< int, int >;

struct stt {
    int u, mask;
    ll d;
    bool operator () (stt x, stt y) {
        return x.d > y.d;
    }
};

const int N = 1e5 + 7;
int n, m, k, l;
int mask[N];
vector< pii > g[N];
ll d[N][35];


bool _digit(char c) {
    return '0' <= c && c <= '9';
}

ll _read() {
    char c;
    ll val = 0;

    while (!_digit(c = getchar()));
    do {
        val = val * 10 + c - '0';
    } while (_digit(c = getchar()));
    return val;
}


void _dijkstra() {
    priority_queue< stt, vector< stt >, stt > q;
    q.push({1, mask[1], 0});

    for (int i = 1; i <= n; ++i)
        fill(d[i], d[i] + 32, 1e18);
    d[1][ mask[1] ] = 0;
    while (!q.empty()) {
        int u = q.top().u, mask_u = q.top().mask;
        ll d_u = q.top().d;
        q.pop();

        if (d_u != d[u][mask_u]) continue;

        for (pii v : g[u]) {
            int nmask = mask_u | mask[v.first];
            if (d[v.first][nmask] > d[u][mask_u] + v.second) {
                d[v.first][nmask] = d[u][mask_u] + v.second;
                q.push({v.first, nmask, d[v.first][nmask]});
            }
        }
    }
}


int main()
{
//    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);

    n = _read(); m = _read(); k = _read(); l = _read();
    for (int i = 1; i <= n; ++i) {
        int si = _read(), ai;
        for (int j = 1; j <= si; ++j) {
            ai = _read();
            mask[i] |= 1 << (ai - 1);
        }
    }
    for (int i= 1; i <= m; ++i) {
        int u = _read(), v = _read(), w = _read();
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    _dijkstra();

    ll res = 1e18;
    for (int i = 0; i < 32; ++i)
        if (__builtin_popcount(i) >= l)
            res = min(res, d[n][i]);

    if (res == 1e18)
        res = -1;
    cout << res;

    return 0;
}
