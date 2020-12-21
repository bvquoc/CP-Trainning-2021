#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORV(v, H) for (auto &v: H)

#define ii pair <int, int>
#define fi first
#define se second
#define ll long long

#define vi vector <int>
#define vii vector <ii>
#define pb push_back

#define reset(f, val) memset(f, val, sizeof(f))

#define MASK(i) (1ll << (i))
#define BIT(mask, i) (((mask) >> (i)) & 1ll)
#define ONBIT(mask, i) ((mask) | (1ll << (i)))
#define OFFBIT(mask, i) ((mask) &~ (1ll << (i)))

const int MAXN = 2e5 + 1005;
const int  MOD = 1e9 + 7;

int N;
int A[MAXN], B[MAXN];

namespace Subtask1 {
    int CALC1() {
        int RES = 0;
        FOR(i, 1, N) {
            if (i == 1) continue;
            int j = i;
            while (j > 1 && A[j - 1] > A[j]) {
                swap(A[j - 1], A[j]);
                ++RES;
                --j;
            }
        }
        return RES;
    }

    struct FenwickTree {
        int BIT[MAXN];
        void update(int u) {
            for (u; u; u -= u & -u)
                BIT[u]++;
        }

        int get(int u) {
            int res = 0;
            for (u; u <= N + 5; u += u & -u)
                res += BIT[u];
            return res;
        }
    } BIT;

    int CALC2() {
        int ans = 0;
        FOR(i, 1, N) {
            BIT.update(B[i]);
            ans += BIT.get(B[i] + 1);
            if (ans >= MOD) ans -= MOD;
        }
        return ans;
    }

    void SOLVE() {
        cout << min(CALC1(), CALC2()) % MOD << '\n';
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);

    cin >> N;
    FOR(i, 1, N) cin >> A[i];
    FOR(i, 1, N) cin >> B[i];

    Subtask1 :: SOLVE();
    return 0;
}
