/*          _
         __(.)< (cocc)
        \____)
    ~~~~~~~~~~~~~~~~
*/

#include <bits/stdc++.h>

#define FASTCIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define DEBUG freopen("_inp.inp", "r", stdin);
#define FILE(name) freopen(name".inp","r", stdin); freopen(name".out", "w", stdout);
#define runTime(num) cout << "\nTime: " << fixed << setprecision(num) << (double)(clock() - time)/CLOCKS_PER_SEC << "s\n";

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, b, a) for (int i = b; i >= a; i--)
#define PB push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define BIT(x) (1LL << (x))
#define GET(S, x) ((S >> x) & 1LL)

#define INF (int)(1e9+7)
#define LLINF (ll)(1e18+7)
#define N (ll)(5e5+5)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, q;
int a[N];

vi g[N];
int par[N];
int h[N];
int nChild[N];
int cntLf = 0;
int lf[N];
int full = 0;

int nChain = 0;
int nPos = 0;
int head[N];
int ind[N];
int pos[N];
int bck[N];

int bit[N];
int sPnt;
vector<pi> go;

void dfs(int u, int p) {
    par[u] = p;
    nChild[u] = 1;
    int leaf = 1;
    for (auto v : g[u]) if (v != p) {
        leaf = 0;
        h[v] = h[u] + 1;
        dfs(v, u);
        nChild[u] += nChild[v];
    }
    lf[u] = leaf;
    full += leaf;
}

void upd(int i, int k) {
    for (i; i < N; i += i & (-i)) {
        bit[i] += k;
    }
}

int sum(int i) {
    int res = 0;
    for (i; i > 0; i -= i & (-i)) {
        res += bit[i];
    }
    return res;
}

int get(int l, int r) {
    return sum(r) - sum(l-1);
}

void hld(int u) {
    if (head[nChain] == 0) head[nChain] = u;
    ind[u] = nChain;
    pos[u] = ++nPos;
    bck[nPos] = u;

    int mxv = 0;

    for (auto v : g[u]) if (v != par[u]) {
        if (mxv == 0 || nChild[mxv] < nChild[v]) {
            mxv = v;
        }
    }
    if (mxv != 0) hld(mxv);
    for (auto v : g[u]) if (v != par[u] && v != mxv) {
        go.PB({sPnt, nPos});
        nChain++;
        sPnt = nPos + 1;
        hld(v);
    }
}

void getResult() {
    int cnt = 0;
    for (auto v : go) {
        int l = v.fi;
        int r = v.se;
        if (get(l, r) > 0) cnt++;
    }
    //cout << cnt << "\n";
    //cout << cntLf << " LF \n";
    //FOR(i, 1, n) cout << a[i] << ' ';
    int res = (cnt + 1)/2;
    if (cntLf == full && full % 2 == 0) res += 1;
    cout << res << "\n";
}

int main()
{
    auto time = clock();
    FASTCIN
    //DEBUG
    FILE("SOCKS")

    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> a[i];
    }
    FOR(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].PB(v);
        g[v].PB(u);
    }

    dfs(1, 0);
    sPnt = 1;

    hld(1);
    go.PB({sPnt, nPos});
    FOR(i, 1, n) {
        if (a[i] != 0) upd(pos[i], 1);
        if (a[i] != 0 && lf[i]) cntLf++;
    }
    getResult();
    FOR(i, 1, q) {
        int x;
        cin >> x;
        a[x] = 1 - a[x];
        int tmp = a[x] ? 1 : -1;
        if (tmp == 1 && lf[x]) cntLf++;
        else if (tmp == -1 && lf[x]) cntLf--;
        upd(pos[x], tmp);
        getResult();
    }

    //FOR(i, 1, n) cout << ind[i] << ' ';

    //runTime(5);
    return 0;
}


