#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define tkn "gift11"
#define X first
#define Y second
#define FORU(i, a, b) for (int i = a; i <= b; i++)
#define FFOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r){
    return uniform_int_distribution<ll> (l, r) (rng);
}
const int N = 2003;
const int M = 6e6 + 3;
const int base = 1e9 + 7;
const ll mod = 998244353;
const int logmax = 25;
int n, a[N], pos[N];
bool kt[N];
ll fac[N];
ll res  = 0;
void input() {
    cin >> n;
    FORU(i, 1, n) cin >> a[i];
}
vector <int> digit;
void process(){
    int pre = 0;
    int sum1, sum2;
    sum1 = sum2 = 0;
    FORU(i, 1, n){
        digit.clear();
        int d = a[pos[i]];
        while (d > 0){
            digit.push_back(d % 10);
            d /= 10;
        }
        FORD(j, digit.size() - 1, 0){
            pre++;
            if (pre % 2) sum1 = (sum1 + digit[j]) % 11;
            else sum2 = (sum2 + digit[j]) % 11;
        }
    }
    if ((sum1 - sum2 + 11) % 11 == 0) res++;
}
void Try(int id){
    if (id == n + 1) {process(); return;}
    FORU(i, 1, n){
        if (! kt[i]){
            kt[i] = 1;
            pos[i] = id;
            Try(id + 1);
            kt[i] = 0;
        }
    }
}
void sub1(){
    FORU(i, 1, n) kt[i] = 0;
    res = 0;
    Try(1);
    cout << res << '\n';
}
void sub2(){
    res = 0;
    int sum1, sum2;
    sum1 = sum2 = 0;
    int pre;
    FORU(i, 1, n){
        int d = a[i];
        pre = -1;
        while (d ){
            pre++;
            if (pre % 2) sum1 = (sum1 + d % 10) % 11;
            else sum2 = (sum2 + d % 10) % 11;
            d /= 10;
        }
    }
    if ((sum1 - sum2 + 11) % 11) cout << 0 << '\n';
    else {
        res = 1;
        FORU(i, 1, n) res = (res * i) % mod;
        cout << res << '\n';
    }
}
int sum[2][N];
void init(){
    FORU(i, 1, n) pos[i] = (log10(a[i])) + 1;
    int pre, d;
    FORU(i, 1, n){
        pre = 0; d = a[i]; sum[0][i] = sum[1][i] = 0;
        if (pos[i] % 2) pre = 1;
        else pre = 0;
        while (d){
            sum[pre][i] = (sum[pre][i] + d % 10) % 11;
            pre = 1 - pre;
            d /= 10;
        }
    }
}
ll f[N][N][11];
void sub4(){
    init();
    FORU(i, 0, n) FORU(j, 0 ,n) FORU(k, 0, 10) f[i][j][k] = 0;
    f[0][0][0] = 1;
    int tmp1, tmp2;
    int nr;
    FORU(i, 1, n){
        FORU(j, 0, i){
            FORU(k, 0, 10){
                tmp1 = (sum[0][i] - sum[1][i] + 11) % 11;
                tmp2 = (sum[1][i] - sum[0][i] + 11) % 11;
                nr = (k - tmp1 + 11 ) % 11;
                f[i][j][k] = f[i - 1][j][nr] % mod;
                nr = (k - tmp2 + 11 ) % 11;
                if (j) f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][nr]) % mod;
            }
        }
    }
    int nn = n - (n + 1) / 2;
    res = (f[n][(n + 1) / 2][0] * (fac[nn] * fac[(n + 1) / 2]) % mod ) % mod;
    cout <<res << '\n';
}

void sol() {
    if (n <= 9) {sub1(); return;}
    bool even, odd;
    odd = even = 0;
    FORU(i, 1 , n){
        int cnt = (log10(a[i])) + 1;
        if (cnt % 2) odd = 1;
        else even = 1;
    }
    if (! odd) {sub2(); return;}
    sub4();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(tkn".inp","r", stdin);
    freopen(tkn".out", "w", stdout);
    fac[0] =1;
    FORU(i, 1, 2000) fac[i] = (fac[i - 1] * i) % mod;
    int test; cin >> test;
    while (test --){
        input();
        sol();
    }
    return 0;
}
