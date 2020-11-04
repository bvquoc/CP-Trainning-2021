#include <bits/stdc++.h>
using namespace std;
long long a[1000005],d,s,n,k,m,t=1,i,b[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.inp","r",stdin);
    cin >> m >> n;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
        b[i]=b[i-1]+a[i];
    }
    for (i=1;i<=n;i++)
    {
        s=b[i]-b[i-t];
        if (s<m)
        t++;
    }
    cout<<t;
}
