#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

bool sb1,sb2;
ll dem,n,m,q,u,v,x,a[500005],bac[500005],dem3,p[500005],nhom[5],cs[500005],tam;
vector <ll> ds[500005];

void sub1()
{
    if (dem >= 2) cout << 1 <<'\n'; else cout << 0 <<'\n';

    for (ll i = 1;i<=q;++i)
    {
        cin >> x;
        if (a[x] == 1) {dem--; a[x] = 0;} else {dem++; a[x] = 1;}
        if (dem >= 2) cout << 1 <<'\n'; else cout << 0 <<'\n';
    }

    return;
}

void dfs(ll u,ll trc,ll goc)
{
    p[u] = goc;
    for (auto v:ds[u])
      if (v != trc) dfs(v,u,goc);
    return;
}

void sub2()
{
     ll goc;
     for (ll i = 1;i<=n;++i) if (bac[i] == 3) {goc = i; break;}

     ll cnt = 0; p[goc] = 0;
     for (auto v:ds[goc])
     {
         dfs(v,goc,v);
         cnt++;
         cs[v] = cnt;
     }

     for (ll i = 1;i<=n;++i)
     if (i != goc && a[i] == 1)
     {
         ll tam = p[i];
         nhom[cs[tam]]++;
     }

     if (dem <= 1) {cout << 0 <<'\n';} else
     {
         ll cc = 0;
         for (ll i = 1;i<=3;++i) if (nhom[i] > 0) cc++;
         if (cc == 1 || cc == 2) cout << 1 <<'\n'; else
         if (cc == 3) cout << 2 <<'\n';
     }

     for (ll i = 1;i<=q;++i)
     {
          cin >> x;
          if (a[x] == 1)
          {
             tam = p[x];
             nhom[cs[tam]]--;
             dem--;
             a[x] = 0;
          } else
          {
             tam = p[x];
             nhom[cs[tam]]++;
             dem++;
             a[x] = 1;
          }

          if (dem <= 1) {cout << 0 <<'\n';} else
          {
             ll cc = 0;
             for (ll j = 1;j<=3;++j) if (nhom[j] > 0) cc++;
             if (cc == 1 || cc == 2) cout << 1 <<'\n'; else
             if (cc == 3) cout << 2 <<'\n';
          }
     }

     return;
}

int main()
{
    freopen("socks.inp","r",stdin); freopen("socks.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q; dem = 0;
    for (ll i = 1;i<=n;++i)
    {cin >> a[i]; if (a[i] == 1) dem++;}

    sb1 = true; sb2 = true;
    for (ll i = 1;i<=n - 1;++i)
    {
        cin >> u >> v;
        ds[u].pb(v);
        ds[v].pb(u);
        bac[u]++;
        bac[v]++;
        if (bac[u] > 2) sb1 = false;
        if (bac[v] > 2) sb1 = false;
        if (bac[u] == 3) dem3++;
        if (bac[v] == 3) dem3++;

        if (bac[u] > 3) sb2 = false;
        if (bac[v] > 3) sb2 = false;
    }

    if (dem3 != 1) sb2 = false;

    if (sb1) {sub1(); return 0;}
    if (sb2) {sub2(); return 0;}

    return 0;
}
