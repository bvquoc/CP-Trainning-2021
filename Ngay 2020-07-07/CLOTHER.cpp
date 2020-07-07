#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 102;
int n, m, g;
int t[N], a[N];

int32_t main(void) {
    FastIO;
    freopen("CLOTHER.INP","r",stdin);
    freopen("CLOTHER.OUT","w",stdout);
    cin >> n >> m >> g;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    
    return 0;
}