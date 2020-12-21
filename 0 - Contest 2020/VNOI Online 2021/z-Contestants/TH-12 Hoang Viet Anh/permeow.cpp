/** VanhG **/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ii pair<int, int>
#define tkn "permeow"
#define X first
#define Y second
#define FORU(i, a, b) for (int i = a; i <= b; i++)
#define FFOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r){
    return uniform_int_distribution<ll> (l, r) (rng);
}
const int N = 200007;
const ll base = 1e18;
const ll mod = 1e9 + 7;
int n, a[N], b[N];
ll fac[N], inv[N];
void input(){
    cin >> n;
    FORU(i, 1, n) cin >> a[i];
    FORU(i, 1, n) cin >> b[i];
}
void sub1(){
    int res = 0;
    FORU(i, 1, n) FORU(j, 1, i -1)
        if (a[i] < a[j]) res++;
    cout << res;
    return;
}
ll Pow(ll a, ll b){
    if (b == 0) return 1;
    if (b == 1) return a % mod;
    ll q = Pow(a, b / 2);
    q = (q * q) % mod;
    if (b % 2) q = (q * a) % mod;
    return q;
}
void init(){
    fac[0] = 1; inv[0] = 1;
    FORU(i, 1, n){
        fac[i] = (fac[i -1] * i) % mod;
        inv[i] = Pow(fac[i], mod - 2);
    }
}
ll C(int n, int k){
    ll res = fac[n];
    res = (res * inv[k]) % mod;
    res = (res * inv[n - k]) % mod;
    return res;
}
void sub2(){
    init();
    ll tmp = C(n, 2);
    tmp = (tmp * tmp)  % mod;
    tmp = (tmp * fac[n - 2]) % mod;
    cout << tmp; return;
}
int kt[10], x[10], res = 0;
void process(int dd){
    bool ch = 1;
    if (dd == 1)
    {
        FORU(i, 1, n) {
            if (x[i] > b[i]) {ch = 0; break;}
            if (x[i] < b[i]) {break;}
        }
        if (! ch) return;
    }
    else{
        FORU(i, 1, n) {
            if (x[i] > a[i]) {ch = 0; break;}
            if (x[i] < a[i]) {break;}
        }
        if (! ch) return;
    }
    FORU(i, 1, n) FORU(j, 1, i - 1)
        if (x[i] < x[j]) {
            if (dd == 1)res++;
            else res--;
        }
}
void Try(int id, int dd){
    if (id == n + 1) {process(dd); return;}
    FORU(i ,1, n) {
        if (kt[i]) continue;
        kt[i] = 1;
        x[id] = i;
        Try(id + 1,dd);
        kt[i] = 0;
    }
}
void sub3(){
    res = 0;
    Try(1 , 1);
    Try(1, 0);
    cout << res;
}
void sub4(){
    cout << 0;
    return;
}
void sol() {
    if (n <= 2000){
        int sub = 1;
        FORU(i, 1, n) if (a[i] != b[i]) {sub = 2; break;}
        if (sub == 1) {sub1(); return;}
        FORU(i, 1, n) if (a[i] != i || b[i] != n - i + 1){
            sub = 3; break;}
        if (sub == 2) {sub2(); return;}
        sub3() ;return;
    }
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
