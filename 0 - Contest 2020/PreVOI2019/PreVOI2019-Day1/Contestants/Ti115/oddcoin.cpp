#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair< int, int > ii;

const int mod = 1e9 + 7;
const int inf = 2e9;

vector< int > coin;

int pw[10], q;

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    freopen("oddcoin.inp", "r", stdin);
    freopen("oddcoin.out", "w", stdout);
    pw[0] = 1;
    for(int i = 1; i <= 4; i++)
        pw[i] = pw[i - 1] * 10;
    for(int i = 0; i <= 4; i++) {
        coin.pb(1 * pw[i]);
        coin.pb(3 * pw[i]);
        coin.pb(5 * pw[i]);
    }
    cin >> q;
    while(q--) {
        int x, t;
        cin >> x >> t;
        int ans = inf;
        for(int times = 0; times <= 50000; times++) {
            int tmp = t - times * x;
            if(tmp < 0) break;
            int sum = times;
            for(int j = 14; j >= 0; j--) {
                int rem = tmp / coin[j];
                tmp -= rem * coin[j];
                sum += rem;
            }
            ans = min(ans, sum);
        }
        cout << ans << "\n";
    }
}
