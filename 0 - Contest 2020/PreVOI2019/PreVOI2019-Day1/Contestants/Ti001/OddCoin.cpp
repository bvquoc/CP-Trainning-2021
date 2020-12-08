#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 2e9 + 11,
          N = 1e5 + 11;
int coin[20], f[N], tr[N];
int Cost(ll x) {
    int ans = 0;
    for (int i = 15; i > 0; i--)
        if (x >= coin[i]) {
            ans += x / coin[i];
            x %= coin[i];
        }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("OddCoin.inp", "r", stdin);
    freopen("OddCoin.out", "w", stdout);
    coin[1] = 1;
    coin[2] = 3;
    coin[3] = 5;
    int ntest;
    cin >> ntest;
    for (int i = 4; i <= 15; i++)
        coin[i] = coin[i - 3] * 10;
    while (ntest--) {
        ll x, t;
        cin >> x >> t;
        int l = 1,
            r =  50000,
            lim = 0;
        if (r > t / x)
            r = t / x;
        while (l <= r) {
            int mid = l + r >> 1;
            ll temp = x * mid;
            if (mid < Cost(temp)) {
                l = mid + 1;
                lim = mid;
            }
            else
                r = mid - 1;
        }
        int res = inf;
        for (int i = 0; i <= lim; i++)
            res = min(res, i + Cost(t - x * i));
        cout << res << '\n';
    }
}
