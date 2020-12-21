#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int Mod=1e9+7;
int a[N],b[N],n;
int it[4*N];
void update(int i,int j,int t,int u,int v)
{
    if (j<i||u<i||j<u) return;
    if (u<=i&&j<=u) {it[t]=v;return;}
    int mid=(i+j)/2;
    update(i,mid,2*t,u,v);
    update(mid+1,j,2*t+1,u,v);
    it[t]=it[2*t]+it[2*t+1];
}
int query(int i,int j,int t,int u,int v)
{
    if (j<i||v<u||v<i||j<u) return 0;
    if (u<=i&&j<=v) return it[t];
    int mid=(i+j)/2;
    return query(i,mid,2*t,u,v)+query(mid+1,j,2*t+1,u,v);
}
void sub1()
{
    int kq=0;
    for (int i=1;i<=n;i++)
    {
        kq=(kq+query(1,n,1,a[i]+1,n))%Mod;
        update(1,n,1,a[i],1);
    }
    cout<<kq;
}
void sub2()
{
    if (n==2) {cout<<1;return;}
    long long kq=0,dem=1;
    for (int i=1;i<=n;i++) dem=(dem*i)%Mod;
    int a=0,b=1,c=2,d=3;
    for (int i=1;i<=dem/6;i++)
    {
        kq=(kq+a+2*b+2*c+d)%Mod;
        a++;b++;c++;d++;
    }
    cout<<kq;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("PERMEOW.INP","r",stdin);
    freopen("PERMEOW.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int kt1=1,kt2=1;
    for (int i=1;i<=n;i++)
    {
        cin>>b[i];
        if (a[i]!=b[i]) kt1=0;
        if (a[i]!=i||b[i]!=n-i+1) kt2=0;
    }
    if (kt1) sub1();
    else if (kt2) sub2();
}
