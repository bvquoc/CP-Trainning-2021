//
#include <bits/stdc++.h>

using namespace std;
#define task        "SOCKS"
#define maxn        500005
#define maxm
#define maxs
#define p_b         push_back
#define fs          first
#define sc          seconcl
#define oo          2000000000
#define mocl         998244353
#define ll          long long

typedef pair <int, int> II;
typedef pair <II, int> III;

int n, q;
vector <int> g[maxn];
int a[maxn], cl[maxn], deg[maxn], leaves[maxn], sl[5];
int root;
int id = 0;

void sub1() {
    int cnt = 0;
    for(int i=1; i<=n; ++i) if(a[i] == 1) ++cnt;
    if (cnt <= 1) cout << 0 << '\n';
    else cout << 1<< '\n';
    for (int i = 1; i <= q; ++i) {
        int u;
        cin >> u;
        if(a[u] == 1) {
            --cnt;
            a[u] = 0;
        }
        else {
            ++cnt;
            a[u] = 0;
        }
        if (cnt <= 1) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
}

void DFS (int u) {
    cl[u] = 1;
    leaves[u] = id;
    for(auto &v : g[u]) {
        if (cl[v] == 0) DFS(v);
    }
}

void sub2() {
    for (auto & u : g[root]) {
        ++id;
        DFS (u);
    }
    for (int i = 1; i <= n; ++i) if (a[i] == 1) ++sl[leaves[i]];
    if (sl[1] > 0 && sl[2] > 0 && sl[3] > 0) cout << 2;
    else if (sl[1] == 0 && sl[2] == 0 && sl[3] == 0) cout << 0;

    else if (sl[1] == 0 && sl[2] > 0 && sl[3] > 0) cout << 1;
    else if (sl[1] > 0 && sl[2] == 0 && sl[3] > 0) cout << 1;
    else if (sl[1] > 0 && sl[2] > 0 && sl[3] == 0) cout << 1;

    else if (sl[1] == 1 && sl[2] == 0 && sl[3] == 0) cout << 0;
    else if (sl[1] == 0 && sl[2] == 1 && sl[3] == 0) cout << 0;
    else if (sl[1] == 0 && sl[2] == 0 && sl[3] == 1) cout << 0;

    else if (sl[1] > 1 && sl[2] == 0 && sl[3] == 0) cout << 1;
    else if (sl[1] == 0 && sl[2] > 1 && sl[3] == 0) cout << 1;
    else if (sl[1] == 0 && sl[2] == 0 && sl[3] > 1) cout << 1;
    cout << '\n';
    for (int i = 1; i <= q; ++i) {
        int u;
        cin >> u;
        if(a[u] == 0) {
            a[u] = 1;
            ++sl[leaves[u]];
        } else {
            a[u] = 0;
            --sl[leaves[u]];
        }
        if (sl[1] > 0 && sl[2] > 0 && sl[3] > 0) cout << 2;
        else if (sl[1] == 0 && sl[2] == 0 && sl[3] == 0) cout << 0;

        else if (sl[1] == 0 && sl[2] > 0 && sl[3] > 0) cout << 1;
        else if (sl[1] > 0 && sl[2] == 0 && sl[3] > 0) cout << 1;
        else if (sl[1] > 0 && sl[2] > 0 && sl[3] == 0) cout << 1;

        else if (sl[1] == 1 && sl[2] == 0 && sl[3] == 0) cout << 0;
        else if (sl[1] == 0 && sl[2] == 1 && sl[3] == 0) cout << 0;
        else if (sl[1] == 0 && sl[2] == 0 && sl[3] == 1) cout << 0;

        else if (sl[1] > 1 && sl[2] == 0 && sl[3] == 0) cout << 1;
        else if (sl[1] == 0 && sl[2] > 1 && sl[3] == 0) cout << 1;
        else if (sl[1] == 0 && sl[2] == 0 && sl[3] > 1) cout << 1;
        cout << '\n';
    }
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].p_b (v);
        g[v].p_b (u);
        ++deg[u];
        ++deg[v];
    }
    int check = 0;
    for (int u = 1; u <= n; ++u) {
        if (deg[u] >= 3) {
            root = u;
            sub2();
            return 0;
        }
        else if (deg[u] == 1) ++check;
    }
    sub1();
}
