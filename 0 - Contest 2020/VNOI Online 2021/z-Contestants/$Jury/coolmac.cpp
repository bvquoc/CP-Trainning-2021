#include <bits/stdc++.h>

using namespace std;
const int maxT = 100000;
int main() {
#define TASK "COOLMAC"
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;
    vector<int> far(maxT + 5);
    for (int i = 1; i <= m; ++i) {
        int l, r;
        cin >> l >> r;
        far[l] = max(far[l], r);
    }
    for (int i = 1; i <= maxT; ++i)
        far[i] = max(far[i], far[i - 1]);
    int n;
    cin >> n;
    int t_min = maxT;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        t_min = min(t_min, x);
    }
    int res = 0;
    while (t_min <= maxT) {
        if (far[t_min] <= t_min) return !(cout << -1);
        t_min = far[t_min];
        ++res;
        if (t_min == maxT) break;
    }
    cout << res;
    return 0;
}