#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
int n, m, ans = 0, mn;
int b[100002], st[400002];
ii a[100002];
void build(int id, int l, int r) {
    if(l > r) return;
    if(l == r) {
        st[id] = a[l].se;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}
int get_max(int id, int l, int r, int u, int v) {
    if(r < u || v < l || l > r) return -1e9;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(get_max(id * 2, l, mid, u, v),
               get_max(id * 2 + 1, mid + 1, r, u, v));
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //if(fopen("test.inp", "r"))
    //    freopen("test.inp", "r", stdin);
    //else {
        #define file "COOLMAC"
        freopen(file".INP", "r", stdin);
        freopen(file".OUT", "w", stdout);
    //}
    cin >> n;
    for(int i = 1; i <= n; ++ i) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++ i) b[i] = a[i].fi;
    cin >> m;
    mn = 1e9;
    for(int i = 1; i <= m; ++ i) {
        int x;
        cin >> x;
        mn = min(mn, x);
    }
    build(1, 1, n);
    int l = 0, r;
    while(1) {
        r = upper_bound(b + 1, b + 1 + n, mn) - b - 1;
        //cout << mn << ' ' << r << '\n';
        if(r == l) break;
        mn = get_max(1, 1, n, l + 1, r) + 1;
        ++ ans;
        l = r;
        //cout << mn << '\n';
    }
    if(mn <= 100000) cout << -1;
    else cout << ans;
    return 0;
}
