#include<bits/stdc++.h>
using namespace std;
long long m,a[100005],n;
bool kiemtra(int  mid)
{
    for(int i=mid;i<=n;i++)
        if(a[i]-a[i-mid]<m)return false;
     return true;
}
long long res=1e18,l,r,mid;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]+=a[i-1];
    if(a[n]<m){cout<<n+1;return 0;}
    l=1,r=n;
    while(l<=r)
    {
         mid=(l+r)/2;
        if(kiemtra(mid))
        {
            res=min(res,mid);
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<res;
}
