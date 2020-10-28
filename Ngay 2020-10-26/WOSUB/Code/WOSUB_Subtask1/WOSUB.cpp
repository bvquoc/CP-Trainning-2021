#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
using namespace std;

const int N = 100005;
int n, S, a[N];
int res = -1;

signed main(void) {
    FastIO;
    freopen("WOSUB.INP","r",stdin);
    freopen("WOSUB.OUT","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    cin >> S;
    
    for (int l=1; l<=n; l++) for (int r=l; r<=n; r++) {
	int cur_S = 0;
	for (int i=l; i<=r; i++) cur_S += a[i];
        if (cur_S == S) {
            res = max(res, r-l+1);
        }
    }
    
    cout << res;
    return 0;
}