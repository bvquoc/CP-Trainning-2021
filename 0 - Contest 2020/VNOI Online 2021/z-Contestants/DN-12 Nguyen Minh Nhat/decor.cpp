#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nhat "decor"
#define db double
#define pb push_back
#pragma GCC optimize("Ofast")
const int mm=5e5+5;
int n,m,k;
int a[mm];
vector<int> e[mm],st[mm];
int s[mm],xl[mm];
int re=0,vt;
void vet()
{
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int jj=0;
    for(int i=1;i<=n;i++)
    {
        while(jj<n&&s[jj+1]-s[i-1]+k>=jj+2-i) jj++;
        if(re<jj-i+1) re=jj-i+1,vt=i;
    }
    if(re) printf("%d %d",vt,vt+re-1);
    else printf("-1");
}
int f[mm];
void upd(int v,int val)
{
    while(v<=n) f[v]+=val,v+=(v&-v);
}
int get(int u,int v)
{
    int res=0;
    while(v>=u)
        if(v-(v&-v)>=u) res+=f[v],v-=(v&-v);
        else res+=a[v],v--;
    return res;
}
int kt[mm];
int cnt=0;
void dfs(int u)
{
    kt[u]=cnt;
    xl[cnt]+=a[u];
    st[cnt].pb(u);
    for(int v:e[u])
        if(!kt[v]) dfs(v);
}
void giai()
{
    scanf("\n");
    for(int i=1;i<=m;i++)
    {
        int x,y; scanf("%d %d\n",&x,&y);
        e[x].pb(y); e[y].pb(x);
    }
    for(int i=1;i<=n;i++)
        if(!kt[i]) cnt++,dfs(i);
    for(int i=1;i<=cnt;i++)
    {
        sort(st[i].begin(),st[i].end());
        for(int v:st[i]) a[v]=0;
        for(int j=0;j<xl[i];j++) a[st[i][j]]=1,upd(st[i][j],1);
    }
    int jj=0;
    for(int i=1;i<=n;i++)
    {
        while(jj<n&&get(i,jj+1)+k>=jj+2-i) jj++;
        if(re<jj-i+1) re=jj-i+1,vt=i;
        if(a[i]&&xl[kt[i]]<st[kt[i]].size())
        {
            upd(i,-1);
            a[st[kt[i]][xl[kt[i]]]]=1;
            upd(st[kt[i]][xl[kt[i]]],1);
            xl[kt[i]]++;
        }
    }
    if(re) printf("%d %d",vt,vt+re-1);
    else printf("-1");
}
int main()
{
    freopen(nhat".inp","r",stdin);
    freopen(nhat".out","w",stdout);
    scanf("%d %d %d\n",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        char c; scanf("%c",&c);
        a[i]=c-'0';
    }
    if(!m) vet();
    else giai();
}
