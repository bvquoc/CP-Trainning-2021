#include<bits/stdc++.h>
using namespace std;
int n, q, cnt1, root;
int msk[500002], bac[500002], cnt[10];
vector<int> a[500002];
void sub1() {
    if(cnt1 > 1) cout << 1 << '\n';
    else cout << 0 << '\n';
    for(int i = 1; i <= q; ++ i) {
        int x;
        cin >> x;
        msk[x] = 1 - msk[x];
        if(msk[x]) ++ cnt1;
        else -- cnt1;
        if(cnt1 > 1) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
void dfs(int u, int par, int k) {
    //cout << u << ' ' << par << '\n';
    if(u != root) {
        if(msk[u] == 1) ++ cnt[k];
        bac[u] = k;
    }
    for(int i = 0; i < a[u].size(); ++ i) {
        int v = a[u][i];
        if(v == par) continue;
        if(u == root) dfs(v, u, i + 1);
        else dfs(v, u, k);
    }
}
void sub2() {
    int res = 0;
    dfs(root, root, 0);
    if(cnt[1]) ++ res;
    if(cnt[2]) ++ res;
    if(cnt[3]) ++ res;
    if(res <= 1) {
        if(cnt1 < 2) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
    else cout << res - 1 << '\n';
    for(int i = 1; i <= q; ++ i) {
        res = 0;
        int x;
        cin >> x;
        msk[x] = 1 - msk[x];
        if(msk[x]) {
            ++ cnt[bac[x]];
            ++ cnt1;
        }
        else {
            -- cnt[bac[x]];
            -- cnt1;
        }
        if(cnt[1]) ++ res;
        if(cnt[2]) ++ res;
        if(cnt[3]) ++ res;
        if(res <= 1) {
            if(cnt1 < 2) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else cout << res - 1 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //if(fopen("test.inp", "r"))
    //    freopen("test.inp", "r", stdin);
    //else {
        #define file "SOCKS"
        freopen(file".INP", "r", stdin);
        freopen(file".OUT", "w", stdout);
    //}
    cin >> n >> q;
    cnt1 = 0;
    int mx = 0;
    for(int i = 1; i <= n; ++ i) {
        cin >> msk[i];
        cnt1 += msk[i];
        bac[i] = 0;
    }
    for(int j = 1; j < n; ++ j) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        ++ bac[u];
        ++ bac[v];
        mx = max(mx, bac[u]);
        mx = max(mx, bac[v]);
        if(bac[u] == 3) root = u;
        if(bac[v] == 3) root = v;
    }
    //cout << 1 << '\n';
    if(mx == 2) sub1();
    else sub2();
    return 0;
}
