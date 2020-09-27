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

const int N = 1000006;
int n, k, a[N];
ii L[N], R[N];


void Solve_MinArr() {
    stack <int> S;
    FOR(i,1,n) {
        while (!S.empty() && a[S.top()] >= a[i]) S.pop();
        L[i].fi = (S.empty() ? 0 : S.top());
        S.push(i);
    }
    while (!S.empty()) S.pop();
    FORD(i,n,1) {
        while (!S.empty() && a[S.top()] >= a[i]) S.pop();
        R[i].fi = (S.empty() ? n+1 : S.top());
        S.push(i);
    }
}
void Solve_MaxArr() {
    stack <int> S;
    FOR(i,1,n) {
        while (!S.empty() && a[S.top()] <= a[i]) S.pop();
        L[i].se = (S.empty() ? 0 : S.top());
        S.push(i);
    }
    while (!S.empty()) S.pop();
    FORD(i,n,1) {
        while (!S.empty() && a[S.top()] <= a[i]) S.pop();
        R[i].se = (S.empty() ? n+1 : S.top());
        S.push(i);
    }
}

signed main(void) {
    FastIO;
    freopen("LMINMAX.INP","r",stdin);
    freopen("LMINMAX.OUT","w",stdout);
    cin >> n >> k;
    a[0] = INT_MAX;
    FOR(i,1,n) cin >> a[i];
    // if (n<=1000) {
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
        // return 0;
    // }

    // Solve_MinArr();
    // Solve_MaxArr();
    // FOR(i,1,n) {
    //     int Max = INT_MIN, Min = INT_MAX;
    //     if (L[i].se == 0) {
    //         Max = a[i];
            
    //     }
    // }
    return 0;
}