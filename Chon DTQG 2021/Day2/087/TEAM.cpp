#include <bits/stdc++.h>;

using namespace std;
long long n,k,a[1000005];

int main()
{
    freopen("TEAM.INP","r",stdin);
    freopen("TEAM.OUT","w",stdout);
    cin>>n>>k;
    long long tong=0;
    for(long long i=0;i<n;i++) {cin>>a[i]; tong=tong+a[i];}

    k=k%tong;
    for(long long i=0;i<n;i++)
    {
        if(k<a[i]) break;
        k=k-a[i];
    }

    cout<<k;
    return 0;
}
