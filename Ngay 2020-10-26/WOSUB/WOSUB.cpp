#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
using namespace std;

const int N = 100005;
int n, S, a[N];
int psum[N];
int res = -1;

signed main(void) {
    FastIO;
    freopen("WOSUB.INP","r",stdin);
    freopen("WOSUB.OUT","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }
    cin >> S;
    
    for (int i=1; i<=n; i++) {
        int x = S + psum[i-1];
        int l = i, r = n, mid;
        while (l <= r) {
            mid = (l+r)/2;
            if (psum[mid] == x) {
                res = max(res, mid-i+1);
                break;
            }
            if (psum[mid] < x) l = mid+1;
            else r = mid-1;
        }
    }
    
    cout << res;
    return 0;
}