#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define pb push_back
#define pii pair<int,int>
#define ppi pair<pii,int>
#define fi first
#define se second
#define bit(x,i) ((x>>i)&1)
#define onbit(x,i) (x|(1<<i))
using namespace std;

const int N = 5e5+5;
int n, m, k;
int a[N], s[N];

void sub1()
{
    int j = 1, res = 0, J = 0, I = 0;
    forinc(i,1,n)
    {
        while(s[i]-s[j-1] > k && j<=i) j++;
        int len = i-j+1;
        if(len > res)
        {
            res = len;
            I = j;
            J = i;
        }
    }
    if(!res) cout << -1;
    else cout << I << ' ' << J;
    exit(0);
}

vector<int> ke[N];
int lt, sum[N], vis[N];
void DFS(int u)
{
    vis[u] = lt;
    sum[lt] += a[u];
    for(int v : ke[u]) if(!vis[v]) DFS(v);
}

int L, R, dd[N];
bool check(int len)
{
    forinc(i,1,lt) dd[i] = sum[i];
    int need = 0;
    forinc(i,1,len)
    {
        dd[vis[i]]--;
        if(dd[vis[i]] < 0) need++;
    }
    forinc(l, 1, n-len+1)
    {
        int r = l+len-1;
        if(need <= k)
        {
            L = l;
            R = r;
            return 1;
        }
        if(dd[vis[l]] < 0) need--;
        dd[vis[l]]++;
        dd[vis[r+1]]--;
        if(dd[vis[r+1]] < 0) need++;
    }
    return 0;
}

void bisearch()
{
 //   check(2); return;
    int l = 0, r = n, res = 0;
    while(l<=r)
    {
        int m = (l+r)/2;
        if(check(m))
        {
            res = m;
            l = m+1;
        }
        else r = m-1;
    }
    if(!res) cout << -1;
    else
    {
        check(res);
        cout << L << ' ' << R;
    }
    exit(0);
}

int main()
{
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    forinc(i,1,n)
    {
        char ch; cin >> ch;
        a[i] = ch - '0';
        s[i] = s[i-1] + (1-a[i]);
    }
    if(!m) sub1();
    else
    {
        forinc(i,1,m)
        {
            int u, v;
            cin >> u >> v;
            ke[u].pb(v);
            ke[v].pb(u);
        }
        forinc(i,1,n) if(!vis[i])
        {
            ++lt;
            DFS(i);
        }
        bisearch();
    }
}
