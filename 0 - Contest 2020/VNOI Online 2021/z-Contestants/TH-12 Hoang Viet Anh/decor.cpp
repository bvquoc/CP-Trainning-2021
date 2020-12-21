/** VanhG **/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ii pair<int, int>
#define tkn "decor"
#define X first
#define Y second
#define FORU(i, a, b) for (int i = a; i <= b; i++)
#define FFOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r){
    return uniform_int_distribution<ll> (l, r) (rng);
}
const int N = 5e5 + 7;
const ll base = 1e18;
const ll mod = 998244353;
int n, m , k;
int a[N], b[N], lab[N];
vector <int> adj[N];
void input(){
    cin >> n >> m >> k;
    char c;
    FORU(i, 1, n){
        cin >> c;
        if (c == '0') a[i] = 0;
        else a[i] = 1;
    }
    int u,v;
    FORU(i, 1, m){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
int getroot(int u){
    if (lab[u] < 0) return u;
    return lab[u] = getroot(lab[u]);
}
void join(int u, int v){
    u = getroot(u); v = getroot(v);
    if (u == v) return;
    if (lab[u] > lab[v]) swap(u,v);
    lab[u] += lab[v];
    lab[v] = u;
}
void init(){
    FORU(i, 1, n) lab[i] = -1;
    FORU(i, 1, n){
        for (int v : adj[i]) join(v, i);
    }
}
void sub1(){
    int res = 0, cnt = 0, pos = 0;
    FORU(i, 1, n){
        if (a[i] == 0) cnt = 0;
        else {
            cnt++;
            if (res < cnt) {res = cnt; pos = i;}
        }
    }
    if (pos == 0) {cout << -1; return;}
    cout << pos - res + 1 << " " << pos;
}
int sum[N];
void sub2(){
    int cnt = 0;
    FORU(i ,1, n) if (a[i] == 0) cnt++;
    if (cnt <= k) { cout << 1 << " " << n; return;}
    int res = 0; sum[0] = 0;
    FORU(i, 1, n) sum[i] = sum[i -1] + (1 - a[i]);
    int lo, hi, mid, ans, l = -1,r = -1;
    FORU(i, 1, n){
        ans =0 ;
        lo = i; hi = n;
        while (lo <= hi){
            mid = (lo + hi) >> 1;
            if (sum[mid] - sum[i - 1] <= k) {
                ans = max(ans, mid - i + 1);
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        if (res < ans){
            res = ans;
            l = i; r = i + ans - 1;
        }
    }
    if (l == -1 ) cout << -1;
    else cout << l << " " << r;
}
bool check(int l, int r){
    FORU(i, 1, n) b[i] = a[i];
    int cnt = k;
    FORU(i, l , r){
        if (b[i] != 1){
            FORU(j, 1, l - 1) {
                if (b[j] == 1 && getroot(i) == getroot(j)){
                    swap(b[i], b[j]);
                    //cout << i << " " << j << '\n';
                    break;
                }
            }
            if (b[i]) continue;
            FORU(j, r + 1, n){
                if (b[j] == 1 && getroot(i) == getroot(j)){
                    swap(b[j], b[i]);
                   // cout << i << " " << j << '\n';
                    break;
                }
            }
        }

        if (! b[i]){
            if (cnt == 0) return 0;
            cnt --; b[i] = 1;
        }
    }
    return 1;
}
void sub3(){
    init();
    int lo, hi, mid, l = -1, r = -1, res = 0, ans =0;
    FORU(i, 1, n){
        lo = i; hi = n; ans = 0;
        while (lo <= hi){
            mid = (lo + hi) >> 1;
            if (check(i, mid)){
                ans = mid - i + 1;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        if (res < ans) {
            res = ans; l = i; r = i + ans - 1;
        }
    }
    if (l == -1) cout << -1;
    else cout << l << " " << r;
}
void sub4(){
    init();
    int cnt = 0, l = -1 , r = -1, tmp = 0;;
    int res = 1, lo = -1, hi = -1;
    FORU(i, 1, n) {
        cnt += 1 - a[i];
        if (a[i] == 1) lo = hi = i;
    }
    if (cnt <= k) {cout << 1 << " " << n; return;}
    else if (cnt == n) {cout << -1; return;}
    cnt = 50000000 / (2 * n);
    FORU(i, 1, cnt){
        l = Rand(1, n - res);
        r = Rand(l + res, n);
        tmp = r - l + 1;
        if (l == r) continue;
        //cerr << l << " " << r << '\n';
        if (check(l, r)) {res = tmp; lo = l; hi = r;}
    }
    cout << lo << " " << hi;
}
void sol() {
    if (m == 0 && k == 0) {sub1(); return;}
    if (m == 0) {sub2(); return;}
    if (n <= 2000) {sub3(); return;}
    sub4();
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
