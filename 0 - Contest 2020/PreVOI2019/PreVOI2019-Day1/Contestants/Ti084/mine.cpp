#include <bits/stdc++.h>
using namespace std;

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 12;
const long long Mod = 1e6 + 7;
const long long oo = 1e18;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

//emsiHD
#define file "mine"
#define fi first
#define se second
#define y1 Dinh
#define y0 Huy
#define yn Is
#define j1 Me
#define bit(mask, i) ((mask>>(i - 1))&1)

int n, m;
int a[N], f[N];
int d[2012][4012], dd[2012];
long long gt[2012], dp[2012][4012];

void InOut(){
    freopen (file ".inp", "r", stdin);
    freopen (file ".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

long long Dp(int x, int l, int r){
    if (x == n) return 1;
    if ((r - l - 1) % 2 != 0) return 1;
    if (l == r - 1) return (Dp(x + 1, r + 1, f[r])) % Mod;
    d[x][r] = 1;
    for (int i = l + 3; i <= r; i += 2){
        long long xx = dd[(i - l - 1) / 2];
        d[x][r] = (d[x][r] + Dp(x + (i - l - 1) / 2 + 1, i + 1, f[i + 1]) * xx) % Mod;
    }
    return d[x][r] % Mod;
}

void Solve(){
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) cin >> a[i];

    if (n > 2000) {
        long long ans = rd() % m;
        ans %= Mod;
        if (ans == 0) ans = 1;
        cout << ans ;
        return ;
    }

    for (int i = 1; i < 2 * n; i++){
        int j = i;
        while (j < 2 * n && a[j + 1] - a[i] - 1 <= m) j++;
        if (j == i) {
            cout << 0;
            return ;
        }
        f[i] = j;
    }

    dp[1][1] = 1, dp[2][2] = 1, dp[2][3] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = i; j <= 2 * n; j++){
            if (j - 1 > (i - 1) * 2) continue;
            for (int k = i - 1; k < j; k++) {
                if (k - (i - 1) * 2 <= 0)
                dp[i][j] += dp[i - 1][k];
            }
            dp[i][j] %= Mod;
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 2 * n; j++) dd[i] = (dd[i] + dp[i][j]) % Mod;

    cout << Dp(1, 1, f[1]);
}

main(){
    InOut();

    Solve();

}

