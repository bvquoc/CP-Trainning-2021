#include <bits/stdc++.h>
#define maxn 2005
#define maxc 1000000007
#define MOD 1000000007
#define task "gift11"
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
using namespace std;

int n;
pii a[maxn];
ll dp[maxn][maxn][11], p[maxn], C[maxn][maxn];
int d[maxn], f[maxn];
string s[maxn];

pii convert(int x){
    vector<int> v;
    while(x){
        v.pb(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    int res = 0;
    for(int i = 0; i < v.size(); ++ i){
        if(i & 1) res -= v[i];
        else res += v[i];
    }
    return {(res % 11 + 11) % 11, (v.size() % 2)};
}

void Calc(vector<int> v){
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for(int i = 1; i < v.size(); ++ i){
        for(int sum = 0; sum < 11; ++ sum){
            dp[i][0][sum] = dp[i - 1][0][(sum + v[i]) % 11];
            for(int j = 1; j <= i + 1; ++ j){
                (dp[i][j][sum] += dp[i - 1][j][(sum + v[i]) % 11] + dp[i - 1][j - 1][(sum - v[i] + 11) % 11]) % MOD;
            }
        }
    }
    int cnt = (v.size()) / 2;
    for(int i = 0; i < 11; ++ i) {
        f[i] = dp[(v.size() - 1)][cnt][i];
        f[i] = f[i] * (p[cnt] * (p[v.size() - cnt - 1]) % MOD) % MOD;
    }
}

void Calc2(vector<int> v){
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for(int i = 1; i < v.size(); ++ i){
        for(int sum = 0; sum < 11; ++ sum){
            dp[i][0][sum] = dp[i - 1][0][(sum + v[i]) % 11];
            for(int j = 0; j <= i + 1; ++ j){
                (dp[i][j][sum] += dp[i - 1][j][(sum + v[i]) % 11] + dp[i - 1][j - 1][(sum - v[i] + 11) % 11]) % MOD;
            }
        }
    }
    for(int i = 0; i < 11; ++ i) {
        d[i] = 0;
        for(int j = 0; j < v.size(); ++ j) {
            (d[i] += (dp[v.size() - 1][j][i] * ((p[j] * p[v.size() - j - 1] % MOD) % MOD))) %= MOD;
        }
    }
}

void sub1(){
    int res = 0;
    for(int i = 1; i <= n; ++ i){
        (res += a[i].F) %= 11;
    }
    if(res % 11 == 0){
        ll ans = 1;
        for(int i = 1; i <= n; ++ i){
            ans = (ans * i) % MOD;
        }
        cout << ans << '\n';
    }
    else cout << 0 << '\n';
}

bool check(string s){
    int res = 0;
    for(int i = 0; i < s.size(); ++ i){
        if(i & 1) res -= (s[i] - '0');
        else res += (s[i] - '0');
    }
    res = (res % 11 + 11) % 11;
    return res == 0;
}

void trau(){
    vector<int> v;
    for(int i = 1; i <= n; ++ i){
        cin >> s[i];
        v.pb(i);
    }
    int ans = 0;
    do{
        string res = "";
        for(int i = 1; i <= n; ++ i) res += s[v[i - 1]];
        if(check(res)) ++ ans;
    } while(next_permutation(v.begin(), v.end()));
    cout << ans << '\n';
}

void Solve(){
    cin >> n;
    p[0] = 1;
    for(int i = 1; i <= n; ++ i) p[i] = (p[i - 1] * i) % MOD;
    if(n <= 8){
        trau();
        return;
    }
    vector<int> v;
    v.pb(0);
    for(int i = 1; i <= n; ++ i) {
        int x;
        cin >> x;
        a[i] = convert(x);
        if(a[i].S == 1) v.pb(a[i].F);
    }
    if(v.size() == 1){
        sub1();
        return;
    }
    Calc(v);
    if(v.size() == n + 1){
        cout << f[0] << '\n';
        return;
    }
    v.clear();
    v.pb(0);
    for(int i = 1; i <= n; ++ i) if(a[i].S == 0){
        v.pb(a[i].F);
    }
    Calc2(v);
    ll ans = 0;
    for(int i = 0; i < 11; ++ i){
        int k = (1ll * f[i] * d[(11 - i) % 11] % MOD);
        k = (1ll * k * C[v.size() - 1][n - (v.size() - 1)]) % MOD;
        ans = (ans + k) % MOD;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int t;
    for(int j = 1;j <= 2000;j++)
        for(int i = 0;i <= j;i++)
        if(i == 0 || i == j) C[i][j] = 1;
        else C[i][j] = C[i][j-1] + C[i-1][j-1];
    cin >> t;
    while(t --){
        Solve();
    }

    return 0;
}
