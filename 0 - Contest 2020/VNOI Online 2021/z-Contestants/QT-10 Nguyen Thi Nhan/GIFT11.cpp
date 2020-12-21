#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

long long t,n,ans,a[2002];

string res;

bool dd[2002];

int cs(int x)
{
    int tmp = 0;
    while (x > 0)
    {
        tmp++;x = x / 10;
    }
    return tmp;
}

string doi(int x)
{
    string tmp = "";
    while (x > 0)
    {
        tmp = (char)(x % 10 + '0') + tmp;
        x = x / 10;
    }
    return tmp;
}

bool check(string x)
{
    int tc = 0;int tl = 0;
    for (int i = 0;i < x.size();i++)
        if (i % 2 == 0)
            tc = tc + (int)(x[i] - '0');
        else
            tl = tl + (int)(x[i] - '0');
    if (abs(tc - tl) % 11 == 0) return true;
    return false;
}

void TRY(int i)
{
    for (int j = 1;j <= n;j++)
        if (dd[j] == false)
        {
            dd[j] = true;
            string tmp = doi(a[j]);
            res = res + doi(a[j]);
            if (i < n)
                TRY(i + 1);
            else
                if (check(res))
                    ans++;
            dd[j] = false;
            res.erase((int)res.size() - tmp.size(),(int)tmp.size());
        }
}

int main()
{
    freopen("GIFT11.INP","r",stdin);
    freopen("GIFT11.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int s = 0;
        ans = 0;res = "";
        cin >> n;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i];s = s + cs(a[i]);
        }
        if (s <= 9)
            TRY(1);
        else
        {
            for (int i = 1;i <= n;i++)
                res = res + doi(a[i]);
            if (check(res))
            {
                ans = 1;
                for (int i = 1;i <= n;i++)
                    ans = ans * i % mod;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
