#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 200005
#define remain(x) if (x > MOD) x -= MOD
#define ii pair<int, int>
#define vi vector<int>
#define vii vector< ii >
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "decor"
#define int long long

using namespace std;

typedef long double ld;

int n,m,k;
vector<int> a[N];
int bi[N];

void readfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen(Task".inp","r"))
    {
        freopen(Task".inp","r",stdin);
        freopen(Task".out","w",stdout);
    }
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++)
    {
        char x;
        cin >> x;
        bi[i] = x-'0';
    }
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin >> u >> v;
        a[u].pb(v);
    }
}

void proc()
{
    int res = -99;
    if (k==0 && m==0)
    {
        int pre = 0;
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            if (pre==0 && bi[i]==1)
            {
                pre = 1;
                ans = 1;
                res = max(res,ans);
            }
            else if (pre==1 && bi[i]==1) ans++, res = max(res,ans);
            else if (pre==1 && bi[i]==0) ans=0, pre=0;
        }
    }
    cout << res;
}

signed main()
{
    readfile();
    proc();
    return 0;
}
