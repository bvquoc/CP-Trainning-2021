#include <bits/stdc++.h>

using namespace std;
pair<int, int> a[100005], b[100005];
int n, m, res = 1e9, minr = 1e9;
void sub_1() {
    for (int i = 0; i < (1 << m); ++ i) {
            int k = 0, check = 1;
            for (int j = 1; j <= m; ++ j)
                if ((i >> (j - 1)) & 1) b[++ k].first = a[j].first, b[k].second = a[j].second;
            sort(b + 1, b + k + 1);
            if (b[1].first > minr) continue;
            for (int j = 2; j <= k; ++ j) {
                if (b[j - 1].second < minr) {
                    if (b[j].first > minr) {check = 0; break;}
                }
                else if (b[j - 1].second >= minr) {
                        if (b[j].first > b[j - 1].second) {check = 0; break;}
                    }
            }
            if (b[k].second < 100000) check = 0;
            if (check) res = min(res, k);
        }
    if (res == 1e9) cout << -1; else cout << res;
}
void sub_2() {
    sort(a + 1, a + m + 1);
    pair<int, int> cmp = {minr, 1e9};
    int vt = upper_bound(a + 1, a + m + 1, cmp) - a - 1;
    if (vt == 0) {cout << -1; return;}
    for (int j = vt + 1; j <= m; ++ j) {
        if (a[j - 1].second < minr) {
                    if (a[j].first > minr) continue;
                }
        else if (a[j - 1].second >= minr) {
                    if (a[j].first > a[j - 1].second) continue;
            }
        if (a[j].second < 100000) continue;
        res = min(res, j - vt + 1);
    }
    if (a[vt].second >= 100000) res = 1;
    if (res == 1e9) cout << -1; else cout << res;
}
int main()
{
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m;
    for (int i = 1; i <= m; ++ i) cin >> a[i].first >> a[i].second;
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        int x;
        cin >> x;
        minr = min(minr, x);
    }
    if (n <= 10 && m <= 16) { sub_1(); return 0;}
    sub_2();
    return 0;
}
