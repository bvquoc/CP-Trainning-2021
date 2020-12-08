#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e6 + 3;
int n, m, a[400100], x[30], res, f[4010][4010];
stack <int> s;
void cal()
{
    stack <int> s;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (x[i] == 0)
            s.push(i);
        else
        {
            if (s.empty())
                return;
            if (a[i] - s.top() > m)
                return;
            s.pop();
        }
    }
    if (s.empty())
        res++;
}
void gen01(int i)
{
    for (int j = 0; j < 2; j++)
    {
        x[i] = j;
        if (i == 2 * n)
            cal();
        else
            gen01(i + 1);
    }
}
void sub1()
{
    gen01(1);
    cout << res % mod;
}
int calc(int i, stack <int> s, bool ok)
{
    if (ok)
    {
        if (s.empty())
            return 0;
        if (a[i] - s.top() > m)
            return 0;
        else
            s.pop();
    }
    else
        s.push(a[i]);
    if (i == 2 * n)
        return (s.empty());
    if (f[i][s.size()] != -1)
        return f[i][s.size()];
    f[i][s.size()] = (calc(i + 1, s, 0) + calc(i + 1, s, 1)) % mod;
    return f[i][s.size()];
}
void sub5()
{
    memset(f, 255, sizeof(f));
    cout << calc(1, s, 0) % mod;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MINE.inp", "r", stdin);
    freopen("MINE.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i];
    //cout << mod << " ";
    if (n <= 10)
        sub1();
    else
        sub5();
}
