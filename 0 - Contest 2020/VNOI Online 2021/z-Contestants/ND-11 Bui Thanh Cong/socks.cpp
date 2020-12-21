#include<bits/stdc++.h>
using namespace std;
const long o=500005;
long n,q,mau[o],dd[o];
vector<long>ke[o];
void sub1()
{
    long sl=0;
    for(long i=1;i<=n;i++)
        sl+=mau[i];
    cout<<(sl>1)<<'\n';
    while(q--)
    {
        long vt; cin>>vt;
        if(mau[vt])sl--;
        else sl++;
        mau[vt]=(mau[vt]+1)%2;
        cout<<(sl>1)<<'\n';
    }
}
void dfs(long cs,long p,long u)
{
    dd[u]=cs;
    for(long i=0;i<ke[u].size();i++)
    {
        long v=ke[u][i];
        if(v!=p)dfs(cs,u,v);
    }
}
long tinh(long a,long b,long c,long d)
{
    long gg=(a>0)+(b>0)+(c>0);
    if(gg>=2)return gg/2+gg%2;
    return (a>1 || b>1 || c>1 || d>0);
}
void sub2()
{
    long goc;
    for(goc=1;goc<=n;goc++)
        if(dd[goc]==3)break;
    dfs(0,goc,ke[goc][0]);
    dfs(1,goc,ke[goc][1]);
    dfs(2,goc,ke[goc][2]);
    long sl[]={0,0,0,0};
    for(long i=1;i<=n;i++)
        sl[dd[i]]+=mau[i];
    cout<<tinh(sl[0],sl[1],sl[2],sl[3])<<'\n';
    while(q--)
    {
        long vt; cin>>vt;
        if(mau[vt])sl[dd[vt]]--;
        else sl[dd[vt]]++;
        mau[vt]=(mau[vt]+1)%2;
        cout<<tinh(sl[0],sl[1],sl[2],sl[3])<<'\n';
    }
}
long dq(long p,long u)
{
    long da=0;
    for(long i=0;i<ke[u].size();i++)
    {
        long v=ke[u][i];
        if(v!=p)da+=dq(u,v);
    }
    if(da>0)return da;
    return mau[u];
}
void sub3()
{
    long goc;
    for(goc=1;goc<=n;goc++)
        if(dd[goc]>1)break;

    long sc=dq(goc,goc),sl=0;
    for(long i=1;i<=n;i++)
        sl+=mau[i];

    if(sc>=2)cout<<sc/2+sc%2<<'\n';
    else cout<<(sl>1)<<'\n';

    while(q--)
    {
        long vt; cin>>vt;
        mau[vt]=(mau[vt]+1)%2;

        sc=dq(goc,goc); sl=0;
        for(long i=1;i<=n;i++)
            sl+=mau[i];

        if(sc>=2)cout<<sc/2+sc%2<<'\n';
        else cout<<(sl>1)<<'\n';
    }
}
int main()
{
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(long i=1;i<=n;i++)
        cin>>mau[i];
    long mx=0,lh3=0;
    for(long i=1;i<n;i++)
    {
        long u,v; cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
        dd[u]++; dd[v]++;
        if(dd[u]<=2)
            mx=max(mx,dd[u]);
        else lh3++;
        if(dd[v]<=2)
            mx=max(mx,dd[v]);
        else lh3++;
    }
    if(mx<=2 && lh3==0)sub1();
    else if(lh3==1)sub2();
    else if(n<=1000 && q<=1000)sub3();
    return 0;
}
