#include<bits/stdc++.h>
using namespace std;
ifstream fi("SOCKS.inp");
ofstream fo("SOCKS.out");
typedef vector<int>dinhke;
vector<dinhke>dsk;
const int nmax=5e5+5;
int n,q,mau[nmax],d[nmax],thay[nmax],sldo;
bool test=true;
void nhap()
{
    fi>>n>>q;
    for(int i=1;i<=n;++i) fi>>mau[i];
    dsk.resize(n+1);
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        fi>>x>>y;
        dsk[x].push_back(y);
        dsk[y].push_back(x);
    }
    for(int i=1;i<=q;++i) fi>>thay[i];
    for(int i=1;i<=n;++i)
    {
        if(dsk[i].size()>=3) test=false;
    }
}
void sub1()
{
    for(int i=1;i<=n;++i)
    {
        if(mau[i]==1)
        {
            ++sldo;
        }
    }
    if(sldo>=2) fo<<1<<"\n";
    else fo<<0<<"\n";
    for(int i=1;i<=q;++i)
    {
        if(mau[thay[i]]==1) --sldo;
        else ++sldo;
        if(sldo>=2) fo<<1<<"\n";
        else fo<<0<<"\n";
    }
}
void dfs(int u,int cha_u)
{
    if(dsk[u].size()==1&&u!=1)
    {
        if(mau[u]==1) d[u]=1;
        return;
    }
    int tong=0;
    for(int i=0;i<dsk[u].size();++i)
    {
        int v=dsk[u][i];
        if(v==cha_u) continue;
        dfs(v,u);
        tong+=d[v];
    }
    if(mau[u]==1) d[u]=1;
    d[u]=max(d[u],tong);
    return;
}
void vet()
{
    memset(d,0,sizeof(d));
    dfs(1,0);
    if(mau[1]==1) ++d[1];
    fo<<d[1]-1<<"\n";
    for(int i=1;i<=q;++i)
    {
        memset(d,0,sizeof(d));
        if(mau[thay[i]]==1) mau[thay[i]]=0;
        else mau[thay[i]]=1;
        dfs(1,0);
        if(mau[1]==1) ++d[1];
        fo<<d[1]-1<<"\n";
    }
}
int main()
{
    nhap();
    if(test==false) vet();
    else sub1();
}
