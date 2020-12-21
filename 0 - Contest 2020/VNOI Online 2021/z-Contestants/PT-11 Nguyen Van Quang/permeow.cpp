#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pb push_back
#define task "permeow"
#define MASK(i) ( 1 << (i) )
#define BIT(i, x) ( (1 << (i)) & x )
#define ii pair<int, int>
#define fi first
#define sc second

const int MAXN = 200055;
const int MOD  = 1e9 + 7;
int N, M, T, Q, K;
int A[MAXN];
int B[MAXN];
int sum = 0;

struct FenwickTree{
    int T[MAXN];
    void RESET(int _N){
        memset(T, 0, (_N + 5) * sizeof(int));
    }
    void update(int i){
        while (i > 0){
            T[i] ++;
            i -= i &-i;
        }
        return;
    }
    int get(int i){
        int res = 0;
        while (i <= N){
            res += T[i];
            i += i &-i;
        }
        return res;
    }
};

FenwickTree BIT;
namespace SUBTASK1{
    void SOLVE(int *A){
        BIT.RESET(N);
        int ans = 0;
        for (int i = 1; i <= N; i ++){
            ans += BIT.get(A[i]);
            BIT.update(A[i]);
        }
        cout << ans % MOD << '\n';
    }
}

namespace SUBTASK2{
    void SOLVE(){
        if (N == 1) { cout << 0; return; }
        if (N == 2) { cout << 1; return; }
        ll curN = 1LL * N * (N - 1) / 2;
        ll fact = 1;
        for (int i = 3; i <= N; i ++)
            fact = fact * i % MOD;
        cout << 1LL * fact * curN % MOD << '\n';
    }
}

main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i ++)
        cin >> A[i];
    for (int i = 1; i <= N; i ++)
        cin >> B[i];
    bool ok = 1;
    for (int i = 1; i <= N; i ++)
        if (A[i] != B[i]) { ok = 0; break; }
    if (ok){
        SUBTASK1 :: SOLVE(A);
        return 0;
    }
    ok = 1;
    for (int i = 1; i <= N; i ++)
        if (A[i] != i || B[i] != N - i + 1)
            { ok = 0; break; }
    if (ok){
        SUBTASK2 :: SOLVE();
        return 0;
    }
}
