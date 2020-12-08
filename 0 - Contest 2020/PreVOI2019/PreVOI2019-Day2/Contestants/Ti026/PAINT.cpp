///------------------  ONESHOTAC -------------------
#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
//#define f first
//#define s second
//#define int long long
using namespace std;

const int MOD=1e9+7;
//const int N = 200005;
int n;
int a[10005], pos = 0;
vector < int > vt[35];
//vector < int > child[35];
struct Query
{
    int t, x, y;
}q[1000005];
int par[35];
void sub1()
{
    FOR(i, 1, n)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            char u;
            cin >> u;
            a[++ pos] = u - 'a' + 1;
            vt[u - 'a' + 1].push_back(pos);
        }
        else
        {
            char u, v;
            cin >> u >> v;
            if(u == v) continue;
            for(int x : vt[u - 'a' + 1])
            {
                a[x] = v - 'a' + 1;
                vt[v - 'a' + 1].push_back(x);
            }
            vt[u - 'a' + 1].clear();
        }
    }
    FOR(i, 1, pos)
    {
        cout << (char)(a[i] + 'a' - 1);
    }
}
int get_par(int u)
{
    if(par[u] == u) return u;
    return par[u] = get_par(par[u]);
}
//void update(int u, int v)
//{
//    for(int x : child[u])
//    {
//        update(x, v);
//    }
//    child[u].clear();
//    child[v].push_back(u);
//    par[u] = v;
//}
void sub2()
{
    FOR(i, 1, n)
    {
//        char s;
        cin >> q[i].t;
        if(q[i].t == 1)
        {
            char s;
            cin >> s;
            q[i].x = s - 'a' + 1;
            pos ++;
        }
        else
        {
            char u, v;
            cin >> u >> v;
            q[i].x = u - 'a' + 1;
            q[i].y = v - 'a' + 1;
        }
    }
    FOR(i, 1, 30) par[i] = i;
    int pos1 = pos;
    FORD(i, n, 1)
    {
        if(q[i].t == 1)
        {
            int u = par[q[i].x];
            a[pos] = u;
            pos --;
        }
        else
        {
            par[q[i].x] = get_par(q[i].y);
//            update(q[i].x, q[i].y);
        }
    }
    FOR(i, 1, pos1)
    {
        cout << (char)(a[i] + 'a' - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    cin >> n;
    if(n <= 10000)
    {
        sub1();
    }
    else
    {
        sub2();
    }
    return 0;
}
