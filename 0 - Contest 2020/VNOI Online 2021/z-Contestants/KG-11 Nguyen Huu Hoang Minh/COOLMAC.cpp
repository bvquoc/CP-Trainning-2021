#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 100005
#define remain(x) if (x > MOD) x -= MOD
#define ii pair<int, int>
#define vi vector<int>
#define vii vector< ii >
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "coolmac"
#define int long long

using namespace std;

typedef long double ld;

int n,m, Min = LLONG_MAX;
ii coat[N];
int f[N];

bool cmp(ii a, ii b)
{
    return a.se < b.se;
}

bool cmp2(int a, int b)
{
    return a > b;
}

void readfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen(Task".inp","r"))
    {
        freopen(Task".inp","r",stdin);
        freopen(Task".out","w",stdout);
    }
    cin >> m;
    for(int i=1; i<=m; i++)
    {
        cin >> coat[i].fi >> coat[i].se;
    }
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        Min = min(Min,x);
    }
    for(int i=1; i<=m; i++) f[i] = LLONG_MAX;
    sort(coat+1,coat+1+m,cmp);
}

void proc()
{
    f[m] = 1;
    if (coat[m].se < 100000) {cout << -1; return ;}
    for(int i=m-1; i>=1; i--)
    {
        for(int j=i+1; j<=m; j++)
        {
            if (coat[i].se >= coat[j].fi)
            {
                f[i] = min(f[i],f[j]+1);
            }
        }
    }
    int res=LLONG_MAX;
    for(int i=1; i<=m; i++) if (coat[i].fi <= Min && coat[i].se >= Min) res = min(res,f[i]);
    cout << res;
}

signed main()
{
    readfile();
    proc();
    return 0;
}
