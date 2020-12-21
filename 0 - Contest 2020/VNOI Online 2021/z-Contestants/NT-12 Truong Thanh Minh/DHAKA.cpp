#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for(ll i = (a); i <= (b); ++i)
#define req(i, a, b) for(ll i = (a); i >= (b); --i)
#define name "DHAKA"
#define pb push_back
#define eb emplace_back
#define sz size()
#define ff first
#define ss second
typedef pair < ll, ll > ii;
const ll maxn = 1e5 + 7, oo = 1e18, mod = 1e9 + 7;
ll n, m, k, l, x, y, w, d[maxn], s[maxn], res = oo, cha[maxn], hang[maxn], ok[maxn], dmin[maxn][3];
vector < ii > a[maxn], anew[maxn];
vector < ll > duahau[maxn];
vector < pair < ll, ii > > canh;

void dijkstra()
{
    priority_queue < ii, vector < ii >, greater < ii > > q;
    q.push({0, 1});
    fill(d+2, d+n+1, oo);
    while (!q.empty())
    {
        int x = q.top().second;
        ll dx = q.top().first;
        q.pop();
        if (dx != d[x])
            continue;
        for (ii i : a[x])
        {
            if (d[i.ff] > d[x] + i.second)
            {
                d[i.ff] = d[x] + i.ss;
                cha[i.ff] = x;
                q.push({d[i.ff], i.ff});
            }
        }
    }

}
ll goc(int x)
{
    if (x != cha[x])
        cha[x] = goc(cha[x]);
    return cha[x];
}
bool hopnhat(int x, int y)
{
    x = goc(x);
    y = goc(y);
    if (x == y)
        return false;
    if (hang[x] == hang[y])
        ++hang[x];
    if (hang[x] > hang[y])
        cha[y] = x;
    else cha[x] = y;
    return true;
}

void solve()
{
    rep (i, 1, n)
    {
        cha[i] = i;
        hang[i] = 0;
    }
    set < ll > ttm;
    ll tmp = 0;
    for (auto i : canh)
    {
        int x = i.ss.ff;
        int y = i.ss.ss;
        if (ok[x] && ok[y])
        {
            if (hopnhat(x, y))
            {
                for (auto j : duahau[x])
                    ttm.insert(j);
                for (auto j : duahau[y])
                    ttm.insert(j);
                tmp += i.ff;
                anew[x].pb(ii(y, i.ff));
                anew[y].pb(ii(x, i.ff));
            }
        }
    }
    if (ttm.sz >= l && goc(1) == goc(n))
        res = min (res, tmp);
}
void thu(int i)
{
    if (i > n)
    {
        if (ok[1])
            solve();
        return;
    }
    rep (j, 0, 1)
    {
        ok[i] = j;
        thu(i + 1);
        ok[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    cin >> n >> m >> k >> l;
    rep (i, 1, n)
    {
        cin >> s[i];
        rep (j, 1, s[i])
        {
            cin >> x;
            duahau[i].pb(x);
        }
    }
    rep (i, 1, m)
    {
        cin >> x >> y >> w;
        a[x].pb({y, w});
        a[y].pb({x, w});
        canh.pb({w, ii(x, y)});
    }
    sort(canh.begin(), canh.end());
    if (l == 0)
    {
        dijkstra();
        cout << res;
    }
    if (l == 1)
    {
        dijkstra();
        int i = n;
        if (s[1] > 0)
        {
            cout << d[n];
            return 0;
        }
        if (d[n] == oo)
        {
            cout << -1;
            return 0;
        }
        ok[n] = 1;
        while (i != 1)
        {
            if (s[i] > 0)
            {
                cout << d[n];
                return 0;
            }
            i = cha[i];
            ok[i] = 1;
        }
        ll tmp = oo;
        rep (i, 1, n)
            if (ok[i])
                for (auto j : a[i])
                {
                    if (s[j.ff] > 0)
                        tmp = min (tmp, j.ss);
                }
        cout << d[n] + tmp * 2;
        return 0;
    }
    //dijkstraAC();
    if (n <= 10)
    {
        ok[1] = 1;
        thu(2);
        if (res == oo)
            res = -1;
        cout << res;
        return 0;
    }
    cout << -1;
}
