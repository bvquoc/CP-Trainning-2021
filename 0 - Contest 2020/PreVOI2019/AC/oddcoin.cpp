#include <bits/stdc++.h>

using namespace std;

/***

The V-Country has the coin values of "1, 3, 5, 10, 30, 50, ..., 50000.
For each of the query (independently solved) you are given two integer
(xi, ti). You need to answer how many coin at least you need to pay for
the sum value of ti, assumed that you added xi to the set of coin.

***/

int get(int x) {
    int risan = 0;
    int a[3] = {50000, 30000, 10000};
    for(int t = 4; t >= 0; --t) {
        for(int j = 0; j < 3; ++j) {
            risan += x / a[j];
            x %= a[j];
            a[j] /= 10;
        }
    }
    return risan;
}

int main() {
    if(fopen("1.inp", "r")) {
        freopen("1.inp", "r", stdin);
    }
    else {
        freopen("oddcoin.inp", "r", stdin);
        freopen("oddcoin.out", "w", stdout);
    }

    int Q; cin >> Q;
    while(Q--) {
        int x, t; cin >> x >> t;
        int ans = t;
        for(int i = 0; i < 50000; ++i) {
            if(t < 0) break;
            ans = min(ans, i + get(t));
            t -= x;
        }
        cout << ans << "\n";
    }

    return 0;
}
