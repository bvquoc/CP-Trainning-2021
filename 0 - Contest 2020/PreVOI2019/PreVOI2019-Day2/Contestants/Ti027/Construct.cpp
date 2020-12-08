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
int a[1000005],b[1000005];

//data structure//

///function///
//preset//

//input//
void input()
{
    cin >> n >> m;
    for (int i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    return;
}

//algorithm//
int dvc(int l,int r)
{
    if (r<l) return 0;
    if (r==l) return b[l];
    int Min=inf;
    int res=0;
    for (int i=l;i<=r;++i)
    {
        Min=min(Min,b[i]);
    }
    int L=l;
    for (int i=l;i<=r;++i)
    {
        b[i]-=Min;
        if (b[i]==0)
        {
            res+=dvc(L,i-1);
            L=i+1;
        }
    }
    res+=dvc(L,r);
    //cout << res << ' ' << l << ' ' << r << '\n';
    return res+Min;
}

//solve//
void solve()
{
    for (int i=1;i<=m;++i)
    {
        int sign;
        cin >> sign;
        if (sign==1)
        {
            int x,y,z;
            cin >> x >> y >> z;
            for (int i=x;i<=y;++i)
                a[i]+=z;
        }
        else
        {
            int x,y;
            cin >> x >> y;
            for (int i=1;i<=n;++i)
                b[i]=a[i];
            cout << dvc(x,y) << "\n";
        }
    }
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
	freopen("Construct.INP","r",stdin);
    freopen("Construct.OUT","w",stdout);
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
