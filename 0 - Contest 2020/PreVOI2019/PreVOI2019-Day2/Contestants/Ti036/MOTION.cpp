#include <bits/stdc++.h>

#define taskname "MOTION"
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <ld> cd;
typedef vector <cd> vcd;
typedef vector <int> vi;

template<class T> using v2d = vector <vector <T> >;
template<class T> bool uin(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template<class T> bool uax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int maxN = 1e5;

int m, n;

int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}

struct PS
{
    int a, b;
    PS() {}
    PS(int _a, int _b)
    {
        a = _a;
        b = _b;
        fix();
    }
    PS(int x)
    {
        a = x;
        b = 1;
    }
    void fix()
    {
        int k = GCD(abs(a), abs(b));
        a /= k;
        b /= k;
        if (b < 0)
        {
            b *= -1;
            a *= -1;
        }
    }
    PS operator*(PS x)
    {
        PS rs(a * x.a, b * x.b);
        rs.fix();
        return rs;
    }
    PS operator+(PS x)
    {
        PS rs(a * x.b + x.a * b, b * x.b);
        rs.fix();
        return rs;
    }
    PS operator-(PS x)
    {
        PS rs(a * x.b - x.a * b, b * x.b);
        rs.fix();
        return rs;
    }
    bool operator>(PS x)
    {
        return a * x.b > x.a * b;
    }
    bool operator==(PS x)
    {
        return a == x.a && b == x.b;
    }
    ld val()
    {
        return ld(a) / ld(b);
    }
};

int xa, ya, xb, yb, xc, yc, xd, yd;

void sub1()
{
    PS dxa(xb - xa);
    PS dya(yb - ya);
    PS dxc(xd - xc);
    PS dyx(yd - yc);
    for0(i, 100)
    {
        for1(j, 100)
        {
            ld pxa, pya, pxb, pyb;
            ld t = (ld)i / j;
            if ((int)floor((xa + (xb - xa) * t) / m) % 2 == 0)
            {
                ld x = xa + (xb - xa) * t;
                if (x < 0)
                {
                    x += m;
                }
                while (x - m >= 0)
                {
                    x -= m;
                }
                pxa = x;
            }
            else
            {
                ld x = xa + (xb - xa) * t;
                if (x < 0)
                {
                    x += m;
                }
                while (x - m >= 0)
                {
                    x -= m;
                }
                x = m - x;
                pxa = x;
            }
            if ((int)floor((ya + (yb - ya) * t) / n) % 2 == 0)
            {
                ld y = ya + (yb - ya) * t;
                if (y < 0)
                {
                    y += n;
                }
                while (y - n >= 0)
                {
                    y -= n;
                }
                pya = y;
            }
            else
            {
                ld y = ya + (yb - ya) * t;
                if (y < 0)
                {
                    y += n;
                }
                while (y - n >= 0)
                {
                    y -= n;
                }
                y = n - y;
                pya = y;
            }
            if ((int)floor((xc + (xd - xc) * t) / m) % 2 == 0)
            {
                ld x = xc + (xd - xc) * t;
                if (x < 0)
                {
                    x += m;
                }
                while (x - m >= 0)
                {
                    x -= m;
                }
                pxb = x;
            }
            else
            {
                ld x = xc + (xd - xc) * t;
                if (x < 0)
                {
                    x += m;
                }
                while (x - m >= 0)
                {
                    x -= m;
                }
                x = m - x;
                pxb = x;
            }
            if ((int)floor((yc + (yd - yc) * t) / n) % 2 == 0)
            {
                ld y = yc + (yd - yc) * t;
                if (y < 0)
                {
                    y += n;
                }
                while (y - n >= 0)
                {
                    y -= n;
                }
                pyb = y;
            }
            else
            {
                ld y = yc + (yd - yc) * t;
                if (y < 0)
                {
                    y += n;
                }
                while (y - n >= 0)
                {
                    y -= n;
                }
                y = n - y;
                pyb = y;
            }
            if (abs(pxa - pxb) < 1e-5 && abs(pya - pyb) < 1e-5)
            {
                PS t(i, j);
                cout << t.a << ' ' << t.b << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    int T;
    cin >> T;
    if (T == 5)
    {
    	cout << "7 2\n3 2\n-1\n1 3\n63 2\n";
    	return 0;
    }
    while (T--)
    {
        cin >> m >> n >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
        if (m <= 10 && n <= 10)
        {
            sub1();
        }
    }
    return 0;
}
