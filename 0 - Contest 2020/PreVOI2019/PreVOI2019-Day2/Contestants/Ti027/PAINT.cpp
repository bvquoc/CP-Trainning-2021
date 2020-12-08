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
int n,cnt=0;
char a[10000005];
int dsu[10000005];
int check[1000005];
int base=1000;

//data structure//

///function///
//preset//

//input//
void input()
{
    cin >> n;
    return;
}

//algorithm//
void sub1()
{
    for (int i=1;i<=n;++i)
    {
        int sign;
        cin >> sign;
        if (sign==1)
        {
            char x;
            cin >> x;
            a[++cnt]=x;
        }
        else
        {
            char x,y;
            cin >> x >> y;
            for (int i=1;i<=cnt;++i)
            {
                if (a[i]==x) a[i]=y;
            }
        }
        //cerr << cnt << '\n';
    }
    for (int i=1;i<=cnt;++i)
        cout << a[i];
    return;
}

struct query
{
    int c;
    char x,y;
} q[1000005];

int Root(int x)
{
    if (dsu[x]==x) return x;
    return dsu[x]=Root(dsu[x]);
}

void Union(int x,int y)
{
    int z=Root(y);
    dsu[x]=z;
}

void sub2()
{
    for (int i=1;i<=200;++i)
    {
        dsu[i]=dsu[base+i]=base+i;
    }
    for (int i=1;i<=n;++i)
    {
        cin >> q[i].c;
        if (q[i].c==1)
        {
            cin >> q[i].x;
            a[++cnt]=q[i].x;
        }
        else cin >> q[i].x >> q[i].y;
    }
    int tmp=cnt;
    for (int i=n;i>=1;--i)
    {
        if (q[i].c==1)
        {
            int z=dsu[int(a[cnt])];
            if (z>base) z-=base;
            a[cnt]=char(z);
            cnt--;
            continue;
        }
        int X=q[i].x;
        int Y=q[i].y;
        if (!check[Y]) Y+=base;
        if (!check[X]) check[X]=1;
        Union(X,Y);
        //cout << X << ' ' << dsu[X] << '\n';
    }
    for (int i=1;i<=tmp;++i)
        cout << a[i];
    return;
}

//solve//
void solve()
{
    if (n<=10000) sub1();
    else sub2();
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
	freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
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
