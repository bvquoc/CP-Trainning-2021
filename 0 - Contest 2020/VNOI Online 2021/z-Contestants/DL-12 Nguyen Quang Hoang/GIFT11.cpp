#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int t, n, dd[20], b[2002];
string a[2002];
ll ans;
void sub1(int x, int val, int msk) {
    if(x > n) {
        if(abs(val) % 11 == 0) ans = (ans + 1ll) % mod;
        return;
    }
    for(int i = 1; i <= n; ++ i) {
        if(!dd[i]) {
            int res = 0, mask = msk;
            for(int j = 0; j < a[i].size(); ++ j) {
                mask = (mask + 1) % 2;
                if(mask) res += a[i][j] - 48;
                else res -= a[i][j] - 48;
            }
            dd[i] = 1;
            sub1(x + 1, val + res, mask);
            dd[i] = 0;
        }
    }
}
void sub2() {
    int res = 0;
    ans = 1ll;
    for(int i = 1; i <= n; ++ i) {
        res += b[i];
        ans = (1ll * i * ans) % mod;
    }
    if(abs(res) % 11 != 0) ans = 0ll;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //if(fopen("test.inp", "r"))
    //    freopen("test.inp", "r", stdin);
    //else {
        #define file "GIFT11"
        freopen(file".INP", "r", stdin);
        freopen(file".OUT", "w", stdout);
    //}
    cin >> t;
    while(t --) {
        ans = 0ll;
        cin >> n;
        for(int i = 1; i <= n; ++ i) {
            cin >> a[i];
            int k = a[i].size();
            for(int j = 0; j < k; ++ j) {
                if(((j + 1) & 1)) b[i] += a[i][j] - 48;
                else b[i] -= a[i][j] - 48;
            }
        }
        if(n <= 10) sub1(1, 0, 0);
        else sub2();
        cout << ans << '\n';
    }
    return 0;
}
