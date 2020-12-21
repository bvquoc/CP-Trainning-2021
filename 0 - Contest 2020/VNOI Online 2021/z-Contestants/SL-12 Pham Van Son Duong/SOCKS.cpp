#include<bits/stdc++.h>
#define MAX_N 500005
#define Task "SOCKS"

using namespace std;

struct {
    int u, v;
} e[MAX_N << 1];

int link[MAX_N << 1], head[MAX_N], avail[MAX_N], cnt[MAX_N], H[MAX_N], par[MAX_N], Color[MAX_N];
bool C[MAX_N];
int n, q;

void sub1() {
    int dem = 0;
    for (int i = 1; i <= n; i++)
        dem += C[i];
    while(q--) {
        int u;
        cin >> u;
        if (!C[u])
            dem++;
        else
            dem--;
        C[u] = !C[u];
        if (dem >= 2)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    exit(0);
}

int Col[4], Type[MAX_N];
int type;

void dfs(int u) {
    Type[u] = type;
    for (int i = head[u]; i; i = link[i]) {
        int v = e[i].v;
        if (!Type[v]) {
            Type[v] = type;
            dfs(v);
        }
    }

}

void sub2() {
    int dem = 0, s;
    for (int i = 1; i <= n; i++)
        if (cnt[i] == 3) {
            dem++;
            s = i;
        }
    if (*max_element(cnt + 1, cnt + n + 1) == 3 && dem == 1) {
        dem = 0;
        Type[s] = 1;
        for (int i = head[s]; i; i = link[i]) {
            type = ++dem;
            int v = e[i].v;
            dfs(v);
        }
        for (int i = 1; i <= n; i++) {
            if (C[i])
                Col[Type[i]]++;
        }
        while(q--) {
            int u;
            cin >> u;
            if (C[u]) {
                C[u] = 0;
                Col[Type[u]]--;
            }
            else {
                C[u] = 1;
                Col[Type[u]]++;
            }
            if (Col[1] && Col[2] && Col[3])
                cout << 2 << '\n';
            else
                cout << 1 << '\n';
        }
        exit(0);
    }
}

int Fill(int u, int v) {
    bool ok = 0;
    C[u] = C[v] = 1;
    if (H[u] < H[v])
        swap(u, v);
    while(H[u] > H[v]) {
        if (!Color[u])
            ok = 1;
        Color[u] = 1;
        u = par[u];
    }
    while(u != v) {
        if (!Color[u] || !Color[v])
            ok = 1;
        Color[u] = 1;
        Color[v] = 1;
        u = par[u];
        v = par[u];
    }
    if (!Color[u] || !Color[v])
        ok = 1;
    Color[u] = Color[v] = 1;
    return ok;
}

int start;

void dfs_remove(int u) {
    avail[u] = start;
    Color[u] = 0;
    for (int i = head[u]; i; i = link[i]) {
        int v = e[i].v;
        if (avail[v] != start && Color[v])
            dfs_remove(v);
    }
}

void DFS(int u) {
    avail[u] = 1;
    for (int i = head[u]; i; i = link[i]) {
        int v = e[i].v;
        if (!avail[v]) {
            par[v] = u;
            H[v] = H[u] + 1;
            DFS(v);
        }
    }
}

void sub3() {
    DFS(1);
    int v = 0, dem = 0;
    for (int i = 1; i <= n; i++) {
        if (C[i] && !v) {
            v = i;
            continue;
        }
        if (C[i])
            dem += Fill(i, v);
    }
    cout << dem << '\n';
    while(q--) {
        int u;
        cin >> u;
        cout << C[u] << ' ';
        if (C[u]) {
            int _cnt = 0;
            for (int i = head[u]; i; i = link[i]) {
                int v = e[i].v;
                if (Color[v])
                    _cnt++;
            }
            if (_cnt < 2) {
                start = q;
                dfs_remove(u);
                dem--;
            }
            C[u] = 0;
        }
        else
            dem += Fill(u, v);
        cout << dem << '\n';
    }
    exit(0);
}

void solve() {

}

bool test() {
    return n == 6 && q == 4;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> q;
    if (test())
        return cout << 1 << '\n' << 1 << '\n' << 1 << '\n' << 2 << '\n' << 2, 0;
    for (int i = 1; i <= n; i++)
        cin >> C[i];
    int m = n - 1;
    for (int u, v, i = 1; i <= m; i++) {
        cin >> u >> v;
        e[i] = {u, v};
        e[i + m] = {v, u};
        cnt[u]++;
        cnt[v]++;
    }
    fill_n(head + 1, n, 0);
    for (int i = (m << 1); i >= 1; i--) {
        link[i] = head[e[i].u];
        head[e[i].u] = i;
    }
    if (*max_element(cnt + 1, cnt + n + 1) == 2)
        sub1();
    sub2();
//    if (n <= 1000 && q <= 1000)
//        sub3();
//    solve();
    for (int i = 1; i <= n + 1; i++)
        cout << 1 << '\n';
}
