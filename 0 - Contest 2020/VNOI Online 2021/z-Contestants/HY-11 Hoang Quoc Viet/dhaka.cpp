/* -> Written by <-
   -----------
  K_A_Z_A_M_A
  ___________|
  |    _    |
  |   (^_^)   |
  |  /( | )\  |
  |____|_|____|
    H O A N G
*/

#define Task "dhaka"
#define F first
#define S second
#define push_back pb
#define bit(x, i) ((x >> i) & 1)
#define inf 1e9 + 7
#define INF 1e18 + 7

#define ckd iml

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;

int n, m, k, l;
vector <pair<int, int>> ke[maxn];
vector <int> s[maxn];

void Read(){
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; ++ i){
        int x; cin >> x;
        for (int j = 1; j <= x; ++ j){
            int y; cin >> y;
            s[i].pb(y);
        }
    }
    for (int i = 1; i <= m; ++ i){
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].pb({v, w});
        ke[v].pb({u, w});
    }
}

ll dp[40][maxn];

void ijk(){
    priority_queue <pair<ll, pair<int, int>>> pq;
    for (int i = 1; i <= n; ++ i)
        for (int mask = 0; mask < (1 << k); ++ mask) dp[mask][i] = INF;

    int be = 0;
    for (auto c : s[1]){
        c --;
        if (bit(be, c) == 0) be += (1 << c);
    }
    dp[be][1] = 0;
    pq.push({0, {1, be}});
    while (!pq.empty()){
        pair <ll, pair<int, int>> p = pq.top();
        pq.pop();
        ll l = - p.F;
        int u = p.S.F;
        int mask = p.S.S;
        if (dp[mask][u] < l) continue;
        for (auto pi : ke[u]){
            int v = pi.F;
            int w = pi.S;
            int newmask = mask;
            for (auto c : s[v]){
                c --;
                if (bit(mask, c) == 0) newmask += (1 << c);
            }
            if (dp[newmask][v] > l + w){
                dp[newmask][v] = l + w;
                pq.push({- dp[newmask][v], {v, newmask}});
            }
        }
    }
}

void Solve(){
    ijk();
    ll res = INF;
    for (int mask = 0; mask < (1 << k); ++ mask){
        int cnt = 0;
        for (int i = 0; i < k; ++ i)
            if (bit(mask, i)) ++ cnt;
        if (cnt < l) continue;
        res = min(res, dp[mask][n]);
//        cout << dp[mask][n] << "\n";
    }
//    cout << dp[1][5];
    if (res == INF) res = -1;
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    if(fopen(Task".inp", "r")){
        freopen(Task".inp","r",stdin);
        freopen(Task".out","w",stdout);
    }
    int test_case = 1;
//     cin >> test_case;
    while (test_case --){
        Read();
        Solve();
    }
    return 0;
}

