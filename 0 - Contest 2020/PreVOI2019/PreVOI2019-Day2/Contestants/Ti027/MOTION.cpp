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

//data structure//
struct point
{
    int x,y;
};

struct edge
{
    point u,v;
} a,b;

vector <edge> v1,v2;

///function///
//preset//

//input//
void input()
{
    cin >> n >> m >> a.u.x >> a.u.y >> a.v.x >> a.v.y >> b.u.x >> b.u.y >> b.v.x >> b.v.y;
    return;
}

//algorithm//
int process(vector <edge> &v,edge z)
{
    edge res;
    while (res!=z)
    {
        v.pb(res);
        edge t=res;
        res.u=t.v;
    }
}

//solve//
void solve()
{
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
	//freopen("CLIQUE.INP","r",stdin);
    //freopen("CLIQUE.OUT","w",stdout);
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
