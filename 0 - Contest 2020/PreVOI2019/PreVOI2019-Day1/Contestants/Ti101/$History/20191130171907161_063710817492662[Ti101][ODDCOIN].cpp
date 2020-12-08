#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

const int N = int(1e6) + 7;
const int oo = int(1e9) + 9;
typedef pair<int, int> pii;

vector<int> s;
int f[N], x, t, cost;

int DP(int t) {
    f[0] = 0;
    for(int i = 1; i <= t; ++i) {
        f[i] = oo;
        for(int v: s) {
            if(v > i) break;
            f[i] = min(f[i], f[i - v] + 1);
        }
    }
    return f[t];
}

int F(int t, int val, int val2, int lower) {
    if(t < val) return 1e9;
    if(t == val) return 1;
    int div = (t - lower) / val, div2 = 0;
    while((ll)t - 1ll * div * val < 0) --div;
    while((ll)t - 1ll * div * val > lower) ++div;
    while((ll)t - 1ll * div * val - div2 * val2 > lower) ++div2;
    int res = 1e9;
    if(t - div * val - div2 * val2 >= 0) res = DP(t - div * val - div2 * val2) + div + div2;
    if(t - div * val - (div2 - 1) * val2 < N && t - div * val - (div2 - 1) * val2 >= 0 && div2 > 0) res = min(res, DP(t - div * val - (div2 - 1) * val2) + div2 + div - 1);
    if((ll)t - (ll)(div + 1) * val - div2 * val2 >= 0) res = min(res, DP(t - (ll)(div + 1) * val - div2 * val2) + div2 + div + 1);
    return res;
}

void Solve() {
    cin >> x >> t; s.pb(x);
    sort(s.begin(), s.end());
    if(t < N) cout << DP(t) << '\n';
    else cout << min(F(t, s[15], s[14], N - 1), F(t, s[14], s[13], N - 1)) << '\n';
    s.erase(lower_bound(s.begin(), s.end(), x));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "oddcoin"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".ans", "w", stdout);
    }
    s = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
    int nTest; cin >> nTest;
    while(nTest --) Solve();
}
