#include <bits/stdc++.h>
using namespace std;

int n, a[100005], b[100005];

int main() {
    freopen("iq.inp", "r", stdin);
    freopen("iq.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a+n);
    sort(b, b+n);

    int id = 0, ans = 0;
    for (int i = 0; max(i, id) < n; i++) {
        while (id < n && a[i] >= b[id])
            id++;
        ans++;
        id++;
    }
    cout << ans;

    return 0;
}
