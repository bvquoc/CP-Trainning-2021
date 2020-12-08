#include <iostream>
#include <algorithm>
#include <cstdio>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
const int maxn=400003;
typedef long long ll;
const ll mod=1000003;
int a[maxn];
int n,m;
ll igt[maxn];
ll gt[maxn];
ll poom(ll a,ll b)
{
    if (b==0) return ll(1);
    ll p=poom(a,b/2);
    p=p*p;
    p=p%mod;
    if (b%2==0) return p;
    else return ((p*a)%mod);
}

void init()
{
    gt[0]=1;
    for(ll i=1;i<=maxn;++i)
    {
        gt[i]=gt[i-1]*i;
        gt[i]=gt[i]%mod;
    }
    igt[0]=1;
    for(ll i=1;i<=maxn;++i)
        igt[i]=poom(gt[i], mod-2);
}

void solve()
{
    ll kq=1;
    for(int i=n*2;i>0;i-=2)
    {
        kq=kq*gt[i];
        kq=kq%mod;
        kq=kq*igt[2];
        kq=kq%mod;
        kq=kq*igt[i-2];
        kq=kq%mod;
    }
    cout<<kq;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    cin>>n>>m;
    _for(i,0,n) cin>>a[i];
    init();
    solve();
}
