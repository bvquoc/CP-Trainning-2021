// https://lqdoj.edu.vn/problem/multm
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
using lint = long long;
using ld = long double;

const int N = 100005;
int n, res = 0;
lint P, a[N];
map <lint, bool> mark;
multiset <lint> S;
set <lint> A;

signed main(void) {
    FastIO;
    freopen("input.txt","r",stdin);
    cin >> n >> P;
    FOR(i,1,n) {
        cin >> a[i];
        S.insert(a[i]);
        A.insert(a[i]);
    }

    if (P == 1) {
        cout << A.size();
        exit(0);
    }

    res = n;
    for (int x: A) {
        if (mark[x]) continue;
        int a = S.count(x), b = S.count(x*P);
        res -= min(a,b);
        mark[x] = true;
        mark[x*P] = true;
        S.erase(x);
        S.erase(x*P);
    }

    cout << res;
    return 0;
}