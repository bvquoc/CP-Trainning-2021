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

const int N = 100005, INF = LLONG_MAX;
int n, a[N], psum[N];
int res = INF;
vector <int> p;

signed main(void) {
    FastIO;
    freopen("ARRANGE.INP","r",stdin);
    freopen("ARRANGE.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }

    if (psum[n] % n == 0) { // Subtask 1
        int x = psum[n]/n;
        res = 0;
        FOR(i,1,n) if (a[i]>x) res += a[i]-x;
        cout << res;
        exit(0);
    }

    int x1 = psum[n]/n, x2 = x1+1;
    FOR(i,1,n) if (i*x1 + (n-i)*x2 == psum[n]) p.push_back(i);
    
    sort(a+1, a+1+n);
    for (int x: p) {
        int cur = 0;
        FOR(i,1,x) cur += max(0ll, x1-a[i]);
        FOR(i,x+1,n) cur += max(0ll, a[i]-x2);
        res = min(res, cur);
    }
    cout << res;
    return 0;
}