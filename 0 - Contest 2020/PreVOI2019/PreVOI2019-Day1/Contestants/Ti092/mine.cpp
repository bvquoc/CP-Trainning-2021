#include <bits/stdc++.h>

using namespace std;
const int mod=1000003;
int n,m,a[200001],p[30],kt[30],check[30],f[200001];
void sub2()
{
    f[1]=1;
    f[2]=2;
    f[3]=5;
    f[4]=14;
    for (int i=5;i<=n;i++)
    {
        f[i]=f[i-1]*2;
        for (int j=1;j<=i-2;j++)
        {
            f[i]+=f[j]*f[i-1-j];
            f[i]%=mod;
        }
    }
    cout<<f[n];
}
int main()
{
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
   // if (n<=10) sub1();
   sub2();
}
