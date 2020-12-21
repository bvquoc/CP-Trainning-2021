#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fr(i,a,b) for(int i = a; i <= b; i++)
#define ll long long
#define ii pair<long long,long long>
#define pb push_back

int n,m,k,l;
int s[100010];
vector<ii> ed[100010];
int a[100010][10];
ll d[100010];

void io () {
    freopen ("dhaka.inp", "r", stdin);
    freopen ("dhaka.out", "w", stdout);
}

void inp () {
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for(int j = 1; j <= s[i]; j++)
        {
            cin >> a[i][j];
        }
    }
    int u, v;
    ll w;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        ed[u].pb(ii(w, v));
        ed[v].pb(ii(w, u));
    }
}

void dijkstra1(int s)
{
    priority_queue<ii> qu;
    for(int i = 1;  i <= n; i++)
    {
        d[i] = 1e18;
    }
    d[s] = 0;
    qu.push(ii(0,s));
    while(qu.size() != 0)
    {
        ii top = qu.top();
        qu.pop();
        ll GT = - top.fi;
        int u = top.se;
        if(GT != d[u]) continue;
        for(int i = 0; i < ed[u].size(); i++)
        {
            int v = ed[u][i].se;
            ll w = ed[u][i].fi;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                qu.push(ii(-d[v],v));
            }
        }
    }
}

void sub2 () {
    dijkstra1(1);
    if(d[n] == 1e18)
    {
        cout << "-1";
    }
    else cout << d[n];
}

ll dist[3][100010];
void dijkstra2(int id, int s)
{
    priority_queue<ii> qu;
    for(int i = 1; i <= n; i++)
    {
        dist[id][i] = 1e18;
    }
    dist[id][s] = 0;
    qu.push(ii(0,s));
    while(qu.size() != 0)
    {
        ii top = qu.top();
        qu.pop();
        ll GT = -top.fi;
        int u = top.se;
//        cout << u << " " << GT << "\n";
        if(GT != dist[id][u]) continue;
        for(int i = 0 ; i < ed[u].size(); i++)
        {
            int v = ed[u][i].se;
            ll w = ed[u][i].fi;
            if(dist[id][v] > dist[id][u] + w)
            {
                dist[id][v] = dist[id][u] + w;
                qu.push(ii(-dist[id][v], v));
            }
        }
    }
}

void sub3 ()
{
    dijkstra2(1,1);
    dijkstra2(2,n);
    for(int i = 1; i <= n; i++)
    {
//        cout << dist[1][i] << "\n";
    }
    ll res = 1e18;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] >= l)
        {
            res = min(res, dist[1][i] + dist[2][i]);
        }
    }
    if(res == 1e18)
    {
        cout << "-1";
    }
    else cout << res;
}

int tt[20];
ll canh[110][110];
void sub1 ()
{
//    cout << n << "\n";
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) canh[i][j] = 1e18;
    for(int i = 1; i <= n; i++)
    {
        tt[i] = i;
        canh[i][i] = 0;
        for(int j = 0; j < ed[i].size(); j++)
        {
            canh[i][ed[i][j].se] = ed[i][j].fi;
            canh[ed[i][j].se][i] = ed[i][j].fi;
        }
    }
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
    {
        if(i == j) continue;
        canh[i][j] = min(canh[i][j], canh[i][k] + canh[k][j]);
    }
//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 1; j <= n; j++)
//        {
//            cout << canh[i][j] << " " << i << " " << j << "\n";
//        }
//    }
    ll ans = 1e18;
    do
    {
        int start = 1;
        int endd = n;
        set<int> nowHave;
        for(int i = 1; i <= s[start]; i++)
        {
            nowHave.insert(a[start][i]);
        }
        for(int i = 1; i <= s[endd]; i++)
        {
            nowHave.insert(a[endd][i]);
        }
        ll res = 0;
//        cout << start << " ";
        if(nowHave.size() >= l)
        {
            res += canh[start][endd];
            ans = min(ans, res);
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            res += canh[start][tt[i]];
            for(int j = 1; j <= s[tt[i]]; j++)
            {
                nowHave.insert(a[tt[i]][j]);
            }
            if(nowHave.size() >= l)
            {
                res += canh[tt[i]][endd];
                ans = min(ans, res);
                break;
            }
            start = tt[i];
        }
        if(nowHave.size() >= l)
        {
            res += canh[start][endd];
            ans = min(ans, res);
        }
    } while(next_permutation(tt + 1, tt + n + 1));
    if(ans == 1e18)
    {
        cout << "-1";
    }
    else cout << ans;
}


int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    io ();
    inp ();
    if(n <= 10) {sub1 (); return 0;}
    if(l == 0) {sub2 (); return 0;}
    sub3 ();
    return 0;
}

