#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N];
long long s[N];
bool check (int l)
{
    for (int i=l;i<=n;i++)
    {
        if (s[i]-s[i-l]<m) return false;
    }
    return true;
}
int main()
{
    cin>>m>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    int L=1,R=N,ans;
    while (L<=R)
    {
        int mid=(L+R)/2;
        if (check(mid))
        {
            ans=mid;
            R=mid-1;
        }
        else L=mid+1;
    }
    cout<<ans;
}
