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
#define int long long
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

const int INF = 1e9+7;
int a, b, c;
int cnt = 0;

#define calc(x,y) (((y)-(x))/2 + ((y)-(x))%2)

signed main(void) {
    FastIO;
    freopen("SPIRIT.INP","r",stdin);
    freopen("SPIRIT.OUT","w",stdout);
    cin >> a >> b >> c;
    cnt = (b/c) - (a/c);
    
    if (cnt == 0) {
        cout << calc(a,b);
        exit(0);
    }

    int L = LLONG_MAX, R = -1;
    { // Tìm bội nhỏ nhất lớn hơn a
        int l = 1, r = 1e9, mid;
        while (l <= r) {
            mid = (l+r)/2;
            if (mid*c > a) {
                minimize(L, mid*c);
                r = mid-1;
            } else l = mid+1;
        }
    }
    { // Tìm bội của c lớn nhất nhỏ hơn b
        int l = 1, r = 1e9, mid;
        while (l <= r) {
            mid = (l+r)/2;
            if (mid*c < b) {
                maximize(R, mid*c);
                l = mid+1;
            } else r = mid-1;
        }
    }

    int res = calc(a,L-1) + calc(R+1,b);
    int cnt = R/c - L/c + 1;
    res += cnt + (cnt-1)*calc(L+1,L+c-1);
    cout << res;
    return 0;
}