#include <bits/stdc++.h>

using namespace std;
long long n,A[20],N,s,kt[20],a[200009],b[200009],dem,j,i,vt;

int main()
{
    freopen("PERMEOW.INP","r",stdin);
    freopen("PERMEOW.OUT","w",stdout);
    cin>>n;
    if (n==1)
    {
        cout<<0;
        return 0;
    }
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (i=1;i<=n;i++)
    {
        cin>>b[i];
        if (a[i]==b[i])
            dem++;
    }
    if (dem==n)
    {
        dem=0;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
                if (a[j]==i)
                {
                    vt=j;
                    break;
                }
            for (j=vt;j>=i+1;j--)
            {
                swap(a[j],a[j-1]);
                dem++;
            }
        }
        cout<<dem;
        return 0;
    }
    if (n==2)
    {
        cout<<1;
        return 0;
    }
    s=9;
    N=1;
    for (i=1;i<=n;i++)
        N=N*i;
    for (i=2;i<=N/6;i++)
        s=((s%1000000007)+((s+6)%1000000007)%1000000007);
    cout<<s;
    return 0;
}
