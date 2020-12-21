#include <bits/stdc++.h>
#define N 100002
using namespace std;
struct pt { int u,tt; long long k; };
pt h[N*32+1];
long long f[N][33],vt[N][33],n,m,u,v,i,x,k,sl,cnt,nh,tt,tt2,msk[N];
vector <int> a[N],c[N];
void up(int u)
{
    while(1)
    {
        int p=u/2;
        if(p==0 || h[p].k<h[u].k) break;
        swap(vt[h[u].u][h[u].tt],vt[h[p].u][h[p].tt]);
        swap(h[u],h[p]);
        u=p;
    }
}
void down(int u)
{
    while(1)
    {
        int p=u*2;
        if(p<nh && h[p+1].k<h[p].k) p++;
        if(p>nh || h[p].k>h[u].k) break;
        swap(vt[h[u].u][h[u].tt],vt[h[p].u][h[p].tt]);
        swap(h[u],h[p]);
        u=p;
    }
}
void push(int u,int tt,long long k)
{
    h[++nh]={ u,tt,k }; vt[u][tt]=nh;
    up(nh);
}
void pop()
{
    swap(h[1],h[nh--]); vt[h[1].u][h[1].tt]=1;
    down(1);
}
int main()
{
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>sl>>k;
    for(u=1;u<=n;u++)
    {
        cin>>cnt;
        while(cnt--) { cin>>x; x--; msk[u]|=(1<<x); }
    }
    while(m--)
    {
        cin>>u>>v>>x;
        a[u].push_back(v); a[v].push_back(u);
        c[u].push_back(x); c[v].push_back(x);
    }
    m=sl; sl=k;
    for(u=1;u<=n;u++)
        for(tt=0;tt<(1<<m);tt++) f[u][tt]=round(1e18);
    f[1][msk[1]]=0; push(1,msk[1],0);
    while(nh>0)
    {
        int u=h[1].u,tt=h[1].tt; pop();
        if(u==n)
        {
            cnt=0;
            for(i=0;i<m;i++) cnt+=((tt>>i)&1);
            if(cnt>=sl) { cout<<f[u][tt]; return 0; }
        }
        for(i=0;i<a[u].size();i++)
        {
            int v=a[u][i];
            int tt2=tt|msk[v];
            if(f[v][tt2]>f[u][tt]+c[u][i])
            {
                f[v][tt2]=f[u][tt]+c[u][i];
                if(vt[v][tt2]==0) push(v,tt2,f[v][tt2]);
                else
                {
                    h[vt[v][tt2]].k=f[v][tt2];
                    up(vt[v][tt2]);
                }
            }
        }
    }
    cout<<-1;
}
