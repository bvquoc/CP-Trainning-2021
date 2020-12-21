#include <bits/stdc++.h>
#define task "coolmac"
#define ll long long
#define MAX 100000
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define MIN(x,y) x=min(x,y)
#define INF 1000000000
using namespace std;
int st[(MAX+1)*8+5];
int NEXT[MAX+5],n,m;

void build(int id,int l,int r)
{
    if(l>r) return ;
    if(l==r)
    {
        st[id]=INF;
        return ;
    }
    int mid=(l+r)/2;
    build(id*2  ,l    ,mid);
    build(id*2+1,mid+1,r  );
    st[id]=min(st[id*2],st[id*2+1]);
}

void update(int id,int l,int r,int i,int val)
{
    if(i<l||r<i) return;
    if(i==l&&r==i)
    {
        st[id]=min(st[id],val);
        return ;
    }
    int mid=(l+r)/2;
    update(id*2  ,l    ,mid,i,val);
    update(id*2+1,mid+1,r  ,i,val);
    st[id]=min(st[id*2],st[id*2+1]);
}

int get(int id,int l,int r,int u,int v)
{
    if(l>v||r<u) return INF;
    if(u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n;

    rep(i,1,n)
    {
        int L,R;
        cin>>L>>R;L++;R++;
        NEXT[L]=max(NEXT[L],R);
    }

    build(1,1,MAX+1);

    for(int L=MAX+1;L>=1;--L) if(NEXT[L])
    {
        int R=NEXT[L],val;
        if(R==MAX+1) val=1;
        else val=get(1,1,MAX+1,L,R)+1;
        update(1,1,MAX+1,L,val);
    }

    cin>>m;

    int hi=INF;
    for(int i=1;i<=m;++i)
    {
        int t;cin>>t;
        hi=min(hi,t+1);
    }

    int result=INF;
    result=min(result,get(1,1,MAX+1,1,hi));

    if(result==INF) cout<<-1;
    else            cout<<result;
}
