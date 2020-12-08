#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
    char c;
    while (!isdigit(c = getchar()));
    x = c - 48;
    while (isdigit(c = getchar()))
        x = (x << 3) + (x << 1) + c - 48;
}
template <typename T> void wrip(T x) {
    if (x > 9)
        wrip(x / 10);
    putchar(x % 10 + 48);
}
template <typename T> inline void write(T x) {
    wrip(x);
    putchar('\n');
}
typedef long long ll;
const int N = 1e5 + 11;
int n, m, top;
ll ans, a[N], q[N], cost[N];
struct st{
    ll cost, Max, Min, Lmin, Rmin, lazy;
} it[4 * N], last;
void push(int id) {
    int lf = id << 1;
    int rt = id << 1 | 1;
    int k = it[id].lazy;
    it[lf].Max += k;
    it[lf].Min += k;
    it[lf].Lmin += k;
    it[lf].Rmin += k;
    it[lf].lazy += k;
    it[rt].Max += k;
    it[rt].Min += k;
    it[rt].Lmin += k;
    it[rt].Rmin += k;
    it[rt].lazy += k;
    it[id].lazy = 0;
}
void update(int id, int l, int r, int u, int v, int k) {
    if (l > v || r < u)
        return;
    if (u <= l && r <= v) {
        it[id].Max += k;
        it[id].Min += k;
        it[id].Lmin += k;
        it[id].Rmin += k;
        it[id].lazy += k;
        return;
    }
    if (it[id].lazy)
        push(id);
    int mid = l + r >> 1;
    int lf = id << 1;
    int rt = lf | 1;
    update(lf, l, r, u, v, k);
    update(rt, mid + 1, r, u, v, k);
    it[id].cost = it[lf].cost + it[rt].cost;
    it[id].cost += min(it[lf].Max, it[rt].Max) - min(it[lf].Rmin, it[rt].Lmin);
    if (it[rt].Max > it[lf].Max) {
        it[id].Lmin = min(it[lf].Min, it[rt].Lmin);
        it[id].Rmin = it[rt].Rmin;
    }
    else {
        it[id].Lmin = it[lf].Lmin;
        it[id].Rmin = min(it[lf].Rmin, it[rt].Min);
    }
    it[id].Max = max(it[lf].Max, it[rt].Max);
    it[id].Min = max(it[lf].Min, it[rt].Min);
}
void get(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return;
    if (u <= l && r <= v) {
        ans += it[id].cost;
        ans += min(last.Max, it[id].Max) - min(last.Rmin, it[id].Lmin);
        if (it[id].Max > last.Max)
            last.Lmin = min(last.Lmin, it[id].Lmin);
        else
            last.Rmin = min(last.Rmin, it[id].Min);
        it[id].Max = max(last.Max, it[id].Max);
        it[id].Min = max(last.Min, it[id].Min);
        return;
    }
    int mid = l + r >> 1;
    int lf = id << 1;
    int rt = lf | 1;
    get(lf, l, r, u, v);
    get(rt, mid + 1, r, u, v);
    it[id].cost = it[lf].cost + it[rt].cost;
    it[id].cost += min(it[lf].Max, it[rt].Max) - min(it[lf].Rmin, it[rt].Lmin);
    if (it[rt].Max > it[lf].Max) {
        it[id].Lmin = min(it[lf].Min, it[rt].Lmin);
        it[id].Rmin = it[rt].Rmin;
    }
    else {
        it[id].Lmin = it[lf].Lmin;
        it[id].Rmin = min(it[lf].Rmin, it[rt].Min);
    }
    it[id].Max = max(it[lf].Max, it[rt].Max);
    it[id].Min = max(it[lf].Min, it[rt].Min);
}
int main() {
    freopen("ConStruct.inp", "r", stdin);
    freopen("ConStruct.out", "w", stdout);
    int ntest;
    read(ntest);
    while (ntest--) {
        read(n);
        read(m);
        for (int i = 1; i <= n; i++)
            read(a[i]);
        while (m--) {
            int type, l, r;
            read(type);
            read(l);
            read(r);
            if (type == 1) {
                int k; read(k);
                for (int i = l; i <= r; i++)
                    a[i] += k;
            }
            else {
                q[top = 1] = 0;
                for (int i = l; i <= r; i++) {
                    while (q[top] > a[i])
                        top--;
                    cost[i] = a[i] - q[top];
                    q[++top] = a[i];
                }
                q[top = 1] = 0;
                ll res = 0;
                for (int i = r; i >= l; i--) {
                    while (q[top] >= a[i])
                        top--;
                    res += min(cost[i], a[i] - q[top]);
                    q[++top] = a[i];
                }
                write(res);
            }
        }
    }
}
