#include <iostream>
#include <bits/stdc++.h>
#define FORU(i , a , b) for (int i = (a) ; i <= (b) ; i++)
#define FORD(i , a , b) for (int i = (a) ; i >= (b) ; i--)
#define pii pair <int , int>
#define fi first
#define se second
#define task "DECOR"
#define oo (int)1e9
using namespace std;
const int maxn = 5e5 + 10;
int par[maxn] , n , m , k , a[maxn];
int light[maxn] , cnt[maxn];
string s;
int ans1 , ans2 , best;
int Find(int u)
{
    if (par[u] != u) par[u] = Find(par[u]);
    return par[u];
}
void join(int u , int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    light[v] += light[u];
    par[u] = v;
}
void input()
{
    cin >> n >> m >> k >> s;
    FORU(i , 1 , n)
    {
        light[i] = a[i] = (int)s[i - 1] - 48;
        par[i] = i;
    }
    FORU(i , 1 , m)
    {
        int u , v;
        cin >> u >> v;
        join(u , v);
    }
}
int go(int pos , int rem)
{
    if (pos > n) return 0;
    int ret = 0;
    int tmp = Find(pos);
    if (light[tmp] > 0)
    {
        light[tmp]--;
        ret = max(ret , go(pos + 1 , rem) + 1);
        light[tmp]++;
    }
    if (rem > 0)
    {
        ret = max(ret , go(pos + 1 , rem - 1) + 1);
    }
    if (best < ret)
    {
        best = ret;
        ans1 = pos;
        ans2 = ans1 + best - 1;
    }
    else if (best == ret)
    {
        if (ans1 > pos)
        {
            ans1 = pos;
            ans2 = ans1 + best - 1;
        }
    }
    return ret;
}
bool check(int x)
{
    memset(cnt , 0 , sizeof(cnt));
    set <int> s;
    int tmp = 0;
    FORU(i , 1 , x)
    {
        int tmp1 = Find(i);
        if (cnt[tmp1] >= light[tmp1])
        {
            tmp++;
        }
        cnt[tmp1]++;
    }
    if (k >= tmp)
    {
        ans1 = 1;
        ans2 = x;
        return true;
    }
    FORU(i , 2 , n - x + 1)
    {
        int tmp1 = Find(i - 1);
        int pos = i + x - 1;
        int tmp2 = Find(pos);
        if (cnt[tmp1] > light[tmp1])
        {
            tmp--;
        }
        cnt[tmp1]--;
        if (cnt[tmp2] >= light[tmp2])
        {
            tmp++;
        }
        cnt[tmp2]++;
        if (k >= tmp)
        {
            ans1 = i;
            ans2 = i + x - 1;
            return true;
        }
    }
    return false;
}
void solve()
{
    int L = 1 , R = n;
    while (L <= R)
    {
        int m = (L + R) / 2;
        if (check(m)) L = m + 1;
        else R = m - 1;
    }
    cout << ans1 << " " << ans2;
}
void sub3()
{
    FORU(i , 1 , n)
    {
        go(i , k);
    }
    cout << ans1 << " " << ans2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp" , "r" , stdin);
    freopen(task".out" , "w" , stdout);
    input();
    solve();
    return 0;
}
