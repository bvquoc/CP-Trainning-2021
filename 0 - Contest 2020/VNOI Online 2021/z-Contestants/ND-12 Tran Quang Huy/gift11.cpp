#include <bits/stdc++.h>
#define N 2001
using namespace std;
long long lt[N],a[N],n,i,mod=998244353,kq,q,b[N];
int scs(int n)
{
    int kq=0;
    while(n>0) { kq++; n/=10; }
    return kq;
}
bool check()
{
    long long d=0;
    for(i=1;i<=n;i++)
        d=(d*lt[scs(a[b[i]])]+a[b[i]])%11;
    return d==0;
}
void sub1()
{
    kq=0;
    do
    {
        if(check()) kq++;
    }
    while(next_permutation(b+1,b+n+1));
    cout<<kq<<'\n';
}
void sub2()
{
    long long gt=1;
    for(i=1;i<=n;i++) gt=gt*i%mod;
    if(check()) cout<<gt<<'\n';
    else cout<<0<<'\n';
}
int main()
{
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>q;
    lt[0]=1;
    for(i=1;i<=2000;i++) lt[i]=lt[i-1]*10%11;
    while(q--)
    {
        cin>>n;
        for(i=1;i<=n;i++) cin>>a[i];
        for(i=1;i<=n;i++) b[i]=i;
        if(n<=9) sub1();
        else sub2();
    }
}
