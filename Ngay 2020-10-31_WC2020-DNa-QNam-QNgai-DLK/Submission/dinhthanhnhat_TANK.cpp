#include <bits/stdc++.h>
using namespace std;
long long a[1000005],b,c,d,s,n,k,m,res=1,i,x[1000005];
int main()
{
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin >> m >> n;
    for (c=1;c<=n;c++)
    {
        cin >> a[c];x[c]=x[c-1]+a[c];
    }
    for (c=1;c<=n;c++)
    {
        s=x[c]-x[c-res];
        if (s<m)
        res++;
    }
    cout << res ;
}