#include <bits/stdc++.h>
#define ll long long
const int N=1e5+5;
using namespace std;
int t;
int n,m;
int a[N];
ll b[N],f[N];
inline int ReadInt()
{
    char c;
    for(c=getchar(); '0'>c||c>'9'; c=getchar());
    int x=c-'0';
    for(c=getchar(); '0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    return x;
}
struct SegmentTree
{
    ll t[4*N],d[4*N];
    int L[4*N],R[4*N];
    void init(int node,int l,int r)
    {
        L[node]=l,R[node]=r;
        if(l==r)
        {
            t[node]=a[l];
            return;
        }
        int mid=(l+r)>>1;
        init(node*2,l,mid);
        init(node*2+1,mid+1,r);
    }
    void lazy_update(int node)
    {
        if(L[node]<R[node])
        {
            t[node*2]+=d[node];
            d[node*2]+=d[node];
            t[node*2+1]+=d[node];
            d[node*2+1]+=d[node];
        }
        d[node]=0;
    }
    ll Get(int node,int l,int r)
    {
        if(R[node]<l||r<L[node])
            return 0;
        if(l<=L[node]&&R[node]<=r)
            return t[node];
        ll trai=Get(node*2,l,r);
        ll phai=Get(node*2+1,l,r);
        return trai+phai;
    }
    void update(int node,int l,int r,ll val)
    {
        if(R[node]<l||r<L[node])
            return;
        if(l<=L[node]&&R[node]<=r)
        {
            t[node]+=val;
            d[node]+=val;
            return;
        }
        lazy_update(node);
        update(node*2,l,r,val);
        update(node*2+1,l,r,val);
    }
    void del()
    {
        memset(t,0,sizeof(t));
        memset(d,0,sizeof(d));
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
    }
} IT;
void inp()
{
    n=ReadInt(),m=ReadInt();
    for(int i=1; i<=n; ++i)
        a[i]=ReadInt();
}
void solve1(int l,int r)
{
    int val;
    val=ReadInt();
    IT.update(1,l,r,val);
}
void solve2(int l,int r)
{
    ll ans=0;
    for(int i=l; i<=r; ++i)
        b[i]=IT.Get(1,i,i);
    stack<int>st;
    for(int i=l;i<=r;++i)
    {
        bool kt=false;
        while(st.size()&&b[st.top()]>=b[i])
        {
            if(b[st.top()]==b[i])f[i]=0;
            st.pop();
        }
        if(kt)
        {
            st.push(i);
            continue;
        }
        if(!st.size())f[i]=b[i];
        else f[i]=b[i]-b[st.top()];
        st.push(i);
    }
    while(st.size())st.pop();
    for(int i=r;i>=l;--i)
    {
        while(st.size()&&b[st.top()]>b[i])st.pop();
        if(!st.size())f[i]=min(f[i],b[i]);
        else f[i]=min(f[i],b[i]-b[st.top()]);
        st.push(i);
    }
    for(int i=l;i<=r;++i)
        ans+=f[i];
    cout<<ans<<"\n";
}
void process()
{
    IT.init(1,1,n);
    while(m--)
    {
        int type,l,r;
        type=ReadInt(),l=ReadInt(),r=ReadInt();
        if(type==1)
            solve1(l,r);
        else
            solve2(l,r);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CONSTRUCT.inp","r",stdin);
    freopen("CONSTRUCT.out","w",stdout);
    t=ReadInt();
    while(t--)
    {
        inp();
        process();
        IT.del();
    }
    return 0;
}
