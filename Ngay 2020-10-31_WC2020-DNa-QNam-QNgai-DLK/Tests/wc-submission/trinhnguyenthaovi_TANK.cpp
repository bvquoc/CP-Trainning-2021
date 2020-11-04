#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <int, int>
#define NAME "TEST"

using namespace std;

const int N = 1e5 + 5, oo = 1e9, mod = 1e9 + 7;

int n, m, a[N], sum[N], res;
bool ok;

int main()
{
//    freopen (NAME".INP", "r", stdin);
//    freopen (NAME".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; ++i)
    {
        ok = 1;
        for (int j = 1; j <= n - i + 1; ++j)
        {
            if (sum[j + i - 1] - sum[j - 1] < m)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            res = i;
            break;
        }
    }
    cout << res;

    return 0;
}
