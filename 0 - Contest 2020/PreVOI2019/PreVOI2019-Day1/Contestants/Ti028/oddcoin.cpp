#include<bits/stdc++.h>

#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repn(i,a,b) for(ll i=a;i>=b;i--)
#define repv(i,v) for(__typeof(v.begin())i=v.begin();i!=v.end();i++)
#define ll long long int
#define db double
#define sqr(x) x*x
#define getbit(i,x) ((x>>(i-1))&1)
#define ft first
#define sc second
#define name "oddcoin"

using namespace std;

typedef pair<ll,ll> ii;
const ll oo=3e9;

ll a[20],d[60000000],res,test,T;

ll dq(ll x)
{
    if(d[x]!=-1) return d[x];
    ll tmp=oo;
    repn(i,16,1) if(x>=a[i])tmp=min(tmp,dq(x-a[i])+1);
    return d[x]=tmp;
}

void tinh()
{
    a[1]=1;a[2]=3;a[3]=5;
    a[4]=10;a[5]=30;a[6]=50;
    a[7]=100;a[8]=300;a[9]=500;
    a[10]=1000;a[11]=3000;a[12]=5000;
    a[13]=10000;a[14]=30000;a[15]=50000;
    cin >> a[16] >> T;
    rep(i,1,T) d[i]=-1;
    rep(i,1,16) d[a[i]]=1;
    cout<<dq(T)<<"\n";
}

int main()
{
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> test;
    while(test--) tinh();
    return 0;
}
