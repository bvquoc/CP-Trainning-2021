/*
#Modular Arithmetic, #Uniform Motion
*/
#define taskname "MOTION"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
using lli = long long;

lli m, n;
struct TVector
{
    lli x, y;
    TVector operator - (const TVector& other) const
    {
        return {x - other.x, y - other.y};
    }
};
using TPoint = TVector;

struct TFrac
{
    lli r, s;
} Result;

struct TMotion1D
{
    lli Start;
    lli Velocity;
};

struct TParameter //FirstMeet/Denominator + t * (Period / Denominator)
{
    lli FirstMeet, Period;
    lli Denominator;
    inline bool Valid()
    {
        return FirstMeet == 0 || Denominator != 0;
    }
    inline bool AlwaysTrue()
    {
        return FirstMeet == 0 && Denominator == 0;
    }
};

TPoint A, C;
TVector u, v;

void ReadInput()
{
    TPoint B, D;
    cin >> m >> n
        >> A.x >> A.y
        >> B.x >> B.y
        >> C.x >> C.y
        >> D.x >> D.y;
    u = B - A;
    v = D - C;
}

TParameter GetParameters(lli range, const TMotion1D& A, const TMotion1D& B)
{
    TParameter Param;
    Param.FirstMeet = B.Start - A.Start;
    Param.Denominator = A.Velocity - B.Velocity;
    if (Param.Denominator < 0)
    {
        Param.FirstMeet = -Param.FirstMeet;
        Param.Denominator = -Param.Denominator;
    }
    if (Param.FirstMeet < 0)
        Param.FirstMeet += range;
    Param.Period = range;
    return Param;
}

lli GCD(lli a, lli b)
{
    while (b != 0)
    {
        lli r = a % b;
        a = b;
        b = r;
    }
    return a;
}

lli SolveDiophantine(lli a, lli b, lli c)
{
    if (a == 0 && b == 0)
        return (c == 0 ? 0 : -1);
    lli d = GCD(a, b);
    if (c % d != 0)
        return -1;
    a /= d; b /= d; c /= d;
    lli m, n, q, r, xm, xn, xr;
    m = a; xm = 1;
    n = b; xn = 0;
    while (n != 0)
    {
        q = m / n; r = m - q * n;
        xr = xm - q * xn;
        m = n; xm = xn;
        n = r; xn = xr;
    }
    xm = xm * c;
    if (b != 0)
    {
        xm = xm % b;
        if (xm < 0) xm += abs(b);
    }
    return xm;
}

void Update(TFrac NewRes)
{
    if (Result.r == -1)
    {
        Result = NewRes;
        return;
    }
    if (NewRes.r * Result.s < NewRes.s * Result.r)
        Result = NewRes;
}

void Reduce(TFrac& f)
{
    lli d = GCD(f.r, f.s);
    f.r /= d;
    f.s /= d;
}

void Solve()
{
    Result = {-1, 0};
    TParameter Param1, Param2;
    for (int trial1 = 0; trial1 <= 1; ++trial1)
    {
        Param1 = GetParameters(2 * m, {A.x, u.x}, {C.x, v.x});
        A.x = 2 * m - A.x;
        u.x = -u.x;
        if (!Param1.Valid())
            continue;
        for (int trial2 = 0; trial2 <= 1; ++trial2)
        {
            Param2 = GetParameters(2 * n, {A.y, u.y}, {C.y, v.y});
            A.y = 2 * n - A.y;
            u.y = -u.y;
            if (!Param2.Valid())
                continue;
            if (Param1.AlwaysTrue())
            {
                Update({Param2.FirstMeet, Param2.Denominator});
                continue;
            }
            if (Param2.AlwaysTrue())
            {
                Update({Param1.FirstMeet, Param1.Denominator});
                continue;
            }
            lli nRounds = SolveDiophantine(
                              Param1.Period * Param2.Denominator,
                              -Param2.Period * Param1.Denominator,
                              Param2.FirstMeet * Param1.Denominator - Param1.FirstMeet * Param2.Denominator
                          );
            if (nRounds != -1)
                Update({Param1.FirstMeet + nRounds * Param1.Period, Param1.Denominator});
        }
    }
    if (Result.r == -1)
        cout << "-1\n";
    else
    {
        Reduce(Result);
        cout << Result.r << ' ' << Result.s << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    int ntests;
    cin >> ntests;
    while (ntests-- > 0)
    {
        ReadInput();
        Solve();
    }
}
