#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
using namespace std;

const int N = 100005;
int n, S, a[N];
int psum[N];
int res = -1;

int sum(int l, int r) {
    return psum[r] - psum[l-1];
}

signed main(void) {
    FastIO;
    freopen("WOSUB.INP","r",stdin);
    freopen("WOSUB.ANS","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }
    cin >> S;
    
    for (int l=1; l<=n; l++) for (int r=l; r<=n; r++) {
        if (sum(l,r) == S) {
            res = max(res, r-l+1);
        }
    }
    
    cout << res;
    return 0;
}