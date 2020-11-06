#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <int, int>
#define NAME "TEST"

using namespace std;

const int N = 5e3 + 5, oo = 1e9, mod = 1e9 + 7;

int n, res, start, match[N], save[N], s[N][N], tmp, mi, ma;
int l, r, mid;
vector <int> a[N];

bool dfs(int u)
{
    if (save[u] == start) return 0;
    save[u] = start;
    for (int i = 0; i < a[u].size(); ++i)
    {
        int v = a[u][i];
        if (s[u][v] >= tmp &&  (match[v] == 0 || dfs (match[v]))) /// Y chưa có ny || ny của Y đi yêu được người khác =)))
        {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

bool oke (int m)
{
    res = 0;
    memset (match, 0, sizeof(match));
    memset (save, 0, sizeof(save));
    tmp = m;
    for (start = 1; start <= n; ++start)
        res += dfs(start);
    return (res == n);
}

int main()
{
//    freopen (NAME".INP", "r", stdin);
//    freopen (NAME".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    mi = oo;
    ma = -oo;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> s[i][j + n];
            s[j + n][i] = s[i][j + n];
            a[i].push_back (j + n);
            a[j + n].push_back (i);
            mi = min (s[i][j + n], mi);
            ma = max (s[i][j + n], ma);
        }
    }
    l = mi, r = ma, mid = (l + r) / 2;
    while(l <= r)
    {
        if (oke (mid)) l = mid + 1;
        else r = mid - 1;
        mid = (l + r) / 2;
    }
    cout << mid;
//    for (int i = ma; i >= mi; --i)
//    {
//        if (oke (i))
//        {
//            cout << i;
//            return 0;
//        }
//    }
    return 0;
}

