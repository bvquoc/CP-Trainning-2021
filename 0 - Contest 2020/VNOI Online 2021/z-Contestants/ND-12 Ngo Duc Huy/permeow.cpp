#include <bits/stdc++.h>
#define FILE "permeow"
#define ll long long
using namespace std;

const int Nn = 2009 , M = 1e9+7;
int n,a[Nn],b[Nn];

int vt[Nn];
void sub1()
{
    for(int i=1;i<=n;i++) vt[a[i]]=i;
    ll kq=0;
    for(int i=1;i<=n;i++)
        if(a[i]!=i)
        {
            int l=i,r=vt[i];
            if(l > r) swap(l,r);
            for(int j=r;j>l;j--)
                swap(a[j],a[j-1]),
                kq++;
            kq%=M;
            for(int j=1;j<=n;j++) vt[a[j]]=j;
        }
    cout<<kq;
}
ll lt(ll a,ll x)
{
    if(x <= 0) return 1;
    ll t=lt(a,x/2);
    t=t*t%M;
    if(x%2) return t*a%M;
    return t;
}
void sub2()
{
    if(n <= 2)
    {
        cout<<n-1;
        return ;
    }
    ll d=5,cs=10;
    for(int i=3;i<=n;i++)
        d+=cs,
        cs+=5;
    //cout<<d<<'\n';
    ll gt=1;
    for(int i=1;i<=n;i++) gt=(gt*i)%M;
    ll kq=(gt*d%M)*lt(10,M-2)%M;
    cout<<kq;
}
int main()
{
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    bool ok1=1;
    for(int i=1;i<=n;i++)
        if(a[i]!=b[i]) ok1=0;
    if(ok1) {sub1();return 0;}
    sub2();
}
