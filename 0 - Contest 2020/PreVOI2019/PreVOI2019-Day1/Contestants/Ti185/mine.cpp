///Bankai: Getsuga Tenshou
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
const ll oo=1e6+3;
ll m,n,a[200005],kq;
string cn;
void nhap()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
}
ll poww(ll x,ll y)
{
    ll res=x;
    if(x==1) return 1;
    if(y==0) return 1;
    for(int i=1;i<y;i++)
    {
        res=res*x%oo;
    }
    return res;
}
void xuli()
{
    cout<<poww(2,200000)/2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    nhap();
    xuli();
    return 0;
}
