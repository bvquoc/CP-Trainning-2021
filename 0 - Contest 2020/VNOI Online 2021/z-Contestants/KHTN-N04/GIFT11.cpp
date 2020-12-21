#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 2e3 + 5, mod = 998244353;

int n;
int sum[N][2], len[N];

void readTest(){
    cin >> n;
    ForE(i, 1, n){
        sum[i][0] = sum[i][1] = len[i] = 0;
        int x; cin >> x; int tmpIdx = 0;
        while (x){
            sum[i][tmpIdx] += x % 10;
            x /= 10; tmpIdx = 1 - tmpIdx;
            len[i]++;
        }
        if (!(len[i] & 1)){
            swap(sum[i][0], sum[i][1]);
        }
    }
}

// SUBTASK 1 ====================================

bool checkTest1(){
    return n <= 8;
}

int ans1, curLen1, tmpSum1[2];
int ck1[N];

void bt1(int u){
    if (u == n + 1){
        if (!(abs(tmpSum1[0] - tmpSum1[1]) % 11)){
            ans1++;
        }
        return;
    }
    ForE(i, 1, n){
        if (!ck1[i]){
            if (curLen1 & 1){
                tmpSum1[0] += sum[i][1];
                tmpSum1[1] += sum[i][0];
            }
            else{
                tmpSum1[0] += sum[i][0];
                tmpSum1[1] += sum[i][1];
            }
            curLen1 += len[i];
            ck1[i] = 1;
            bt1(u + 1);
            ck1[i] = 0;
            curLen1 -= len[i];
            if (curLen1 & 1){
                tmpSum1[0] -= sum[i][1];
                tmpSum1[1] -= sum[i][0];
            }
            else{
                tmpSum1[0] -= sum[i][0];
                tmpSum1[1] -= sum[i][1];
            }
        }
    }
}

void solveTest1(){
    ans1 = curLen1 = tmpSum1[0] = tmpSum1[1] = 0;
    ForE(i, 1, n){
        ck1[i] = 0;
    }
    bt1(1);
    cout << ans1 << endl;
}

// SUBTASK 2 ====================================

bool checkTest2(){
    ForE(i, 1, n){
        if (len[i] & 1){
            return 0;
        }
    }
    return 1;
}

int ans2, tmpSum2[2];

void solveTest2(){
    tmpSum2[0] = tmpSum2[1] = 0;
    ForE(i, 1, n){
        tmpSum2[0] += sum[i][0];
        tmpSum2[1] += sum[i][1];
    }
    if (abs(tmpSum2[0] - tmpSum2[1]) % 11){
        ans2 = 0;
    }
    else{
        ans2 = 1;
        ForE(i, 1, n){
            ans2 = (ll)ans2 * i % mod;
        }
    }
    cout << ans2 << endl;
}

// SUBTASK 3 ====================================

bool checkTest3(){
    ForE(i, 1, n){
        if (!(len[i] & 1)){
            return 0;
        }
    }
    return 1;
}

int dp3[N][N][11]; // number of ways to fill i numbers at odd pos and j numbers at even pos, using i + j first numbers, and it's sum have a remainder of k

void solveTest3(){
    ForE(i, 0, n){
        fill(dp3[i][0], dp3[i][n + 1], 0);
    }
    dp3[0][0][0] = 1;
    ForE(idx, 1, n){
        ForE(i, 0, idx){
            int j = idx - i;
            if (i > (n + 1) / 2 || j > n / 2){
                continue;
            }
            if (i){ // put i at odd position
                int diffSumIdx = (sum[idx][0] - sum[idx][1]) % 11;
                diffSumIdx = (diffSumIdx <= 0 ? -diffSumIdx : 11 - diffSumIdx);
                For(k, 0, 11){
                    dp3[i][j][k] += (ll)((n + 1) / 2 - i + 1) * dp3[i - 1][j][diffSumIdx] % mod;
                    if (dp3[i][j][k] >= mod){
                        dp3[i][j][k] -= mod;
                    }
                    diffSumIdx++; if (diffSumIdx == 11) diffSumIdx = 0;
                }
            }
            if (j){ // put i at even position
                int diffSumIdx = (sum[idx][1] - sum[idx][0]) % 11;
                diffSumIdx = (diffSumIdx <= 0 ? -diffSumIdx : 11 - diffSumIdx);
                For(k, 0, 11){
                    dp3[i][j][k] += (ll)(n / 2 - j + 1) * dp3[i][j - 1][diffSumIdx] % mod;
                    if (dp3[i][j][k] >= mod){
                        dp3[i][j][k] -= mod;
                    }
                    diffSumIdx++; if (diffSumIdx == 11) diffSumIdx = 0;
                }
            }
        }
    }
    cout << dp3[(n + 1) / 2][n / 2][0] << endl;
}

// SUBTASK 4 ====================================

int dp4[N][N][11]; // number of ways to fill i numbers at odd pos and j numbers at even pos, using i + j first numbers, and it's sum have a remainder of k

void solveTest4(){
    int sumOdd = 0;
    vi indexesOdd = {0};
    ForE(i, 1, n){
        if (len[i] & 1){
            sumOdd++;
            indexesOdd.push_back(i);
        }
    }
    ForE(i, 0, sumOdd){
        fill(dp4[i][0], dp4[i][sumOdd + 1], 0);
    }
    dp4[0][0][0] = 1;
    ForE(idx, 1, sumOdd){
        ForE(i, 0, idx){
            int j = idx - i;
            if (i > (sumOdd + 1) / 2 || j > sumOdd / 2){
                continue;
            }
            if (i){ // put i at odd position
                int diffSumIdx = (sum[indexesOdd[idx]][0] - sum[indexesOdd[idx]][1]) % 11;
                diffSumIdx = (diffSumIdx <= 0 ? -diffSumIdx : 11 - diffSumIdx);
                For(k, 0, 11){
                    dp4[i][j][k] += (ll)((n + 1) / 2 - i + 1) * dp4[i - 1][j][diffSumIdx] % mod;
                    if (dp4[i][j][k] >= mod){
                        dp4[i][j][k] -= mod;
                    }
                    diffSumIdx++; if (diffSumIdx == 11) diffSumIdx = 0;
                }
            }
            if (j){ // put i at even position
                int diffSumIdx = (sum[indexesOdd[idx]][1] - sum[indexesOdd[idx]][0]) % 11;
                diffSumIdx = (diffSumIdx <= 0 ? -diffSumIdx : 11 - diffSumIdx);
                For(k, 0, 11){
                    dp4[i][j][k] += (ll)(n / 2 - j + 1) * dp4[i][j - 1][diffSumIdx] % mod;
                    if (dp4[i][j][k] >= mod){
                        dp4[i][j][k] -= mod;
                    }
                    diffSumIdx++; if (diffSumIdx == 11) diffSumIdx = 0;
                }
            }
        }
    }
    int diffSumIdxEven = 0;
    ForE(i, 1, n){
        if (!(len[i] & 1)){
            diffSumIdxEven += sum[i][0] - sum[i][1];
        }
    }
    diffSumIdxEven %= 11;
    if (!(sumOdd & 1)){
        diffSumIdxEven = (diffSumIdxEven <= 0 ? -diffSumIdxEven : 11 - diffSumIdxEven);
    }
    int ans = dp4[(sumOdd + 1) / 2][sumOdd / 2][diffSumIdxEven];
    ForE(i, 1, n - sumOdd){
        ans = (ll)ans * i % mod;
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("GIFT11.inp", "r", stdin);
    freopen("GIFT11.out", "w", stdout);
int q; cin >> q; while (q--){
    readTest();
    if (checkTest1()){
        solveTest1();
    }
    else if (checkTest2()){
        solveTest2();
    }
    else if (checkTest3()){
        solveTest3();
    }
    else{
        solveTest4();
    }
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/
