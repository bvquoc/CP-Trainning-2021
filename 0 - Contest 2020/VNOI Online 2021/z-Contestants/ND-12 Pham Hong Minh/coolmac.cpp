#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

struct _
{
    ll L,R;
};
_ x[100005];
vector <ll> ds;
ll n,m,res,c,Min,a,f[100005],dem,cuoi;

bool cmp(_ a,_ b)
{
    if (a.L == b.L) return a.R < b.R;
    return a.L < b.L;
}

void check(ll tt)
{
    ds.clear();
    for (ll i = 1;i<=m;++i)
    if (  ((tt >> (i - 1) ) & 1)!=0)
    {
        ds.pb(i);
    }

    c = -1; ll r;
    for (auto v:ds)
    {
        if (c < x[v].L - 1)
        {
           r = x[v].L - 1;
           if (r >= Min) return;
        }
        c = max(c,x[v].R);
    }
    if (c < 100000) return;

    ll tam = __builtin_popcount(tt);
    if (res == -1 || res > tam) res = tam;

    return;
}

void sub1()
{
    sort(x+1,x+m+1,cmp); res = -1;

    for (ll tt = 1;tt < (1 << m);++tt)
    {
        check(tt);
    }

    cout << res;

    return;
}

bool kt(ll c,ll l)
{
    if (c >= l - 1) return true;

    ll r = l - 1;
    if (r >= Min) return false;
    return true;
}

void sub2()
{
    sort(x+1,x+m+1,cmp); res = -1;
    memset(f,-1,sizeof(f));

    for (ll i = 1;i<=m;++i)
      for (ll j = m;j >= 0;--j)
      {
           if (kt(f[j],x[i].L) == true)
           {
               f[j + 1] = max(f[j + 1] ,max(f[j],x[i].R));

               if (f[j + 1] >= 100000)
               {
                   if (res == -1 || res > j + 1) res = j + 1;
               }
           }
      }

    cout << res;
    return;
}

int main()
{
    freopen("coolmac.inp","r",stdin); freopen("coolmac.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m;
    for (ll i = 1;i <= m;++i)
    {
        cin >> x[i].L >> x[i].R;
    }

    cin >> n;
    Min = 100000;
    for (ll i = 1;i<=n;++i) {cin >> a; Min = min(a,Min);}
    if (m <= 16) {sub1(); return 0;}
    if (m <= 5000) {sub2(); return 0;}
    sub2();

    return 0;
}
