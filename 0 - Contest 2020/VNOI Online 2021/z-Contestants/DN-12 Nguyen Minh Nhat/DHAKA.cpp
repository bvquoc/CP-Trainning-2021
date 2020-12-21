#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nhat "dhaka"
#define db double
#define pb push_back
#pragma GCC optimize("Ofast")
const int mm=1e5+5;
const ll oo=1e15+7;
int n,m,k,l;
struct ii
{
    int u;
    ll w;
};
vector<ii> e[mm];
vector<int> mau[mm];
ll v_dd[mm],v_ddn[mm];
int v_kt[mm];
struct v_ss
{
    bool operator()(ii x,ii y)
    {
        return x.w>y.w;
    }
};
priority_queue<ii,vector<ii>,v_ss> v_hmi;
void v_dijstra(int id)
{
    for(int i=1;i<=n;i++)
        v_dd[i]=oo,v_kt[i]=0;
    v_dd[id]=0; v_hmi.push({id,0});
    while(v_hmi.size())
    {
        ii fi=v_hmi.top(); v_hmi.pop();
        if(v_dd[fi.u]<fi.w) continue;
        v_kt[fi.u]=1;
        for(ii se:e[fi.u])
            if(!v_kt[se.u]&&v_dd[se.u]>v_dd[fi.u]+se.w)
                v_dd[se.u]=v_dd[fi.u]+se.w,v_hmi.push({se.u,v_dd[se.u]});
    }
}
void sub2()
{
    v_dijstra(1);
    if(v_dd[n]-oo) printf("%lld",v_dd[n]);
    else printf("-1");
}
void sub3()
{
    v_dijstra(n);
    for(int i=1;i<=n;i++) v_ddn[i]=v_dd[i];
    v_dijstra(1);
    ll re=oo;
    for(int i=1;i<=n;i++)
        if(mau[i].size()) re=min(re,(ll)v_ddn[i]+v_dd[i]);
    if(re-oo) printf("%lld",re);
    else printf("-1");
}
struct iii
{
    int u,np;
    ll w;
};
struct ss
{
    bool operator()(iii x,iii y)
    {
        return x.w>y.w;
    }
};
priority_queue<iii,vector<iii>,ss> hmi;
ll dd[mm][35];
int kt[mm][35];
int tao(int x,int id)
{
    for(int i:mau[id]) x=(x|(1<<(i-1)));
    return x;
}
void dijstra(int id)
{
    for(int i=1;i<=n;i++)
        for(int j=0;j<(1<<k);j++) dd[i][j]=oo,kt[i][j]=0;
    int tam=tao(0,id);
    dd[id][tam]=0; hmi.push({id,tam,0});
    while(hmi.size())
    {
        iii fi=hmi.top(); hmi.pop();
        if(dd[fi.u][fi.np]<fi.w) continue;
        kt[fi.u][fi.np]=1;
        for(ii se:e[fi.u])
        {
            int tt=tao(fi.np,se.u);
            if(!kt[se.u][tt]&&dd[se.u][tt]>dd[fi.u][fi.np]+se.w)
                dd[se.u][tt]=dd[fi.u][fi.np]+se.w,hmi.push({se.u,tt,dd[se.u][tt]});
        }
    }
}
bool check(int x)
{
    int tam=0;
    for(int i=0;i<k;i++) tam+=((x>>i)&1);
    return tam>=l;
}
void giai()
{
    dijstra(1);
    ll re=oo;
    for(int j=0;j<(1<<k);j++)
        if(check(j)) re=min(re,(ll)dd[n][j]);
    if(re-oo) printf("%lld",re);
    else printf("-1");
}
int main()
{
    freopen(nhat".inp","r",stdin);
    freopen(nhat".out","w",stdout);
    scanf("%d %d %d %d",&n,&m,&k,&l);
    for(int i=1;i<=n;i++)
    {
        int x; scanf("%d",&x);
        for(int j=1;j<=x;j++)
        {
            int y; scanf("%d",&y);
            mau[i].pb(y);
        }
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,z; scanf("%d %d %d",&x,&y,&z);
        e[x].pb({y,z}); e[y].pb({x,z});
    }
    if(!l) sub2();
    else if(k==1) sub3();
    else giai();
}
