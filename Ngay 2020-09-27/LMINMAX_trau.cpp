#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 1000006;
int n, k, a[N];
ii L[N], R[N];

signed main(void) {
    FastIO;
    freopen("LMINMAX.INP","r",stdin);
    freopen("LMINMAX.ANS","w",stdout);
    cin >> n >> k;
    a[0] = INT_MAX;
    FOR(i,1,n) cin >> a[i];
    int res = 1;
    FOR(i,1,n) {
        int Min = a[i], Max = a[i];
        FOR(j,i+1,n) {
            Min = min(a[j], Min);
            Max = max(a[j], Max);
            if (Max-Min <= k) {
                res = max(res, j-i+1);
            }
        }
    }
    cout << res;
    return 0;
}