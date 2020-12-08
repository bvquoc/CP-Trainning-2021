#include<bits/stdc++.h>

#define maxn 100005

using namespace std;
typedef long long ll;

vector < int > a;
ll x, t;

ll Cost(ll k){
    ll ret = 0;
    for (int i = 0; i < a.size(); ++i){
        ret += k / a[i];
        k %= a[i];
    }
    return ret;
}

void solve(){
    cin >> x >> t;
    ll Lim = 100000;
    ll ans = t;
    for (ll i = 0; i <= Lim && x * i <= t; ++i)
        ans = min(ans, Cost(t - x * i) + i);

    ll ret = t / x;
    for (ll i = ret; i >= max(0ll, ret - Lim); --i)
        ans = min(ans, Cost(t - x * i) + i);

    cout << ans << '\n';
}

int main(){
    #define TASK "ODDCOIN"
    freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    for (int i = 1; i <= 10000; i *= 10){
        a.push_back(i);
        a.push_back(3 * i);
        a.push_back(5 * i);
    }

    reverse(a.begin(), a.end());

    int q;
    cin >> q;
    while (q--)
        solve();

    return 0;
}
