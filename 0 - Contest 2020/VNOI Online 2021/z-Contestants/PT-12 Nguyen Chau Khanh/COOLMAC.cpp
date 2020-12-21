#include <bits/stdc++.h>

#define eps                     1e-9
#define endl                    '\n'
//#define int                     long long
#define ll                      long long
#define double                  long double
#define ii                      pair <int, int>
#define fi                      first
#define se                      second
#define all(x)                  (x).begin(), (x).end()
#define BIT(mask, i)            ((mask) & (1ll << (i)))
#define ONBIT(mask, i)          ((mask) | (1ll << (i)))
#define OFFBIT(mask, i)         ((mask) &~ (1ll << (i)))
#define a(i, j)                 aa[((i) - 1) * (NumRow) + (j)]
#define ID(i, j)                (((i) - 1) * (NumRow) + (j))
#define CIDx(i)                 ((i) / (NumRow)) + ((i) % (NumRow) != 0)
#define CIDy(i)                 ((i) % (NumRow)) + ((i) % (NumRow) == 0) * (numRow)
#define Task "COOLMAC"

using namespace std;

const int INF  = 1e9 + 7;
const int MOD  = 1e9 + 7;
const int MAXN = 1e5 + 7;

int M, N;
int t[MAXN];
ii  a[MAXN];

namespace Sub {
    int MIN = INF;
    priority_queue <int> qu;

    void solve(){
        for (int i = 1; i <= N; ++i) MIN = min(MIN, t[i]);
        sort(a + 1, a + M + 1);

        int ans = 0, i = 1, r = MIN - 1;
        while (r != 100000){
            while (i <= M && a[i].fi <= r + 1) {
                qu.push(a[i].se);
                ++i;
            }
            if (qu.empty()) break;
            if (qu.top() <= r) break;
            ++ans;
            r = qu.top();
            qu.pop();
        }
        if (r != 100000) cout << -1;
        else cout << ans;
        exit(0);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
    cin >> M;
    for (int i = 1; i <= M; ++i) cin >> a[i].fi >> a[i].se;
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> t[i];
    Sub :: solve();
}
/*
3
250 100000
150 200
10 300
2
1000 200
*/
