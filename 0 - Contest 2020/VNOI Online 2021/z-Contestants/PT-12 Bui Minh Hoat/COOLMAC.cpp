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
#define all(v) v.begin(), v.end()

#define MASK(i) (1ll << (i))
#define BIT(mask, i) (((mask) >> (i)) & 1ll)
#define ONBIT(mask, i) ((mask) | (1ll << (i)))
#define OFFBIT(mask, i) ((mask) &~ (1ll << (i)))

const int MAXN = 1e5 + 105;
const int   oo = 1e9 + 7;

struct DATA {
    int l, r;
} A[MAXN];

int M, N;
int t[MAXN];

namespace Subtask1 {
    vi H;
    int C[105], D[MAXN];
    int ID, ANS;
    int sum[MAXN];
    void W() {
        int cnt = 0;
        FOR(i, 0, H.size()) sum[i] = 0;
        FOR(i, 1, M) {
            if (!C[i]) continue;
            ++cnt;
            ++sum[D[A[i].l]];
            --sum[D[A[i].r + 1]];
        }
        if (cnt >= ANS) return;
//        FOR(i, 1, M) cout << C[i] << ' ';
//        cout << '\n';
        FOR(i, 1, H.size()) sum[i] += sum[i - 1];
//        FOR(i, 1, H.size()) cout << sum[i] << ' ';
//        cout << '\n';
        FOR(i, D[t[1]], D[100000]) {
//            cout << i << '\n';
            if (sum[i] <= 0) return;
        }
        ANS = cnt;
//        cout << "*";
//        FOR(i, 1, M) cout << C[i];
//        cout << '\n';
    }

    void Try(int i) {
        FOR(j, 0, 1) {
            C[i] = j;
            if (i == M) W();
            else Try(i + 1);
        }
    }

    void SOLVE() {
        H.pb(0);
        FOR(i, 1, M) {
            H.pb(A[i].l);
            H.pb(A[i].r + 1);
        }
        H.pb(100000);
        H.pb(100000 + 1);
        FOR(i, 1, N) H.pb(t[i]);
        sort(all(H));
        H.resize(distance(H.begin(), unique(all(H))));

        ID = 0;
        FORV(val, H) {
            D[val] = ++ID;
        }

        sort(t + 1, t + 1 + N);
        ANS = +oo;
        Try(1);
        if (ANS == +oo) cout << -1 << '\n';
        else cout << ANS << '\n';
    }
}

namespace Subtask2 {
    vi H;
    int D[MAXN];
    int ID;
//    int dp[3005][3005 * 3];
    vector < vector <int> > dp;

    int solve(int i, int j) {
        if (j == D[100000]) return 0;
        if (i > M) return +oo;
        if (dp[i][j] != -1) return dp[i][j];
        int cur = +oo;
        cur = min(cur, solve(i + 1, j));
        if (j >= D[A[i].l])
            cur = min(cur, solve(i + 1, max(j, D[A[i].r])) + 1);
        return dp[i][j] = cur;
    }

    bool cmp(const DATA &A, const DATA &B) {
        if (A.l != B.l) return A.l < B.l;
        return A.r < B.r;
    }

    void SOLVE() {
        H.pb(0);
        FOR(i, 1, M) {
            H.pb(A[i].l);
            H.pb(A[i].r);
        }
        H.pb(100000);
        FOR(i, 1, N) H.pb(t[i]);
        sort(all(H));
        H.resize(distance(H.begin(), unique(all(H))));

        ID = 0;
        FORV(val, H) {
            D[val] = ++ID;
        }

        sort(t + 1, t + 1 + N);
        sort(A + 1, A + 1 + M, cmp);

        if (1ll * (M * 5ll) * ((int) H.size() + 5ll) > 1e8) {
            cout << -1 << '\n';
            exit(0);
        }

        dp.assign(M + 5, vector <int> ((int) H.size() + 5, -1));

        int ANS = solve(1, D[t[1]]);
        if (ANS == +oo) cout << -1 << '\n';
        else cout << ANS << '\n';
    }
}

void PROCESS() {
    if (N <= 10 && M <= 16) {
        Subtask1 :: SOLVE();
        exit(0);
    }
    Subtask2 :: SOLVE();
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);

    cin >> M;
    FOR(i, 1, M) cin >> A[i].l >> A[i].r;
    cin >> N;
    FOR(i, 1, N) cin >> t[i];

    PROCESS();
//    Subtask1 :: SOLVE();
//    Subtask2 :: SOLVE();
    return 0;
}
