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

const int N = 1000006;

int n, k, d[N];

void init() {
    FOR(i,1,sqrt(N)) {
        d[i*i]++;
        int j = i+1;
        while (i*j < N) {
            d[i*j] = d[i*j]+2;
            j++;
        }
    }
}

signed main(void) {
    FastIO;
    freopen("QUIZ.INP","r",stdin);
    freopen("QUIZ.OUT","w",stdout);
    cin >> n >> k;
    init();
    int res = 0;
    FOR(i,1,n-1) {
        if (d[i] == k) {
            res++;
        }
    }
    cout << res;
    return 0;
}