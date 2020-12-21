#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;
#define TASK "COOLMAC"
int m,n;
int Max=1e5+2;
int Min=1e9;
struct Data
{
    int l,r;
    void Read()
    {
        cin>>l>>r;
        ++l,++r;
    }
    bool operator <(const Data &x)const
    {
        if(r==x.r)
            return l<x.l;
        return r>x.r;
    }
} a[N];
void inp()
{
    cin>>m;
    for(int i=1; i<=m; ++i)
        a[i].Read();
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        ++x;
        Min=min(Min,x);
    }
}
class SegmentTree
{
private:
    int t[4*N],d[4*N];
    void init(int node,int l,int r)
    {
        d[node]=1e9;
        t[node]=1e9;
        if(l==r)
        {
            if(r==Max)
                t[node]=0;
            return;
        }
        int mid=(l+r)>>1;
        init(node*2,l,mid);
        init(node*2+1,mid+1,r);
        t[node]=min(t[node*2],t[node*2+1]);
    }
    void lazyUpdate(int node,int l,int r)
    {
        if((l==r)||(d[node]==1e9))
            return;
        for(int x=node*2; x<=node*2+1; ++x)
        {
            t[x]=min(t[x],d[node]);
            d[x]=min(d[x],d[node]);
        }
        d[node]=1e9;
    }
    int GetMin(int node,int L,int R,int l,int r)
    {
        lazyUpdate(node,L,R);
        if(R<l||r<L)
            return 1e9;
        if(l<=L&&R<=r)
            return t[node];
        int mid=(L+R)>>1;
        int Left=GetMin(node*2,L,mid,l,r);
        int Right=GetMin(node*2+1,mid+1,R,l,r);
        return min(Left,Right);
    }
    void Update(int node,int L,int R,int l,int r,int x)
    {
        lazyUpdate(node,L,R);
        if(R<l||r<L)return;
        if(l<=L&&R<=r)
        {
            t[node]=min(t[node],x);
            d[node]=min(d[node],x);
            return;
        }
        int mid=(L+R)>>1;
        Update(node*2,L,mid,l,r,x);
        Update(node*2+1,mid+1,R,l,r,x);
        t[node]=min(t[node*2],t[node*2+1]);
    }
public:
    void init()
    {
        init(1,1,Max);
    }
    int GetMin(int l,int r)
    {
        return GetMin(1,1,Max,l,r);
    }
    void Update(int l,int r,int x)
    {
        Update(1,1,Max,l,r,x);
    }
} IT;
void solve()
{
    IT.init();
    sort(a+1,a+m+1);
    for(int i=1; i<=m; ++i)
    {
        int l=a[i].l,r=a[i].r;
        int res=IT.GetMin(l,r+1);
        IT.Update(l,r,res+1);
    }
    int ans=IT.GetMin(1,Min);
    cout<<((ans==1e9)?(-1):(ans));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    inp();
    solve();
    return 0;
}
