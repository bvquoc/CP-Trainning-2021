#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 200005;
const ll mod = 1000000007;
ll res,a[N],b[N],n,dem,f[200005],gt[200005];
bool sb1,sb2;

void sub1()
{
    res = 0;
    for (ll i = 1;i<=n;++i)
    {
        for (ll j = 1;j<n;++j)
        if (a[j] > a[j+1]) {res++; swap(a[j],a[j+1]);}
    }
    cout << res;
    return;
}

void sub2()
{
    f[1] = 0; gt[0] = 1;
    for (ll i = 1;i<=n;++i) gt[i] = (gt[i-1] * i) % mod;

    for (ll i = 2;i<=n;++i)
    {
        dem = (i - 1) * i / 2;
        dem = (gt[i - 1] * dem) % mod;
        f[i] = (f[i-1] * i) % mod;
        f[i] = (f[i] + dem) % mod;
    }

    cout << f[n] ;

    return;
}

int main()
{
    freopen("permeow.inp","r",stdin); freopen("permeow.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    sb1 = true; sb2 = true;
    for (ll i = 1;i<=n;++i) {cin >> a[i]; if (a[i] != i) sb2 = false;}
    for (ll i = 1;i<=n;++i) {cin >> b[i]; if (a[i] != b[i]) sb1 = false; if (b[i] != n - i + 1) sb2 = false; }

    if (sb1 == true) {sub1(); return 0;}
    if (sb2 == true) {sub2(); return 0;}

    sub2();
    return 0;
}
