#include <bits/stdc++.h>
#define maxn 500005
#define MOD 1000000007
#define task "DECOR"
#define pii pair<int, int>
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
const ll MM = 1ll * MOD * MOD;
int n, m, k, c[maxn];
void Input(){
    string s;
    cin >> n >> m >> k >> s;
    for (int i=1; i<=n; ++i) c[i] = (s[i-1] == '1');
}
void Sub12(){
    int run = 0, cnt = 0, ans = 0;
    pii res = {0, 0};
    for (int i=1; i<=n; ++i){
        while (cnt <= k && run < n) cnt += (c[++run] == 0);
        while (cnt > k) cnt -= (c[run--] == 0);
        if (run-i+1 > ans){
            ans = run-i+1; res = {i, run};
        }
        cnt -= (c[i] == 0);
    }
    if (ans == 0) cout << -1;
    else cout << res.F << " " << res.S;
    exit(0);
}
int root[maxn], dd[maxn];
int get_root(int u){
    return root[u] > 0 ? root[u] = get_root(root[u]) : u;
}
void Add(int u, int v){
    u = get_root(u); v = get_root(v);
    if (u == v) return;
    root[u] += root[v];
    root[v] = u;
}
void Solve(){
    for (int i=1; i<=n; ++i) root[i] = -c[i];
    for (int u, v, i=1; i<=m; ++i){
        cin >> u >> v; Add(u, v);
    }

    int run = 0, cnt = 0, ans = 0, p = 0;
    pii res = {0, 0};
    for (int i=1; i<=n; ++i){
        while (cnt <= k && run < n) {
            p = get_root(++run);
            if (root[p] < 0) root[p]++, dd[run] = 0;
            else cnt++, dd[run] = 1;
        }
        while (cnt > k) --cnt, dd[run--] = 0;
        if (run-i+1 > ans){
            ans = run-i+1; res = {i, run};
        }
        p = get_root(i);
        if (dd[i]) cnt--;
        else root[p]--;
    }
    if (ans == 0) cout << -1;
    else cout << res.F << " " << res.S;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    Input();
    if (m == 0) Sub12();
    Solve();
    return 0;
}
