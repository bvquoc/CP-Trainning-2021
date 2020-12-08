#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define Task "MINE"
//MINE

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 400015;
const int inf = 0x3f3f3f3f;
const ll mod = 1000003;

void InOut();
#define debug(X) cout << #X << " = " << X << '\n'
ll Pow(ll a, ll b){
    if (b == 0) return 1;
    ll tmp = Pow(a, b / 2);
    if (b % 2 == 0) return (tmp * tmp) % mod;
    else return  ( ( (tmp * tmp) % mod) * a) % mod;
}
ll gt[N], ngt[N];
void khoitao(ll M){
    gt[0] = 1;
    for(ll i = 1; i <= M; ++i){
        gt[i] = (gt[i-1] * i) % mod;
    }
    ngt[M] = Pow(gt[M], mod - 2);
    for(ll i = M - 1; i >= 0; --i){
        ngt[i] = ( ngt[i+1] * (i + 1) ) % mod;
    }
}
ll n, m;
ll a[N];
ll C(ll n, ll k){
    return ( ( (gt[n] * ngt[k]) % mod) * ngt[n-k]) % mod;
}
ll ctl(ll n){
    ll k = n / 2;
    return (Pow(k + 1, mod - 2) * C(2 * k, k) ) % mod;
}
ll dp[N];
void solve(){
    khoitao(4000LL);
    dp[n+1] = 1;
    for(int i = n; i >= 1; --i){
        int k = upper_bound(a + 1, a + n + 1, a[i] + m) - a;
        k --;
        if ( (k - i + 1) % 2 == 1) --k;
        if (k <= i) continue;
        dp[i] = (ctl(k - i + 1) * dp[k+1]) % mod;
    }
    cout << dp[1];
}
int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    n = n * 2;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    ll M = ll(1e6);
    if (m == M){
        khoitao(400000LL);
        cout << ctl(n) << '\n';
    } else solve();

return 0;
}

void InOut(){
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
}

