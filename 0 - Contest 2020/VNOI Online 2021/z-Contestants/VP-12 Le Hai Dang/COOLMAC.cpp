#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long LL;
const int MAXN=1+3e5;
const int inf=1+1e9;
const LL mod=1e9+7;
int n,m,a[MAXN];
pair<int,int> p[MAXN],p1[MAXN];
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.se==b.se) return a.fi<b.fi;
    else return a.se<b.se;
}
int f[MAXN],cnt,mi=inf,cnt1,kt[MAXN];
queue<int> q,q1;
int main()
{
#define TASK "COOLMAC"
    if(fopen(TASK ".inp","r"))
    {
        freopen(TASK ".inp","r",stdin);
        freopen(TASK ".out","w",stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>m;
    for(int i=1; i<=m; ++i)
    {
        cin>>p[i].fi>>p[i].se;
    }
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        cin>>a[i];
        mi=min(mi,a[i]);
    }
    sort(p+1,p+m+1,cmp);
    for(int i=1; i<=m; ++i)
    {

        if(q.empty())
        {
            q.push(i);
            continue;
        }
        while(!q.empty()&&p[q.front()].fi>=p[i].fi)
        {
            q.pop();
        }
        q.push(i);
    }
    while(!q.empty())
    {
        f[++cnt]=q.front();
        q.pop();
    }

    for(int i=1; i<=cnt; ++i)
    {

        p1[i]=p[f[i]];
    }
    sort(p1+1,p1+cnt+1);
    for(int i=1; i<=cnt; ++i)
    {
        if(q1.empty())
        {
            q1.push(i);
            continue;
        }
        if(!q1.empty()&&p1[i].fi<=mi)
        {
            q1.pop();
        }
        q1.push(i);
    }
    int ans=q1.size();
    while(!q1.empty())
    {
        int u=p1[q1.front()].fi,v=p1[q1.front()].se;
        kt[u]+=1;
        kt[v+1]-=1;
        q1.pop();
    }
    for(int i=1; i<=100000; ++i)
    {
        kt[i]+=kt[i-1];
    }
    for(int i=mi; i<=100000; ++i)
    {
        if(kt[i]==0)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
