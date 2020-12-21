#include <bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define frd(i,x,y) for(int i=x;i>=y;i--)
#define ll long long
#define pii pair<long long,int>
#define piii pair<long long,pii>
#define fi first
#define se second
#define maxn 100100
#define Bit(x,i) ((x>>i)&1)
#define Turnoff(t,k) (t^(1<<(k)))
using namespace std;
int n,m,k,l;
int s[maxn],a[maxn][10];
long long d[maxn],dp[maxn][40],ans = 1e18;
vector<pii> e[maxn];
void inp()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DHAKA.inp","r",stdin);
    freopen("DHAKA.out","w",stdout);
    cin>>n>>m>>k>>l;
    fr(i,1,n)
    {
        cin>>s[i];
        fr(j,1,s[i]) cin>>a[i][j];
    }
    fr(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back(pii(v,w));
        e[v].push_back(pii(u,w));
    }
}
void dijk(int s)
{
    fr(i,1,n) d[i] = 1e18;
    priority_queue<pii> qu;
    d[s] = 0;
    qu.push(pii(0,s));
    while (!qu.empty())
    {
        pii top = qu.top();
        qu.pop();
        int u = top.se;
        long long du = -top.fi;
        if (du != d[u]) continue;
        for (pii child : e[u])
        {
            int v = child.fi, w = child.se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                qu.push(pii(-d[v],v));
            }
        }
    }
}
void sub2()
{
    dijk(1);
    if (d[n] == 1e18) cout<<"-1";
    else cout<<d[n];
}
void dijkAC()
{
    fr(i,1,n) fr(x,0,(1<<k)-1) dp[i][x] = 1e18;
    priority_queue<piii> qu;
    int mask = 0;
    fr(i,1,s[1]) mask += (1<<(a[1][i]-1));
    dp[1][mask] = 0;
    qu.push(piii(0,pii(1,mask)));
    while (!qu.empty())
    {
        piii top = qu.top();
        qu.pop();
        int u = top.se.fi;
        mask = top.se.se;
        long long du = -top.fi;
        if (du != dp[u][mask]) continue;
        for (pii child : e[u])
        {
            int v = child.fi, w = child.se;
            int newmask = mask;
            fr(i,1,s[v]) if (Bit(newmask,a[v][i]-1) == 0) newmask += (1<<(a[v][i]-1));
            if (dp[v][newmask] > dp[u][mask] + w)
            {
                dp[v][newmask] = dp[u][mask] + w;
                qu.push(piii(-dp[v][newmask],pii(v,newmask)));
            }
        }
    }
}
void subAC()
{
    dijkAC();
    fr(x,0,(1<<k)-1)
    {
        int cnt = 0;
        fr(i,1,k) if (Bit(x,i-1) == 1) cnt++;
        if (cnt < l) continue;
        ans = min(ans,dp[n][x]);
    }
    if (ans == 1e18) cout<<"-1";
    else cout<<ans;
}
int main()
{
    inp();
    if (l == 0) sub2();
    else subAC();
    return 0;
}
