#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

const int N = 100005, INF=9000000000000000000;
int n, a[N];
int sum = 0, Min = INF, Max = -INF;

int32_t main(void) {
    FastIO;
    freopen("MAXMIN.INP","r",stdin);
    freopen("MAXMIN.OUT","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
        Min = min(Min, a[i]);
        Max = max(Max, a[i]);
    }
    cout << sum-Max << ' ' << sum-Min;
    return 0;
}