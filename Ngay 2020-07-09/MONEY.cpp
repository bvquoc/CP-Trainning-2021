#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

const int N = 100005;
int n, g, s, k;
int g_sum = 0, s_sum = 0, k_sum = 0, sum;
struct data {
    int g, s, k;
} a[N];
data res;

int32_t main(void) {
    FastIO;
    freopen("MONEY.INP","r",stdin);
    freopen("MONEY.OUT","w",stdout);
    cin >> g >> s >> k;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i].g >> a[i].s >> a[i].k;
        g_sum += a[i].g;
        s_sum += a[i].s;
        k_sum += a[i].k;
    }
    int cur = g*17*29 + s*29 + k;
    sum = g_sum*17*29 + s_sum*29 + k_sum;
    if (cur < sum) {
        cout << '-' << '1';
    } else {
        cur -= sum;
        res.k = cur%29;
        cur -= res.k;
        res.s = (cur/29)%17;
        cur -= res.s*29;
        res.g = cur/(29*17);
        cout << res.g << ' ' << res.s << ' ' << res.k;
    }
    return 0;
}