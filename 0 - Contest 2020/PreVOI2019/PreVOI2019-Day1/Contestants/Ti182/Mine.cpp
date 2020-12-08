#include <bits/stdc++.h>
using namespace std;
#define MOD 1000003
#define maxn 2003
typedef long long ll;

ll f[maxn];

void cf()
{
    f[1]=f[2]=1;
    for(int i=3;i<maxn;++i)
    {
        f[i]=(f[i-1]+f[i-2])%MOD;
    }
}
void sub1()
{

}
int main()
{
    freopen("Mine.inp","r",stdin);
    freopen("Mine.out","w",stdout);
    cf();
    int n,m,a[maxn];
    cin>>n>>m;
    if(m==1000000) {cout<<f[2*n-1];return 0;}
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sub1();
    return 0;
}
