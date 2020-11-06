#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int>    vi;
typedef pair<int, int> pi;
typedef vector<ll>     vll;
typedef pair<ll, int>  pli;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

template<typename T> void maximize(T &res, T val) { if (res < val) res = val; }
template<typename T> void minimize(T &res, T val) { if (res > val) res = val; }

ll n, k;
vector<ll> fib;
vector<bool> rep(80);
vector<vector<vector<ll> > > f;
ll magic(int i, int j, bool iln)
{
    if (i < 0) return (j >= k) ? j : 0;

    ll &res = f[i][j][iln];
    if (res != -1) return res;

    res = 0;
    int lim = iln || rep[i];
    for (int d = 0; d <= lim; ++d)
        res += magic(i - 1 - d, j + d, iln || (d < lim));

    return res;
}

vector<int> g;
int trau(ll x)
{
    if (x == 0) return g[x] = 0;

    int &res = g[x];
    if (res != -1) return res;
    int t = *--upper_bound(all(fib), x);
    return res = trau(x - t) + 1;
}

vector<vector<int> > dp(100);
int query()
{
    cin >> n >> k;

    if (k >= 80)
    {
        cout << 0 << '\n';
        return 0;
    }

    ll res = 0;
    if (n <= 1e5)
    {
        for (int p = k; p < fib.size(); ++p)
        {
            int pos = upper_bound(all(dp[p]), int(n)) - dp[p].begin();
            res += 1LL * p * pos;
        }
    }
    else 
    {
        for (int i = 79; i >= 0; --i)
        {
            if (n >= fib[i])
            {
                n -= fib[i];
                rep[i] = 1;
            }
            else rep[i] = 0;
        }
        f.assign(80, vector<vll>(80, vector<ll>(2, -1)));
        res = magic(79, 0, false);
    }

    cout << res << '\n';
    return 0;
}

int main()
{
    int q;
    cin >> q;

    fib.assign(82, 1);
    fib[1] = 2;
    for (int i = 2; i <= 82; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    
    g.assign(1e5 + 10, -1);
    for (int i = 1; i < g.size(); ++i)
        dp[trau(i)].push_back(i);

    while (q-->0)
    {
        query();



    }



    return 0;
}