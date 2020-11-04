//Dai Ca Di Hoc
#include <bits/stdc++.h>

#define INF INT_MAX
#define pb push_back
#define maxn 100005

using namespace std;

int n, m, res = 0, current = 0, maxN = -INF;
vector <int> a[maxn * 3];
int mx[maxn * 3], Used[maxn * 3], b[3001][3001];
vector<int> arr;

bool dfs(int u){
    if (Used[u] == current)
        return 0;
    Used[u] = current;
    for (int v : a[u])
    {
        if(b[u][v] < m) continue;
        if (mx[v] == 0){
            mx[v] = u;
            return 1;
        }

        if(dfs(mx[v]))
        {
            mx[v] = u;
            return 1;
        }
    }

    return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifdef hello
	freopen("debug.inp", "r", stdin);
	freopen("debug.out", "w", stdout);
	#endif // hello

    cin >> n;

    int l = INF, r = -INF;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> b[i][j + n];

            b[j + n][i] = b[i][j + n];

            a[i].pb(j + n);
            a[j + n].pb(i);

            l = min(l, b[i][j + n]);
            r = max(r, b[i][j + n]);
        }
    }

    while(l <= r)
    {
        memset(mx, 0, sizeof(mx));
        memset(Used, 0, sizeof(Used));

        int mid = (l + r) / 2;
        m = mid;

        res = 0;

        for (current = n; current >= 1; current--)
            res += dfs(current);

        if(res == n)
        {
            maxN = max(maxN, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << maxN;

    return 0;
}
