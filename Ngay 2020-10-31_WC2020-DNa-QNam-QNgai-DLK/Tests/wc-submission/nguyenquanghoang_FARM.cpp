#include<bits/stdc++.h>
using namespace std;
int n, k, q, p, a[10009], f[10005][10005];
int dp(int u, int v) {
    if(v <= 0 || u > n) return 0;
    int &res = f[u][v];
    if(res + 1) return res;
    res = dp(u + 1, v);
    int i = min(p, v);
    res = max(res, dp(u + k, v - i) + i * a[u]);
    i = v % p;
    res = max(res, dp(u + k, v - i) + i * a[u]);
    return res;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k >> q >> p;
    for(int i = 1; i <= n; ++ i) cin >> a[i];
    memset(f, -1, sizeof f);
    cout << dp(1, q);
    return 0;
}
