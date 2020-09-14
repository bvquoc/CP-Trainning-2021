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

int n, cnt_bit1, cur;
int res = 0;

signed main(void) {
    FastIO;
    freopen("NUMSHIFT.INP","r",stdin);
    freopen("NUMSHIFT.OUT","w",stdout);
    cin >> n;
    cnt_bit1 = __builtin_popcountll(n);
    cur  = 64LL - __builtin_clzll(n) - 1;
    FOR (i,2,cnt_bit1) {
        res += pow(2,cur--);
    }
    cout << res;
    return 0;
}