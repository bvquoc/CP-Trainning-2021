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
#define Task "DECOR"

using namespace std;

const int INF  = 1e18;
const int MOD  = 1e9 + 7;
const int MAXN = 5 * 1e5 + 7;

int N, M, K;
int a[MAXN];
ii b[MAXN];

namespace Sub2 {
    int s[MAXN];

    bool Check(int len){
        for (int l = 1; l <= N; ++l){
            int r = l + len - 1;
            if (len - (s[r] - s[l - 1]) <= K) return true;
        }
        return false;
    }

    int CNP(){
        int l = -1;
        int r = N + 1;
        while (r - l > 1){
            int mid = (r + l) >> 1;
            if (Check(mid)) l = mid;
            else r = mid;
        }
        return l;
    }

    void solve(){
        for (int i = 1; i <= N; ++i) s[i] = s[i - 1] + a[i];

        int len = CNP();
        if (len < 1) cout << -1;
        else {
            for (int l = 1; l <= N; ++l){
                int r = l + len - 1;
                if (len - (s[r] - s[l - 1]) <= K){
                    cout << l << ' ' << r;
                    break;
                }
            }
        }
        exit(0);
    }
}

namespace Sub3 {
    int CNT;
    int s[MAXN], val[MAXN], sum[MAXN], tmp[MAXN];
    vector <int> G[MAXN];

    void DFS(int u){
        sum[CNT] += a[u];
        val[u] = CNT;
        for (int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            if (val[v]) continue;
            DFS(v);
        }
    }

    bool Check(int len){
        for (int l = 1; l <= N; ++l){
            int r  = l + len - 1;
            int d0 = 0;
            for (int i = l; i <= r; ++i) tmp[i] = sum[val[i]];

            for (int i = l; i <= r; ++i){
                if (sum[val[i]]) { --sum[val[i]]; continue; }
                ++d0;
            }
            for (int i = l; i <= r; ++i) sum[val[i]] = tmp[i];
            if (d0 <= K) return true;
        }
        return false;
    }

    int CNP(){
        int l = -1;
        int r = N + 1;
        while (r - l > 1){
            int mid = (r + l) >> 1;
            if (Check(mid)) l = mid;
            else r = mid;
        }
        return l;
    }

    void solve(){
        for (int i = 1; i <= M; ++i){
            G[b[i].fi].push_back(b[i].se);
            G[b[i].se].push_back(b[i].fi);
        }
        for (int i = 1; i <= N; ++i){
            if (val[i]) continue;
            ++CNT;
            DFS(i);
        }
        int len = CNP();
        if (len < 1) { cout << -1; exit(0); }
        for (int l = 1; l <= N; ++l){
            int r  = l + len - 1;
            int d0 = 0;
            for (int i = l; i <= r; ++i) tmp[i] = sum[val[i]];

            for (int i = l; i <= r; ++i){
                if (sum[val[i]]) { --sum[val[i]]; continue; }
                ++d0;
            }
            for (int i = l; i <= r; ++i) sum[val[i]] = tmp[i];
            if (d0 <= K) {
                cout << l << ' ' << r;
                break;
            }
        }
        exit(0);
    }
}

namespace Sub4 {
    int CNT;
    int s[MAXN], val[MAXN], sum[MAXN], tmp[MAXN];
    vector <int> G[MAXN];

    void DFS(int u){
        sum[CNT] += a[u];
        val[u] = CNT;
        for (int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            if (val[v]) continue;
            DFS(v);
        }
    }

    bool Check(int len){
        int d0 = 0;
        for (int i = 1; i <= CNT; ++i) tmp[i] = 0;
        for (int l = 1; l <= len; ++l){
            d0 -= max(0, tmp[val[l]] - sum[val[l]]);
            ++tmp[val[l]];
            d0 += max(0, tmp[val[l]] - sum[val[l]]);
        }
        if (d0 <= K) return true;

        for (int l = 2; l <= N; ++l){
            int r  = l + len - 1;

            d0 -= max(0, tmp[val[l - 1]] - sum[val[l - 1]]);
            --tmp[val[l - 1]];
            d0 += max(0, tmp[val[l - 1]] - sum[val[l - 1]]);

            d0 -= max(0, tmp[val[r]] - sum[val[r]]);
            ++tmp[val[r]];
            d0 += max(0, tmp[val[r]] - sum[val[r]]);

            if (d0 <= K) return true;
        }
        return false;
    }

    int CNP(){
        int l = -1;
        int r = N + 1;
        while (r - l > 1){
            int mid = (r + l) >> 1;
            if (Check(mid)) l = mid;
            else r = mid;
        }
        return l;
    }

    void solve(){
        for (int i = 1; i <= M; ++i){
            G[b[i].fi].push_back(b[i].se);
            G[b[i].se].push_back(b[i].fi);
        }
        for (int i = 1; i <= N; ++i){
            if (val[i]) continue;
            ++CNT;
            DFS(i);
        }
        int len = CNP();
        if (len < 1) { cout << -1; exit(0); }
        int d0 = 0;
        for (int i = 1; i <= CNT; ++i) tmp[i] = 0;
        for (int l = 1; l <= len; ++l){
            d0 -= max(0, tmp[val[l]] - sum[val[l]]);
            ++tmp[val[l]];
            d0 += max(0, tmp[val[l]] - sum[val[l]]);
        }
        if (d0 <= K) { cout << 1 << ' ' << len; exit(0); }

        for (int l = 2; l <= N; ++l){
            int r  = l + len - 1;

            d0 -= max(0, tmp[val[l - 1]] - sum[val[l - 1]]);
            --tmp[val[l - 1]];
            d0 += max(0, tmp[val[l - 1]] - sum[val[l - 1]]);

            d0 -= max(0, tmp[val[r]] - sum[val[r]]);
            ++tmp[val[r]];
            d0 += max(0, tmp[val[r]] - sum[val[r]]);

            if (d0 <= K) { cout << l << ' ' << r; exit(0); }
        }
        exit(0);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i){
        char c; cin >> c;
        a[i] = bool(c == '1');
    }
    for (int i = 1; i <= M; ++i) cin >> b[i].fi >> b[i].se;
    if (!M) Sub2 :: solve();
    if (N <= 2000) Sub3 :: solve();
    Sub4 :: solve();
}
