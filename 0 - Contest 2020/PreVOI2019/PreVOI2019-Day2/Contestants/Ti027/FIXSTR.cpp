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
int m,n;
string s[1000005];
char a[1000005];

//data structure//
class segtree
{
public:
    struct data
    {
        int sum,o,c;
    };
    data st[4000005];
    data combine(data l,data r)
    {
        data res;
        int z=min(l.o,r.c);
        res.o=r.o+l.o-z;
        res.c=l.c+r.c-z;
        res.sum=res.o+res.c;
        return res;
    }
    void build(int id,int l,int r)
    {
        if (l==r)
        {
            if (a[l]=='(')
            {
                st[id].sum=st[id].o=1;
                st[id].c=0;
            }
            else
            {
                st[id].sum=st[id].c=1;
                st[id].o=0;
            }
            //cerr << l << ' ' << st[id].o << ' ' << st[id].c << '\n';
            return;
        }
        int mid=(l+r)>>1;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id]=combine(st[id*2],st[id*2+1]);
        //cout << l << ' ' << r << ' ' << st[id].sum << '\n';
    }
    void update(int id,int l,int r,int u)
    {
        if (u<l||u>r) return;
        if (l==r)
        {
            if (a[l]=='(')
            {
                st[id].o=0;
                st[id].sum=st[id].c=1;
            }
            else
            {
                st[id].o=1;
                st[id].sum=st[id].c=0;
            }
            return;
        }
        int mid=(l+r)>>1;
        update(id*2,l,mid,u);
        update(id*2+1,mid+1,r,u);
        st[id]=combine(st[id*2],st[id*2+1]);
        //cout << l << ' ' << r << ' ' << st[id].sum << '\n';
    }
    data get(int id,int l,int r,int u,int v)
    {
        if (u>r||v<l) return {0,0,0};
        if (u<=l&&r<=v) return st[id];
        int mid=(l+r)>>1;
        return combine(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }
} ST;
///function///
//preset//

//input//
void input()
{
    cin >> s[0] >> m;
    n=s[0].length();
    return;
}

//algorithm//
int process(int l,int r,string x)
{
    stack <int> a,b;
    for (int i=l;i<=r;++i)
    {
        if (x[i]=='(')
        {
            a.push(i);
        }
        else
        {
            if (a.empty()) b.push(i);
            else a.pop();
        }
    }
    return a.size()+b.size();
}

int sub1()
{
    string t=s[0];
    for (int i=1;i<=m;++i)
    {
        s[i]=t;
        char c;
        cin >> c;
        if (c=='U')
        {
            int x;
            cin >> x;
            t=s[x];
        }
        else if (c=='C')
        {
            int x;
            cin >> x;
            if (t[x-1]=='(') t[x-1]=')';
            else t[x-1]='(';
        }
        else
        {
            int x,y;
            cin >> x >> y;
            cout << process(x-1,y-1,t) << '\n';
        }
    }
}

void sub2()
{
    for (int i=0;i<s[0].length();++i)
    {
        a[i+1]=s[0][i];
        //cerr << i+1 << ' ' << a[i+1] << '\n';
    }
    ST.build(1,1,n);
    for (int i=1;i<=m;++i)
    {
        char c;
        cin >> c;
        if (c=='C')
        {
            int x;
            cin >> x;
            ST.update(1,1,n,x);
        }
        else if (c=='Q')
        {
            int x,y;
            cin >> x >> y;
            cout << ST.get(1,1,n,x,y).sum << '\n';
        }
        else continue;
        //cout << '!';
    }
    return;
}

//solve//
void solve()
{
    if (s[0].length()<=1000&&m<=1000) sub1();
    else
        sub2();
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
	freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
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
