#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

const int N = 100005;
int n, a[N];
int sum_pos = 0, cnt_pos = 0, sum_neg = 0;

int32_t main(void) {
    FastIO;
    freopen("SUBSET.INP","r",stdin);
    freopen("SUBSET.OUT","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i]>=0) {
            cnt_pos++;
            sum_pos += a[i];
        } else {
            sum_neg += a[i];
        }
    }
    if (cnt_pos == 0) {
        sum_pos = sum_neg;
        cnt_pos = n;
    }
    cout << sum_pos << ' ' << cnt_pos;
    return 0;
}