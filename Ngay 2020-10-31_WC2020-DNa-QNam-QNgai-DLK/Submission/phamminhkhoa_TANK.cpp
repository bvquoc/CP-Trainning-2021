#include<bits/stdc++.h>
using namespace std;
long long k,n,a[100003],x;
bool check(int l)
{
    for (int i=l;i<=n;i++)
    {
        if (a[i]-a[i-l]<k) return 0;
    }
    return 1;
}
int kq(int w)
{
    int l=1;int r=1e5+3;int res;
    while (l<=r)
    {
        int m=(l+r)/2;
        if (check(m)) {r=m-1;res=m;}
        else l=m+1;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>k>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        a[i]=a[i-1]+x;
    }
    cout<<kq(k);
}
