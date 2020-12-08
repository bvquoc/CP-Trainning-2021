#include<bits/stdc++.h>
using namespace std;
#define fi   first
#define se   second
#define pb push_back
#define pu push
#define pii pair<long long,long long>
#define TASKNAME "mine"
#define ll long long
const long long mod=1e6+3;
ll f[500009];
long long dq(long long so)
{
    long long res=0;
    if (f[so]!=-1) return f[so];
    for (int i=2;i<=so;i+=2)
    {
        res=(res+dq(i-2)%mod*(dq(so-i)%mod))%mod;
    }
    return f[so]=res%mod;
}
ll n,m,a[400009];
ll f2[2000][2000];
ll dq2(int d,int c)
{
    //cout<<d<<c<<endl;
    if (f2[d][c]!=-1) return f2[d][c];
    if (d+1==c && a[c]-a[d]<=m) return 1;
    ll res=0;
    for (int i=1;(d+i)<c;i+=2)
    {
        if (a[d+i]-a[d]>m) break;
        ll tich=1;
        if (d+1<d+i) tich=tich*dq2(d,d+i)%mod;
        if (d+i+2<c) tich=tich*dq2(d+i+1,c)%mod;
        res=res+tich%mod;
    }
    return f2[d][c]=res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(TASKNAME".inp", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
    #endif
    cin>>n>>m;
    for (int i=1;i<=2*n;i++) cin>>a[i];
    if (m==1000000)
    {
        memset(f,-1,sizeof(f));
        f[0]=1;
        cout<<dq(2*n);
    }
    else
    {
        memset(f2,-1,sizeof(f2));
        cout<<dq2(1,2*n);
    }
    return 0;
}
