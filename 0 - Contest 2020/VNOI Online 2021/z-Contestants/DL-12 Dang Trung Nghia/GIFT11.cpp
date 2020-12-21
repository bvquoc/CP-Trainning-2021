#include<bits/stdc++.h>
using namespace std;

const long MOD = 998244353;

struct ore
{
    long val, odd, even, sz;
} a[2005];

long n;

string toString(long x)
{
    string res;
    while (x > 0)
    {
        res.push_back(char(x % 10 + 48));
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

struct ssuubb1
{
    bool used[11];
    long res = 0, X[11];

    void dequy(long i)
    {
        if (i == n + 1)
        {
            long sz = 0;
            long sum = 0;
            for (long j = 1; j <= n; j++)
            {
                if (sz & 1) sum = sum - a[X[j]].odd + a[X[j]].even;
                else sum = sum + a[X[j]].odd - a[X[j]].even;
                sz += a[X[j]].sz;
            }
            if (abs(sum) % 11 == 0) res++;
            return;
        }
        for (long j = 1; j <= n; j++)
        {
            if (used[j]) continue;
            used[j] = true;
            X[i] = j;
            dequy(i + 1);
            used[j] = false;
        }
    }

    void solve()
    {
        res = 0;
        dequy(1);
        cout << res << '\n';
    }
} sub1;

void sub2()
{
    long sum = 0;
    for (long i = 1; i <= n; i++) sum = sum + a[i].odd - a[i].even;
    if (abs(sum) % 11 != 0)
    {
        cout << 0 << '\n';
        return;
    }
    long res = 1;
    for (long i = 1; i <= n; i++) res = (1LL * res * i) % MOD;
    cout << res << '\n';
}

void solve()
{
    cin >> n;
    bool ssub2 = true;
    for (long i = 1; i <= n; i++)
    {
        cin >> a[i].val;
        string tmp = toString(a[i].val);
        a[i].odd = 0;
        a[i].even = 0;
        a[i].sz = tmp.size();
        if (a[i].sz & 1) ssub2 = false;
        for (long j = 0; j < tmp.size(); j++)
        {
            if ((j + 1) & 1) a[i].odd += int(tmp[j]) - 48;
            else a[i].even += int(tmp[j]) - 48;
        }
    }
    if (n <= 9)
    {
        sub1.solve();
        return;
    }
    if (ssub2)
    {
        sub2();
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    freopen("GIFT11.INP", "r", stdin);
    freopen("GIFT11.OUT", "w", stdout);
    long test;
    cin >> test;
    while (test--) solve();
    return 0;
}
