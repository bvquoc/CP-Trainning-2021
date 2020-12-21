#include <bits/stdc++.h>
#define fore(it,a)       for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define forr(i, a, b)    for(int i = (a); i <= (b); ++i)
#define ford(i, a, b)    for(int i = (a); i >= (b); --i)
#define repp(i, a, b)    for(int i = (a); i < (b); ++i)
#define repd(i, a, b)    for(int i = (a); i > (b); --i)
#define mem(a, x)        memset(x, (a), sizeof(x))
#define bitcount(x)      __builtin_popcountll((x))
#define OFFBIT(mask, i)  ((mask) &~ (1ll << (i)))
#define ONBIT(mask, i)   ((mask) | (1ll << (i)))
#define reset(x)         memset(x, 0, sizeof(x))
#define all(a)           (a).begin(), (a).end()
#define BIT(x, i)        (((x) >> (i)) & 1)
#define ii               pair<int, int>
#define MASK(i)          (1LL << (i))
#define mp               make_pair
#define se               second
#define fi               first

using namespace std;

mt19937_64 random_num(chrono::high_resolution_clock::now().time_since_epoch().count());
const int MOD  = 1000000007;
const int inf  = 2000000000;
const int mod  = 1007050321;
const double e = 0.000001;
const int N    = 200005;
const bool aut = 788480;
const int base = 521;

int n, a[N], b[N], bit[N], gt[N], gtd[N];

void update(int pos) {
    for(; pos <= n; pos += pos&-pos)
        bit[pos]++;
}

int get(int pos) {
    int res = 0;
    for(; pos > 0; pos -= pos&-pos)
        res += bit[pos];
    return res;
}

int sub1() {
    forr(i, 1, n) bit[i] = 0;
    int res = 0;
    forr(i, 1, n) {
        res = (res + get(n) - get(a[i])) % MOD;
        update(a[i]);
    }
    return res;
}

int poww(int n, int a) {
    if(n == 1)
        return a;
    if(n == 0)
        return 1;
    int t = poww(n/2, a);
    t = 1LL * t * t % MOD;
    if(n % 2)
        t = 1LL * a * t % MOD;
    return t;
}

int kCn(int k, int n) {
    if(n < k)
        return 0;
    return 1LL * gt[n] * gtd[n-k] % MOD * gtd[k] % MOD;
}

void solve(vector<int> a) {
    repp(i, 0, a.size()) {

    }
}

int main() {
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define     task "permeow"
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);

    cin >> n;
    int cnt = 0;
    forr(i, 1, n) cin >> a[i];
    forr(i, 1, n) cin >> b[i], cnt += b[i] != a[i];
    if(!cnt)
        cout << sub1();
    else {
        gt[0] = 1;
        forr(i, 1, n)
        gt[i] = 1LL * gt[i-1] * i % MOD;
        gtd[n] = poww(MOD-2, gt[n]);
        ford(i, n-1, 0)
        gtd[i] = 1LL * gtd[i+1] * (i+1) % MOD;
        int substract = sub1();
        int ans = 0;
        forr(i, 1, n) {
            int bigger = n-i;
            forr(j, 1, bigger) {
                forr(k, j+1, n)
                ans = (ans + 1LL * kCn(j, bigger) * kCn(k-1-j, i-1) % MOD * gt[n-k] % MOD * gt[k-1] % MOD * j % MOD) % MOD;
            }
        }
        cout << ans;
    }

    return 0;
}
