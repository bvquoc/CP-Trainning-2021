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

const int N = 1000006;
int n, K, a[N], sum = 0;

signed main(void) {
    FastIO;
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    cin >> n >> K;
    FOR(i,1,n) {
        cin >> a[i];
        sum += a[i];
    }
    K %= sum;
    FOR(i,1,n) {
        if (K < a[i]) break;
        K -= a[i];
    }
    cout << K;
    return 0;
}