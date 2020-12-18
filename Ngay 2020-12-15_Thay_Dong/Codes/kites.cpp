#include <bits/stdc++.h>
using namespace std;

#define popcnt __builtin_popcount

using Tp = int;
using ll = long long;

struct point {
    Tp x, y;

    point(Tp x = 0, Tp y = 0): x(x), y(y) {}

    point& operator += (const point &o) {
        x += o.x; y += o.y; return *this;
    }

    point& operator -= (const point &o) {
        x -= o.x; y -= o.y; return *this;
    }

    point& operator *= (const Tp &k) {
        x *= k; y *= k; return *this;
    }

    bool operator != (const point &o) const {
        return x != o.x || y != o.y;
    }

    bool operator == (const point &o) const {
        return x == o.x && y == o.y;
    }

    point operator + (const point &o) const {
        return point(*this) += o;
    }

    point operator - (const point &o) const {
        return point(*this) -= o;
    }

    point operator * (const Tp &k) const {
        return point(*this) *= k;
    }
};

Tp dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

Tp cross(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

Tp orient(const point &a,
const point &b, const point &c) {
    return cross(b - a, c - b);
}

Tp norm(const point &p) {
    return dot(p, p);
}

bool ccw(const point &a,
const point &b, const point &c) {
    return orient(a, b, c) > 0;
}

bool cw(const point &a,
const point &b, const point &c) {
    return orient(a, b, c) < 0;
}

const int MOD = 1e9 + 7;
const int V = 10005;
const int N = 53;

ll dp[N][N][N][N];
point a[N], b[N]; int n;

ll rec(int i, int j, int l, int r) {
    if (i + 1 == j) return 1;
    ll &res = dp[i][j][l][r];
    if (res >= 0) return res;
    point cut(-1, -1);
    res = 0; int p = -1;
    for (int m = 1; m <= n; m++)
        if (b[m].y <= b[l].y
        && b[m].y <= b[r].y
        && ccw(a[i], b[m], b[l])
        && cw(a[j], b[m], b[r]))
            if (cut.y < b[m].y) {
                cut = b[m]; p = m;
            }
    if (p < 0) return 0;
    for (int k = i + 1; k < j; k++)
        (res += rec(i, k, l, p)
        * rec(k, j, p, r)) %= MOD;
    return res;
}

int main() {
    freopen("kites.inp", "r", stdin);
    freopen("kites.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x;
    for (int i = 1; i <= n; i++)
        cin >> b[i].x >> b[i].y;
    sort(a + 1, a + n + 1,
    [](const point &p, const point &q) {
        return p.x < q.x;
    });
    a[0].x = b[0].x = -1;
    a[n + 1].x = b[n + 1].x = V;
    b[0].y = b[n + 1].y = V;
    memset(dp, -1, sizeof dp);
    cout << rec(0, n + 1, 0, n + 1);
}