#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct apply {
    int s, d;
    ll r;
};
apply a[1000009];
int n, k, g[1000009];
ll f[1000009], ans;
bool cmp(apply x, apply y) {
    return x.d < y.d || (x.d == y.d && x.s < y.s);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++ i) {
        cin >> a[i].s >> a[i].d >> a[i].r;
        a[i].d = a[i].s + a[i].d;
    }
    sort(a + 1, a + 1 + n, cmp);
    for(int i = 1; i <= n; ++ i) g[i] = a[i].d;
    f[0] = 0;
    ans = 0ll;
    for(int i = 1; i <= n; ++ i) {
        if(a[i].s < k) f[i] = max(f[i - 1], a[i].r);
        else {
            int j = upper_bound(g + 1, g + 1 + n, a[i].s - k) - g - 1;
            f[i] = max(f[i - 1], f[j] + a[i].r);
        }
        ans = max(ans, f[i]);
        //cout << f[i] << ' ';
    }
    cout << ans;
    return 0;
}
