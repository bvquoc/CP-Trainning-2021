#include <bits/stdc++.h>

#define taskname "oddcoin"
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

const int maxN = 1e5 + 1;
const int maxS = 1e5 + 1;
const ll inf = 1e10;

ll x, t;

vector <pair<ll, ll> > vt;

ll val[21];
ll dp[21][maxS];

ll f[maxN];

void sub1()
{
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (auto &p: vt)
    {
        x = p.fi;
        t = p.se;
        val[16] = x;
        for1(i, 16)
        {
            dp[i][0] = 0;
            for1(j, t)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= val[i])
                {
                    uin(dp[i][j], dp[i][j - val[i]] + 1);
                }
            }
        }
        cout << dp[16][t] << '\n';
    }
}

void init()
{
    val[1] = 1;
    val[2] = 3;
    val[3] = 5;
    fore(i, 4, 15)
    {
        val[i] = val[i - 3] * 10;
    }
}

void sub2()
{
    for (auto &p: vt)
    {
        x = p.fi;
        t = p.se;
        val[16] = x;
        ll add = 0;
        ll mx = *max_element(val + 1, val + 16 + 1);
        if (t >= 1e5)
        {
            add = (t - 100000) / mx;
            t -= add * mx;
        }
        for1(i, t)
        {
            f[i] = inf;
            for1(j, 16)
            {
                if (i >= val[j])
                {
                    uin(f[i], f[i - val[j]] + 1);
                }
            }
        }
        cout << f[t] + add << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    init();
    int T;
    cin >> T;
    ll maxX = 0, maxT = 0;
    while (T--)
    {
        cin >> x >> t;
        uax(maxX, x);
        uax(maxT, t);
        vt.eb(x, t);
    }
    if (maxX <= 1e5 && maxT <= 1e5)
    {
        sub1();
    }
    else
    {
        sub2();
    }
    return 0;
}
