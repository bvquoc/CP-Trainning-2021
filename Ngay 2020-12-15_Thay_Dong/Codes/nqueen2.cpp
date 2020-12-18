#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int a[N], n; bool ok;
int col[N], row[N];
int cross[2][N + N];

bool alive(int i, int j) {
    return !row[i] && !col[j]
    && !cross[0][i + j] &&
    !cross[1][i - j + N];
}

void swit(int i, int j, int t) {
    row[i] += t; col[j] += t;
    cross[0][i + j] += t;
    cross[1][i - j + N] += t;
}

void dfs(int d) {
    if (ok) return;
    if (d == 0) {
        for (int i = 0; i < n; i++)
            cout << a[i] + 1 << ' ';
        cout << '\n'; ok = 1; return;
    }
    int id = -1; int mi = n + 1;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += alive(i, j);
        if (cnt > 0 && cnt < mi) {
            mi = cnt; id = i;
        }
    }
    if (id < 0) return;
    
    for (int j = 0; j < n; j++)
        if (alive(id, j)) {
            swit(id, j, 1); a[id] = j;
            dfs(d - 1); swit(id, j, -1);
        }
}

void solve() {
    memset(col, 0, sizeof col);
    memset(row, 0, sizeof row);
    memset(cross, 0, sizeof cross);
    int d = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]) swit(i, a[i], 1);
        else d++;
    }
    ok = 0; dfs(d);
}

int main() {
    freopen("nqueen2.inp", "r", stdin);
    freopen("nqueen2.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> n) solve();
}