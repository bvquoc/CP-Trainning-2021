#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
#define int         int64_t

using namespace std;

const int N = int(1e3) + 7;
const int mod = int(1e6) + 3;
typedef pair<int, int> pii;


int n, m, a[N], f[N][N];
int fac[int(4e6 + 2)], rev[int(4e6 + 2)];

ll Power(ll x, int y) {
    ll res = 1;
    for(; y > 0; y >>= 1, x = x * x % mod)
        if(y & 1) res = res * x % mod;
    return res;
}

int nCk(int n, int k) {return fac[n] * rev[k] % mod * rev[n - k] % mod;}

int Irene(int n, int d) {
    int res = nCk(n, (n + d) >> 1);
    if(min((n + d) / 2, n - (n + d) / 2) > min((n + d - 2) / 2, n - (n + d - 2) / 2))
        res -= nCk(n, (n + d - 2) >> 1);
    if(res < 0) res += mod;
    return res;
}

void add(int& x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    if(x < 0) x += mod;
}
int mul(int x, int y) {return x * y % mod;}

int DP(int l, int r) {
   if(f[l][r] != -1) return f[l][r];
   int&res = f[l][r];
   if(l >= r || ((r - l + 1) & 1)) return res = 0;
   if(l == r - 1) return res = (a[r] - a[l] <= m);
   if(a[r] - a[l] <= m) res = DP(l + 1, r - 1);
   else res = 0;
   if(a[l + 1] - a[l] <= m) add(res, DP(l + 2, r));
   for(int k = l + 2; k < r; ++k) {
       if(a[k] - a[l] <= m) add(res, mul(DP(l + 1, k - 1), DP(k + 1, r)));
       else break;
   }
   return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "mine"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m; n *= 2;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    if(m == 1000000) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        fac[0] = fac[1] = 1;
        for(int i = 2; i < N; ++i) fac[i] = fac[i - 1] * i % mod;
        rev[N - 1] = Power(fac[N - 1], mod - 2);
        for(int i = N - 2; i >= 0; --i) rev[i] = rev[i + 1] * (i + 1) % mod;
        cout << Irene(n, 0); return 0;
    }
    memset(&f, -1, sizeof f);
    cout << DP(1, n);
}
