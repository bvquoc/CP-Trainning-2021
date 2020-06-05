#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 10004, INF = INT_MAX;
int n, s, a[N];
int dp(int coins[], int N, int M) {
    int f[M+1];

    f[0] = 0;
    for (int i=1; i<=M; i++) {
        f[i] = INF;
    }

    for (int i=1; i<=M; i++) {
        for (int j=1; j<=N; j++)
        if (coins[j] <= i) {
            int tmp = f[i-coins[j]];
            if (tmp != INF && ((tmp + 1) < f[i]))
                f[i] = tmp + 1;
        }
    }

    int res = INF;
    for (int i=s;i<=M;i++) {
        res = min(f[i]+f[i-s],res);
    }
    return res;
}

int32_t main(void) {
    FastIO;
    freopen("CHANGE.INP","r",stdin);
    freopen("CHANGE.OUT","w",stdout);
    cin >> s >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    cout << dp(a,n,s*2);
    return 0;
}
