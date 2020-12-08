#include <bits/stdc++.h>
#define task "fixstr"

using namespace std;

const int N = 1e6 + 5;

struct brackets
{
    int l, p, r;
    brackets(int _l = 0, int _p = 0, int _r = 0)
    {
        l = _l;
        p = _p;
        r = _r;
    }
} it[N << 2];

brackets operator+ (brackets i, brackets j)
{
    int cur = min(i.l, j.r);
    i.l += j.l - cur;
    i.r += j.r - cur;
    i.p += j.p + cur;
    return i;
}

string s;
int id[N];
vector<int> q, in[N];
set<int> res;

brackets build(int k, int l, int r)
{
    if (l == r)
    {
        id[l] = k;
        if (s[l - 1] == '(') ++it[k].l;
        else ++it[k].r;
        return it[k];
    }
    int m = (l + r) >> 1;
    return it[k] = build(k * 2, l, m) + build(k * 2 + 1, m + 1, r);
}

brackets get(int k, int l, int r, int u, int v)
{
    if (r < u || v < l) return brackets();
    if (u <= l && r <= v) return it[k];
    int m = (l + r) >> 1;
    return get(k * 2, l, m, u, v) + get(k * 2 + 1, m + 1, r, u, v);
}

void upd(int k)
{
    swap(it[k].l, it[k].r);
    k >>= 1;
    while (k)
    {
        it[k] = it[k * 2] + it[k * 2 + 1];
        k >>= 1;
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> s;
	int n = s.length(), m;
	cin >> m;
	build(1, 1, n);
	char c;
	for (int i = 1, u, v; i <= m; ++i)
    {
        cin >> c >> u;
        if (c == 'Q')
        {
            cin >> v;
            brackets cur = get(1, 1, n, u, v);
            cout << cur.l + cur.r << '\n';
            continue;
        }
        if (c == 'U')
        {
            for (vector<int>::iterator it = lower_bound(q.begin(), q.end(), u); it != q.end(); ++it)
                for (vector<int>::iterator k = in[*it].begin(); k != in[*it].end(); ++k)
                    if (res.count(*k)) res.erase(*k);
                    else res.insert(*k);
            for (set<int>::iterator it = res.begin(); it != res.end(); ++it)
            {
                upd(id[*it]);
                in[i].push_back(*it);
            }
            if (!res.empty())
            {
                res.clear();
                q.push_back(i);
            }
            continue;
        }
        upd(id[u]);
        in[i].push_back(u);
        q.push_back(i);
    }
	return 0;
}
