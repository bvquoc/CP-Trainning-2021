#include <bits/stdc++.h>
#define task "DECOR"
#define ll long long
#define FOR( i, l, r) for(int i = (l), _r = (r); i <= _r; ++i)
#define FOD( i, l, r) for(int i = (l), _r = (r); i >= _r; --i)
#define REP( i, n)    for(int i = 0, _n = (n); i < _n; ++i)
#define pii pair<int, ll>
#define fi  first
#define se  second
#define MASK(x)  (1ll << (x))
#define BIT(x,k) (((x) >> (k)) & 1ll)
#define OFF(x,k) ((x) & ~(1ll << (k)))
#define ON(x,k)  ((1ll << (k)) | (x))
#define endl '\n'
#define __builtin_popcount __builtin_popcountll
using namespace std;
int const N = 5e5 + 11;
int numNode, numEdge, k;
string s;
int lab[N], sumLight[N];
class DisjointSet
{
public:
    DisjointSet (int n = 0)
    {
        FOR( i, 1, n) lab[i] = -1, sumLight[i] = s[i - 1] - '0';
    }
    int Find(int u)
    {
        return (lab[u] < 0 ? u : lab[u] = Find(lab[u]));
    }
    int join(int u, int v)
    {
        u = Find(u), v = Find(v);
        if(u == v)
            return 0;
        if(lab[u] > lab[v])
            swap( u, v);
        lab[u] += lab[v];
        sumLight[u] += sumLight[v];
        lab[v] = u;
        return 1;
    }
} dsu;
int cur[N];
void inp(void)
{
    cin >> numNode >> numEdge >> k;
    cin >> s;
    dsu = DisjointSet(numNode);
    FOR( i, 1, numEdge)
    {
        int u, v;
        cin >> u >> v;
        dsu.join( u, v);
    }
}
int ans, sta, fin;
int used[N];
void solve(void)
{
    int l = 1;
    FOR( r, 1, numNode)
    {
//        cerr << l << ' ' << r << endl;
        int p = dsu.Find(r);
        if(cur[p] < sumLight[p])
            cur[p]++;
        else
        {
            if(k > 0)
            {
                k--;
                used[p]++;
            }
            else
            {
                while(l <= r)
                {
                    int pl = dsu.Find(l);
                    if(used[pl] > 0)
                    {
                        used[pl]--;
                        used[p]++;
                        ++l;
                        break;
                    }
                    else
                    {
                        cur[pl]--;
                        l++;
                        if(pl == p)
                        {
                            cur[p]++;
                            break;
                        }
                    }
                }
            }
        }
        if(r - l + 1 > ans)
            ans = r - l + 1, sta = l, fin = r;
    }
    if(ans == 0)
    {
        cout << -1;
        return;
    }
    cout << sta << ' ' << fin;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    inp();
    solve();
    return 0;
}
