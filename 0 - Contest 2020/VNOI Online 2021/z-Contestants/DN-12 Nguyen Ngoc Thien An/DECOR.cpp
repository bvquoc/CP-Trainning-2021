#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define ll long long
#define ld double
#define up_b upper_bound
#define low_b lower_bound
#define mp make_pair
#define pb push_back

typedef pair<int,int> pii;

const int oo=1e9;
const int mod=1e9+7;
const int N=5e5;

template<class T> void ckmax(T &a,T b) {a=max(a,b);}
template<class T> void ckmin(T &a,T b) {a=min(a,b);}

ll Power(int x,int y)
{
    ll ans=1;
    for (ll t=x;y;y>>=1)
    {
        if (y&1) ans=(ans*t)%mod;
        t=(t*t)%mod;
    }
    return  ans;
}
ll Rev(int x)
{
    return Power(x,mod-2);
}
bool gt[N+5];
int a[N+5];
int f[N+5];
vector<int> dsk[N+5];
int P[N+5];
int n,m,k;
void dfs(int u,int p,int M)
{
    a[u]=M;
    for (int v:dsk[u])
    {
        if (v==p) continue;
        if (a[v]) continue;
        dfs(v,u,M);
    }
    if (gt[u]) f[M]++;
}
int check(int x)
{
    for (int i=1;i<=n;i++) P[i]=0;
    for (int i=1;i<=x;i++)
        P[a[i]]++;
    int ans=0;
    for (int i=1;i<=n;i++) ans+=max(0,P[i]-f[i]);
    if (ans<=k) return 1;
    for (int i=x+1;i<=n;i++)
    {
        P[a[i-x]]--;if (P[a[i-x]]>=f[a[i-x]]) ans--;
        P[a[i]]++;if (P[a[i]]>f[a[i]]) ans++;
        if (ans<=k) return i-x+1;
    }
    return 0;

}
int main()
{
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>n>>m>>k>>s;
    for (int i=0;i<s.size();i++) gt[i+1]=s[i]-'0';
    for (int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        dsk[x].pb(y);
        dsk[y].pb(x);
    }
    for (int i=1;i<=n;i++) if (!a[i]) dfs(i,0,i);
//    for (int i=1;i<=n;i++) cout<<a[i]<<' '<<f[i]<<endl;
    int l=1,r=n;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (check(mid)) l=mid+1;
        else r=mid-1;
    }
//    for (int i=1;i<=n;i++) cout<<gt[i]<<' '<<a[i]<<' '<<f[i]<<endl;
//    cout<<check(3)<<endl;
    if (r==0) {cout<<-1;return 0;}
    int u=check(r);
    cout<<u<<' '<<u+r-1;
}

