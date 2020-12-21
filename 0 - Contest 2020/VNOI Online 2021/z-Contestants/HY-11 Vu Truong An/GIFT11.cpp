#include <bits/stdc++.h>
#define Task "GIFT11"
#define MOD 998244353
#define mod11 162008

using namespace std;

const int maxn = 2005;

int n;
string a[maxn];
long long P[maxn];

void Prepare() {
    P[0] = 1;
    for(int i = 1; i < maxn; ++ i) P[i] = P[i - 1] * i % MOD;
}

namespace Sub1 {
    int p[15], ans = 0;

    void Solve() {
        ans = 0;
        for(int i = 1; i <= n; ++ i) p[i] = i;
        do {
            int cnt1 = 0, cnt2 = 0, t = 1;
            for(int i = 1; i <= n; ++ i) {
                for(auto c : a[p[i]]) {
                    if(t % 2) cnt1 += c - '0';
                    else cnt2 += c - '0';
                    t ++;
                }
            }
            if(abs(cnt1 - cnt2) % 11 == 0) ++ ans;
        } while(next_permutation(p + 1, p + n + 1));
        cout << ans << "\n";
    }
}

namespace Sub2 {
    int cnt1 = 0, cnt2 = 0;

    void Solve() {
        for(int i = 1; i <= n; ++ i) {
            for(int j = 0; j < a[i].size(); ++ j) {
                int c = a[i][j] - '0';
                if(j % 2 == 0) cnt1 += c;
                else cnt2 += c;
            }
        }
        if(abs(cnt1 - cnt2) % 11 != 0) cout << 0 << "\n";
        else cout << P[n] << "\n";
    }
}

namespace Sub3 {
    long long dp[maxn][12][maxn];
    // dp[r][j] : den i co j k so khong bi dao va so du la r

    int b[maxn];

    void Solve() {
        for(int i = 1; i <= n; ++ i) {
            int cnt1 = 0, cnt2 = 0;
            for(int j = 0; j < (int) a[i].size(); ++ j) {
                int c = a[i][j] - '0';
                if(j % 2 == 0) cnt1 += c;
                else cnt2 += c;
            }
            b[i] = cnt1 - cnt2;
        }
        int nEv = n / 2, nOd = n - nEv;
        for(int i = 0; i <= n; ++ i)
            for(int j = 0; j < 11; ++ j)
                for(int k = 0; k <= nOd; ++ k) dp[i][j][k] = 0;
        dp[0][0][0] = 1;
        for(int i = 1; i <= n; ++ i) {
            for(int r = 0; r < 11; ++ r) {
                for(int j = 0; j <= nOd; ++ j) {
                    int prer = (r - b[i] + mod11) % 11;
                    if(j) (dp[i][r][j] += dp[i - 1][prer][j - 1]) %= MOD;
                     prer = (r + b[i] + mod11) % 11;
                    (dp[i][r][j] += dp[i - 1][prer][j]) %= MOD;
                }
            }
        }
        long long ans = P[nEv] * P[nOd] % MOD;
        ans = ans * dp[n][0][nOd] % MOD;
        cout << ans << "\n";
    }

}
void Process() {
    cin >> n;
    int sub2 = 1, sub3 = 1;
    for(int i = 1; i <= n; ++ i) {
        cin >> a[i];
        if(a[i].size() % 2) sub2 = 0;
        else sub3 = 0;
    }
    if(n <= 8) {
        Sub1::Solve();
        return;
    }
    if(sub2) {
        Sub2::Solve();
        return;
    }
//    if(sub3) {
        Sub3::Solve();
        return;
//    }
}

int main(){
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    Prepare();
    int test; cin >> test;
    while(test --) {
        Process();
    }
}
