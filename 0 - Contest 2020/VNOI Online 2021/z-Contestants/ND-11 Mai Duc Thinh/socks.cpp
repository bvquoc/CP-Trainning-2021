#include<bits/stdc++.h>
#define fort(i,a,b) for(long i=a;i<=b;i++)
#define pb push_back
using namespace std;
const long N=5e5+5;
long n,q,p[N],visit[N],type[5],f[N],up[N];
vector<vector<long> > a;
bool ok1()
{
    fort(i,1,n)
     if (a[i].size()>2) return false;
    return true;
}
bool ok2()
{
    long cnt=0;
    fort(i,1,n)
     if (a[i].size()>3) return false;else
         if (a[i].size()==3) cnt++;
    if (cnt==1) return true;
    return false;
}
void sub1()
{
    long cnt=0;
    fort(i,1,n)
     if (p[i]) cnt++;
    cout<<(cnt>=2)<<'\n';
    while (q--)
    {
        long x;
        cin>>x;
        if (p[x]==0)
        {
            p[x]=1;
            cnt++;
        } else
        {
            p[x]=0;
            cnt--;
        }
        cout<<(cnt>=2)<<'\n';
    }
}
void dfs(long x,long cnt)
{
    visit[x]=cnt;
    for(long i:a[x])
        if (!visit[i])
         dfs(i,cnt);
}
void sub2()
{
    fort(i,1,n)
     if (a[i].size()==3)
     {
         visit[i]=1;
         long cnt=0;
         for(long j:a[i])
            dfs(j,++cnt);
        visit[i]=0;
     }
    long cnt=0;
    fort(i,1,n)
     if (p[i])
        {
            cnt++;
            type[visit[i]]++;
        }
    if (cnt<=1) cout<<"0\n";else
        if ((type[1]!=0)+(type[2]!=0)+(type[3]!=0)<=2) cout<<"1\n";else cout<<"2\n";
    while (q--)
    {
        long x;
        cin>>x;
        if (p[x]==0)
        {
            p[x]=1;
            cnt++;
            type[visit[x]]++;
        } else
        {
            p[x]=0;
            cnt--;
            type[visit[x]]--;
        }
        if (cnt<=1) cout<<"0\n";else
            if ((type[1]!=0)+(type[2]!=0)+(type[3]!=0)<=2) cout<<"1\n";else cout<<"2\n";
    }
}
void dfs1(long x)
{
    visit[x]=1;
    long cnt=0;
    for(long i:a[x])
        if (!visit[i])
    {
        dfs1(i);
        f[x]+=f[i];
        if (up[i]) cnt++;
    }
    if (p[x]==1&&cnt==0) up[x]=1;
    if (cnt%2) up[x]=1;
    f[x]+=cnt/2;
}
void sub3()
{
    fort(i,1,n) f[i]=0;
    dfs1(1);
    if (up[1]) f[1]++;
    cout<<f[1]<<'\n';
    while (q--)
    {
        long x;
        cin>>x;
        p[x]=1-p[x];
        fort(i,1,n) visit[i]=0;
        fort(i,1,n) f[i]=0;
        fort(i,1,n) up[i]=0;
        dfs1(1);
        if (up[1]) f[1]++;
        cout<<f[1]<<'\n';
    }
}
int main()
{
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    a.resize(n+1);
    fort(i,1,n) cin>>p[i];
    fort(i,1,n-1)
    {
        long u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(v);
    }
    if (ok1()) sub1();else
        if (ok2()) sub2();else
            sub3();
}
