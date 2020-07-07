#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

int n, a, b;
int X, Y, ans;

int32_t main(void) {
    FastIO;
    freopen("SHOP.INP","r",stdin);
    freopen("SHOP.OUT","w",stdout);
    int T; cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        X = trunc(b*n/(a+b));
        Y = n-X;
        ans = a*X*X + b*Y*Y;
        X = trunc(b*n/(a+b))+1;
        Y = n-X;
        ans = min(ans,a*X*X + b*Y*Y);
        cout << ans << endl;
    }
    return 0;
}