#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 998244353;
int t, n;
struct Card {
    int evenVal = 0, oddVal = 0, len = 0;
} card[2001];
string s[2001];
//sub1
int p[11];
void sub1 () {
    int ans = 0;
    for (int i = 1; i <= n; ++ i) p[i] = i;
    do {
        int sum = 0, cur = 1;
        for (int i = 1; i <= n; ++ i) {
            if (cur % 2 == 1) sum = (sum + card[p[i]].oddVal) % 11;
            else sum = (sum + card[p[i]].evenVal) % 11;
            cur += card[p[i]].len;
        }
        if (sum == 0) ++ ans;
    }while (next_permutation(p + 1, p + 1 + n));
    cout << ans << '\n';
}

//sub2
bool checkSub2 () {
    for (int i = 1; i <= n; ++ i) {
        if (s[i].size() % 2 == 1) return false;
    }
    return true;
}
void sub2 () {
    ll sum = 0;
    for (int i = 1; i <= n; ++ i) {
        sum = (sum + card[i].oddVal) % 11;
    }
    if (sum != 0) cout << 0 << '\n';
    else {
        ll ans = 1;
        for (int i = 1; i <= n; ++ i) ans = (ans * (1ll * i)) % mod;
        cout << ans << '\n';
    }
}

//sub3

ll dp[11][2010][1010];

ll calc (int du, int i, int le) {
    if (dp[du][i][le] != -1) {
        return dp[du][i][le];
    }
    if (le == 0) {
        return dp[du][i][le] = calc((du - card[i].evenVal + 11) % 11, i - 1, le) % mod;
    }else {
        return dp[du][i][le] = (calc((du - card[i].oddVal + 11) % 11, i - 1, le - 1)
                              + calc((du - card[i].evenVal + 11) % 11, i - 1, le)) % mod;
    }
}

void sub3 () {
    for (int du = 0; du <= 10; ++ du) {
        for (int i = 1; i <= n; ++ i) {
            for (int le = 0; le <= n; ++ le) {
                dp[du][i][le] = -1;
            }
        }
    }
    int le = (n + 1) / 2;
    dp[0][0][0] = 1;
    ll ans = calc(0, n, le);
    for (int i = 1; i <= le; ++ i) {
        ans = (ans * i) % mod;
    }
    for (int i = 1; i <= n - le; ++ i) {
        ans = (ans * i) % mod;
    }
    cout << ans << '\n';
}

int main () {
    freopen("GIFT11.INP", "r", stdin);
    freopen("GIFT11.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> s[i];
        for (int i = 1; i <= n; ++ i) {
            card[i].oddVal = card[i].evenVal = card[i].len = 0;
            s[i] = '0' + s[i];
            for (int j = 1; j < s[i].size(); ++ j) {
                card[i].len ++;
                if (j % 2 == 1) card[i].oddVal = (card[i].oddVal + int(s[i][j] - '0') + 11) % 11;
                else card[i].oddVal = (card[i].oddVal - int(s[i][j] - '0') + 11) % 11;
            }
            card[i].evenVal =  (- card[i].oddVal + 11 * 11) % 11;
        }
        if (n <= 9) {
            sub1();
            continue;
        }

        if (checkSub2()) {
            sub2();
            continue;
        }
        sub3();
    }
    return 0;
}
