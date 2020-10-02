#include <bits/stdc++.h>
using namespace std;

int n,a[1000000],b[1000000],i,j,d;

int SX(const void*a, const void*b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    freopen("IQ.INP","r",stdin);
    freopen("IQ.OUT","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        cin>>b[i];
    qsort(a,n+1,sizeof(int),SX);
    qsort(b,n+1,sizeof(int),SX);
    i=n;
    for(j=n;j>=1;j--)
        if(b[i]>a[j])
            {
                d++;
                i--;
            }
        cout<<d;
    return 0;
}
