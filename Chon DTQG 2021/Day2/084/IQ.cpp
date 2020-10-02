#include <bits/stdc++.h>

using namespace std;
long long i,a[100005],j,b[100005],dem,n,kt[100005],res;
int tknp(long long a[],long long l,long long r,long long x)
{
    while (l<=r)
    {
        res=(l+r)/2;
        if (a[res]==x && kt[res]==0)
            return res;
        if (a[res]>x)
            r=res-1;
        else l=res+1;
    }
    return 0;
}
int main()
{
    freopen("IQ.INP","r",stdin);
    freopen("IQ.OUT","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (i=1;i<=n;i++)
        cin>>b[i];
    sort(a+1,a+1+n);
    for (i=1;i<=n;i++)
    {
        tknp(a,1,n,b[i]);
        if (res<n)
            res++;
        for (j=res;j>=1;j--)
            if (b[i]>a[j] && kt[j]==0)
        {
            dem++;
            kt[j]=1;
            break;
        }
    }
    cout<<dem;
    return 0;
}
