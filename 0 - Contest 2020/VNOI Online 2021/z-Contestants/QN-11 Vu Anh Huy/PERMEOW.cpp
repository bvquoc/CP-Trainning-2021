#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
int n, a[200001], b[200001];

ll fen[200001];
void update (int p) {
    for (int i = p; i <= n; i += i & -i) {
        ++ fen[i];
    }
}
ll get (int p) {
    int res = 0;
    for (int i = p; i; i -= i & -i) {
        res += fen[i];
    }
    return res;
}
//sub1
ll ans = 0;
bool checkSub1 () {
    for (int i = 1; i <= n; ++ i)
        if (a[i] != b[i]) return false;
    return true;
}
void sub1 () {
    memset(fen, 0, sizeof(fen));
    for (int i = n; i >= 1; -- i) {
        ans = (ans + get(a[i] - 1)) % mod;
        update(a[i]);
    }
    cout << ans;
    exit(EXIT_SUCCESS);
}

//sub2
bool checkSub2 () {
    for (int i = 1; i <= n; ++ i) {
        if (a[i] != i) return false;
        if (b[i] != n - i + 1) return false;
    }
    return true;
}
ll dp[200001], fact[200001];
void sub2 () {
    dp[0] = 0;
    fact[0] = 1;
    for (int i = 1; i <= n; ++ i) {
        fact[i] = (fact[i - 1] * i) % mod;
        dp[i] = (dp[i - 1] * i + fact[i - 1] * ((i - 1) * i / 2)) % mod;
    }
    cout << dp[n];
    exit(EXIT_SUCCESS);
}

//sub3
void sub3 () {
}
int main () {
    freopen("PERMEOW.INP", "r", stdin);
    freopen("PERMEOW.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++ i) {
        cin >> b[i];
    }

    if (checkSub1()) sub1();
    if (checkSub2()) sub2();
    return 0;
}
