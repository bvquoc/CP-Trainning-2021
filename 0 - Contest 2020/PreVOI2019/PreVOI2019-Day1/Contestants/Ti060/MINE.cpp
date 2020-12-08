#include <bits/stdc++.h>
#define ll long long
const ll base=1000003;
const int N=4*1e5+5;
using namespace std;
int n,m;
int a[N];
ll gt=1ll;
ll ans=1;
inline int ReadInt()
{
    char c;
    for(c=getchar(); '0'>c||c>'9'; c=getchar());
    int x=c-'0';
    for(c=getchar(); '0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    return x;
}
void input()
{
    n=ReadInt();m=ReadInt();
    for(int i=1; i<=2*n; ++i)
        a[i]=ReadInt();
}
ll Pow(ll x,ll mu)
{
    if(mu==0)
        return 1ll;
    if(mu==1)
        return x%base;
    ll mid=mu>>1;
    ll res=Pow(x,mid);
    res=(res*res)%base;
    if(mu%2)
        res=(res*x)%base;
    return res;
}
void sub25()
{
    for(int i=1; i<=2*n; ++i)
        gt=(1ll*gt*i)%base;
    ll res=Pow(2*1ll,1ll*n);
    ll ans=gt;
    ans=(ans*Pow(res,base-2))%base;
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
    input();
    sub25();
    return 0;
}
