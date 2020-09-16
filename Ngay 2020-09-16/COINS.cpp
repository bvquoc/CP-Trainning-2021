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
using ll = long long;

const int N = 100005;
int n, m;
ii a[N];

signed main(void) {
    FastIO;
    freopen("COINS.INP","r",stdin);
    freopen("COINS.OUT","w",stdout);
    cin >> n >> m;
    FOR(i,1,n) cin >> a[i].first;
    FOR(i,1,n) cin >> a[i].second;
    sort(a+1,a+1+n,[] (const ii &A, const ii &B) {
        return (A.second - A.first) < (B.second - B.first);
    });

    FOR(i,1,n) {
        int cur = a[i].second-a[i].first;
        if (m < cur) break;
        m -= cur;
        m += a[i].second;
    }
    
    cout << m;
    return 0;
}