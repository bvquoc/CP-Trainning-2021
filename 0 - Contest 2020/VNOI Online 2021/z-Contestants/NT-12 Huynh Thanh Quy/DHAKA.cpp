#include <bits/stdc++.h>
#define name "DHAKA"
#define mk make_pair
#define pb push_back
#define ll long long
#define pll pair<ll ,ll>
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
#define pii pair<int,int>
using namespace std;
using plll =pair<ll, pair<ll, ll > >;
const int maxn=1e5+7;
const ll maxd=1e17;
vector<pll> e[maxn];
ll  n, m, k, l;
int cha[maxn];
bool a[maxn][7],bd[6];
void enter()
{
    cin>> n>> m>> k>> l;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>> x;
        for(int j=1; j<=x; j++)
        {
            int y;
            cin>> y;
            bd[y]=true;
            a[i][y]=true;
        }
    }
    for(int i=1; i<=m; i++)
    {
        ll u, v, w;
        cin>> u>> v>>w;
        e[u].pb(mk(v,w));
        e[v].pb(mk(u,w));
    }
    int cnt=0;
    for(int i=1;i<=k;i++)
        if(bd[i]) cnt++;
    if(cnt<l) {cout<<-1; exit(0);}

}
void sub1()
{
    priority_queue<pll, vector<pll>, greater <pll> > qu;
    vector<ll > d(maxn,maxd);
    qu.push(mk(0,1));
    d[1]=0;
    while(qu.size())
    {
        ll  u=qu.top().second;
        ll du = qu.top().first;
        qu.pop();
        if(du!=d[u])
            continue;
        if(u== n)
        {
            cout<< du;
            exit(0);
        }
        for(pll v: e[u])
            if(d[v.first]> d[u]+(ll)v.second)
        {
            d[v.first]= d[u]+(ll)v.second;
            qu.push(mk(d[v.first], v.first));
        }

    }
    cout<<-1;
}
void sub2()
{
    priority_queue<plll, vector<plll > , greater<plll> > qu;
    priority_queue<pll> wu;
    vector<ll> f(maxn,maxd); vector<ll> d(maxn,maxd);
    for(int  i=1;i<=n;i++)
        if(a[i][1]==true)
        {
            wu.push(mk(0,i)); f[i]=0;
        }
    ll vt=0;
    while(wu.size())
    {
        ll u=wu.top().second;
        ll du=wu.top().first;
        wu.pop();
        if(du!=f[u]) continue;
        if(u==n) {
           while(0!=cha[u])
           {
               u=cha[u];
           }
           vt=u; break;
        }
        for(pll v:e[u])
            if(f[v.first]> f[u]+v.second)
        {
            cha[v.first]=u;
            f[v.first]= f[u]+v.second;
            wu.push(mk(f[v.first],v.first));
        }
    }
    qu.push(mk(0,mk(1,a[1][1])));
    d[1]=0;
    ll res=0;
    bool stop=false;
    while(qu.size())
    {
        plll u =qu.top();
        qu.pop();
        if(u.first!=d[u.second.first]) continue;
        if(u.second.first==vt)
        {
            if(res==0) res= u.first+f[n];
            else  res=min(res,u.first+f[n]);
            if(stop==true) break;
            stop=true;
        }
        if(u.second.first==n)
        {
            if(u.second.second==1) { cout<< u.first; exit(0);}
            if(res==0) {res= u.first +2*f[n]; continue;}
            else  res=min(res,u.first +2*f[n]);
           break;
        }
        for(pll v: e[u.second.first])
        {
            if(d[v.first]> d[u.second.first]+v.second)
            {
                d[v.first]= d[u.second.first]+v.second;
                if(u.second.second==0) u.second.second=a[v.first][1];
                qu.push(mk(d[v.first],mk(v.first,u.second.second)));
            }
        }

    }
    cout<<res;

}
int main()
{
    ios;
    freopen(name".INP","r",stdin);
 freopen(name".OUT","w",stdout);
    enter();
    if(l==0)
        sub1();
    else
    {
        if(k==1) sub2();
        else
            sub1();
    }


    return 0;
}
