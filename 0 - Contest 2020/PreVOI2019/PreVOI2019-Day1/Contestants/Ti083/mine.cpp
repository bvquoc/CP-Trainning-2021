#include <bits/stdc++.h>

using namespace std;

const string TASK = "mine";

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define fi first
#define se second

const int MOD = 1000003;
const int MAXN = 400007;
int fact[MAXN], invfact[MAXN];
int N, M;

void add(int &a, int b)
{
    a = ((a += b) >= MOD ? a - MOD : a);
}

void sub(int &a, int b)
{
    a = ((a -= b) < 0 ? a + MOD : a);
}


int bpow(int a, int p)
{
    int ans = 1;
    for (; p; p >>= 1, a = (1ll * a * a) % MOD) {
        if (p & 1) {
            ans = 1ll * ans * a % MOD;
        }
    }
    return ans;
}

const int SMALL_N = 2006;
int dp[SMALL_N * 2][SMALL_N];
int f[SMALL_N * 2][SMALL_N];

int main()
{
    freopen((TASK + ".inp").c_str(), "r", stdin);
    freopen((TASK + ".out").c_str(), "w", stdout);
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fact[0] = 1;
    FOR(i, 1, MAXN - 1) fact[i] = 1ll * fact[i - 1] * i % MOD;
    invfact[MAXN - 1] = bpow(fact[MAXN - 1], MOD - 2);
    FORB(i, MAXN - 2, 0) invfact[i] = 1ll * invfact[i + 1] * (i + 1) % MOD;

    scanf("%d %d", &N, &M);
    if (M == 1000000) {
        ll ans = 1;
        ans = ans * fact[2 * N] % MOD;
        ans = ans * invfact[N] % MOD;
        ans = ans * invfact[N] % MOD;
        ans = ans * bpow(N + 1, MOD - 2) % MOD;
        cout << ans << endl;
        return 0;
    }

    vector<int> A(2 * N + 1);
    FOR(i, 0, 2 * N - 1) scanf("%d", &A[i]);
    A[2 * N] = MOD + MOD;

    vector<int> bad(2 * N);
    for (int l = 0, r = 0; l < 2 * N; ++l) {
        for (; A[l] + M >= A[r]; ++r);
        bad[l] = r;
//        cerr << "bad " << l << ": " << r << endl;
    }

    dp[0][0] = 1;
    FOR(i, 0, 2 * N - 1) {
        int limit = i / 2;
        FOR(j, 0, limit) {
            add(dp[i + 1][j], dp[i][j]);
            add(dp[i + 1][j + 1], dp[i][j]);

            FOR(i1, i, bad[i] + 1) FOR(j1, j, min(i - j, i1 / 2)) f[i][j] = 0;
            f[i][j] = dp[i][j];
            FOR(i1, i, bad[i]) FOR(j1, j, min(i - j, i1 / 2)) {
                add(f[i1 + 1][j1], f[i1][j1]);
                add(f[i1 + 1][j1 + 1], f[i1][j1]);
            }

            sub(dp[bad[i] + 1][i - j], f[bad[i] + 1][i - j]);
            cerr << "dp " << i << ' ' << j << ": " << dp[i][j] << endl;
        }
    }

//    cerr << dp[2 * N][N] << endl;
    cout << dp[2 * N][N] << endl;
    return 0;
}

/*
3 6
1 2 3 7 9 10
*/
