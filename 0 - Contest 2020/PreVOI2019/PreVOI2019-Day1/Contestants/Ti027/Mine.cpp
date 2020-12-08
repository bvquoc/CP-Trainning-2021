#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define f1(i, n) for(int i=1;i<=n;i++)
#define f0(i, n) for(int i=0;i<n;i++)
#define ldb ldouble
#define inf 99999999999999999
//#define mod 998244353
#define mod 1000003
#define int ll

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

//**Start here**//

///declaration///
//variables//
int n,m;
int a[2000005];
int fact[2000005];
int DP[2000005];
int b[2000005];
int c[2000005];

//data structure//

///function///
//preset//

//input//
void input()
{
    cin >> n >> m;
    for (int i=1;i<=2*n;++i)
    {
        cin >> a[i];
        DP[i]=-1;
    }
    return;
}

//algorithm//
int binsearch(int x)
{
    int l=1,r=(n<<1);
    if (x>a[r]) return r;
    while (r>l)
    {
        int mid=(l+r)>>1;
        //cerr << mid << endl;
        if (a[mid]>x) r=mid;
        else l=mid+1;
    }
    return l-1;
}

int powmod(int x,int y)
{
    int res=1;
    while (y>0)
    {
        if (y&1) res=(res*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return res;
}

int C(int x)
{
    int z=(fact[x]*fact[x+1])%mod;
    int y=powmod(z,mod-2);
    return (fact[x<<1]*y)%mod;
}

int dp(int x)
{
    //cerr << "!" << x << '\n';
    if (x>(n<<1)) return 1;
    if (DP[x]!=-1) return DP[x];
    int sum=0;
    for (int i=x+1;i<=b[x];i+=2)
    {
        //cerr << x << ' ' << i << ' ';
        int t=c[(i-x-1)>>1]%mod;
        //cerr << t << '\n';
        sum+=(t*(dp(i+1)))%mod;
        sum%=mod;
    }
    //cerr << x << ' ' << sum << endl;
    return DP[x]=sum;
}

//solve//
void solve()
{
    int z=(n<<1);
    for (int i=1;i<=z;++i)
    {
        b[i]=binsearch(a[i]+m);
        //cerr << i << ' ' << b[i] << '\n';
    }
    fact[0]=1;
    for (int i=1;i<=z;++i)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    c[0]=1;
    for (int i=1;i<=n;++i)
    {
        c[i]=C(i)%mod;
    }
    cout << dp(1);
    return;
}

//output//
void output()
{
    return;
}

///main///
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("Mine.INP","r",stdin);
    freopen("Mine.OUT","w",stdout);
    /*int test;
    cin >> test;
    for (int k=1;k<=test;++k)*/
    {
        input();
        solve();
        output();
    }
    return 0;
}

/**code-by-@datr1bs**/
