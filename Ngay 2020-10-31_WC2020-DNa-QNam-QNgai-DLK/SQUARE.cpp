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
    int LEFT_LIM = LLONG_MAX, l = 0, r = 1e9;
    while (l <= r) {
        int mi = (l+r) / 2;
        if (sqr(mi)+k >= 0) {
            LEFT_LIM = mi;
            r = mi - 1;
        } else l = mi + 1;
    }
    
    FOR(i, LEFT_LIM, LEFT_LIM+6e7) {
        int cur = sqr(i)+k;
        if (isSquare(cur)) {
            cout << sqrt(cur);
            exit(0);
        }
    }
    cout << "none";
    
    // duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    // std::cout<<"\nTotal time: "<< duration <<'\n';
    return 0;
}