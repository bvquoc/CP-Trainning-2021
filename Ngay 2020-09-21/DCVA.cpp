#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define bb first
#define aa second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 100005;
int n, c, a[N], b[N];
int dp[N], k;
double x[N];
int p[N], q[N];

bool ok(int i) {
    if (b[i] == p[k]) return false;
    double xm = 1.0*(dp[i]-q[k])/(p[k]-b[i]);
    double xn = 1.0*(dp[i]-q[k-1])/(p[k-1]-b[i]);
    return (xn<xm);
}

signed main(void) {
    FastIO;
    freopen("DCVA.INP","r",stdin);
    freopen("DCVA.OUT","w",stdout);
    cin >> n >> c;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> b[i];
    dp[1]=c;
    k = 1;
    x[1] = -INT_MAX;
    p[1] = b[1];
    q[1] = dp[1];
    int u = 1;
    FOR(i,2,n) {
        // u là chỉ số lớn nhất mà x[u]≤a[i];
        while (u<=k && x[u]<=a[i])
            ++u;
        --u;
        // Tính giá trị hàm min tại a[i]
        dp[i] = q[u] + p[u] * a[i];

        if (b[i] == p[k] && dp[i]>=q[k])
            continue; // Bỏ qua dp[i]+b[i]*x

        // Tính lại đường gấp khúc min
        while (k > 1 && !ok(i))
            --k;
        if (u > k)
            u = k;
        if (k == 1 && p[1] == b[i])
            q[1] = dp[i];
        else {
            p[++k] = b[i];
            q[k] = dp[i];
            x[k] = 1.0 * (q[k - 1] - q[k]) / (p[k] - p[k - 1]);
        }
    }
    cout << dp[n];
    return 0;
}