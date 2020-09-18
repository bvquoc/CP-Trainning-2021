#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 10004;
int n, k, a[N];
bool isPlus[N], ok = false;
string ans;

void checkArr() {
    int cur_sum = a[1];
    for (int i=2; i<=n; i++) {
        if (isPlus[i]) cur_sum += a[i];
        else cur_sum -= a[i];
    }
    if (cur_sum % k == 0) {
        ok = true;
        for (int i=2; i<=n; i++) {
            ans += (isPlus[i]?'+':'-');
        }
    }
}
void Try(int i) {
    if (ok) return;
    for (int j=0; j<=1; j++) {
        isPlus[i] = j;
        if (i<n) Try(i+1);
        else checkArr();
    }
}

signed main(void) {
    FastIO;
    freopen("KMULT.INP","r",stdin);
    freopen("KMULT.OUT","w",stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    Try(2);
    cout << ok << '\n' << ans;
    return 0;
}