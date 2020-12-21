#include <bits/stdc++.h>
#define task "GIFT11"
#define ll long long
#define FOR( i, l, r) for(int i = (l), _r = (r); i <= _r; ++i)
#define FOD( i, l, r) for(int i = (l), _r = (r); i >= _r; ++i)
#define REP( i, n)    for(int i = 0, _n = (n); i < _n; ++i)
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1ll << (x))
#define BIT(x, k) (1ll & ((x) >> (k)))
#define ON(x, k)  ((x) | (1ll << (k)))
#define OFF(x, k) ((x) & ~(1ll << (k)))
#define endl '\n'
#define __builtin_popcount __builtin_popcountll
using namespace std;
int const N = 2003;
int const mod = 998244343;
int n, cntDigit, okEven, okOdd;
string a[N];
void inp(void)
{
    cntDigit = 0;
    okEven = okOdd = 1;
    cin >> n;
    FOR( i, 1, n)
    {
        cin >> a[i];
        cntDigit += a[i].size();
        if(a[i].size() % 2)
            okEven = 0;
        else
            okOdd = 0;
    }
}
int ans = 0;
void sub1(void)
{
    int ans = 0;
    vector<int> per;
    FOR( i, 1, n) per.push_back(i);
    do
    {
        int sumOdd = 0, sumEven = 0;
        int cnt = 0;
        for(int i : per)
            REP( j, a[i].size())
        {
            ++cnt;
            if(cnt % 2)
                sumOdd += a[i][j] - '0';
            else
                sumEven += a[i][j] - '0';
        }
        if(((sumOdd - sumEven) % 11 + 11) % 11 == 0)
            ++ans;
    }
    while(next_permutation(per.begin(), per.end()));
    cout << ans << endl;
}
void sub2(void)
{
    int sumOdd = 0, sumEven = 0;
    int cnt = 0;
    FOR( i, 1, n) REP( j, a[i].size())
    {
        ++cnt;
        if(cnt % 2)
            sumOdd += a[i][j] - '0';
        else
            sumEven += a[i][j] - '0';
    }
    if(((sumOdd - sumEven) % 11 + 11) % 11 != 0)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 1;
    FOR( i, 1, n) ans = 1ll * ans * i % mod;
    cout << ans << endl;
}
int dp[N][N / 2][11];
int Odd[N], Even[N];
void add(int &a, int const &b)
{
    a += b;
    if(a >= mod)
        a -= mod;
}
void sub3(void)
{
    FOR( i, 1, n) FOR( j, 0, n / 2) REP( k, 11) dp[i][j][k] = 0;
    FOR( i, 1, n)
    {
        Odd[i] = Even[i] = 0;
        int cnt = 0;
        REP( j, a[i].size())
        {
            ++cnt;
            if(cnt % 2)
                Odd[i] += a[i][j] - '0';
            else
                Even[i] += a[i][j] - '0';
        }
    }
    dp[0][0][0] = 1;
    FOR( i, 1, n) FOR( j, 0, min(i - 1, n / 2)) REP( k, 11) if(dp[i - 1][j][k] > 0)
    {
        add(dp[i][j + 1][(k + (Even[i] - Odd[i]) % 11 + 11) % 11], dp[i - 1][j][k]);
        add(dp[i][j][(k + (Odd[i] - Even[i]) % 11 + 11) % 11], dp[i - 1][j][k]);
    }
    int ans = dp[n][n / 2][0];
    FOR( i, 1, (n + 1) / 2) ans = 1ll * ans * i % mod;
    FOR( i, 1, n / 2) ans = 1ll * ans * i % mod;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        inp();
        if(cntDigit <= 8)
        {
            sub1();
            continue;
        }
        if(okEven)
        {
            sub2();
            continue;
        }
        if(okOdd)
            sub3();
    }
    return 0;
}
