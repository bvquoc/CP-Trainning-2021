#include <bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back

using namespace std;

const int N = 5e5 + 5;

int n, m, k, s[N], visited[N], d[N], d0[N], root[N];
string S;
vector <int> ke[2005];

int bs(int u)
{
    int l = 0, r = u - 1, res = 0;

    while (l <= r){
        int m = (l + r) / 2;

        if (s[u] - s[m] + k >= u - m){
            res = u - m;
            r = m - 1;
        }
        else l = m + 1;
    }

    return res;
}

void dfs(int u, int p)
{
    if (S[u - 1] - '0' == 1) d0[p]++;

    visited[u] = 1;
    root[u] = p;

    for (int v : ke[u]){
        if (visited[v] == 1) continue;

        dfs(v, p);
    }
}

int main()
{
    IOS;
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);

    cin >> n >> m >> k;
    cin >> S;

    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;

        ke[u].pb(v);
        ke[v].pb(u);
    }

    int ans = 0, ans0;
    if (m == 0){
        for (int i = 1; i <= n; i++){
            s[i] = s[i - 1] + S[i - 1] - '0';

            int res = bs(i);
            if (ans < res){
                ans = res;
                ans0 = i;
            }
        }
    }
    else{
        for (int i = 1; i <= n; i++){
            if (visited[i] == 0) dfs(i, i);
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++) d[j] = d0[j];

            int x = i - 1, k0 = k;
            while (x <= n){
                if (d[root[x + 1]] == 0){
                    if (k0 == 0) break;

                    k0--;
                }
                d[root[x + 1]]--;
                x++;
            }

            x = min(x + k0, n);

            if (ans < x - i + 1){
                ans = x - i + 1;
                ans0 = x;
            }
        }
    }

    if (ans == 0) cout << -1;
    else cout << ans0 - ans + 1 << " " << ans0;
}
