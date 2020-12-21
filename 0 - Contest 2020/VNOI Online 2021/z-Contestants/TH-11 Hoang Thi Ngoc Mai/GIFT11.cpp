#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define N 2005
#define MOD 998244353

int t, n, sschan;
ll a[N];

bool CountSCS(ll x)
{
    int cnt = 0;
    while(x)
    {
        cnt ++;
        x /= 10;
    }
    if(cnt % 2 == 0)
        return true;
    return false;
}

void read()
{
    sschan = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        if(CountSCS(a[i]))
            sschan ++;
    }
}

int b[N], res;
bool ktra[N];
vector < int > s;

void tach(ll x)
{
    int tmp = s.size();
    while(x)
    {
        s.push_back(x%10);
        x /= 10;
    }
    reverse(s.begin() + tmp, s.end());
}

void Check()
{
    int le = 0, chan = 0;
    s.clear();
    for(int i = 1; i <= n; i ++)
    {
        tach(a[b[i]]);
    }
    for(int i = 0; i < s.size(); i ++)
    {
        if((i + 1)% 2 == 0)
            chan += s[i];
        else
            le += s[i];
    }
    if((le - chan)%11 == 0)
        res = (res + 1)%MOD;
}

void sinh(int x)
{
    for(int i = 1; i <= n; i ++)
    {
        if(ktra[i])
        {
            ktra[i] = false;
            b[x] = i;
            if(x == n)
                Check();
            else
                sinh(x + 1);
            ktra[i] = true;
        }
    }
}

int cnt1, cnt2;
ll d[N];

void init()
{
    d[0] = 1;
    for(int i = 1; i <= 2000; i ++)
        d[i] = (d[i - 1]*i%MOD)%MOD;
}

void pre(ll x)
{
    s.clear();
    while(x)
    {
        s.push_back(x%10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); i ++)
    {
        if((i + 1)%2 == 0)
            cnt1 += s[i];
        else
            cnt2 += s[i];
    }
}

void sub2()
{
    cnt1 = cnt2 = 0;
    for(int i = 1; i <= n; i ++)
        pre(a[i]);
    if((cnt2 - cnt1) % 11 == 0)
        cout << d[n] << '\n';
    else
        cout << 0 << '\n';
}

void sub1()
{
    fill(ktra + 1, ktra + n + 1, true);
    res = 0;
    sinh(1);
    cout << res << '\n';
}

void solve()
{
    sub1();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GIFT11.INP", "r", stdin);
    freopen("GIFT11.OUT", "w", stdout);
    cin >> t;
    init();
    while(t --)
    {
        read();
        if(n <= 8)
            sub1();
        else
        {
            if(sschan == n)
                sub2();
            else
                solve();
        }
    }
    return 0;
}
