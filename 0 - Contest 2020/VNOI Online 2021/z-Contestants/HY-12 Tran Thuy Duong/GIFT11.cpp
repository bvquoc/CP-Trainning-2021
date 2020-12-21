#include <bits/stdc++.h>
#define maxn 2005
#define MOD 998244353
#define task "GIFT11"
#define pii pair<int, int>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const ll MM = 1ll * MOD * MOD;
int n[11], T;
string a[11][maxn];
void Sub1(){
    for (int t=1; t<=T; ++t){
        int m = n[t], ans = 0;
        vector<int> p(m);
        for (int i=0; i<m; ++i) p[i] = i+1;
        do {
            string s = "";
            for (int i=0; i<m; ++i) s += a[t][p[i]];
            int val = 0;
            for (int j=1, i=0; i<s.size(); ++i, j*=-1)
                val += j * (s[i]-'0');
            if (val % 11 == 0) ans++;
        } while (next_permutation(all(p)));
        cout << ans%MOD << "\n";
    }
    exit(0);
}
int p[maxn];
void Sub2(){
    for (int t=1; t<=T; ++t){
        int m = n[t];
        ll sum = 0;
        for (int i=1; i<=m; ++i)
            for (int k=1, j=0; j<a[t][i].size(); ++j, k*=-1)
                sum += k * (a[t][i][j]-'0');
        if (sum % 11 == 0) cout << p[m]; else cout << 0;
        cout << "\n";
    }
    exit(0);
}
int d[maxn], dp[maxn][maxn][11];
void Sub3(){
    for (int t=1; t<=T; ++t){
        int m = n[t], l = (n[t]+1)/2;
        ll sum = 0;
        for (int i=1; i<=m; ++i){
            d[i] = 0;
            for (int k=1, j=0; j<a[t][i].size(); ++j, k*=-1)
                d[i] += k * (a[t][i][j]-'0');
            d[i] %= 11; d[i] = (d[i] + 11) % 11;
            sum += d[i];
        }
        sum %= 11; sum = (sum + 11) % 11;
        int val = 0;
        //for (int i=1; i<=m; ++i) dp[1][i][d[i]] = 1;
        for (int j=1; j<=m; ++j)
            for (int r=0; r<11; ++r)
                dp[1][j][r] = (dp[1][j-1][r] + (r==d[j])) % MOD;
        for (int i=2; i<=l; ++i)
            for (int j=i; j<=m; ++j)
                for (int r=0; r<11; ++r){
                    val = (r+d[j])%11;
                    dp[i][j][val] = (dp[i-1][j-1][r] + dp[i][j-1][val]) % MOD;
                }
        val = sum * 2 % 11;
        int ans = dp[l][m][val];
        //for (int i=1; i<=m; ++i) ans = (ans + dp[l][i][val]) % MOD;
        ans = ans * (p[l] * p[m-l] % MOD) % MOD;
        cout << ans << "\n";
    }
    exit(0);
}
void Solve(){
    Sub1();
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    cin >> T;
    int sum = 0;
    bool check2 = 1, check3 = 1;
    for (int i=1; i<=T; ++i){
        cin >> n[i];
        for (int j=1; j<=n[i]; ++j) {
            cin >> a[i][j];
            check2 &= (a[i][j].size() % 2 == 0);
            check3 &= (a[i][j].size() % 2 == 1);
        }
        sum += n[i];
    }
    if (sum <= 8) Sub1();
    p[0] = 1;
    for (int i=1; i<=sum; ++i) p[i] = p[i-1] * i % MOD;
    if (check2) Sub2();
    if (check3) Sub3();
    Solve();
    return 0;
}
