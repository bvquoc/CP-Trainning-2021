#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
const int maxn=200001;
typedef long long ll;
const ll oo=100000000000ll;
ll f[maxn];
ll a[100];

ll n,coin;
void enter()
{
    cin>>coin>>n;
    a[15]=coin;
}
void qhd()
{
    a[15]=coin;
    _for(i,1,maxn+1) f[i]=oo;
    f[0]=0;
    _for(i,1,maxn+1)
    {
        _for(j,0,16)
        {
            if ( i - a[j]>=0)
            {
                f[i]=min(f[i], f[i- a[j]] + 1);
            }
        }
    }
    if (coin<=maxn)
    {
        ll kq=0;
        ll _cnt=oo;
        _for(i,1,maxn+1)
        {
            _cnt=min(_cnt,f[i]*(n/i) + f[n%i]);
        }
        cout<<kq + _cnt<<"\n";
    }
    else
    {
        ll kq=0;
        kq=kq+ n/coin;
        n=n%coin;
        ll _cnt=oo;
        _for(i,1,maxn+1)
        {
            _cnt=min(_cnt,f[i]*(n/i) + f[n%i]);
        }
        cout<<kq + _cnt<<"\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    a[0]=1; a[1]=3; a[2]=5; a[3]=10; a[4]=30; a[5]=50; a[6]=100; a[7]=300; a[8]=500; a[9]=1000;
    a[10]=3000; a[11]=5000; a[12]=10000; a[13]=30000; a[14]=50000;
    int t;
    cin>>t;
    _for(i,0,t)
    {
        enter();
        qhd();
    }
}
