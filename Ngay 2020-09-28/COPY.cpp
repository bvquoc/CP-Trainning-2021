#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

const int INF = 1e18;
const int N = 1000006;

int n, W, w[N], dp[N];

signed main() {
    FastIO;
    freopen("COPY.INP","r",stdin);
    freopen("COPY.OUT","w",stdout);
    cin >> n >> W;
    FOR(i,1,n) {
        cin >> w[i];
        dp[i] = INF;
    }

    FOR(i,1,n) {
        FORD(j,n,1) {
            if (dp[j - 1] == INF) continue;
            dp[j] = min(dp[j], dp[j - 1] + w[i]);
        }
    }

    FORD(i,n,0) {
        if (dp[i] <= W) {
            cout << i;
            break;
        }
    } 

    return 0;
}