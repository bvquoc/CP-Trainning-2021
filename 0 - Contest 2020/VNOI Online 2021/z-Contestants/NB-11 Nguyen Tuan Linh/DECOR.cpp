#include <bits/stdc++.h>
#define TASK "DECOR"
#define fast ios::sync_with_stdio(0)
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const ll MOD = 1e9 + 7;
const int maxn = 5e5;

int n, m, k, f[maxn + 5], t[maxn + 5], h[maxn + 5];
string s;
vector <int> a[maxn + 5];
pii res;

pii MAX(pii a, pii b)
{
    if (a.F > b.F) return a;
    if (a.F == b.F && a.S < b.S) return a;
    return b;
}

void subtask1()
{
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            pos = i;
            continue;
        }
        res = MAX(res, {i - pos, pos + 1});
    }
    if (res.F == 0) cout << -1;
    else cout << res.S << ' ' << res.S + res.F - 1;
}

bool check(int x)
{
    for (int i = 1; i <= n - x + 1; i++) {
        if (t[i + x - 1] - t[i - 1] + k >= x) {
            res = MAX(res, {x, i});
            return 1;
        }
    }
    return 0;
}

void subtask2()
{
    for (int i = 1; i <= n; i++) {
        t[i] = t[i - 1] + s[i] - '0';
    }
    int l = 1, r = n, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    if (res.F == 0) cout << -1;
    else cout << res.S << ' ' << res.S + res.F - 1;
}

bool dd[maxn + 5];
int cnt;

void dfs(int u, int type)
{
    dd[u] = 1; h[u] = type;
    f[type] += (s[u] - '0');
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (dd[v]) continue;
        dfs(v, type);
    }
}

int d[maxn + 5];

bool Check(int x)
{
    int u = 0;
    for (int i = 1; i <= x; i++) {
        d[h[i]]++;
        if (d[h[i]] == 1) u += f[h[i]];
    }
    if (u + k >= x) {
        res = MAX(res, {x, 1});
        return 1;
    }
    for (int i = x + 1; i <= n; i++) {
        d[h[i]]++;
        if (d[h[i]] == 1) u += f[h[i]];
        d[h[i - x]]--;
        if (d[h[i - x]] == 0) u = f[h[i - x]];
        if (u + k >= x) {
            res = MAX(res, {x, 1});
            return 1;
        }
    }
    return 0;
}

void subtask3()
{
    for (int i = 1; i <= n; i++) {
        if (!dd[i]) {
            cnt++;
            dfs(i, cnt);
        }
    }
    int l = 1, r = n, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (Check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    if (res.F == 0) cout << -1;
    else cout << res.S << ' ' << res.S + res.F - 1;
}

int main()
{
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);

    fast;

    cin >> n >> m >> k >> s; s = ' ' + s;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }

    if (m == 0 && k == 0) subtask1();
    else if (m == 0) subtask2();
    else subtask3();

    return 0;
}
