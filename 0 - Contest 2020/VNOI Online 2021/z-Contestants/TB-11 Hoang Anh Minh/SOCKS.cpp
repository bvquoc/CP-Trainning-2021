#include <iostream>
#include <bits/stdc++.h>
#define FORU(i , a , b) for (int i = (a) ; i <= (b) ; i++)
#define FORD(i , a , b) for (int i = (a) ; i >= (b) ; i--)
#define pii pair <int , int>
#define fi first
#define se second
#define task "SOCKS"
#define oo (int)1e9
using namespace std;
const int maxn = 5e5 + 10;
int n , deg[maxn] , num , MAX , a[maxn] , q , st;
int total , timein[maxn] , cnt , k , val[4];
pii f[5];
vector <int> adj[maxn];
void input()
{
    cin >> n >> q;
    FORU(i , 1 , n) {
        cin >> a[i];
    }
    FORU(i , 1 , n - 1)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
        FORU(j , 0 , 1)
        {
            int tmp = (!j) ? u : v;
            if (MAX < deg[tmp])
            {
                MAX = deg[tmp];
                num = 1;
                st = tmp;
            }
            else if (MAX == deg[tmp]) num++;
        }
    }
}
void upd_1(int u)
{
    if (a[u]) total--;
    else total++;
    a[u] = 1 - a[u];
}
int get_1()
{
    if (total <= 1) return 0;
    return 1;
}
void sub1()
{
    FORU(i , 1 , n) total += a[i];
    cout << get_1() << '\n';
    while (q--)
    {
        int x;
        cin >> x;
        upd_1(x);
        cout << get_1() << '\n';
    }
}
void dfs(int u)
{
    timein[u] =++cnt;
    for (int v : adj[u])
    {
        if (!timein[v])
        {
            if (u == st) f[++k].fi = cnt + 1;
            dfs(v);
            if (u == st) f[k].se = cnt;
        }
    }
}
void upd_2(int u)
{
    if (u == st)
    {
        a[u] = 1 - a[u];
        return;
    }
    int tmp;
    FORU(i , 1 , 3) if (timein[u] >= f[i].fi && timein[u] <= f[i].se) tmp = i;
    if (a[u]) val[tmp]--;
    else val[tmp]++;
    a[u] = 1 - a[u];
}
int get_2()
{
    int active = 0 , tmp;
    FORU(i , 1 , 3) if (val[i] > 0)
    {
        active++;
        tmp = i;
    }
    if (active == 1)
    {
        if (val[tmp] > 1) return 1;
        else
        {
            if (a[st]) return 1;
            else return 0;
        }
    }
    else if (active == 2)
    {
        return 1;
    }
    else if (active == 3)
    {
        return 2;
    }
    return 0;
}
void sub2()
{
    dfs(st);
    FORU(i , 1 , n)
    {
        if(a[i])
        {
            FORU(j , 1 , 3) if (timein[i] >= f[j].fi && timein[i] <= f[j].se) val[j]++;
        }
    }
    cout << get_2() << '\n';
    while (q--)
    {
        int x;
        cin >> x;
        upd_2(x);
        cout << get_2() << '\n';
    }
}
void solve()
{
    if (MAX == 3 && num == 1) sub2();
    else if (MAX == 2) sub1();
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
