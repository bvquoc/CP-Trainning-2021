#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define f1(i, n) for(int i=1;i<=n;i++)
#define f0(i, n) for(int i=0;i<n;i++)
#define ldb ldouble
#define inf 99999999999999999
//#define mod 998244353
#define mod 1000000007
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
deque <int> t{1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000},v;
int DP[25][1000005];

//data structure//

///function///
//preset//

//input//
void input()
{
    cin >> n >> m;
    v=t;
    return;
}

//algorithm//
int dp(int i,int mask,int j)
{
    if (i<0)
    {
        if (j==0) return 0;
        else return inf;
    }
    if (DP[i][mask]!=-1) return DP[i][mask];
    int newmask=mask|(1<<i);
    int p=min(j/v[i]+dp(i-1,newmask,j%v[i]),dp(i-1,mask,j));
    //cout << p << ' ' << i << ' ' << j << '\n';
    return DP[i][mask]=p;
}

//solve//
void solve()
{
    int ans=inf;
    v.pb(n);
    for (int i=0;i<=v.size();++i)
    {
        for (int j=0;j<=70000;++j)
        {
            DP[i][j]=-1;
        }
    }
    ans=dp(v.size()-1,0,m);
    for (int i=v.size()-1;i>0;--i)
    {
        swap(v[i],v[i-1]);
        for (int i=0;i<=v.size();++i)
        {
            for (int j=0;j<=70000;++j)
            {
                DP[i][j]=-1;
            }
        }
        int z=dp(v.size()-1,0,m);
        //cerr << z << "!\n";
        ans=min(ans,z);
    }
    cout << ans << '\n';
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
	freopen("Oddcoin.INP","r",stdin);
    freopen("Oddcoin.OUT","w",stdout);
    int test;
    cin >> test;
    for (int k=1;k<=test;++k)
    {
        input();
        solve();
        output();
    }
    return 0;
}

/**code-by-@datr1bs**/
