#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
using namespace std;

using ii = pair <int,int>;
using ll = long long;
using ld = long double;

const int N = 504;
int n, r, k, a[N][N];
ll res = 0;
int b[N][N];
set <ii> q;

signed main() {
    FastIO;
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    cin >> n >> r >> k; r--;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }

    while (k--) {
        int x, y;
        cin >> x >> y;
        q.insert(ii(x,y));
    }
    for (ii t: q) {
        int x = t.first, y = t.second;
        for (int i=x; i<=x+r; i++) {
            b[i][y]++; b[i][y+r+1]--;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            b[i][j] += b[i][j-1];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (b[i][j]) res += a[i][j];
        }
    }
    cout << res;
    return 0;
}
