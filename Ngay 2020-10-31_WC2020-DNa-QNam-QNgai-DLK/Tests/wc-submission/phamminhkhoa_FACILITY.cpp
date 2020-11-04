#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
long long res,f[N],d[N];
int n,p,p2,k,x,t;
struct hh
{
    long long a;
    long long b;
    long long c;
};
hh g[N];
bool xet(hh x,hh y)
{
    return (x.b<y.b);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>g[i].a>>x>>g[i].c;
        g[i].b=x+k+g[i].a;
    }
    t=0;sort(g+1,g+n+1,xet);
    for (int i=1;i<=n;i++) d[i]=g[i].b;
    for (int i=1;i<=n;i++) f[i]=1e9;
    for (int i=1;i<=n;i++)
    {
        t=upper_bound(d+1,d+n+1,g[i].a)-d;
        f[i]=max(f[i-1],f[t-1]+g[i].c);
    }
    cout<<f[n];
}
