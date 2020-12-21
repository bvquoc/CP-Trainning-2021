#include <bits/stdc++.h>

#define TASK "SOCKS"

using namespace std;

const int maxn = 1e5 + 5;

int n, q, c[maxn], f[maxn], g[maxn], root;
vector <int> a[maxn];

namespace Sub3
{
    bool mk[maxn];

//    void DFS(int u)
//    {
//        int red_child = 0, rc = 0;
//        for (auto v : a[u])
//        {
//            if (mk[v]) continue;
//            mk[v] = 1;
//            DFS(v);
//            if (g[v] != 0) red_child ++, rc = v, g[u] ++;
//
//        }
//        if (red_child >= 2) f[u] = red_child - 1;
//        else if (red_child == 1)
//        {
//            if (c[u] == 1) f[u] = 1;
//            else f[u] = f[rc];
//        }
//    }
//
    void Main()
    {
//        while (q--)
//        {
//            int x;
//            cin >> x;
//            c[x] ^= 1;
//            memset(f, 0, sizeof(f));
//            memset(mk, 0, sizeof(mk));
//            mk[1] = 1;
//            DFS(1);
//        }
    }
}

namespace Sub1
{
    void Main()
    {
        int cred = accumulate(c + 1, c + n + 1, 0);
        if (cred < 2) cout << 0 << "\n";
        else cout << 1 << "\n";
        while (q--)
        {
            int x;
            cin >> x;
            int old = c[x];
            c[x] ^= 1;
            cred += c[x] - old;
            if (cred < 2) cout << 0 << "\n";
            else cout << 1 << "\n";
        }
    }
}

namespace Sub2
{
    int in[maxn], mk[maxn], cred[maxn];

    void DFS(int u, int x)
    {
        in[u] = x;
        for (auto v : a[u])
        {
            if (mk[v]) continue;
            mk[v] = 1;
            DFS(v, x);
        }
    }

    void Main()
    {
        int cnt = 0;
        mk[root] = 1;
        for (auto u : a[root])
        {
            cnt ++;
            mk[u] = 1;
            DFS(u, cnt);
        }
        for (int i = 1; i <= n; i ++)
            if (c[i]) cred[in[i]] ++;
        int sum = cred[1] + cred[2] + cred[3];
        if (sum == 1)
        {
            if (c[root] == 0) cout << 0 << "\n";
            else cout << 1 << "\n";
        }
        else
        {
            int dif = (cred[1] != 0) + (cred[2] != 0) + (cred[3] != 0);
            cout << dif - 1 << "\n";
        }
        while (q--)
        {
            int x;
            cin >> x;
            int old = c[x];
            c[x] ^= 1;
            cred[in[x]] += c[x] - old;
            sum = cred[1] + cred[2] + cred[3];
            if (sum == 1)
            {
                if (c[root] == 0) cout << 0 << "\n";
                else cout << 1 << "\n";
            }
            else if (sum != 0)
            {
                int dif = (cred[1] != 0) + (cred[2] != 0) + (cred[3] != 0);
                cout << dif - 1 << "\n";
            }
            else cout << 0 << "\n";
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen(TASK".inp", "r", stdin);
	freopen(TASK".out", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= n; i ++) cin >> c[i];
	bool bamboo = 1, T_tree = 1;
	for (int u, v, i = 1; i < n; i ++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        if (a[u].size() >= 3 || a[v].size() >= 3) bamboo = 0;
    }
	if (bamboo) Sub1::Main();
	else
    {
        for (int i = 1; i <= n; i ++)
        {
            if (a[i].size() == 3)
            {
                if (root) T_tree = 0;
                else root = i;
            }
            else if (a[i].size() > 3) T_tree = 0;
        }
        if (T_tree) Sub2::Main();
        else if (n <= 1000) Sub3::Main();
    }


	return 0;
}
