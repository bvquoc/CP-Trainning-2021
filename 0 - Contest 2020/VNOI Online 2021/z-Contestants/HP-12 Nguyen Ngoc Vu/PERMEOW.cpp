#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(i,x) for(auto &i:x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r)
{
    return l+rng()%(r-l+1);
}
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define pii pair<int,int>
#define fi first
#define se second
#define batbit(i,x) (x|(1ll<<i))
#define getbit(i,x) ((x>>i)&1)

const int mn=2010,mod=1e9+7;
int n,a[mn],ok1=1,b[mn];

main()
{
    freopen("PERMEOW.INP","r",stdin);
    freopen("PERMEOW.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forinc(i,1,n)
    {
        cin >> a[i];
        if(a[i]!=i) ok1=0;
    }
    forinc(i,1,n)
    {
        cin >> b[i];
        if(b[i]!=n-i+1) ok1=0;
    }
    if(ok1)
    {
        int res=1;
        forinc(i,1,n) res=(res*i)%mod;
        res=(n*(n-1)/4*res)%mod;
        cout << res;
    }
    else
    {
        int res=0;
        forinc(i,1,n-1)
        {
            forinc(j,i+1,n) if(a[i]>a[j]) res++;
        }
        cout << res;
    }
}
