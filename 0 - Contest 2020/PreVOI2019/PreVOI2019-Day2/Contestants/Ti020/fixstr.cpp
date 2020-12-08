#include <bits/stdc++.h>
#define LL long long
#define F first
#define S second
#define PII pair<int,int>
using namespace std;
const int N=100001;
struct data
{
    char f;
    int s,t;
}p[N];
int lz[N*4],it[N*4],kt[N],m,n,d[N];
string s;
vector<int> a[N];
void ud(int k,int d,int c,int l,int r,int val)
{
    if (d!=c)
    {
        lz[k*2]+=lz[k];
        lz[k*2+1]+=lz[k];
    }
    it[k]+=lz[k];
    lz[k]=0;
    if (d>r||c<l) return;
    if (d>=l&&c<=r)
    {
        it[k]+=val;
        //cout<<d<<" "<<c<<" "<<val<<" "<<l<<" "<<r<<" "<<it[k]<<"\n";
        if (d!=c)
        {
            lz[k*2]+=val;
            lz[k*2+1]+=val;
        }
        return;
    }
    int m=(d+c)/2;
    ud(k*2,d,m,l,r,val);
    ud(k*2+1,m+1,c,l,r,val);
    it[k]=min(it[k*2],it[k*2+1]);
}
int tv(int k,int d,int c,int l,int r)
{
    if (d!=c)
    {
        lz[k*2]+=lz[k];
        lz[k*2+1]+=lz[k];
    }
    it[k]+=lz[k];
    lz[k]=0;
    if (d>r||c<l) return 1e9;
    if (d>=l&&c<=r) return it[k];
    int m=(d+c)/2;
    return min(tv(k*2,d,m,l,r),tv(k*2+1,m+1,c,l,r));
}
void dfs(int u)
{
    if (p[u].f=='Q')
    {
        int x=tv(1,0,n,p[u].s-1,p[u].s-1);
        int y=tv(1,0,n,p[u].s,p[u].t);
        int z=tv(1,0,n,p[u].t,p[u].t);
        y-=x;
        z-=x;
        kt[u]=max(-y,0)*2+z;
    }
    if (p[u].f=='C')
    {
        int cs=p[u].s;
        //cout<<u<<" "<<cs<<" ";
        if (s[cs-1]==')') s[cs-1]='(',ud(1,0,n,cs,n,2);
        else s[cs-1]=')',ud(1,0,n,cs,n,-2);
    }
    for (auto v:a[u]) dfs(v);
    if (p[u].f=='C')
    {
        int cs=p[u].s;
        if (s[cs-1]==')') s[cs-1]='(',ud(1,0,n,cs,n,2);
        else s[cs-1]=')',ud(1,0,n,cs,n,-2);
    }
}
int main()
{
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    ios_base::sync_with_stdio();
    cin.tie(0);cout.tie(0);
    cin>>s;
    cin>>m;
    n=s.length();
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        if (s[i-1]=='(') sum++;
        else sum--;
        ud(1,0,n,i,i,sum);
    }
    for (int i=1;i<=m;i++) d[i]=i;
    for (int i=1;i<=m;i++)
    {
        cin>>p[i].f>>p[i].s;
        if (p[i].f=='Q') cin>>p[i].t;
        if (p[i].f=='U') d[i]=d[p[i].s-1];
        else a[d[i-1]].push_back(i);
    }
    dfs(0);
    for (int i=1;i<=m;i++)
    if (p[i].f=='Q') cout<<kt[i]<<"\n";
    return 0;
}
