#include <bits/stdc++.h>

using namespace std;

int n, q;
int a[500005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SOCKS.INP","r",stdin);
    freopen("SOCKS.OUT","w",stdout);
    cin >> n >> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt += a[i];
    }
    if (cnt > 1) cout << 1 << endl;
    for (int i = 1, x, y; i < n; i++) cin >> x >> y;
    int x;
    while (q--) {
        cin >> x;
        if (a[x] == 0) {
            a[x] = 1;
            cnt++;
        } else {
            a[x] = 0;
            cnt--;
        }
        if (cnt > 1) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
