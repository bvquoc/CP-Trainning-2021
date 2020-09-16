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

const int N = 10004;
int n, cnt[N];
int L = INT_MAX, R = INT_MIN;
long long res = 0;

signed main(void) {
    FastIO;
    freopen("PARK.INP","r",stdin);
    freopen("PARK.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) {
        int x; cin >> x;
        x -= 10100000;
        cnt[x]++;
    }

    FOR(k,2010,9999) {
        if (!cnt[k]) continue;
        res += 100;
        if (cnt[k]>5) {
            res += (cnt[k]-5);
        }
    }

    cout << res;
    return 0;
}