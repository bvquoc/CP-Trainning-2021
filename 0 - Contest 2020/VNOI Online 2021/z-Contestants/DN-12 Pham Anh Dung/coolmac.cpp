#include <bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int N = 1e5 + 5;

int Fe[N];

void upd(int u, int w)
{
    while (u <= (int)1e5 + 1){
        Fe[u] = max(Fe[u], w);
        u += u & -u;
    }
}

int get(int u)
{
    int res = 0;
    while (u >= 1){
        res = max(res, Fe[u]);
        u -= u & -u;
    }
    return res;
}

int main()
{
    IOS;
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;

        u++;v++;
        upd(u, v);
    }

    int res = 1e9, m;
    cin >> m;
    for (int i = 1; i <= m; i++){
        int u;
        cin >> u;

        u++;
        res = min(res, u);
    }
    res--;

    int ans = 0;
    while (1){
        int res0 = get(res + 1);

        if (res0 == (int)1e5 + 1){
            cout << ans + 1;
            return 0;
        }

        if (res0 <= res){
            cout << -1;
            return 0;
        }

        res = res0;
        ans++;
    }
}
