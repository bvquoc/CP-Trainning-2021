#include <bits/stdc++.h>
using namespace std;

#define task "coolmac"
#define ll long long
#define ii pair<int, int>
#define fi first
#define sc second
#define pb push_back
#define MASK(i) ( 1 << (i) )
#define BIT(i, x) ( (1 << (i)) & (x) )
#define C_BIT(i) ( __builtin_popcountll(i) )

const int MAXN = 100005;
const int oo   = 1e9 + 7;
int M, N, T, K, Q;
ii A[MAXN];
int B[MAXN];

void minimize(int &x, const int &y) { if (x > y) x = y; }

namespace SUBTASK1{
    int F[MAXN];

    void SOLVE(){

        int MINN = 100000;
        for (int i = 1; i <= M; i ++)
            minimize(MINN, B[i]);
        int ans = oo;
        for (int mask = 0; mask < MASK(N); mask ++){
            memset(F, 0, sizeof(F));
            for (int i = 1; i <= N; i ++){
                if (BIT(i - 1, mask) == 0) continue;
                F[A[i].fi] ++;
                F[A[i].sc + 1] --;
            }
            bool ok = 1;
            for (int i = 0; i <= 100000; i ++){
                F[i] += F[i - 1];
                if (i >= MINN && F[i] < 1){
                    ok = 0;
                    break;
                }
            }
            if (!ok) continue;
            minimize(ans, C_BIT(mask));
        }
        if (ans < oo)
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }
}

main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i ++){
        cin >> A[i].fi >> A[i].sc;
    }
    cin >> M;
    for (int i = 1; i <= M; i ++)
        cin >> B[i];
    if (N <= 10 && M <= 16){
        SUBTASK1 :: SOLVE();
        return 0;
    }
    cout << -1;
}
