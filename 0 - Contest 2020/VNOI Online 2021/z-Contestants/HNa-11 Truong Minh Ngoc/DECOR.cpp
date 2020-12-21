#include <bits/stdc++.h>

const int N = 5e5 + 5, mod = 1e9 + 7;
#define X first
#define Y second
#define fo(i,j,k) for(int i = j; i <= k; ++i)
#define of(i,j,k) for(int i = j; i >= k; --i)
#define PB push_back
#define all(a) (a).begin(),(a).end()
#define reset(a,val) fill(a+1,a+sizeof(a),val)
#define getbit(i,j) (int)(((i) >> (j)) & 1)
#define task "DECOR"

using namespace std;

typedef pair <int,int> ii;
typedef long long ll;

vector <int> a[N];
ii couple[N];
int n,m,k;
string s;
int sum[N],space[N],d,c;

void read()
{
    cin >> n >> m >> k >> s;
    s = ' ' + s;
    fo(i,1,m)
    {
        cin >> couple[i].X >> couple[i].Y;
        a[couple[i].X].PB(couple[i].Y);
        a[couple[i].Y].PB(couple[i].X);
    }
}

int dau[N];

void init()
{
    int max1 = 0;
    fo(i,1,n)
    {
        space[i] = space[i-1];
        if(s[i] == '1')
            sum[i] = sum[i-1] + 1;
        else
        {
            sum[i] = 0;
            space[i] = space[i-1] + 1;
            dau[space[i]] = i;
        }
        if(max1 < sum[i])
        {
            max1 = sum[i];
            c = i;
            d = i - sum[i] + 1;
        }
    }

    if(sum[n] == 0)
    {
        cout << -1;
        exit(0);
    }

    if(sum[n] == n)
    {
        cout << 1 << ' ' << n;
        exit(0);
    }
}

void solve1()
{
    int max1 = 0;

    fo(i,1,n)
    {
        int id = upper_bound(space+i+1,space+n+1,space[i-1] + k) - space - 1;
        if(max1 < sum[i-1] + id - i + 1)
        {
            max1 = sum[i-1] + id - i + 1;
            d = i;
            c = id;
        }
    }

    cout << d << " " << c;
}

vector <int> tplt[N];
bool ok[N],vsd[N];
int pt[N],cnt = 0,dem[N];
bool f[2005][2005];

void DFS(int u,int lt)
{
    vsd[u] = true;
    pt[u] = lt;
    if(s[u] == '1')
    {
        dem[lt]++;
        ok[lt] = true;
        tplt[lt].PB(u);
    }
    for(auto v : a[u])
    {
        if(vsd[v]) continue;
        DFS(v,lt);
    }
}

void solve2()
{
    fo(i,1,n) if(!vsd[i]) DFS(i,++cnt);
    fo(i,1,cnt) sort(all(tplt[i]));

    of(i,n,1) fo(j,i+1,n)
    {
        int sp = space[j] - space[i-1];
        if(sp <= k)
        {
            f[i][j] = true;
            continue;
        }

    }

    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    read();
    init();
    solve1();
    /// solve2();

    return 0;
}
