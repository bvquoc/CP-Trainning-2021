#include <bits/stdc++.h>

using namespace std;
const int oo = 1e9;

int n, m, k;
string s;
vector <int> a[500005];
int Ln[500005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    cin >> n >> m >> k;
    cin >> s;
    s = 'c' + s;
    s = s + 'c';
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int l0 = 1;
    int l = 1, r = 1, res = 0;
    if (m == 0 && k == 0) {
        for (int i = 1; i <= n + 1; i++) {
            if (s[i] == '1') Ln[i] = Ln[i - 1] + 1;
            else {
                if (Ln[i - 1] > res) {
                    res = Ln[i - 1];
                    r = i - 1;
                    l = l0;
                }
                l0 = i + 1;
                Ln[i] = 0;
            }
        }
        if (res <= 0) cout << -1;
        else cout << l << " " << r;
        return 0;
    }
    if (m == 0) {
        for (int i = 1; i <= n; i++) {
            int C = k;
            for (int j = i; j <= n + 1; j++) {
                if (C > 0 && s[j] == '0') {
                    C--;
                    continue;
                }
                if (s[j] == '1') continue;
                if (res < j - i + 1) {
                    res = j - i + 1;
                    l = i;
                    r = j - 1;
                }
                break;
            }
        }
        if (res <= 0) cout << -1;
        else cout << l << " " << r;
        return 0;
    }
    cout << 1 << " " << n;
    return 0;
}
