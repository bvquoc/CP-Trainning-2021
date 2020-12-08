#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define Task "ODDCOIN"
//ODDCOIN

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100015;
const ll inf = 1e18;

void InOut();
#define debug(X) cout << #X << " = " << X << '\n'

ll x, t, q;
ll dp[50015];
void solve(){
    vector<ll> a;
    ll cur = 1;
    ll c = 5;
    while(c--){
        a.push_back(1 * cur);
        a.push_back(3 * cur);
        a.push_back(5 * cur);
        cur = cur * 10;
    }
    cin >> x >> t;
    a.push_back(x);
    sort(a.begin(), a.end());
    int n = sz(a);
    ll M = 50000;
    for(int i = 0; i <= M; ++i) dp[i] = inf;
    dp[0] = 0;
    for(int i = 1; i <= M; ++i){
        for(int id = 0; id < n; ++id){
            if (i >= a[id]) dp[i] = min(dp[i], dp[i-a[id]] + 1);
        }
    }
    ll ans = inf;
    for(int i = 0; i < n; ++i){
        if (a[i] > t) continue;
        ll ret = 0;
        ll T = t;
        ll ma = a[i];
        ll y;
        if (T > M){
            ll k = T - M;
            y = (k - 1) / ma + 1;
            ret = ret + y;
            T = T - y * ma;
        }
        ans = min(ans, dp[T] + ret);
    }
    cout << ans << '\n';

}
int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> q;
    while(q--) solve();
return 0;
}

void InOut(){
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
}

