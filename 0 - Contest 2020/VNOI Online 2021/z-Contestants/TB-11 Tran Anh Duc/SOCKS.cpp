#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x,i) (((x)>>(i)) & 1)
#define SET_ON(x,i) ((x) | MASK(i))
#define SET_OFF(x,i) ((x) & ~(MASK(i)))
using namespace std;
const int MAXN=1e5+1;
int n,q;
int a[MAXN],deg[MAXN];
int cnt[MAXN];
vector<int> adj[MAXN];
int b[MAXN];
void sub1()
{
    int cnt=0;
    cout<<1<<endl;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            if(deg[i]==1)
            {
                cnt++;
            }
        }
    }
    if(cnt==2)
    {
        for(int i=1;i<=q;i++)   cout<<1<<endl;
    }
    else    for(int i=1;i<=q;i++)   cout<<2<<endl;
}
void sub2()
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i])
        {
            if(deg[i]==1)   cnt++;
        }
    }
    if(cnt==3)  for(int i=1;i<=q+1;i++) cout<<1<<endl;
    else if(cnt==2)
    {
        cout<<1<<endl;
        for(int i=1;i<=q;i++)
        {
            cout<<2<<endl;
        }
    }
    else if(cnt==1)
    {
        cout<<2<<endl;
        for(int i=1;i<=q;i++)
        {
            cout<<2<<endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SOCKS.INP" , "r" , stdin);
    freopen("SOCKS.OUT" , "w" , stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ma=0;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
        ma=max(ma,max(deg[u],deg[v]));
        cnt[ma]++;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>b[i];
    }
    if(ma==2)
    {
        sub1();
        return 0;
    }
    if(cnt[deg[3]]==1)
    {
        sub2();
        return 0;
    }
    return 0;
}
