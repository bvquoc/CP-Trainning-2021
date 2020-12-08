#include <bits/stdc++.h>
#define task "paint"

using namespace std;

const int N = 1e6 + 5;

int par[N], rt[26], val[N];

int root(int k)
{
    return par[k] < 0 ? k : (par[k] = root(par[k]));
}

void _merge(int u, int v)
{
    if ((u = root(u)) == (v = root(v))) return;
    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	int n, K = 0;
	cin >> n;
	char x, y;
	memset(par, -1, sizeof(par));
	memset(val, -1, sizeof(val));
	for (int i = 0, q; i < n; ++i)
    {
        cin >> q >> x;
        if (q == 1)
        {
            ++K;
            if (!rt[x - 'a']) rt[val[K] = x - 'a'] = K;
            else _merge(rt[x - 'a'], K);
            continue;
        }
        cin >> y;
        if (!rt[x - 'a']) continue;
        if (rt[y - 'a'])
            _merge(rt[x - 'a'], rt[y - 'a']);
        val[rt[x - 'a']] = -1;
        val[rt[y - 'a'] = root(rt[x - 'a'])] = y - 'a';
        rt[x - 'a'] = 0;
    }
    for (int i = 1; i <= K; ++i) cout << (char) ('a' + val[root(i)]);
	return 0;
}
