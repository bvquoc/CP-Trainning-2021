#include <bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define sz(x) (int)x.size()

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

struct ii{
    int u, s;
    ll w;
};

struct cmp{
    bool operator() (ii p1, ii p2){
        return p1.w < p2.w;
    }
};

priority_queue < ii, vector<ii>, cmp> hm;

vector <int> ke[N];
vector <ll> we[N];

int n, m, nk, l, a[N];
ll d[N][35];

void proc()
{
    for (int B = 0; B < (1 << nk); B++){
        for (int i = 1; i <= n; i++) d[i][B] = 1e18;
    }

    d[1][a[1]] = 0;
    hm.push({1, a[1], 0});

    while (!hm.empty()){
        ii x = hm.top();
        hm.pop();

        for (int i = 0; i < sz(ke[x.u]); i++){
            int v = ke[x.u][i], w = we[x.u][i];
            int s = a[v] | x.s;

            if (d[v][s] > x.w + w){
                d[v][s] = x.w + w;
                hm.push({v, s, d[v][s]});
            }
        }
    }

    ll ans = 1e18;
    for (int B = 0; B < (1 << nk); B++){
        int cnt = 0;

        for (int i = 0; i < nk; i++){
            if ((B >> i)&1) cnt++;
        }

        if (cnt >= l) ans = min(ans, d[n][B]);
    }

    if (ans >= 1e18) ans = -1;
    cout << ans;
}

int main()
{
    IOS;
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);

    cin >> n >> m >> nk >> l;
    for (int i = 1; i <= n; i++){
        int nn;
        cin >> nn;

        for (int j = 1; j <= nn; j++){
            int t;
            cin >> t;

            a[i] += (1 << (t - 1));
        }
    }

    for (int i = 1; i <= m; i++){
        int u, v , w;
        cin >> u >> v >> w;

        ke[u].pb(v);
        ke[v].pb(u);

        we[u].pb(w);
        we[v].pb(w);
    }

    proc();
}
