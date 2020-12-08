#include<bits/stdc++.h>
#define x first
#define t second
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
int q,n;
const int mn=1e5+10;
const int mn2=5e7+10;
const int oo=2e9;
typedef pair<int,int> pi;
pi a[55];
int d[20];
int maxx;
//------------------
void pre()
{
    int lt=1;
    while(lt<=10000)
    {
        d[++n]=1*lt;
        d[++n]=3*lt;
        d[++n]=5*lt;
        lt*=10;
    }
}
//-------------------------
//sub2()
int f[mn],g[mn];
void sub1()
{
    fill(f,f+100000+2,oo);
    f[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=1e5;j++)
        if(j>=d[i])
        f[j]=min(f[j],f[j-d[i]]+1);
    for(int cnt=1;cnt<=q;cnt++)
    {
        int x=a[cnt].x;
        int t=a[cnt].t;
        for(int j=0;j<=t;j++)
            g[j]=f[j];
        for(int j=x;j<=t;j++)
            if(j>=x)
            g[j]=min(g[j],g[j-x]+1);
        cout<<g[t]<<'\n';
    }
}
//--------------------------------------
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    cin>>q;
    pre();
    for(int i=1;i<=q;i++)
    {
        cin>>a[i].x>>a[i].t;
        maxx=max(maxx,a[i].t);
    }
    if(maxx<=1e5)
        sub1();
    return 0;
}
