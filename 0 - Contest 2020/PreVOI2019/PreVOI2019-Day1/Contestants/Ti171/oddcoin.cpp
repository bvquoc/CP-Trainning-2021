#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ( (int)(x).size() )
#define fi first
#define se second
using LL = long long;
const int inf = 2e9 + 7;

int nTest, x, t;
vector<int> coin{ 1, 3, 5 }, f;

void Main() {
    cin >> x >> t;
    int ans = inf;
    pair<int, int> cur{ t / x, t % x };
    while (cur.se <= t) {
        ans = min(ans, f[cur.se] + cur.fi);
        --cur.fi; cur.se += x;
        if (cur.se >= sz(f) ) break ;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("oddcoin.INP", "r", stdin);
    freopen("oddcoin.OUT", "w", stdout);

    while (sz(coin) < 15) coin.emplace_back(coin[ sz(coin) - 3 ] * 10);

    f.assign(1e6, inf); f[0] = 0;
    for (int c : coin) {
        for (int i = 0; i < sz(f); ++i) {
            if (i + c >= sz(f) ) break ;
            f[i + c] = min(f[i + c], f[i] + 1);
        }
    }

    cin >> nTest;
    while (nTest--) Main();

    return 0;
}

