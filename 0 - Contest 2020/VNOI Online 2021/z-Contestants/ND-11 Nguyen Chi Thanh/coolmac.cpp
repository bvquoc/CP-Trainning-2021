#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define nmax 100010
#define pb push_back
#define eb emplace_back

using namespace std;
int n,m,mi,f[nmax],st[4*nmax];
pii a[nmax];
vector<int> vt[nmax];
void update(int id,int l,int r,int i,int val)
{
    if (i>r || i<l) return;
    if (l==r)
    {
        st[id]=val;
        return;
    }

    int mid=(l+r)>>1;
    update(id*2,l,mid,i,val); update(id*2+1,mid+1,r,i,val);
    st[id]=min(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if (u>r || v<l) return 1e9;
    if (u<=l && v>=r) return st[id];

    int mid=(l+r)>>1;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main()
{
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].fi>>a[i].se;
        vt[a[i].fi].pb(a[i].se);
    }

    mi=1e9;
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        int x; cin>>x;
        mi=min(mi,x);
    }

    for (int i=0;i<=100000;i++) f[i]=1e9;

    for (int i=100000;i>=0;i--)
    {
        int ans=1e9;
        for (int j:vt[i]) ans=min(ans,get(1,1,100001,i+1,j+1)+1);
        f[i]=ans;
        update(1,1,100001,i,f[i]);
    }

    int res=1e9;
    for (int i=0;i<=mi;i++) res=min(res,f[i]);
    if (res>n) cout<<-1;
    else cout<<res;
    return 0;
}
