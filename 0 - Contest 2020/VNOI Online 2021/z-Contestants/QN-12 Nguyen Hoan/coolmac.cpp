#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fr(i,a,b) for(int i = a; i <= b; i++)
#define ll long long
#define pb push_back
typedef struct pair<long long, long long> ii;

vector<int> a[100010];
int start = 1e9;
int m,n;
ii Mac[100010];
ll d[100010];
ll res = 1e9;
vector<int> canStart, canStop;
void io () {
    freopen ("coolmac.inp", "r", stdin);
    freopen ("coolmac.out", "w", stdout);
}
void inp () {
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> Mac[i].fi >> Mac[i].se;
//        cout << Mac[i].fi << " " << Mac[i].se << "\n";
    }
    cin >> n;
    int t;
    for(int i = 1; i <= n; i++)
    {
        cin >> t;
        start = min(start, t);
    }
}

void dijkstra(int s)
{
    priority_queue<ii> qu;
    for(int i = 1; i <= m; i++)
    {
        d[i] = 1e9;
    }
    d[s] = 1;
    qu.push(ii(-1,s));
    while(qu.size() != 0)
    {
        ii top = qu.top();
        qu.pop();
        ll GT = -top.fi;
        ll u = top.se;
        if(GT != d[u]) continue;
        for(int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i];
            if(d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                qu.push(ii(-d[v], v));
            }
        }
    }
}

void sub () {
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(Mac[i].fi <= Mac[j].fi and Mac[i].se >= Mac[j].fi) {a[i].pb(j);continue;}
            if(Mac[i].se + 1 == Mac[j].fi) {a[i].pb(j);continue;}
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(Mac[i].fi <= start and start <= Mac[i].se) {canStart.pb(i);}//cout << "start " << i << "\n";}
        if(Mac[i].se == 100000) {canStop.pb(i);}// cout << "stop " << i << "\n";}
    }
    for(int i = 0; i < canStart.size(); i++)
    {
        int u = canStart[i];
        dijkstra(u);
        for(int j = 0; j < canStop.size(); j++)
        {
            int v = canStop[j];
            res = min(res, d[v]);
        }
    }
    if(res == 1e9)
    {
        cout << "-1";
    }
    else
    {
        cout << res;
    }
}

bool cmp(ii a, ii b)
{
    return a.fi < b.fi;
}

void sub2 ()
{
    sort(Mac + 1, Mac + 1 + m);
    int i = 1;
    int maxx;
    int ans = 0;
    while(true)
    {
        maxx = -1;
        while(Mac[i].fi <= start and i <= m)
        {
//            cout << Mac[i].fi << " " << i << "\n";
            maxx = max((ll)maxx, Mac[i].se);
            ++i;
        }
        if(maxx == -1)
        {
//            cout << start << "\n";
            cout << "-1";
            exit(0);
        }
        start = max(start, maxx); ++ ans;
        if(i > m || start >= 100000) break;
    }
    cout << ans;
}
int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    io ();
    inp ();
    if(m <= 3000) sub ();
    else
        sub2 ();
    return 0;
}

