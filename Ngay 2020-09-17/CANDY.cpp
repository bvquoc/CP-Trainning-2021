#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 502;
int n, a[N];
ii res = ii(INT_MAX,INT_MAX);
int lim = 0, dp[N][200005];

signed x[N];
bool mark[N];
void Try(int i) {
    FOR(j,0,2) {
        x[i] = j;
        mark[i] = true;
        if (i == n) {
            int A[3];
            A[0] = A[1] = A[2] = 0;
            FOR(k,1,n) A[x[k]] += a[k];
            if (A[1] == A[2]) {
                // cout << A[1] << ' ' << A[0] << endl;
                if (A[0]<res.second) {
                    res.first = A[1];
                    res.second = A[0];
                }
            }
        } else Try(i+1);
    }
}

signed main(void) {
    FastIO;
    freopen("CANDY.INP","r",stdin);
    freopen("CANDY.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
        lim += a[i];
    }

    if (n<=13) { // Subtask 1
        Try(1);
        cout << res.first+res.second;
    }

    // Subtask 2: DP
    // FOR(i,0,n) FOR(j,0,lim) dp[i][j] = -1;
    // FOR(i,0,n) FOR(j,0,200000) dp[i][j] = -1;
    // dp[0][0] = 0;
    // FOR(i,1,n) {
    //     for(int c=0; c+a[i]<=lim; c++) {
    //         dp[i][c] = max({dp[i-1][c], dp[i-1][c+a[i]]+a[i], dp[i-1][abs(c-a[i])] + a[i]}); 
    //     }
    // }
    
    // int res = 0; lim = 0;
    // FOR(i,1,n) {
    //     lim += a[i];
    //     res += a[i] - dp[i][0];
    // }
    // cout << lim - dp[n][0];
    return 0;
}