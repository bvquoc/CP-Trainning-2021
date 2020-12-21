#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define eb emplace_back

#define FORU(i, a, b) for(__typeof(b) i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(__typeof(a) i = (a); i >= (b); --i)

#define Fast_IO ios_base::sync_with_stdio(false); cin.tie(0);

#define PROB "GIFT11"
void Fi(){
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp", "r", stdin);
        freopen(PROB".out", "w", stdout);
    }
}

typedef pair<int, int> pii;

const int MOD = 998244353;
const int N = 2e3 + 1;

int a[N], s[N], cnt[N], n;
int gt[N];
bool vis[N];

int sum = 0, ans = 0;
void bt(int id, int t){
    if(id == n + 1){
        if(sum % 11 == 0)
            (++ans) %= MOD;
        return;
    }
    FORU(i, 1, n) if(!vis[i]){
        vis[i] = 1;
        sum += s[i] * t;
        bt(id + 1, (cnt[i] % 2 ? -t : t));
        sum -= s[i] * t;
        vis[i] = 0;
    }
}

pii cal(int x){
    int su = 0, d = 0, t = 1;
    while(x > 0){
        su += (x % 10) * t;
        ++d;
        t = -t;
        x /= 10;
    }
    return {su, d};
}

void solve(){
    cin >> n;
    FORU(i, 1, n) cin >> a[i];
    int flag2 = 1;
    FORU(i, 1, n){
        tie(s[i], cnt[i]) = cal(a[i]);
        if(cnt[i] % 2) flag2 = 0;
    }
    if(n <= 9){
        ans = sum = 0;
        memset(vis, false, sizeof(vis));
        bt(1, 1);
        cout << ans << "\n";
        return;
    }
    if(flag2){
        int su = 0;
        FORU(i, 1, n){
            su += s[i];
        }
        if(su % 11) cout << "0\n";
        else cout << gt[n] << "\n";
        return;
    }
}

int main(){
    Fast_IO;
    Fi();
    FORU(i, 1, N - 1) gt[i] = (1LL * gt[i - 1] * i) % MOD;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
