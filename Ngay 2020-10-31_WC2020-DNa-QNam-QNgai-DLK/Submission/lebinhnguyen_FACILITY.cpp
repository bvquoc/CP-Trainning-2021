#include <bits/stdc++.h>
using namespace std;
struct mang
{
    long long  f,s,t;
};
mang a[1000001];
long long  n,b[1000001],d[1000001],k;

bool cmp(mang a, mang b)
{
    return a.s < b.s;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        long long  x,y,z;
        cin>>x>>y>>z;
        a[i].f=x;
        a[i].s=x+y+k;
        a[i].t=z;
    }
    b[0]=0;
    d[0]=0;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        int k=upper_bound(b,b+i,a[i].f)-b;
        k--;
        b[i]=a[i].s;
        d[i]=max(d[i-1],d[k]+a[i].t);
    }
    cout<<d[n];
}
