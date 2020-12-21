#include<bits/stdc++.h>
using namespace std;
ifstream fi("DHAKA.inp");
ofstream fo("DHAKA.out");
typedef pair<long long,long long>II;
typedef vector<II>dinhke;
vector<dinhke>dsk;
#define ff first
#define ss second
#define mp make_pair
const long long nmax=1e5+5;
const long long vc=1e18+7;
long long n,m,k,l,kq=vc,d[nmax],dua_hau[nmax][10],dem[10];
bool kt[nmax];
void nhap()
{
    fi>>n>>m>>k>>l;
    for(long long i=1;i<=n;++i)
    {
        long long x;
        fi>>x;
        for(long long j=1;j<=x;++j) fi>>dua_hau[i][j];
    }
    dsk.resize(n+1);
    for(long long i=1;i<=m;++i)
    {
        long long x,y,z;
        fi>>x>>y>>z;
        dsk[x].push_back(mp(y,z));
        dsk[y].push_back(mp(x,z));
    }
}
//============================
void dfs(long long u,long long cha_u,long long tong)
{
    if(u==n)
    {
        long long sl=0;
        for(long long j=1;j<=5;++j) if(dem[j]>=1) ++sl;
        //if(tong==7) fo<<cha_u<<" ";
        if(sl>=l)
        {
            kq=min(kq,tong);
        }
        return;
    }
    for(long long i=0;i<dsk[u].size();++i)
    {
        long long v=dsk[u][i].ff;
        long long w=dsk[u][i].ss;
        if(kt[v]==true&&v!=cha_u)
        {
            kt[v]=false;
            for(long long j=1;j<=5;++j)
            {
                long long tmp=dua_hau[v][j];
                ++dem[tmp];
            }
            dfs(v,u,tong+w);
            kt[v]=true;
            for(long long j=1;j<=5;++j)
            {
                long long tmp=dua_hau[v][j];
                --dem[tmp];
            }
        }
    }
}
void sub1()
{
    for(long long i=1;i<=n;++i) kt[i]=true;
    dfs(1,0,0);
    if(kq==vc) fo<<-1;
    else fo<<kq;
}
//============================
void dijkstra(long long s,long long t)
{
    priority_queue<II>pq;
    for(long long i=1;i<=n;++i)
    {
        kt[i]=true;
        d[i]=vc;
    }
    d[s]=0;
    pq.push(mp(0,s));
    while(true)
    {
        long long u=0;
        while(!pq.empty())
        {
            II tmp=pq.top();
            pq.pop();
            if(d[tmp.ss]==-tmp.ff)
            {
                u=tmp.ss;
                break;
            }
        }
        if(u==0||u==t) return;
        if(kt[u]==false) continue;
        kt[u]=false;
        for(long long i=0;i<dsk[u].size();++i)
        {
            long long v=dsk[u][i].ff;
            long long w=dsk[u][i].ss;
            if(kt[v]==true&&d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                pq.push(mp(-d[v],v));
            }
        }
    }
}
void sub2()
{
    dijkstra(1,n);
    if(d[n]==vc) fo<<-1;
    else fo<<d[n];
}
//=============================
int main()
{
    nhap();
    if(k==0||l==0) sub2();
    else sub1();
}
/*
6 6 2 2
0
1 1
0
1 1
1 1
0
1 2 1
2 3 2
1 4 2
4 5 2
5 6 1
3 6 1
*/
