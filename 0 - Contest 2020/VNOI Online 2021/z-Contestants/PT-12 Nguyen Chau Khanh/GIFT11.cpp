#include <bits/stdc++.h>

#define eps                     1e-9
#define endl                    '\n'
#define int                     long long
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
#define Task "GIFT11"

using namespace std;

const int INF  = 1e18;
const int MOD  = 998244353;
const int MAXN = 2001;

int N, T;
int n[11];
int b[11][MAXN];
int a[MAXN];

int SUM(const int &a, const int &b){
    if (a + b >= MOD) return a - MOD + b;
    return a + b;
}

int CS(int a){
    int cnt = 0;
    while (a) { ++cnt; a /= 10; }
    return cnt;
}

bool Check2(){
    for (int t = 1; t <= T; ++t){
        for (int i = 1; i <= n[t]; ++i) {
            if (CS(b[t][i]) % 2) return false;
        }
    }
    return true;
}

namespace Sub1 {
    vector <int > vt;
    int Even[MAXN], Odd[MAXN], CNT[MAXN];

    void Cal(int i){
        Odd[i] = 0; Even[i] = 0; CNT[i] = 0;
        int x = a[i], d = 1;
        while (x){
            ++CNT[i];
            if (d & 1) Odd[i] += x % 10;
            else Even[i] += x % 10;
            x /= 10;
            ++d;
        }
    }

    void sol(){
        vt.clear();
        for (int i = 1; i <= N; ++i) vt.push_back(i);

        int ans = 0;
        do {
            int d = 1, sum = 0;
            for (int i = 0; i < vt.size(); ++i){
                if (d & 1) {
                    sum = (sum + Odd[vt[i]]) % 11;
                    sum = (sum - Even[vt[i]] + 11 * 11) % 11;
                }
                else {
                    sum = (sum + Even[vt[i]]) % 11;
                    sum = (sum - Odd[vt[i]] + 11 * 11) % 11;
                }
                d += CNT[vt[i]];
            }
            int ok = bool(!sum);
            ans = SUM(ans, ok);
        }
        while (next_permutation(all(vt)));
        cout << ans << '\n';
    }

    void solve(){
        for (int t = 1; t <= T; ++t){
            N = n[t];
            for (int i = 1; i <= N; ++i) {
                a[i] = b[t][i];
                Cal(i);
            }
            sol();
        }
        exit(0);
    }
}

namespace Sub2 {
    int Even[MAXN], Odd[MAXN], CNT[MAXN];

    void Cal(int i){
        Odd[i] = 0; Even[i] = 0; CNT[i] = 0;
        int x = a[i], d = 1;
        while (x){
            ++CNT[i];
            if (d & 1) Odd[i] += x % 10;
            else Even[i] += x % 10;
            x /= 10;
            ++d;
        }
    }

    void solve(){
        for (int t = 1; t <= T; ++t){
            N = n[t];
            for (int i = 1; i <= N; ++i) {
                a[i] = b[t][i];
                Cal(i);
            }
            int d = 1, sum = 0, GT = 1;
            for (int i = 1; i <= N; ++i){
                GT = GT * i % MOD;
                if (d & 1) {
                    sum = (sum + Odd[i]) % 11;
                    sum = (sum - Even[i] + 11 * 11) % 11;
                }
                else {
                    sum = (sum + Even[i]) % 11;
                    sum = (sum - Odd[i] + 11 * 11) % 11;
                }
                d += CNT[i];
            }
            if (!sum) cout << GT << "\n";
            else cout << "0\n";
        }
        exit(0);
    }
}

namespace Sub3 {
    int A[MAXN];
    int dp[1500][1500][12];
    int Even[MAXN], Odd[MAXN], CNT[MAXN];

    void Cal(int i){
        Odd[i] = 0; Even[i] = 0; CNT[i] = 0;
        int x = a[i], d = 1;
        while (x){
            ++CNT[i];
            if (d & 1) Odd[i] += x % 10;
            else Even[i] += x % 10;
            x /= 10;
            ++d;
        }
    }

    int DP(int x, int odd, int eve, int r){
        if (x <= 0) return bool(!r);
        if (dp[x][odd][r] != -1) return dp[x][odd][r];
        int cur = 0, newr;

        newr = r;
        newr = (newr + Odd[A[x]]) % 11;
        newr = (newr - Even[A[x]] + 11 * 11) % 11;
        cur  = SUM(cur, DP(x - 1, odd, eve + 1, newr) * eve % MOD);

        newr = r;
        newr = (newr + Even[A[x]]) % 11;
        newr = (newr - Odd[A[x]] + 11 * 11) % 11;
        cur  = SUM(cur, DP(x - 1, odd + 1, eve, newr) * odd % MOD);

        return dp[x][odd][r] = cur;
    }

    void sol(){
        int eve = 0, odd = 0, sum = 0, GT = 1;
        for (int i = 1; i <= N; ++i){
            if (CNT[i] & 1){
                ++odd;
                GT = GT * odd % MOD;
                sum = (sum + Odd[i]) % 11;
                sum = (sum - Even[i] + 11 * 11) % 11;
            }
            else {
                ++eve;
                A[eve] = i;
            }
        }
        if (!eve){
            cout << GT << endl;
            return;
        }
        memset(dp, -1, sizeof(dp));
        cout << GT * DP(eve, odd / 2 + 1, odd + 1 - (odd / 2 + 1), sum) << '\n';
    }

    void solve(){
        for (int t = 1; t <= T; ++t){
            N = n[t];
            for (int i = 1; i <= N; ++i) {
                a[i] = b[t][i];
                Cal(i);
            }
            sol();
        }
        exit(0);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
    cin >> T;
    int s = 0;
    for (int t = 1; t <= T; ++t){
        cin >> n[t];
        s += n[t];
        for (int i = 1; i <= n[t]; ++i) cin >> b[t][i];
    }
    if (s <= 20) Sub1 :: solve();
    if (Check2()) Sub2 :: solve();
    Sub3 :: solve();
}
