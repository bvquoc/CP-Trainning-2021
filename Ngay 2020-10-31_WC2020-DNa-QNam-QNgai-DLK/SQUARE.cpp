#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

#define sqr(x) ((x)*(x))
int k;
bool isSquare(int x) {
    if (x < 0) return false;
    int sqrtX = sqrt(x);
    return sqrtX*sqrtX == x;
}

signed main(void) {
    // std::clock_t start;
    // double duration;
    // start = std::clock();
    // clock_t start_t, end_t, total_t;
    // start_t = clock();
    FastIO;
    freopen("SQUARE.INP","r",stdin);
    freopen("SQUARE.OUT","w",stdout);
    int k; cin >> k;
    if (k == 0) {
        cout << "0";
        return 0;
    }
    int absK = (k > 0 ? k : -k), ans = LLONG_MAX;
    for (int a = 1; a*a <= absK; a++) {
        if (absK % a != 0) continue;
        int b = k / a;
        if ((a+b) % 2 == 0) ans = min(ans, abs((a+b) / 2));
    }

    if (ans == LLONG_MAX) cout << "none";
    else cout << ans;
    
    // duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    // std::cout<<"\nTotal time: "<< duration <<'\n';
    return 0;
}