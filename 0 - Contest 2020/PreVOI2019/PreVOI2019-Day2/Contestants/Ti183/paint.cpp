#include <bits/stdc++.h>

using namespace std;
char mau,mau2,ax[1000005];
int n,f[1000005],tt,K,cs[300];
int phin(int u)
{
    return f[u]<0 ? u : f[u]=phin(f[u]);
}
void uni(int u,int v)
{
    if (f[u]>f[v]) swap(u,v);
    f[u]+=f[v];
    f[v]=u;
    if (tt==2) cs[mau2]=u;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>n;K=0;memset(f,-1,sizeof(f));
    for (int i=1;i<=n;++i)
    {
        cin>>tt;
        if (tt==1)
        {
            ++K;
            cin>>mau;
            if (cs[mau]==0) cs[mau]=K;
            else uni(cs[mau],K);
        }
        else
        {
            cin>>mau>>mau2;
            if (mau==mau2) continue;
            if (cs[mau2]==0) cs[mau2]=cs[mau];
            else {uni(cs[mau2],cs[mau]);}
            cs[mau]=0;
        }

    }
    for (int i=0;i<26;++i)
    {
        mau=char(i+'a');
        ax[cs[mau]]=mau;
    }
    for (int i=1;i<=K;++i) cout<<ax[phin(i)];
    return 0;
}
