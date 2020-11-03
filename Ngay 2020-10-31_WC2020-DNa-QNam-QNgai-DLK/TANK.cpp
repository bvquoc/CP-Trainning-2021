#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define endl '\n'
// #define int long long
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    } else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    } else return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 100005;
int M, n, a[N];

ll psum[N];
#define sum(l,r) (psum[r]-psum[l-1])
signed main(void) {
    FastIO;
    freopen("TANK.INP","r",stdin);
    freopen("TANK.OUT","w",stdout);
    cin >> M >> n;
    FOR(i,1,n) {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }

    int res = INT_MAX;
    int l = 0, r = n;
    while (l <= r) {
        int mid = (l+r)/2;
        bool ok = true;
        FOR(i,1,n-mid+1) {
            if (sum(i,i+mid-1) < M) {
                ok = false;
                break;
            }
        }
        if (ok) {
            minimize(res,mid);
            r = mid-1;
        } else l = mid+1;
    }
    cout << res;
    return 0;
}