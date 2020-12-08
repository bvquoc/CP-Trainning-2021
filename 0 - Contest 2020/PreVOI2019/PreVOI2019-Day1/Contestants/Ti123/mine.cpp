#include <bits/stdc++.h>
typedef int64_t ll;
const int maxn = 4010;
const ll base = 1000003;
using namespace std;

ll f[maxn][maxn];
int n, m, a[maxn];
ll Dp(int l, int r) {
    if (l >= r) {
        return f[l][r] = 0;
    }
    if (r == l + 1) {
        if (a[r] - a[l] <= m)
            return f[l][r] = 1;
        return f[l][r] = 0;
    }
    if (f[l][r] != -1)
        return f[l][r];
    ll ans = 0;
    for (int i = l + 1; i <= r - 1; i++) {
        if (a[i] - a[l] > m)
            break;
        else
            ans = (ans + (Dp(l, i) * Dp(i + 1, r) % base)) % base;
    }
    f[l][r] = ans;
    return ans;
}

ll res = 0;
int main()
{
    freopen ("mine.inp", "r", stdin);
    freopen ("mine.out", "w", stdout);
    cin >> n >> m;
    n *= 2;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(f, -1, sizeof(f));
    sort(a + 1, a + n + 1);
    cout << Dp(1, n);
}
