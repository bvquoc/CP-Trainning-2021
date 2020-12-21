#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;

struct Node {
    int x, y;
    Node() {}
    Node(int _x, int _y) {
        x = _x; y = _y;
    }
    bool operator < (const Node &h) const {
        return (y < h.y || (y == h.y && x < h.x));
    }
};

struct SMT {
    int n;
    vector <int> S;
    SMT (int _n = 0) {
        n = _n;
        S.assign(4 * n + 7, 0);
    }
    void update(int i, int l, int r, int x, int c) {
        if (x < l || x > r || l > r) return;
        if (l == r) {
            S[i] = c;
            return;
        }
        int mid = (l + r) >> 1;
        update(2 * i, l, mid, x, c);
        update((2 * i) + 1, mid + 1, r, x, c);
        S[i] = min(S[2 * i], S[(2 * i) + 1]);
    }
    int get(int i, int l, int r, int u, int v) {
        if (v < l || r < u || l > r || u > v) return INF;
        if (u <= l && r <= v) return S[i];
        int mid = (l + r) >> 1;
        return min(get(2 * i, l, mid, u, v), get((2 * i) + 1, mid + 1, r, u, v));
    }
    void update(int x, int c) {
        update(1, 1, n, x, c);
    }
    int get(int u, int v) {
        return get(1, 1, n, u, v);
    }
};

int n, m;
Node a[N];
int ans;

int Search(int X) {
    int l = 1;
    int r = n;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid].y >= X) {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return res;
}

int main()
{
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    scanf("%d", &n);
    SMT IT(n);
    for (int i = 1, u, v; i <= n; i++) {
        scanf("%d%d", &u, &v);
        a[i].x = u; a[i].y = v;
    }
    sort(a + 1, a + n + 1);
    scanf("%d", &m);
    int C = INF;
    for (int i = 1, c; i <= m; i++) {
        scanf("%d", &c);
        C = min(C, c);
    }
    int Mi;
    ans = INF;
    IT.update(0, INF);
    for (int i = 1; i <= n; i++) {
        if (a[i].y < C) {
            IT.update(i, INF);
            continue;
        }
        if (a[i].x <= C) {
            IT.update(i, 1);
            continue;
        }
        int k = Search(a[i].x);
        if (k == 0 || k >= i) {
            IT.update(i, INF);
            continue;
        }
        Mi = IT.get(k, i - 1);
        Mi++;
        if (a[i].y >= 100000) {
            ans = min(ans, Mi);
        }
        IT.update(i, min(Mi, INF));
    }
    if (ans >= INF) printf("-1");
    else printf("%d", ans);
    return 0;
}
