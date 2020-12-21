#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    freopen("DECOR.INP", "r", stdin);
    freopen("DECOR.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        a[i] = c - 48;
    }
    vector<int> s(n + 1);
    s[0] = 0;
    int ans = -1, x, y;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for (int i = 1; i < n; i++) {
        int l = i + 1;
        int r = n;
        while (l < r) {
            int mid = ceil((double) (l + r) / 2);
            if (mid - i + 1 - s[mid] + s[i - 1] <= k) {
                l = mid;
            } else r = mid - 1;
        }
        if (r - i + 1 > ans) {
            ans = r - i + 1;
            x = i;
            y = r;        }
    }
    cout << x << ' ' << y << endl;
    return 0;
}
