#include <bits/stdc++.h>
using namespace std;
#define int long long
int q, x, t, f[1000100];
bool ok[1000100];
int val[] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
void sub2()
{
    memset(ok, 0, sizeof(ok));
    queue <int> q;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        //cout << u << " ";
        q.pop();
        int v;
        for (int i = 0; i < 15; i++)
        {
            v = u + val[i];
            if (v <= t && !ok[v])
            {
                q.push(v);
                f[v] = f[u] + 1;
                ok[v] = 1;
            }
        }
        v = u + x;
        if (v <= t && !ok[v])
        {
            q.push(v);
            f[v] = f[u] + 1;
            ok[v] = 1;
        }
    }
    cout << f[t] << "\n";
}
void sub4()
{
    int res = 0, j = 14;
    bool flag = 1;
    while (t > 0)
    {
        int cur;
        if (flag)
            cur = max(val[j], x);
        else
            cur = val[j];
        if (cur == val[j])
            flag = 0;
        int tmp = t / cur;
        t -= tmp * cur;
        res += tmp;
        j--;
    }
    cout << res << "\n";
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ODDCOIN.inp", "r", stdin);
    freopen("ODDCOIN.out", "w", stdout);
    cin >> q;
    while (q--)
    {
        cin >> x >> t;
        if (x <= 100000 && t <= 100000)
            sub2();
        else
        {
            if (t % x == 0)
                cout << t / x << "\n";
            else
                sub4();
        }
    }
}
