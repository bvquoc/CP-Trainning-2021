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

const int N = 100005, INF = INT_MAX;
int n, m; ii L[N];

double x[N]; // Mảng tọa độ các giao điểm
int p[N]; // Hệ số góc của các đoạn gấp khúc
int q[N]; // Hằng số của đoạn gấp khúc

bool ok (int i) {
    int u = m;
    if (L[i].fi==L[u].fi) return false;
    if (m==1) return true;
    double xM = 1.0 * (L[u].se - L[i].se) / (L[i].fi - L[u].fi);
    u = m-1;
    double xN = 1.0 * (L[u].se - L[i].se) / (L[i].fi - L[u].fi);
    return (xM > xN);
}
signed main(void) {
    FastIO;
    freopen("CMIN.INP","r",stdin);
    freopen("CMIN.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> L[i].first >> L[i].second;

    sort(L+1,L+1+n,greater<ii>());
    m = 0;
    for (int i = 1; i <= n; ++i) {
        while (m > 0 && !ok (i)) --m;
        L[++m] = L[i];
    }

    x[0] = -INF, p[0] = L[1].fi, q[0] = L[1].se;
    for (int i = 1; i < m; ++i) {
        x[i] = 1.0 * (L[i].se - L[i+1].se) / (L[i+1].fi - L[i].fi);
        p[i] = L[i+1].fi;
        q[i] = L[i+1].se;
    }
    x[m]=INF;

    int q, z; 
    cin >> q;
    while (q--) {
        cin >> z;
        int u = upper_bound (x, x + m, z) - x - 1;
        cout << p[u]*z + ::q[u] << endl;
    }
    return 0;
}