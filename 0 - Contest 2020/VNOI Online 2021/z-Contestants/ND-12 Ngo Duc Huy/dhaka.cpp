#include <bits/stdc++.h>
#define FILE "dhaka"
#define ll long long
using namespace std;

const int N = 1e5+7;
const ll oo = 1e15+7;
int n,m,l,k,
    s[N],sobit[1<<5];
struct tp
{
    int u;ll w;
    bool operator > (const tp &o) const
    {
        return w > o.w;
    }
};
vector<tp> a[N];
ll f[N][(1<<5)];
void sub2()
{
    for(int i=1;i<=n;i++) f[i][0]=oo;
    f[1][0]=0;
    priority_queue<tp,vector<tp>,greater<tp> > pq;
    pq.push({1,0});
    while(pq.size())
    {
        int u=pq.top().u;
        ll d=pq.top().w;
        pq.pop();
        if(d != f[u][0]) continue;
        if(u==n)
        {
            cout<<d;
            return ;
        }
        for(tp &v:a[u])
            if(f[v.u][0] > d+v.w)
            {
                f[v.u][0]=d+v.w;
                pq.push({v.u,d+v.w});
            }
    }
    cout<<-1;
}
struct tp2
{
    int u;ll w;int tt;
    bool operator > (const tp2 &o) const
    {
        return w > o.w;
    }
};
void sub3()
{
    for(int i=1;i<=n;i++)
        f[i][0]=f[i][1]=oo;
    f[1][s[1]]=0;
    priority_queue<tp2,vector<tp2>,greater<tp2> > pq;
    pq.push({1,0,s[1]});
    while(pq.size())
    {
        int u=pq.top().u;
        ll d=pq.top().w;
        int tt=pq.top().tt;
        pq.pop();
        if(d != f[u][tt]) continue;
        if(u==n && sobit[tt]==l)
        {
            cout<<d;
            return ;
        }
        for(tp &v:a[u])
            if(f[v.u][tt|s[v.u]] > d+v.w)
            {
                f[v.u][tt|s[v.u]]=d+v.w;
                pq.push({v.u,d+v.w,tt|s[v.u]});
            }
    }
    cout<<-1;
}
void sub()
{
    for(int i=1;i<=n;i++)
        for(int j=0;j<(1<<k);j++) f[i][j]=oo;
    f[1][s[1]]=0;
    priority_queue<tp2,vector<tp2>,greater<tp2> > pq;
    pq.push({1,0,s[1]});
    while(pq.size())
    {
        int u=pq.top().u;
        ll d=pq.top().w;
        int tt=pq.top().tt;
        pq.pop();
        if(d != f[u][tt]) continue;
        if(u==n && sobit[tt]==l)
        {
            cout<<d;
            return ;
        }
        for(tp &v:a[u])
            if(f[v.u][tt|s[v.u]] > d+v.w)
            {
                f[v.u][tt|s[v.u]]=d+v.w;
                pq.push({v.u,d+v.w,tt|s[v.u]});
            }
    }
    cout<<-1;
}
int main()
{
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<(1<<5);i++) sobit[i]=__builtin_popcount(i);
    //for(int i=0;i<(1<<5);i++) cout<<i<<' '<<sobit[i]<<'\n';
    cin>>n>>m>>k>>l;
    int x,y,z;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        for(int j=1;j<=x;j++) cin>>y,s[i]|=(1<<(y-1));
    }
    //for(int i=1;i<=n;i++) cout<<s[i]<<'\n';
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        a[x].push_back({y,z});
        a[y].push_back({x,z});
    }
    if(l==0) {sub2();return 0;}
    if(k==1) {sub3();return 0;}
    sub();
}
