#include <bits/stdc++.h>
#define nmax 200007
#define mod 1000000007
using namespace std;
int n,ck=0,cek=0;
int a[nmax],b[nmax];
int gt[nmax];
long long kq=0;
void sub1()
{
    for (int i=1; i<=n; i++) b[a[i]]=i;
    set <int> s;
    for (int i=1; i<=n; i++)
    {
        if (i==1)
        {
            kq+=b[i]-1;
            s.insert(b[i]);
        }
        else
        {
            kq+=b[i]-(distance(s.begin(),s.lower_bound(b[i])))-1;
            s.insert(b[i]);
        }
    }
    cout << kq;
}
void sub2()
{
    long long kq=0;
    gt[2]=1;
    for (int i=3; i<=n; i++) gt[i]=(gt[i-1]*i)%mod;
    cout << (gt[n]*n*(n-1)/2)%mod;
}
void sub3()
{
    return;
}
int main()
{
    freopen("PERMEOW.INP","r",stdin);
    freopen("PERMEOW.OUT","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++)
    {
        cin >> b[i];
        if (b[i]!=a[n-i+1]) ck++;
        if (b[i]==a[i]) cek++;
    }
    if (ck==0) sub2();
    else if (cek==n) sub1();
    else sub3();
    return 0;
}
