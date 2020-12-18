#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a[N], b[N], c[N];

void solve() {
    int n; cin >> n;
    long long tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; tot += a[i];
    }
    if (tot & 1) {
        cout << "NO\n"; return;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] >= n) {
            cout << "NO\n"; return;
        }
    fill(c, c + n, 0);
    for (int i = 1; i <= n; i++)
        c[a[i]]++;
    for (int i = 1; i < n; i++)
        c[i] += c[i - 1];
    for (int i = n; i > 0; i--)
        b[c[a[i]]--] = a[i];
    reverse(b + 1, b + n + 1);
    int j = n + 1; tot = 0;
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
        long long tmp = 1ll * i * (i - 1);
        while (j - 1 > i && b[j - 1] < i) {
            j--; cur += b[j];
        }
        tmp += cur + 1ll * (j - i - 1) * i;
        if ((tot += b[i]) > tmp) {
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";
}

int main() {
    freopen("graph.inp", "r", stdin);
    freopen("graph.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}