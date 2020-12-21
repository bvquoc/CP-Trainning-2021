#include <bits/stdc++.h>
using namespace std;
struct Suit {
    int l, r;
} suit[100010];
int n, m, t, ans = 0;

int main () {
    freopen("COOLMAC.INP", "r", stdin);
    freopen("COOLMAC.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> suit[i].l >> suit[i].r;
    }
    cin >> m;
    t = 100000;
    for (int i = 1; i <= m; ++ i) {
        int _t; cin >> _t; t = min(t, _t);
    }

    sort(suit + 1, suit + 1 + n, [] (Suit a, Suit b) {
        return a.l == b.l ? a.r > b.r : a.l < b.l;
    });
    int i = 1;
    while (true) {
        int maxR = -1;
        while (suit[i].l <= t && i <= n) {
            maxR = max(maxR, suit[i].r);
            ++ i;
        }
        if (maxR == -1) {
            cout << -1;
            return 0;
        }
        t = max(t, maxR);
        ++ ans;
        if (t >= 100000) break;
    }
    cout << ans;
    return 0;
}
