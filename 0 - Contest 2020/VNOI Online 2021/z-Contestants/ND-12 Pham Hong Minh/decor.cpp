#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
ll l,r,m,n,k,res,dem,d,c,mid,f[500005];
struct _
{
    ll v1,v2;
};
_ ds[500005];

void sub1()
{
    res = 0; dem = 0; d = -1; s = s + '0';
    for (ll i = 1;i<=n;++i)
    {
        if (s[i] == '1') {dem++; if (d == -1) d = i; c = i;} else
        if (s[i] == '0')
        {
           if (dem > 0 && res < dem)
           {
               l = d;
               r = c;
               res = dem;
           }
           dem = 0;
           d = -1;
        }
    }
    cout << l <<" "<<r;
    return;
}

bool check(ll sl)
{
    for (ll i = 1;i<=n - sl + 1;++i)
    {
        dem = f[i + sl - 1] - f[i - 1] + k;
        if (dem >= sl) return true;
    }
    return false;
}

void sub2()
{
    l = 0; r = n;
    while (l <= r)
    {
       mid = (l + r) / 2;
       if (check(mid) == true) {res = mid; l = mid + 1;} else r = mid - 1;
    }

    for (ll i = 1;i<=n - res + 1;++i)
    if (f[i + res - 1] - f[i-1] + k >= res)
    {
        cout << i <<" "<<i + res - 1;
        return;
    }

    return;
}

int main()
{
    freopen("decor.inp","r",stdin); freopen("decor.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    cin >> s;

    for (int i = 1;i<=m;++i) cin >> ds[i].v1 >> ds[i].v2;

    s = '0' + s;
    f[0] = 0;
    for (ll i = 1;i<=n;++i)
    {
        f[i] = f[i-1];
        if (s[i] == '1') f[i]++;
    }

    if (f[n] + k >= n)
    {
        cout << 1 <<" "<<n;
        return 0;
    }

    if (m == 0 && k == 0)
    {
        sub1();
        return 0;
    }
    if (m == 0)
    {
        sub2();
        return 0;
    }
    sub2();
    return 0;
}
