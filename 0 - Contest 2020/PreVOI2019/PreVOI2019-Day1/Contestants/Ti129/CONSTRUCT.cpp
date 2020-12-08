#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define Task "CONSTRUCT"
//CONSTRUCT

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ll N = 100015;
const ll inf = 0x3f3f3f3f;

void InOut();
#define debug(X) cout << #X << " = " << X << '\n'
ll t;
ll n, m;
ll a[N], x[N];
ll Get(ll l, ll r){
    if (l > r) return 0;
    if (l == r) return a[l];
    ll mi = inf;
    ll ret = 0;
    for(ll i = l; i <= r; ++i){
        mi = min(mi, a[i]);
    }

    for(ll i = l; i <= r; ++i){
        a[i] -= mi;
    }
    ret += mi;
    vector<ll> pos;
    pos.push_back(l - 1);
    for(ll i = l; i <= r; ++i){
        if (a[i] == 0) pos.push_back(i);
    }
    pos.push_back(r + 1);
    for(ll i = 0; i < sz(pos) - 1; ++i){
        ll L = pos[i] + 1, R = pos[i+1] - 1;
        ret += Get(L, R);
    }
    return ret;
}
void solve(){
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    while(m--){
        ll type, L, R, d;
        cin >> type >> L >> R;
        if (type == 1){
            cin >> d;
            for(ll i = L; i <= R; ++i) a[i] += d;
        } else {
            for(ll i = L; i <= R; ++i) x[i] = a[i];
            cout << Get(L, R) << '\n';
            for(ll i = L; i <= R; ++i) a[i] = x[i];
        }
    }
}
int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--) solve();
return 0;
}

void InOut(){
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
}

