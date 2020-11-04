#include<bits/stdc++.h>
using namespace std;
struct hh
{
    long long l,r,gt;
};
bool cmp (hh a,hh b)
{
    if(a.r==b.r)return a.gt<b.gt;
    return a.r<b.r;
}
hh a[1000001];
long long k,n,b[1000001],kq,y,f[1000001],t,d[1000001],res,s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].l>>y>>a[i].gt;
        a[i].r=a[i].l+y+k;
    }
    sort(a+1,a+1+n,cmp);

    f[0]=0;
    for(int i=1;i<=n;i++)
    {
        k=upper_bound(b,b+i,a[i].l)-b;
        k--;
        b[i]=a[i].r;
        kq=max(kq,k);
                d[i]=max(d[i-1],d[k]+a[i].gt);
    }
    cout<<d[n];
}
