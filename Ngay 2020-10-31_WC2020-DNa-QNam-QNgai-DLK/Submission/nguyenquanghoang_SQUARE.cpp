#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, a, b, ans = 1e18, k2;
void xet(ll b) {
    a = k / b - b;
    if(abs(a) & 1ll) return;
    a /= 2;
    if(a + b >= 0) ans = min(ans, a + b);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> k;
    if(k == 0) {
        cout << 0;
        return 0;
    }
    for(b = 1; b * b <= abs(k); ++ b) {
        if(abs(k) % b == 0) {
            xet(b);
            xet(k / b);
            xet(-b);
            xet(-k / b);
        }

    }
    if(ans == 1e18) cout << "none";
    else cout << ans;
}
