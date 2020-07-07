#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

const int N = 100005;
int n, a[N];
int ans = 0, cnt = 0, max_neg = LLONG_MIN;

int32_t main(void) {
    FastIO;
    freopen("SUBSET.INP","r",stdin);
    freopen("SUBSET.OUT","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i]>=0) {
            cnt++;
            ans += a[i];
        } else {
            max_neg = max(max_neg,a[i]);
        }
    }
    if (cnt == 0) {
        ans = max_neg;
        cnt = 0;
        for (int i=1; i<=n; i++) {
            if (a[i]==max_neg) {
                cnt++;
            }
        }
    }
    cout << ans << ' ' << cnt;
    return 0;
}