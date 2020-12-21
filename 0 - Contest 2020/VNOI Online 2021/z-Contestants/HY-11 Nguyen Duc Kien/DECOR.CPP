#include <bits/stdc++.h>

#define TASK "DECOR"

using namespace std;

const int maxn = 5e5 + 5;

int n, m, k;
char a[maxn];
pair <int, int> p[maxn];

namespace Sub1
{
    void Main()
    {
        int res = 0, l, r, st = 1;
        int len = 0;
        for (int i = 1; i <= n; i ++)
        {
            if (a[i] == '1') len ++;
            else
            {
                if (len > res)
                {
                    res = len;
                    l = st;
                    r = i - 1;
                }
                len = 0;
                st = i + 1;
            }
        }
        if (res == 0) cout << "-1\n";
        else
        {
            cerr << res << "\n";
            cout << l << " " << r << "\n";
        }

    }
}

namespace Sub2
{
    int res, resl, resr;

    bool ok(int x)
    {
        int ck = 0;
        for (int i = 1; i <= x; i ++)
            ck += (a[i] == '0');
        if (ck <= k)
        {
            resl = 1, resr = x;
            return 1;
        }
        for (int i = 2; i + x - 1 <= n; i ++)
        {
            ck -= (a[i - 1] == '0');
            ck += (a[i + x - 1] == '0');
            if (ck <= k)
            {
                resl = i, resr = i + x - 1;
                return 1;
            }
        }
        return 0;
    }

    void Main()
    {
        int l = 0, r = n + 1;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (ok(mid)) l = mid;
            else r = mid;
        }
        if (l == 0) {cout << "-1" << "\n"; return;}
        ok(l);
        cerr << l << "\n";
        cout << resl << " " << resr << "\n";
    }
}

namespace Sub3
{
    int res, resl, resr, in[maxn], ccp, sz[maxn], tmpsz[maxn];
    vector <int> b[maxn];

    void DFS(int u)
    {
        for (auto v : b[u])
        {
            if (in[v]) continue;
            in[v] = ccp;
            if (a[v] == '1') sz[ccp] ++;
            DFS(v);
        }
    }

    bool ok(int x)
    {
        int add = 0;
        for (int i = 1; i <= n; i ++) tmpsz[i] = sz[i];

        for (int i = 1; i + x - 1 <= n; i ++)
        {
            for (int j = 1; j <= ccp; j ++) tmpsz[i] = sz[i];
            for (int j = i; j <= i + x - 1; j ++)
            {
                if (a[j] == '1') tmpsz[in[j]] --;
            }
            for (int j = 1; j <= i + x - 1; j ++)
            {
                if (a[j] == '0')
                {
                    if (tmpsz[in[i]] > 0) tmpsz[in[i]] --;
                    else add ++;
                }
            }
            if (add <= k)
            {
                resl = i, resr = i + x - 1;
                return 1;
            }
        }
        return 0;
    }

    void Main()
    {
        if (n > 5000) {cout << -1; return;}
        for (int i = 1; i <= m; i ++)
        {
            int u = p[i].first;
            int v = p[i].second;
            b[u].push_back(v);
            b[v].push_back(u);
        }

        for (int i = 1; i <= n; i ++)
            if (!in[i])
            {
                ccp ++;
                in[i] = ccp;
                sz[ccp] = (a[i] == '1');
                DFS(i);
            }

        int l = 0, r = n + 1;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (ok(mid)) l = mid;
            else r = mid;
        }
        if (l == 0) {cout << "-1" << "\n"; return;}
        ok(l);
        cerr << l << "\n";
        cout << resl << " " << resr << "\n";
    }
}

namespace Sub4
{
    int res, resl, resr, in[maxn], ccp, sz[maxn], tmpsz[maxn];
    vector <int> b[maxn];

    void DFS(int u)
    {
        for (auto v : b[u])
        {
            if (in[v]) continue;
            in[v] = ccp;
            if (a[v] == '1') sz[ccp] ++;
            DFS(v);
        }
    }

    bool ok(int x)
    {
        int add = 0;
        for (int i = 1; i <= n; i ++) tmpsz[i] = sz[i];
        for (int i = 1; i <= x; i ++)
            if (a[i] == '1') tmpsz[in[i]] --;
        for (int i = 1; i <= x; i ++)
        {
            if (a[i] == '0')
            {
                if (tmpsz[in[i]] != 0) tmpsz[in[i]] --;
                else add ++;
            }
        }
        if (add <= k)
        {
            resl = 1, resr = x;
            return 1;
        }
        for (int i = 2; i + x - 1 <= n; i ++)
        {
            if (a[i - 1] == '1') tmpsz[in[i - 1]] ++;
            else
            {
//                if (tmpsz[in[i - 1]] == 0) add--;
                if (tmpsz[in[i - 1]] != sz[in[i - 1]]) tmpsz[in[i - 1]] ++;
                else add--;

            }
            if (a[i + x - 1] == '1') tmpsz[in[i + x - 1]] --;
            else
            {
                if (tmpsz[in[i + x - 1]] != 0) tmpsz[in[i + x - 1]] --;
                else add ++;
            }

            if (add <= k)
            {
                resl = i, resr = i + x - 1;
                return 1;
            }
        }
        return 0;

    }

    void Main()
    {
        for (int i = 1; i <= m; i ++)
        {
            int u = p[i].first;
            int v = p[i].second;
            b[u].push_back(v);
            b[v].push_back(u);
        }

        for (int i = 1; i <= n; i ++)
            if (!in[i])
            {
                ccp ++;
                in[i] = ccp;
                sz[ccp] = (a[i] == '1');
                DFS(i);
            }

        ok(4);
        int l = 0, r = n + 1;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (ok(mid)) l = mid;
            else r = mid;
        }
        if (l == 0) {cout << "-1" << "\n"; return;}
        ok(l);
        cerr << l << "\n";
        cout << resl << " " << resr << "\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen(TASK".INP", "r", stdin);
	freopen(TASK".OUT", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= m; i ++) cin >> p[i].first >> p[i].second;
	if (m == 0 && k == 0) Sub1::Main();
    else if (m == 0) Sub2::Main();
    else if (n <= 2000) Sub3::Main();
    else Sub4::Main();
//    Sub3::Main();
//    Sub4::Main();
	return 0;
}
