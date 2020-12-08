#include <bits/stdc++.h>
using namespace std;
typedef double ld;
const ld eps = 1e-9;
struct point{
    ld x, y;
    point() {
        x = y = 0.0;
    }
    point(const ld &_x, const ld &_y) {
        x = _x,
        y = _y;
    }
};
struct line{
    ld a, b, c;
    line() {
        a = b = c = 0.0;
    }
    line(const ld &_a, const ld &_b, const ld &_c) {
        a = _a, b = _b, c = _c;
    }
    line(const point &x, const point &y) {
        if (x.x == y.x) {
            a = 1, b = 0, c = -x.x;
            return;
        }
        if (x.y == y.y) {
            a = 0, b = 1, c = -y.y;
            return;
        }
        a = 1, b = (y.x - x.x) / (x.y - y.y);
        c = -(x.x + b * x.y);
    }
};
inline point operator -(const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
}
inline ld operator * (const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}
inline int ccw(point a, point b, point c) {
    ld x = (b - a) * (c - b);
    if (x > eps) return 1;
    if (x < -eps) return -1;
    return 0;
}
inline point inter(const line &a, const line &b) {
    point M;
    if (a.a == 0) {
        M.y = -a.c;
        M.x = (b.b * M.y + b.c) / -b.a;
        return M;
    }
    if (b.a == 0) {
        M.y = -b.c;
        M.x = (a.b * M.y + a.c) / -a.a;
        return M;
    }
    if (a.b == 0) {
        M.x = -a.c;
        M.y = (b.a * M.x + b.c) / -b.b;
        return M;
    }
    if (b.b == 0) {
        M.x = -b.c;
        M.y = (a.a * M.x + a.c) / -a.b;
        return M;
    }
    M.y = (b.c - a.c) / (a.b - b.b);
    M.x = (a.b * M.y + a.c) / -a.a;
    return M;
}

ld len(point a, point b) {
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
long long p, q, p1, q1, p2, q2;
bool check(point a, point b, point c, point d) {
    if ((ccw(a, b, c) < 0 &&  ccw(a, b, d) < 0) || (ccw(a, b, c) > 0 &&  ccw(a, b, d) > 0))
        return false;
    point M = inter(line(a, b), line(c, d));
    p1 = len(a, M); q1 = len(M, b);
    p2 = len(c, M); q2 = len(M, d);
    long long x = __gcd(p1, q1);
    p1 /= x; q1 /= x;
    x = __gcd(p2, q2);
    p2 /= x; q2 /= x;
    if (p1 == p2 && q1 == q2) {
        p = p1, q = q1;
        return true;
    }
    return false;
}
int n, m;
void Go(point &a, point &b) {
    point ke;
    ke.x = 2 * b.x - a.x;
    ke.y = 2 * b.y - a.y;
    a = b;
    b = ke;
    if (b.x < 0)
        b.x = -b.x,
        a.x = -a.x;
    if (b.x > n)
        b.x = 2 * n - b.x,
        a.x = 2 * n - a.x;
    if (b.y < 0)
        b.y = -b.y,
        a.y = -a.y;
    if (b.y > m)
        b.y = 2 * m - b.y,
        a.y = 2 * m - a.y;
}
point a, b, c, d;
int main() {
    freopen("MoTion.inp", "r", stdin);
    freopen("MoTion.out", "w", stdout);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> m;
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        cin >> c.x >> c.y;
        cin >> d.x >> d.y;
        long long lim = 1e5;
        for (int ans = 0; ans <= lim; ans++) {
            if (check(a, b, c, d)) {
                p += q * ans;
                goto line0;
            }
            Go(a, b);
            Go(c, d);
        }
        cout << -1 << '\n';
        continue;
        line0:;
        cout << p << ' ' << q << '\n';
    }
}
