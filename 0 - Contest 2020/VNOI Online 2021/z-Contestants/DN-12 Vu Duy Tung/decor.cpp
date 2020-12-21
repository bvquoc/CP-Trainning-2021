#include<bits/stdc++.h>
#define mino "decor"

#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define INC(i,a,b) for(int i=a; i<=b; i++)
#define DEC(i,a,b) for(int i=a; i>=b; i--)
#define REP(i,a,b) for(int i=a; i<b; i++)

#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e17

const int N = 5e5 + 2;

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;


int n, m, k, sl;
int a[N], s[N], Near[N], nx[N], Fe[N];
int Tam[N], Last[N];
int type[N];
int Count[N];
vi g[N];

void solve1()
{
    INC(i,1,n) s[i] = s[i-1] + (a[i] == 0);

    int Max = 0, ml, mr;
    INC(i,1,n)
    {
        int l = i, r = n, res = -1;
        while( l <= r )
        {
            int mid = (l + r)/2;
            if( s[mid] - s[i-1] <= k )
            {
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if( res != -1 )
        {
            if( Max < res - i + 1 )
            {
                Max = res-i+1;
                ml = i;
                mr = res;
            }
        }
    }
    if( Max == 0 ) cout << "-1";
    else cout << ml << ' ' << mr;
}

void dfs(int u)
{
    type[u] = sl;
    if( a[u] == 1 ) Count[sl]++;

    for(int v : g[u])
        if( !type[v] ) dfs(v);
}

void upd(int i, int val)
{
    while( i <= n )
    {
        Fe[i] += val;
        i += i&-i;
    }
}

int get(int i)
{
    int cnt = 0;
    while( i )
    {
        cnt += Fe[i];
        i -= i&-i;
    }
    return cnt;
}

int get2(int l, int r)
{
    if( l > r ) return 0;
    return get(r) - get(l-1);
}

void solve2()
{
    INC(i,1,m)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    INC(i,1,n)
    {
        if( type[i] == 0 )
        {
            sl++;
            dfs(i);
            Near[sl] = n+1;
            Tam[sl] = Count[sl];
        }
    }

    DEC(i,n,1)
    {
        nx[i] = Near[type[i]];
        Near[type[i]] = i;
    }

    INC(i,1,n)
    {
        if( Tam[type[i]] > 0 )
        {
            a[i] = 1;
            upd(i, 1);
            Tam[type[i]]--;
            Last[type[i]] = i;
        }
        else a[i] = 0;
    }

    int Max = 0, ml, mr;
    int j = 1;
    INC(i,1,5)
    {
        j = max(j, i);
        while( j <= n && (j-i+1) - get2(i,j) <= k ) j++;
//        INC(j,1,n) cout << a[j] << ' '; cout << endl;
//        cout << i << ' ' << j-1 << endl;

        if( j - i > Max )
        {
            Max = j-i;
            ml = i;
            mr = j-1;
        }

        if( a[i] == 1 )
        {
            a[i] = 0;
            upd(i, -1);

            if( 1 <= Last[type[i]] && Last[type[i]] <= n )
            {
                int pos = nx[Last[type[i]]];
                a[pos] = 1;
                if( pos > 0 ) upd(pos, 1);
                Last[type[i]] = pos;
            }
        }
    }

    if( Max == 0 ) cout << "-1";
    else cout << ml << ' ' << mr;
}

int main()
{
    freopen(mino".inp","r",stdin);
    freopen(mino".out","w",stdout);

    turbo

    cin >> n >> m >> k;

    INC(i,1,n)
    {
        char x; cin >> x;
        a[i] = x - '0';
    }

    if( m == 0 )
        solve1();
    else
        solve2();


}
