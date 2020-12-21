#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define task "decor"
#define MASK(i) ( 1 << (i) )
#define BIT(i, x) ( (1 << (i)) & x )
#define ii pair<int, int>
#define fi first
#define sc second


const int MAXN = 500005;
int N, M, T, K, Q;
int S[MAXN];
int cnt0;
int pa[MAXN];
int d[MAXN];
int val[MAXN];

namespace SUBTASK1{
    void SOLVE(){
        int cur = 0;
        int l = 0;
        int ansL = 0;
        int ans = 0;
        for (int i = 1; i <= N; i ++){
            if (cur == 0){
                if (S[i] == 1){
                    l = i;
                    cur ++;
                }
            }
            else{
                if (S[i] == 1){
                    cur ++;
                }
                else cur = 0;
            }
            if (ans < cur){
                ans = cur;
                ansL = l;
            }
        }
        if (ans == 0) { cout << -1; return; }
        cout << ansL << ' ' << ansL + ans - 1;
    }
}

namespace SUBTASK2{
    int pre[MAXN];
    int check(int x){
        for (int i = 1; i <= N; i ++){
            if (i + x - 1 > N) break;
            if (pre[i + x - 1] - pre[i - 1] <= K)
                return i;
        }
        return -1;
    }
    void SOLVE(){
        pre[0] = 0;
        for (int i = 1; i <= N; i ++)
            pre[i] = pre[i - 1] + (S[i] == 0);
        int ans = -1;
        int ansL = -1;
        int l = 1, r = N;
        while (l <= r){
            int mid = (l + r) >> 1;
            int cur = check(mid);
            if (cur != -1){
                if (ans < mid){
                    ans = mid;
                    ansL = cur;
                }
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if (ans < 0) cout << -1;
        else cout << ansL << ' ' << ansL + ans - 1;
    }
}

void maximize(int &x, const int &y) { if (x < y) x = y; }

namespace SUBTASKFULL{
    int cntCC = 0;
    ii E[MAXN];
    int F[MAXN];
    int root(int u){
        if (u == pa[u]) return u;
        return pa[u] = root(pa[u]);
    }
    void DSU(int u, int v){
        int X = root(u);
        int Y = root(v);
        if (X == Y) return;
        if (d[X] > d[Y]) swap(X, Y);
        d[Y] += d[X];
        val[Y] += val[X];
        pa[X] = Y;
        return;
    }
    void SOLVE(){
        for (int i = 1; i <= N; i ++){
            pa[i] = i;
            d[i] = 1;
            val[i] = (S[i] == 1);
        }
        pa[N + 1] = N + 1;
        d[N + 1] = 1;
        val[N + 1] = 0;
        for (int i = 1; i <= M; i ++){
            int u, v;
            cin >> u >> v;
            E[i] = { u, v };
            DSU(u, v);
        }
        int l = 1;
        int r = 1;
        int ans = 0;
        int ansL = 0;
        int curK = K;
        for (int l = 1; l <= N; l ++){
            maximize(r, l);
            bool ok = 1;

            while (curK >= 0 && r <= N){
                int ROOT = root(r);
                F[ROOT] ++;
                if (F[ROOT] > val[ROOT])
                    if (curK > 0)
                        curK --;
                    else break;
                r ++;
            }
            if (ans < r - l){
                ans = r - l;
                ansL = l;
            }
            int curROOT = root(l);
            if (F[curROOT] > val[curROOT])
                curK ++;
            F[curROOT] --;

        }
        if (ans == 0) cout << -1;
        else
            cout << ansL << ' ' << ansL + ans - 1 << '\n';
    }
}

main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i ++){
        char x;
        cin >> x;
        S[i] = (int)x - '0';
        if (S[i] == 0) cnt0 ++;
    }
    if (M == 0 && K == 0){
        SUBTASK1 :: SOLVE();
        return 0;
    }
    if (cnt0 <= K) { cout << 1 << ' ' << N; return 0; }
    if (M == 0){
        SUBTASK2 :: SOLVE();
        return 0;
    }
    SUBTASKFULL :: SOLVE();
}

