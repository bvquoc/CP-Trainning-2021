#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 1000006;
int n, k, a[N];
int pos_k = -1;

int32_t main(void) {
    FastIO;
    freopen("LSEARCH.INP","r",stdin);
    freopen("LSEARCH.OUT","w",stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i]==k) {
            pos_k = i;
        }
    }
    cout << pos_k;
    return 0;
}