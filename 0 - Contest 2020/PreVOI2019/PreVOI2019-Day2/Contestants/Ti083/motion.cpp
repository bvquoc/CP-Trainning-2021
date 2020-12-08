#include <bits/stdc++.h>

using namespace std;

const string TASK = "motion";

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()

using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
#define fi first
#define se second

const int INF = 1e9 + 7;

int ceil_div(int a, int b)
{
    assert(a >= 0);
    return (a + b - 1) / b;
}

pii solve1(int a, int b, int m)
{
    if (a == 0) {
        if (b % m == 0) return pii(0, 1);
        return pii(INF, 1);
    }
    int x = (-b) % m;
    if (x < 0) x += m;
    assert(x >= 0);
    return pii(x, a);
}

void extended_euclid(int a, int b, int c, int &x, int &y)
{
//    cerr << "ee " << a << ' ' << b << ' ' << c << endl;
    if (b == 0) {
        x = c / a, y = 0;
        return;
    } else if (a == 0) {
        x = 0, y = c / b;
        return;
    } else if (b < 0) {
        extended_euclid(a, -b, c, x, y);
        y = -y;
    } else if (a < 0) {
        extended_euclid(-a, b, c, x, y);
        x = -x;
    } else if (a < b) {
        extended_euclid(b, a, c, y, x);
    } else {
        int q = a / b, r = a % b;
        extended_euclid(b, r, c, y, x);
        y -= q * x;
    }

    if (x < 0) {
        int z = ceil_div(-x, b);
        x += b * z, y -= b * z;
    }
    if (x >= b) {
        int z = x / b;
        x -= b * z, y += b * z;
    }
}

int solve2(int a1, int m1, int a2, int m2)
{
//    cerr << "solve2 " << a1 << ' ' << m1 << ' ' << a2 << ' ' << m2 << endl;
    assert(a1 < m1);
    int a = m1, b = -m2, c = a2 - a1;
    int d = __gcd(abs(a), abs(b));
    if (d == 0 || c % d) return INF;

    a /= d, b /= d, c /= d;
//    cerr << "abc " << a << ' ' << b << ' ' << c << endl;
    int x, y;
    extended_euclid(a, b, c, x, y);
//    cerr << x << ' ' << y << endl;

    if (x < 0) {
        int z = ceil_div(-x, b);
        x += b * z, y -= b * z;
    }
    if (x >= b) {
        int z = x / b;
        x -= b * z, y += b * z;
    }

    return x * m1 + a1;
}

pii solve(int a1, int b1, int m1, int a2, int b2, int m2)
{
//    cerr << "solve  " << a1 << ' ' << b1 << ' ' << m1 << ' ' << a2 << ' '<< b2 << ' ' << m2 << endl;
    if (a1 == 0) {
        if (b1 % m1 == 0) return solve1(a2, b2, m2);
        return pii(INF, 1);
    }
    if (a2 == 0) {
        if (b2 % m2 == 0) return solve1(a1, b1, m1);
        return pii(INF, 1);
    }

    if (a1 < 0) a1 = -a1, b1 = -b1;
    if (a2 < 0) a2 = -a2, b2 = -b2;

    b1 %= m1, b2 %= m2;
    if (b1 >= 0) b1 -= m1;
    if (b2 >= 0) b2 -= m2;
//        cerr << "solve  " << a1 << ' ' << b1 << ' ' << m1 << ' ' << a2 << ' '<< b2 << ' ' << m2 << endl;


    int num = solve2(-b1 * a2, m1 * a2, -b2 * a1, m2 * a1);
    if (num == INF) return pii(INF, 1);
    return pii(num, a1 * a2);
}

bool operator< (pii p1, pii p2)
{
//    cerr << p1.fi << ' ' << p1.se << endl;
//    cerr << p2.fi << ' ' << p2.se << endl;
    return 1ll * p1.fi * p2.se < 1ll * p2.fi * p1.se;
}

#define min min_
pii min(pii a, pii b) { return a < b ? a : b; }

int main()
{
    freopen((TASK + ".inp").c_str(), "r", stdin);
    freopen((TASK + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tests;
    cin >> tests;
    while (tests--) {
        int M, N, x1, y1, a1, b1, x2, y2, a2, b2;
        cin >> M >> N >> x1 >> y1 >> a1 >> b1 >> x2 >> y2 >> a2 >> b2;
        a1 -= x1, b1 -= y1, a2 -= x2, b2 -= y2;

        M *= 2, N *= 2;

        pii ans(INF, 1);
        ans = min(ans, solve(a1 - a2, x1 - x2, M, b1 - b2, y1 - y2, N));
        ans = min(ans, solve(a1 - a2, x1 - x2, M, b1 + b2, y1 + y2, N));
        ans = min(ans, solve(a1 + a2, x1 + x2, M, b1 - b2, y1 - y2, N));
        ans = min(ans, solve(a1 + a2, x1 + x2, M, b1 + b2, y1 + y2, N));

        int d = __gcd(ans.fi, ans.se);
        if (ans.fi == INF) cout << -1 << '\n';
        else cout << ans.fi / d << ' ' << ans.se / d << '\n';
    }
}

/*
5
7 2 0 0 1 2 7 2 6 0
3 3 0 0 3 3 3 0 2 1
4 4 0 2 2 4 3 2 2 2
4 4 1 0 4 4 3 0 0 4
9 7 0 0 1 1 9 0 8 7
*/
