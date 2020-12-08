#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
    char c;
    while (!isdigit(c = getchar()));
    x = c - 48;
    while (isdigit(c = getchar()))
        x = (x << 3) + (x << 1) + c - 48;
}
const int N = 3e6 + 11;
int n, m;
int pa[N], root[N];
int Find(int u) {
    return !pa[u] ? u : pa[u] = Find(pa[u]);
}
void Dsu(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v)
        return;
    pa[v] = u;
}
int main() {
    freopen("Paint.inp", "r", stdin);
    freopen("Paint.out", "w", stdout);
    int q;
    read(q);
    m = q;
    for (int i = 'a'; i <= 'z'; i++)
        root[i] = ++m;
    while (q--) {
        int type;
        read(type);
        char a, b;
        while (!isalpha(a = getchar()));
        if (type == 1)
            Dsu(root[a], ++n);
        if (type == 2) {
            while (!isalpha(b = getchar()));
            if (a != b) {
                pa[root[a]] = root[b];
                root[a] = ++m;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int u = Find(i);
        for (int j = 'a'; j <= 'z'; j++)
            if (u == root[j])
                putchar(char(j));
    }
}
