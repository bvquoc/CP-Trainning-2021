#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int unsigned long long 

int n, n_len = 0;
int res = 0;

int len(int x) {
    int ans = 0;
    do {
        ans++;
        x/=10;
    } while (x!=0);
    return ans;
}

int32_t main(void) {
    FastIO;
    freopen("SEQLEN.INP","r",stdin);
    freopen("SEQLEN.OUT","w",stdout);
    cin >> n;
    n_len = len(n);
    int cur = 9;
    for (int i=1; i<n_len; i++) {
        res += (cur*i);
        cur *= 10;
    }
    cur = 1;
    for (int i=1;i<n_len; i++) {
        cur *= 10;
    }
    res += (n-cur+1)*n_len;
    cout << res;
    return 0;
}