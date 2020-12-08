/// !! Killian !! ///

#include <bits/stdc++.h>
#define Killian "CONSTRUCT"
#define MOD 1000000007
#define endl "\n"
#define pii pair <int,int>
using namespace std;
int T,n,m;
struct Tree
{
    long long lazy;
    long long maxl,maxr;
    long long val;
} st[400005];
Tree t= {-1,-1,-1,-1};
int a[100005];
void down(int node)
{
    long long delta = st[node].lazy;
    st[node*2].lazy += delta;
    st[node*2].maxl += delta;
    st[node*2].maxr += delta;
    st[node*2].val += delta;
    st[node*2+1].lazy += delta;
    st[node*2+1].maxl += delta;
    st[node*2+1].maxr += delta;
    st[node*2+1].val += delta;
    st[node].lazy = 0;
}
void make_st(int node,int l,int r)
{
    if (l==r)
    {
        st[node].maxl=a[l];
        st[node].maxr=a[l];
        st[node].val=a[l];
        return;
    }
    make_st(node*2,l,(l+r)/2);
    make_st(node*2+1,(l+r)/2+1,r);
    st[node].val=st[node*2].val+st[node*2+1].val-min(st[node*2].maxr,st[node*2+1].maxl);
    st[node].maxl=st[node*2].maxl;
    st[node].maxr=st[node*2+1].maxr;
}
void update(int node,int l,int r,int u,int v,int val)
{
    if (v < l || r < u)
        return ;
    if (u <= l && r <= v)
    {
        st[node].maxl += val;
        st[node].maxr += val;
        st[node].val += val;
        st[node].lazy += val;
        return ;
    }
    down(node);
    update(node*2,l,(l+r)/2,u,v,val);
    update(node*2+1,(l+r)/2+1,r,u,v,val);
    st[node].val=st[node*2].val+st[node*2+1].val-min(st[node*2].maxr,st[node*2+1].maxl);
    st[node].maxl=st[node*2].maxl;
    st[node].maxr=st[node*2+1].maxr;
}
Tree getans (int node,int l,int r,int u,int v)
{
    if (v < l || r < u)
        return t;
    if (u <= l && r <= v)
        return st[node];
    down(node);
    Tree h1=getans(node*2,l,(l+r)/2,u,v);
    Tree h2=getans(node*2+1,(l+r)/2+1,r,u,v);
    if (h1.val==t.val)
        return h2;
    else if (h2.val==t.val)
        return h1;
    Tree h;
    h.val=h1.val+h2.val-min(h1.maxr,h2.maxl);
    h.maxl=h1.maxl;
    h.maxr=h2.maxr;
    return h;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Killian".inp","r",stdin);
    freopen(Killian".out","w",stdout);
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        make_st(1,1,n);
        for (int i=1; i<=m; i++)
        {
            int type;
            cin>>type;
            if (type==1)
            {
                int l,r,k;
                cin>>l>>r>>k;
                update(1,1,n,l,r,k);
            }
            else
            {
                int l,r;
                cin>>l>>r;
                Tree res=getans(1,1,n,l,r);
                cout<<res.val<<endl;
            }
        }
        for (int i=1; i<=4*n; i++)
            st[i]= {0,0,0,0};
    }
}
