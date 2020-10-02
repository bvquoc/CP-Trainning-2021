#include <bits/stdc++.h>
using namespace std;
int64_t n,a[100000000],sum=0,k;
 int main()
 {
    freopen("TEAM.INP","r",stdin);
    freopen("TEAM.OUT","w",stdout);
    cin>>n>>k;
    for (int64_t i=1;i<=n;i++)
    { cin>>a[i]; sum+=a[i]; }
    sum=k%sum;
    int i=1;
    while (sum>=a[i])
    {
        sum-=a[i];
        i++;
    }
    cout<<sum;
     return 0;
 }
