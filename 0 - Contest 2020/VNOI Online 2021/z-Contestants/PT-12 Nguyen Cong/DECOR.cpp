#include <bits/stdc++.h>
using namespace std;

struct Tnode
{
    int u, v;
};
int n, m, k;
string str;
int Sum[500010];
Tnode E[500010];

namespace SUBFULL
{

int pa[500010];
int num[500010];
int root(int u)
{
    return (pa[u] < 0) ? u : pa[u] = root(pa[u]);
}
void DSU(int u, int v)
{
    if((u = root(u)) == (v = root(v)))
        return ;
    if(pa[u] > pa[v])
        swap(u, v);
    pa[u] += pa[v];
    num[u] += num[v];
    pa[v] = u;
}
int cnt[500010];
int check(const int &mid)
{
    memset(cnt, 0, sizeof cnt);
    int can = 0;
    for(int i = 1; i <= mid; i++)
    {
        int u = root(i);
        cnt[u]++;
        can += (cnt[u] > num[u]);
    }
    if(can <= k)
        return 1;
    int l = 1;
    for(int i = mid + 1; i <= n; i++)
    {
        int u = root(l);
        can -= (cnt[u] > num[u]);
        cnt[u]--;
        l++;
        u = root(i);
        cnt[u]++;
        can += (cnt[u] > num[u]);
        if(can <= k)
            return l;
    }
    return 0;
}
void Process()
{
//    str = " " + S;
    memset(pa, -1, sizeof pa);
    for(int i = 1; i <= n; i++)
        num[i] = (str[i] == '1');
    for(int i = 1; i <= n; i++)
        DSU(E[i].u, E[i].v);
//    check(3);
    int l = 1, r = n;
    int ans = -1;
    int Left = -1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        int temp = check(mid);
        if(temp)
        {
            ans = mid;
            Left = temp;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if(ans == -1) {
        cout << -1;
    }
    else {
        cout << Left << " " << ans;
    }
}
}

main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);

    cin >> n >> m >> k;
    cin >> str;
    str = "@" + str;
    for(int i = 1; i <= m; i ++)
    {
        int u, v;
        cin >> u >> v;
        E[i].u = u;
        E[i].v = v;
    }

    SUBFULL::Process();

}
