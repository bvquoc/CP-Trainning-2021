#include <bits/stdc++.h>

using namespace std;
int m, n, mi, mark[1000009], pre[1000009], ans = 0;
pair < int, int > a[1000009];
int main()
{
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].first >> a[i].second;
        mark[a[i].first]++;
        mark[a[i].second+1]--;
    }
    mi = INT_MAX;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mi = min(mi, x);
    }
    for (int i = 1; i <= 1e5; i++)
        pre[i] = pre[i-1] + mark[i];
    for (int i = mi; i <= 1e5; i++)
        if (pre[i] < 1)
        {
            cout << -1;
            return 0;
        }
    sort(a+1, a+m+1);
    for (int i = mi; i <= 1e5; i++)
        if (pre[i] == 1 && pre[i] != pre[i+1])
            ans++;
    cout << ans;
    return 0;
}
