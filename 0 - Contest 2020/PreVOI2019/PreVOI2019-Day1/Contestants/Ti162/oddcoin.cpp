#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ii pair <int,int>
#define pl pair <ll,ll>
#define fr(i,x,y) for (int i=x;i<=y;i++)
#define ft(i,x,y) for (int i=y;i>=x;i--)
#define N 100005
using namespace std ;
int q;
ll f[5000007],a[20],minn=1e18;
void inp()
{
    freopen("oddcoin.inp","r",stdin) ;
    freopen("oddcoin.out","w",stdout);
    scanf("%d",&q);
}
bool checking(int i,ll t)
{
    if (i==30 or i==50 or i==100 or i==300 or i==500 or i==1000 or i==3000 or i==5000) return true ;
    if (i==10000 or i==30000 or i==50000) return true ;
    if (i==1 or i==3 or i==5 or i==10 or i==t) return true ;
    return false ;

}
ll xuli(ll x,ll t)
{
    fr(i,1,t) f[i]=1e9 ;
    fr(i,1,t)
    {
        if (checking(i,x))
        {
            //cout<<i<<endl;
            f[i]=1;
        }
        else
        {
            fr(j,1,i)
            {
                f[i]=min(f[i],f[j]+f[i-j]);
            }
        }
    }
    return f[t];
}
void sub()
{
    fr(i,1,q)
    {
        ll x,t ;
        scanf("%lld%lld",&x,&t);
        printf("%lld\n",xuli(x,t));
    }
}
int main()
{
    inp() ;
    sub() ;
}
