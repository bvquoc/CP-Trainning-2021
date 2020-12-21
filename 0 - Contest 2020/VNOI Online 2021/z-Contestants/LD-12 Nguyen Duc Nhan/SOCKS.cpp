#include <bits/stdc++.h>

using namespace std;
const int maxN = 5e5;
int n, q;
int c[maxN + 5];
vector <int> a[maxN + 5];
int arr[maxN + 5];
int pos[maxN + 5];
int maxsiz;
int ant[maxN + 5];
int d[maxN + 5];
void sub1()
{
    int st = -1, ed = -1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i].size() == 1)
                if (st == -1) st = i;
                else ed = i;
        }
        int cnt = 0;
        int pre = 0;
        while (st != ed)
        {
            arr[++cnt] = st;
            pos[st] = cnt;
            int cur = st;
            for (auto v : a[st])
                if (v != pre) st = v;
            pre = cur;
        }
        arr[++cnt] = ed;
        pos[ed] = cnt;
        int siz = 0;
        int ans = 0;
        priority_queue <int, vector <int>, greater<int> > ql;
        priority_queue <int> qr;
        for (int i = 1; i <= n; i++)
            if (c[arr[i]] == 1) ql.push(i), qr.push(i), siz++;
        if (siz >= 2) ans = qr.top() - ql.top();
        while (q--)
        {
            int x;
            cin >> x;
            if (c[x] == 0)
            {
                if (qr.size() != 0 && x > qr.top()) qr.push(x);
                if (ql.size() != 0 && x < ql.top()) ql.push(x);
                if (siz <= 1) qr.push(x), ql.push(x);
                siz++;
                c[x] = 1;
            }
            else
            {
                c[x] = 0;
                while (c[qr.top()] == 0 && qr.size() != 0) qr.pop();
                while (c[ql.top()] == 0 && ql.size() != 0) ql.pop();
                siz --;
            }
            if (siz >= 2) ans = qr.top() - ql.top();
            else ans = 0;
            cout << ans << '\n';
        }
}
void dfs(int u,int p)
{
    ant[u] = ant[p];
    d[u] = d[p] + 1;
    for (auto v : a[u])
        if (v != p)
            dfs(v, u);
}
/*void sub2()
{
    int st;
    for (int i = 1; i <= n; i++)
        if (a[i].size() == 3) st = i;
    for (int color = 1; color <= 3; color++)
    {
        ant[st] = color;
        dfs(a[st][color - 1], st);
    }

}*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SOCKS.INP", "r", stdin);
    freopen("SOCKS.OUT", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        if (maxsiz < a[i].size()) maxsiz = a[i].size();
    if (maxsiz == 2)
    {
        sub1();
    }
    /*else
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (a[i].size() == 3) cnt++;
        if (cnt == 1) sub2();
    }*/
    return 0;
}
