#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <deque>
#include <queue>

using namespace std;

char __;
template<typename T>
void getSigned(T &x)
{
    while (__ = getchar(), __ != '-' && (__ < '0' || __ > '9'));
    bool sign(__ == '-');
    if (sign) __ = getchar();

    x = __ - '0';
    while (__ = getchar(), __ >= '0' && __ <= '9')
        x = (x << 3) + (x << 1) + (__ - '0');

    if (sign) x = -x;
}

void file(const string FILE = "Test")
{
    freopen((FILE + ".INP").c_str(), "r", stdin);
    freopen((FILE + ".OUT").c_str(), "w", stdout);
}

template<typename T> inline void maximize(T &res, const T &val) { if (res < val) res = val; }
template<typename T> inline void minimize(T &res, const T &val) { if (res > val) res = val; }

#define all(x) (x).begin(), (x).end()
typedef pair<int, int> pi;
typedef long long ll;
const int LIM = 200200;
const int MOD = 1e9 + 7;
const ll LMOD = 1LL * MOD * MOD;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
/// ====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====

int n;
int t[LIM];
void add(int p)
{
    for (; p > 0; p -= p & -p)
        ++t[p];
}

void rmv(int p)
{
    for (; p > 0; p -= p & -p)
        --t[p];
}

int cnt(int p)
{
    int res = 0;
    for (; p <= n; p += p & -p)
        res += t[p];

    return res;
}

int solve2(int n)
{
    if (n <= 1) return 0;

    --n;
    int fact = 1;
    for (int i = 2; i < n; ++i)
        fact = (1LL * fact * i) % MOD;

    int x = (1LL * n * (n + 1) / 2) % MOD;
    int y = (1LL * x * x) % MOD;
    return (1LL * fact * y) % MOD;
}

ll fsum(int n) { return 1LL * n * (n + 1) / 2; }

int main()
{
    memset(t, 0, sizeof(t));

    file("PERMEOW");
//    file();
    cin >> n;

//    int fact[n + 10];
//    fact[0] = 1;
//    int x;
//    cin >> x;
//    for (int i = 1; i <= n + 10; ++i)
//    {
//        fact[i] = (1LL * fact[i - 1] * i) % MOD;
//    }
//
//    for (int i = 1; i < n; ++i)
//    {
//        int x;
//        cin >> x;
//        int y = fact[i - 1];
//        int k = x / y;
//        int p = i * (i + 1) / 2;
//        cout << x << ' ' << y << ' ' << k << ' ' << p * p << endl;
//    }
//    return 0;

    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; ++i) getSigned(a[i]);
    for (int i = 1; i <= n; ++i) getSigned(b[i]);
//    for (int i = 1; i <= n; ++i) a[i] = i;
//    for (int i = 1; i <= n; ++i) b[i] = n - i + 1;

    bool sub2 = true;
    for (int i = 1; i <= n; ++i)
    {
        if ((a[i] != i) || (b[i] != n - i + 1))
        {
            sub2 = false;
            break;
        }
    }

    if (sub2)
    {
        cout << solve2(n);
        return 0;
    }

    if (a[1] == b[1] || n < 10)
    {
        ll res = 0;
        while (true)
        {
            for (int i = 1; i <= n; ++i)
            {
                res += cnt(a[i]);
                add(a[i]);
            }
            if (res >= LMOD) res -= LMOD;

            bool ok = true;
            for (int i = 1; i <= n; ++i)
            {
                if (a[i] != b[i])
                {
                    ok = false;
                    break;
                }
            }
            if (ok) break;

            for (int i = 1; i <= n; ++i) rmv(a[i]);
            next_permutation(a + 1, a + n + 1);
        }

        cout << res % MOD;
        return 0;
    }

    int fact[n + 1];
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; ++i)
        fact[i] = (1LL * fact[i - 1] * i) % MOD;

    int l = a[1];
    {
        for (int i = 2; i <= n; ++i)
        {
            int expected = i - (i <= a[1]);
            if (a[i] != expected)
            {
                ++l;
                break;
            }
        }
    }

    int r = b[1];
    {
        for (int i = n; i >= 2; --i)
        {
            int expected = i - (i <= b[1]);
            if (b[n - i + 2] != expected)
            {
                --r;
                break;
            }
        }
    }


    ll head = 0;
    while (a[1] != l)
    {
        for (int i = 1; i <= n; ++i)
        {
            head += cnt(a[i]);
            add(a[i]);
        }
        if (head >= LMOD) head -= LMOD;

        for (int i = 1; i <= n; ++i) rmv(a[i]);
        next_permutation(a + 1, a + n + 1);
    }

    ll tail = 0;
    while (b[1] != r)
    {
        for (int i = 1; i <= n; ++i)
        {
            tail += cnt(b[i]);
            add(b[i]);
        }
        if (tail >= LMOD) tail -= LMOD;

        for (int i = 1; i <= n; ++i) rmv(b[i]);
        prev_permutation(b + 1, b + n + 1);
    }

    int res = (head + tail) % MOD;
    for (int i = l; i <= r; ++i)
    {
        res += solve2(n - 1) + (1LL * fact[n - 1] * (i - 1)) % MOD;
        if (res >= MOD)
            res -= MOD;
    }

    cout << res << endl;
    return 0;
}
