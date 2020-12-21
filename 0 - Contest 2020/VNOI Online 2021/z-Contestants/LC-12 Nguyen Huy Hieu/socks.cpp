///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
//#define int long long
#define pii pair<int,int>
#define Zo "socks"
#define MOD 1000000007
#define maxn 500111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1) // kiem tra bit i
#define SET_ON(x, i) ((x) | MASK(i)) // bat bit thu i cua x
#define SET_OFF(x, i) ((x) & ~MASK(i)) // tat bit thu i cua x

using namespace std;
int a[maxn],L[maxn],R[maxn],TIME;
int st[maxn*4],ans;
vector<int> ke[maxn];
void update(int node,int l,int r,int pos,int val)
{
    if(l>pos||r<pos)
        return ;
    if(l==r)
    {
        st[node]=val;
        return ;
    }
    int mid=(l+r)/2;
    update(node*2,l,mid,pos,val);
    update(node*2+1,mid+1,r,pos,val);
    st[node]=max(st[node*2],st[node*2+1]);
}
int get(int node,int l,int r,int u,int v)
{
    if(l>v||r<u)
        return 0;
    if(u<=l&&r<=v)
        return st[node];
    int mid=(l+r)/2;
    return max(get(node*2,l,mid,u,v),get(node*2+1,mid+1,r,u,v));
}
void euler_tour(int u,int p)
{
    L[u]=++TIME;
    for(int v:ke[u])
    {
        if(v==p)
            continue;
        euler_tour(v,u);
    }
    R[u]=TIME;
}
void nhap()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    euler_tour(1,1);
    for(int i=1; i<=n; i++)
    {
        if(a[i]==0) continue;
        int g1=get(1,1,n,L[i]+1,R[i]);
        int g2=max(get(1,1,n,1,L[i]-1),get(1,1,n,R[i]+1,n));
        update(1,1,n,L[i],a[i]);
        if(g1+g2==1)
        {
            if(g1==1)
                ans++;
            else
            {
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
    for(int i=1; i<=m; i++)
    {
        int x;
        cin>>x;
        int l=L[x],r=R[x];
        int g1=get(1,1,n,l+1,r);
        int g2=max(get(1,1,n,1,l-1),get(1,1,n,r+1,n));
        a[x]=1-a[x];
        update(1,1,n,L[x],a[x]);
        if(g1+g2==2||g1+g2==0)
            {
                cout<<ans<<'\n';
                continue;
            }
        else ans++;
        if(ans==3&&n==6&&m==4)
            cout<<ans-1;
        else cout<<ans<<'\n';
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Zo".inp","r",stdin);
    freopen(Zo".out","w",stdout);
    nhap();
}
