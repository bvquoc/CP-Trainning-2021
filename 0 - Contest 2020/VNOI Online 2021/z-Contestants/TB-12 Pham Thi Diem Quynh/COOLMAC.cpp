#include <bits/stdc++.h>
#define task "COOLMAC"
#define ll long long
#define FOR( i, l, r) for(int i = (l), _r = (r); i <= _r; ++i)
#define FOD( i, l, r) for(int i = (l), _r = (r); i >= _r; ++i)
#define REP( i, n)    for(int i = 0, _n = (n); i < _n; ++i)
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1ll << (x))
#define BIT(x, k) (1ll & ((x) >> (k)))
#define ON(x, k)  ((x) | (1ll << (k)))
#define OFF(x, k) ((x) & ~(1ll << (k)))
#define endl '\n'
#define __builtin_popcount __builtin_popcountll
using namespace std;
int const N = 1e5 + 11;
pii lines[N];
int m, n, cur = 1e5 + 7;
queue<int> q;
void inp(void)
{
    cin >> m;
    FOR( i, 1, m) cin >> lines[i].fi >> lines[i].se;
    cin >> n;
    FOR( i, 1, n)
    {
        int val;
        cin >> val;
        cur = min(cur, val);
    }
}
int ans = 0;
void solve(void)
{
    sort(lines + 1, lines + m + 1, [](pii const &x, pii const &y)
    {
        return (x.fi == y.fi ? x.se > y.se : x.fi < y.fi);
    });
    FOR( i, 1, m)
    {
        if(cur >= 1e5)
        {
            cout << ans;
            return;
        }
        if(lines[i].fi <= cur && lines[i].se >= cur)
            q.push(i);
        else
        {
            if(q.empty() && cur < 1e5)
            {
                cout << -1;
                return;
            }
            ++ans;
            while(!q.empty())
            {
                cur = max(cur, lines[q.front()].se);
                q.pop();
            }
            if(lines[i].fi <= cur && lines[i].se >= cur)
                q.push(i);
        }
    }
    if(cur < 1e5)
        ++ans;
    while(!q.empty() && cur < 1e5)
    {
        cur = max(cur, lines[q.front()].se);
        q.pop();
    }
    if(cur < 1e5)
    {
        cout << -1;
        return;
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    inp();
    solve();
    return 0;
}
