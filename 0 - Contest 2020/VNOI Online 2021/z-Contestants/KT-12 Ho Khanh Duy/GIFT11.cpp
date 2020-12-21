#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5+5;
const ll MOD = 998244353;

ll n;
string a[N], c[N];
ll d[N];
ll ans;

void check(){
    ll odd = 0;
    ll even = 0;
    string S;

    for (ll i=1; i<=n; i++)
        S += c[i];

    for (ll i=0; i<S.size(); i++){
        ll x = S[i] - '0';
        if ((i + 1)&1) odd += x;
        else even += x;
    }

    if ((odd - even) % 11 == 0){
        ans++;
        ans %= MOD;
    }
}

void cal(ll i){
    for (ll j=1; j<=n; j++){
        if (d[j] == 0){
            c[i] = a[j];
            if (i == n)
                check();
            else{
                d[j] = 1;
                cal(i+1);
                d[j] = 0;
            }
        }
    }
}


void solve(){
//    a.clear();

    cin >> n;
    for (ll i=1; i<=n; i++){
        cin >> a[i];
    }

    ans = 0;

    cal(1);

    cout << ans << "\n";
}

int main() {
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll T; cin >> T;
    while (T--){
        solve();
    }

    return 0;
}
