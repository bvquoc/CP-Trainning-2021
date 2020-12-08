#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long N=200005,M=1000003;
long n,m,a[2*N];
ll f[4005][4005];
ll dp[N];
ll dq(long d,long c)
{
    if(d>c)return 1;
    if(f[d][c]!=-1)return f[d][c];
    ll res=0;
    for(long i=d+1;i<=c;i+=2)
    if(a[i]-a[d]<=m)
       res=(res+dq(d+1,i-1)*dq(i+1,c)%M)%M;
    return f[d][c]=res;
}
int main()
{
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(long i=1;i<=2*n;i++)
        cin>>a[i];
    sort(a+1,a+1+2*n);
    if(n<=2000)
    {
        memset(f,-1,sizeof(f));
        cout<<dq(1,2*n);
        return 0;
    }
    return 0;
}
