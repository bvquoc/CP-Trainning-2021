#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long>
#define F first
#define S second
#define pb push_back

using namespace std;

ll n,k,pos,tt,x,y;
char c,c1,c2;

vector < pll > a;
vector < int > vt[30];
map <char,int> goc;
vector <int> ds[1000001];

void dfs(int id,int mau)
{
   a.pb({id,mau});
   for (auto v:ds[id])
    dfs(v,mau);
}

void sub2()
{
    k = 0;
    for (char c='a'; c<='z'; ++c) goc[c]=-1;

    for (int i=1;i<=n;++i)
    {
        cin >> tt;
        if (tt==1)
        {
            k++;
            cin >> c;
            x=c - 'a';
            if (goc[c]==-1) goc[c]=k; else ds[goc[c]].pb(k);
        } else
        {
          cin >> c1 >> c2;
          if (c1==c2) continue;
          x = c1 - 'a'; y = c2 - 'a';

          int g1=goc[c1] , g2 = goc[c2];
          ds[g2].pb(g1);

          goc[c1]=-1;
        }
    }

    for (char c='a';c<='z';++c)
    if (goc[c]!=-1)
    {
       x=c - 'a';
       pos = goc[c];
       dfs(pos,x);
    }

    sort(a.begin(),a.end());
    for (ll i=0;i<a.size();++i)
    {
        x = a[i].S;
        c= x + 'a';
        cout<<c;
    }
}

int main()
{
    freopen("PAINT.inp","r",stdin); freopen("PAINT.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    if (n>10000) {sub2(); return 0;}
    k=0;
    for (ll i=1; i<=n; ++i)
    {
        cin >> tt;
        if (tt==1)
        {
          k++;
          cin >> c;
          x = c - 'a';

          vt[x].pb(k);
        } else
        {
          cin >> c1 >> c2;
          if (c1==c2) continue;
          x = c1 - 'a'; y = c2 - 'a';

          for (auto v:vt[x]) vt[y].pb(v);
          vt[x].resize(0);
        }
    }

    for (char c='a'; c<='z'; ++c)
    {
        x = c - 'a';
        for (auto v:vt[x]) a.pb({v,x});
    }

    sort(a.begin(),a.end());
    for (ll i=0;i<a.size();++i)
    {
        x = a[i].S;
        c= x + 'a';
        cout<<c;
    }
    return 0;
}
