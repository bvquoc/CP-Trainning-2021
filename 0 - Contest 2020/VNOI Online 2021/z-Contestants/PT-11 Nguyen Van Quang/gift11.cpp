#include <bits/stdc++.h>
using namespace std;

#define task "gift11"
#define ll long long
#define ii pair<int, int>
#define fi first
#define sc second
#define pb push_back
#define MASK(i) ( 1 << (i) )
#define BIT(i, x) ( (1 << (i)) & (x) )
#define C_BIT(i) ( __builtin_popcountll(i) )

const int MAXN = 2002;
const int MOD  = 998244353;
int N, M, T, K, Q;
int A[MAXN];
int P[MAXN];
int F[MAXN];

void ADD(int &x, const int &y){
    x += y;
    if (x >= MOD)
        x -= MOD;
}

void Init(){
    P[0] = 1;
        for (int i = 1; i < MAXN; i ++)
            P[i] = P[i - 1] * 10 % 11;
    F[0] = 1;
    for (int i = 1; i < MAXN; i ++)
        F[i] = F[i - 1] * i % MOD;
    return;
}

namespace SUBTASK1{
    vector<int> V;
    int D[MAXN];
    int digits(int &x){
        return log10(x) + 1;
    }

    void SOLVE(){
        V.clear();
        for (int i = 1; i <= N; i ++){
            D[i] = digits(A[i]);
            V.pb(i);
        }
        int cnt = 0;
        do{
            int cur = 0;
            for (int i = 0; i < V.size(); i ++)
                cur = (cur * P[D[V[i]]] + A[V[i]]) % 11;
            if (cur % 11 == 0){
                cnt ++;
            }
        } while( next_permutation(V.begin(), V.end()) );
        cout << cnt % MOD << '\n';
        return;
    }
}

namespace SUBTASK2{
    int calc(int x){
        int res = 0;
        int pos = 0;
        if (SUBTASK1 :: digits(x) & 1) pos = 1;
        while (x > 0){
            int cur = x % 10;
            if (pos == 0)
                res -= cur;
            else
                res += cur;
            pos ^= 1;
            x /= 10;
        }
        return res;
    }
    void SOLVE(){
        int ans = 0;
        for (int i = 1; i <= N; i ++)
            ADD(ans, calc(A[i]));

        if (ans % 11 == 0)
            cout << F[N] << '\n';
        else
            cout << 0 << '\n';
    }
}

namespace SUBTASK3{
    int dp[11][MAXN][1005];
    int solve(int k, int i, int re){
        if (re < 0) return 0;
        if (N - i + 1 - re < 0) return 0;
        if (i > N){
            return (k % 11 == 0 && re == 0);
        }
        if (dp[k][i][re] != -1) return dp[k][i][re];
        int res = 0;
        ADD(res, solve((k + A[i] + 11 * 11) % 11, i + 1, re - 1));
        ADD(res, solve((k - A[i] + 11 * 11) % 11, i + 1, re));
        return dp[k][i][re] = res;
    }
    void SOLVE(){
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= N; i ++){
            A[i] = SUBTASK2 :: calc(A[i]) % 11;
        }
        cout << (1LL * F[N / 2] * (1LL * F[N - N / 2] * solve(0, 1, N / 2) % MOD) % MOD) << '\n';
    }
}
//
//namespace SUBTASKFULL{
//    int dp[11][2001][1001];
//    int de[11][2001][1001];
//    int S[11];
//    int D[MAXN];
//    int rem;
//    int cnt;
//    int tmp;
//
//    int solve(int k, int i, int re, int &rem){
//        if (re < 0) return 0;
//        if (cnt - re + 1 - re < 0) return 0;
//        if (i > N){
//            return (k % 11 == rem && re == 0);
//        }
//        if (dp[k][i][re] != -1) return dp[k][i][re];
//        int res = 0;
//        if (D[i] & 1){
//            ADD(res, solve((k + A[i] + 11 * 11) % 11, i + 1, re - 1, rem));
//            ADD(res, solve((k - A[i] + 11 * 11) % 11, i + 1, re, rem));
//        }
//        return dp[k][i][re] = res;
//    }
//
//    int solveEven(int k, int i, int re){
//        if (re < 0) return 0;
//        if (tmp - re + 1 - re < 0) return 0;
//        if (i > N)
//            return (k % 11 == ((11 - rem) % 11) && re == 0);
//        if (de[k][i][re] != -1) return de[k][i][re];
//        int res = 0;
//        if ((D[i] & 1) == 0){
//            ADD(res, solveEven((k + A[i] + 11 * 11) % 11, i + 1, re - 1));
//            ADD(res, solveEven((k - A[i] + 11 * 11) % 11, i + 1, re));
//        }
//        return de[k][i][re] = res;
//    }
//    void SOLVE(){
//        cnt = 0;
//        int rem = 0;
//        for (int i = 1; i <= N; i ++){
//            D[i] = SUBTASK1 ::  digits(A[i]);
//            A[i] = SUBTASK2 :: calc(A[i]) % 11;
//            if (D[i] & 1)
//                cnt++;
//        }
//        int ans = 0;
//        tmp = N - cnt;
//        for (int i = 0; i < 11; i ++){
//            memset(dp, -1, sizeof(dp));
//            memset(de, -1, sizeof(de));
//            rem = i;
//            S[i] = (1LL * F[cnt / 2] * (1LL * F[cnt - cnt / 2] * solve(0, 1, cnt / 2, rem) % MOD) % MOD);
//            if (tmp == 0) ADD(ans, S[i])
//            else
//            ADD(ans, 1LL * S[i] * solveEven(0, 1, (cnt - cnt / 2) / 2) % MOD);
//        }
//        cout << ans << '\n';
//    }
//}

main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> T;
    Init();
    while (T --){
        cin >> N;
        int cntOdd  = 0;
        for (int i = 1; i <= N; i ++){
            cin >> A[i];
            if (SUBTASK1 :: digits(A[i]) & 1) cntOdd ++;
        }
        if (N <= 9){
            SUBTASK1 :: SOLVE();
            continue;
        }
        if (cntOdd == 0){
            SUBTASK2 :: SOLVE();
            continue;
        }
        if (cntOdd == N){
            SUBTASK3 :: SOLVE();
            continue;
        }
        cout << 0 << '\n';
//        SUBTASKFULL :: SOLVE();
    }
}
