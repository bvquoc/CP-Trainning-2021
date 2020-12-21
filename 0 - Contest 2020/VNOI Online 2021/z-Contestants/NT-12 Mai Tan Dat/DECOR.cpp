#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair< int, int >;


const int N = 5e5;
int n, m, k;
int resl, resr = -1;
int glow[N];
vector< int > g[N];


bool _digit(char c) {
    return '0' <= c && c <= '9';
}

int _read() {
    char c;
    ll val = 0;

    while (!_digit(c = getchar()));
    do {
        val = val * 10 + c - '0';
    } while (_digit(c = getchar()));
    return val;
}


void _sub12() {
    int glowstt[N];
    for (int i = 1; i <= n; ++i)
        glowstt[i] = glow[i];

    int l = 1, r = 0, nlight = k;
    for (; r < n; ++l) {
        if (glowstt[l - 1] == 2) ++nlight;

        r = max(r, l - 1);
        while (r < n && (glowstt[r + 1] || nlight)) {
            ++r;
            if (!glowstt[r]) {
                glowstt[r] = 2;
                --nlight;
            }
        }
        if (r - l > resr - resl) {
            resl = l;
            resr = r;
        }
    }
}



int root[N];
void _dfs34(int u, int curroot) {
    root[u] = curroot;
    for (int v : g[u])
        if (!root[v]) {
            _dfs34(v, curroot);
            glow[u] += glow[v];
        }
}

void _sub34() {
    for (int i = 1; i <= n; ++i)
        if (!root[i])
            _dfs34(i, i);


    int glowstt[N];
    fill(glowstt, glowstt + n + 1, 0);
    glowstt[0] = -1;

    int l = 1, r = 0, nlight = k;
    for (; r < n; ++l) {
        if (glowstt[l - 1] == 0) ++nlight;
        else ++glow[ root[l - 1] ];

        r = max(r, l - 1);
        while (r < n && (glow[ root[r + 1] ] || nlight)) {
            ++r;
            if (glow[ root[r] ]) {
                glowstt[r] = root[r];
                --glow[ root[r] ];
            }
            else
                --nlight;
        }
        if (r - l > resr - resl) {
            resl = l;
            resr = r;
        }
    }
}

int main()
{
    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);

    n = _read(); m = _read(); k = _read();
    char c;
    while (!_digit(c = getchar()));
    for (int i = 1; i <= n; ++i) {
        glow[i] = c - '0';
        c = getchar();
    }
    for (int i = 1; i <= m; ++i) {
        int u = _read(), v = _read();
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (m == 0)
        _sub12();
    else
        _sub34();


    if (resl <= resr)
        cout << resl << ' ' << resr;
    else
        cout << -1;


    return 0;
}

