#include <bits/stdc++.h>
using namespace std;
long long  a[100005],ans,n,m;
bool check(int mm)
{
    for(int i=mm;i<=n;i++)
        if(a[i]-a[i-mm]<m) return false ;
    return true;
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]+=a[i-1];
    int l=1,r=n;
    ans=n+1;
    while(l<=r)
    {
        int mm=(l+r)/2;
        if(check(mm))
        {
            ans=mm;
            r=mm-1;
        }
        else
        {
            l=mm+1;
        }
    }
    cout<<ans;
}
