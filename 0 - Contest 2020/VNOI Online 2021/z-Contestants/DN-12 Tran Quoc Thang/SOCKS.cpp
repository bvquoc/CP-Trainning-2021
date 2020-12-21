#include<bits/stdc++.h>
using namespace std;

long long n ,m ,x ,y ,gt[1000005] ,d[155];
long long kq ,temp ,dem;
int dd[500005] ,de[500005];
const int mod = 1000000007;
string s;

struct ii
{
    int x ,y;
};

int power(int a, int n ,int mod )
{
    int res = 1;
    for (; n; n >>= 1, a = 1LL * a * a % mod)
    {
        if (n & 1) res = 1LL * res * a % mod;
    }
    return res;
}

int nhan ( int a, int n ,int mod )
{
    int res = 0;
    for ( ;n ;n >>= 1 ,a = (0LL + a + a) % mod )
    {
        if (n & 1) res = (0LL + res + a) % mod;
    }
    return res;
}

int C ( int n ,int k ,int mod)
{
    return gt[n]*power(gt[k]*gt[n-k]%mod,mod-2,mod)%mod;
}

void giaithua( int n )
{
    gt[0] = 1;
    for( int i = 1 ; i <= n ;i++ )
    {
        gt[i] = (gt[i-1]*i)%mod;
    }
}

int p[500005][25] ,h[500005];
vector<int> a[500005];

void dfs( int u ,int pr )
{
    for( int i = 1 ; i <= 20 ;i++ )
    {
        p[u][i] = p[p[u][i-1]][i-1];
    }
    for( int v : a[u] )
    {
        if( v == pr ) continue;
        p[v][0] = u;
        h[v] = h[u]+1;
        dfs(v ,u);
    }
}

int jump( int x ,int kc )
{
    for( int i = 20 ;i >= 0 ;i-- )
    {
        if( kc >= (1<<i) )
        {
            kc -= (1<<i);
            x = p[x][i];
        }
    }
    return x;
}

int LCA( int x ,int y )
{
    if( h[x] > h[y] ) swap(x ,y);
    y = jump(y ,h[y]-h[x]);
    if( x == y ) return x;
    for( int i = 20 ; i >= 0 ;i-- )
    {
        if(p[x][i] != p[y][i])
        {
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}

void di( int u ,int pr )
{
    for( int v : a[u] )
    {
        if( v == pr ) continue;
        di(v ,u);
        de[u] += de[v];
    }
    de[u] = max( de[u] ,dd[u]);
}


main()
{
    freopen("SOCKS.inp" ,"r" ,stdin);
    freopen("SOCKS.out" ,"w" ,stdout);
    int q;
    cin >> n >> q;
    for( int i = 1 ; i <= n ;i++ )
    {
        cin >> x;
        dd[i] = x;
    }
    for( int i = 2 ; i <= n ;i++ )
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    h[1] = 1;
    dfs(1 ,1);
    int goc = 0;
    for( int i = 1 ; i <= n ;i++ )
    {
        if( dd[i] )
        {
            di(i ,i);
            cout<<de[i]<<'\n';
            break;
        }
    }
    int te;
    for( int i = 1 ; i <= q ;i++ )
    {
        cin >> te;
        for( int j = 1 ; j <= n ;j++ ) de[j] = 0;
        if( dd[te] )
        {
            for( int j = 1 ; j <= n ;j++ )
            {
                if( dd[j] )
                {
                    di(j ,j);
                    cout<<de[j];
                    break;
                }
            }
            cout<<0<<'\n';
        }
        else
        {
            di(te ,te);
            cout<<de[te]<<'\n';
        }
    }
}
