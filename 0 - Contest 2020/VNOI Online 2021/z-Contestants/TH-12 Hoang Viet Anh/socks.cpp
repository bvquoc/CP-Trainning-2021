#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define tkn "socks"
#define X first
#define Y second
#define FORU(i, a, b) for (int i = a; i <= b; i++)
#define FFOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r){
    return uniform_int_distribution<ll> (l, r) (rng);
}
const int N = 5e5 + 7;
const int M = 6e6 + 3;
const int base = 1e9 + 7;
const ll mod = 998244353;
const int logmax = 25;
int n, q, res;
int a[N];
vector <int> adj[N];
void input(){
    cin >> n >> q;
    FORU(i, 1, n) cin >> a[i];
    int u, v;
    FFOR(i, 1, n){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void sub1(){
    int cnt = 0;
    FORU(i, 1, n) cnt += a[i];
    if (cnt <= 1) cout << 0 << '\n';
    else cout << 1 <<'\n';
    int x;
    while (q --){
        cin >> x;
        if (a[x]) cnt--;
        else cnt++;
        a[x] = 1 - a[x];
        if (cnt <= 1)cout << 0 << '\n';
        else cout << 1 << '\n';
    }
}
int br[N], col;
void dfs2(int u, int pa){
    br[u] = col;
    for (int v : adj[u]){
        if (v == pa) continue;
        dfs2(v, u);
    }
}
void sub2(int root){
    int cnt[3];
    FORU(i, 0, 2) {
        col = i;
        cnt[i] = 0;
        dfs2(adj[root][i], root);
    }
    FORU(i, 1, n) {if (i != root) cnt[br[i]] += a[i];}
    int x;
    if (cnt[1] + cnt[2] + cnt[0] + a[root] <= 1) cout << 0 << '\n';
    else if (cnt[1] && cnt[2] && cnt[0]) cout << 2 << '\n';
    else cout << 1 << '\n';
    while (q -- ){
        cin >> x;
        if (x != root){
            if (a[x]) cnt[br[x]]--;
            else cnt[br[x]]++;
        }
        a[x] = 1 - a[x];
        if (cnt[1] + cnt[2] + cnt[0] + a[root] <= 1) cout << 0 << '\n';
        else if (cnt[1] && cnt[2] && cnt[0]) cout << 2 << '\n';
        else cout << 1 << '\n';
    }
}
int dfs(int u, int pa){
    int tmp = 0;
   // cout << u << " " << pa << " " << tmp << '\n';
    for (int v : adj[u]){
        if (v == pa) continue;
        tmp += dfs(v, u);
    }
    if (tmp == 0) tmp += a[u];
    if (tmp > 1) {
        res += (tmp + 1) / 2;
        return 1;
    }
    else return tmp;
}
void sub3(){
    int vt = 0;
    int cnt = 0;
    FORD(i, n, 1) if (a[i] == 1) {vt = i; cnt++;}
    res = 0;
    if (vt == 0 || cnt <= 1) cout << 0 << '\n';
    else {
        //root = vt;
        int d = dfs(vt, vt);
        if (d) res++;
        cout << res << '\n';\
    }
    int x;
    while (q --){
        cin >> x;
        if (a[x]) cnt--;
        else cnt++;
        a[x] = 1 - a[x];
        FORU(i, 1, n) if (a[i]) vt = i;
        if (cnt <= 1) {cout << 0 << '\n';}
        else {
            res = 0;
            vt = dfs(vt, vt);
            if (vt % 2) res++;
            cout << res << '\n';
        }
    }
}
void sol() {
    int ma = 0, cnt = 0, vt = 0;
    FORU(i, 1, n){
        ma = max(ma,(int)(adj[i].size()));
        if (adj[i].size() == 3) {cnt++; vt = i;}
    }
    if (ma == 2) {sub1(); return;}
    if (ma == 3 && cnt == 1) {sub2(vt); return;}
    if (n <= 1000 && q <= 1000) {sub3(); return;}

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(tkn".inp","r", stdin);
    freopen(tkn".out", "w", stdout);
    int test; test = 1;
    while (test --){
        input();
        sol();
    }
    return 0;
}
