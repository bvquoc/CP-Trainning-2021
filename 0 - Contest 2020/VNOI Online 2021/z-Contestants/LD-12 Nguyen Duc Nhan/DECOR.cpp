#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxN = 5e5;
int n, m, k;
int a[maxN + 5];
int b[maxN + 5];
void sub12()
{
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == 0)
            b[++cnt] = i;
    b[0] = 0;
    b[++cnt] = n + 1;
    if (cnt - 1 <= k) cout << 1 << " " << n;
    else
    {
        int l, r;
        l = r = 0;
        for (int i = k ;i < cnt; i++)
        {
            int curl, curr;
            if (b[i - k] + 1 != b[i - k + 1]) curl = b[i - k] + 1;
            else curl = b[i - k + 1];
            if (b[i + 1] - 1 != b[i]) curr = b[i + 1] - 1;
            else curr = b[i];
            if (r - l < curr - curl) r = curr, l = curl;
        }
        if (l != 0 ) cout << l << " " << r;
        else cout << -1;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DECOR.INP", "r", stdin);
    freopen("DECOR.OUT", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        a[i] = x - '0';
    }
    if (m == 0)
    {
        sub12();
    }
    cout << -1;
    return 0;
}
