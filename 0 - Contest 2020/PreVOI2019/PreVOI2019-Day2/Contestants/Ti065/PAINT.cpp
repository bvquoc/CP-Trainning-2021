#include <bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;
int n;
int first[30];
int par[N];
int K=0;
int color[N];
char a[1005];
int root(int x)
{
    while(par[x]>-1)x=par[x];
    return x;
}
void merger(int x,int y)
{
    if((x=root(x))==(y=root(y)))return;
    par[y]+=par[x];
    par[x]=y;
}
void sub1()
{
    int K=0;
    while(n--)
    {
        int k;
        cin>>k;
        if(k==1)
        {
            char x;
            cin>>x;
            K++;
            a[K]=x;
        }
        else
        {
            char x,y;
            cin>>x>>y;
            for(int i=1;i<=K;i++)
            {
                if(a[i]==x)a[i]=y;
            }
        }
    }
    for(int i=1;i<=K;i++)
    {
        cout<<a[i];
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    memset(par,-1,sizeof(par));
    cin>>n;
    if(n<=1000)
    {
        sub1();
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        if(k==1)
        {
           K++;
           char x;
           cin>>x;
           int u=x-'a'+1;
           if(first[u]==0)
           {
               first[u]=K;
               color[K]=u;
           }
           else
           {
               merger(K,first[u]);
           }
        }
        if(k==2)
        {
            char x,y;
            cin>>x>>y;
            int u=x-'a'+1;
            int v=y-'a'+1;
            if(!first[u])continue;
            if(first[v])merger(first[u],first[v]);
            else
            {
                first[v]=first[u];
            }
            color[first[u]]=v;
            first[u]=0;
        }
    }
    for(int i=1;i<=K;i++)
    {
        int ru=root(i);
        cout<<char(color[ru]+96);
    }
}
