#include <bits/stdc++.h>
#define fi first
#define se second
#define fr(i, x, y) for (int i = x; i <= y; ++i)
#define ft(i, x, y) for (int i = y; i >= x; --i)
#define pii pair <int, int>
#define getbit(x, k) ((x) & (1 << (k)))
#define flip(x, k) ((x) ^ (1 << (k)))
#define ll long long
using namespace std;
int n, m, min_t = 1e6, max_t = 0, min_val[100010], max_val[100010], cnt, res = 1e6, d[100010];
pii t[100010];
vector <int> edge[100010];
void inp ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("coolmac.inp", "r", stdin);
    freopen ("coolmac.out", "w", stdout);
    cin >> m;
    fr (i, 1, m) cin >> t[i].fi >> t[i].se;
    cin >> n;
    fr (i, 1, n)
    {
        int temp;
        cin >> temp;
        min_t = min(min_t, temp);
    }
    max_t = 1e5;
}
void sub1 ()
{
    sort (t + 1, t + m + 1);
    fr (x, 0, (1 << m) - 1)
    {
        bool ok = false;
        int cnt = 0, templ = 1e6, tempr = 0;
        fr (i, 1, m) if (getbit(x, i - 1))
        {
            cnt++;
            if (t[i].fi > tempr + 1 and t[i].fi > min_t and t[i].fi <= max_t) templ = 1e6, tempr = 0;
            templ = min(templ, t[i].fi);
            tempr = max(tempr, t[i].se);
            if (templ <= min_t and tempr >= max_t) ok = true;
        }
        if (ok == true) res = min(res, cnt);
    }
    if (res == 1e6) res = -1;
    cout << res;
}
void dfs (int u)
{
    cnt++;
    if (min_val[u] <= min_t and max_val[u] >= max_t) res = min (res, cnt);
    d[u] = 1;
    for (int v : edge[u])
    {
        if (d[v] == 1) continue;
        min_val[v] = min(min_val[u], t[v].fi);
        max_val[v] = max(max_val[u], t[v].se);
        dfs (v);
    }
    cnt--;
}
void sub2 ()
{
    sort (t + 1, t + m + 1);
    fr (i, 1, m) fr (j, 1, m)
    {
        if (t[i].fi < t[j].fi and t[j].fi <= t[i].se + 1 and t[j].se > t[i].se) edge[i].push_back(j);
    }
    fr (i, 1, m)
    {
        fr (j, 1, m) d[j] = 0;
        cnt = 0;
        min_val[i] = t[i].fi;
        max_val[i] = t[i].se;
        dfs (i);
    }
    if (res == 1e6) res = -1;
    cout << res;
}
bool check (int mid)
{
//    cout << min_t << "\n";
    fr (i, 1, m)
    {
//        cout << t[i].fi << "\n";
        if (t[i].fi > min_t) break;
//        cout << i << "\n";
        int pos = i, st = i, maxr = t[i].se, dem = 1, _pos = i;
//        cout << pos << "\n";
        while (pos <= m and st <= m)
        {
            dem++;
            pos = _pos;
            while (st <= m and t[pos].se >= t[st].fi - 1)
            {
//                cout << mid << " " << pos << " " << st << "\n";
                if (maxr <= t[st].se)
                {
                    maxr = t[st].se;
                    _pos = st;
                }
                st++;
            }
            if (pos == _pos) break;
            if (t[i].fi <= min_t and maxr >= max_t and dem <= mid) return true;
        }
    }
    return false;
}
void sub3 ()
{
    sort (t + 1, t + m + 1);
    int l = 0, r = m;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    if (check(l)) cout << l;
    else
    {
        if (check(r)) cout << r;
        else cout << -1;
    }
}
int main ()
{
    inp();
    if (n <= 1000) sub2();
    else sub3();
    return 0;
}




