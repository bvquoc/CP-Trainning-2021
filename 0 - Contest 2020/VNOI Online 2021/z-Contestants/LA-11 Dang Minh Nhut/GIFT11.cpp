#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

int n;
vector<vector<ll>> dp[11];
string a[2005];
int idx[2005];
int r1[2005], r2[2005];
bool allEven, allOdd;
const ll MOD = 998244353;

void Input() {
    cin >> n;
    allEven = true, allOdd = true;
    memset(idx, 0, sizeof idx);
    memset(r1, 0, sizeof r1);
    memset(r2, 0, sizeof r2);
    for(int i = 0; i < n; ++i) {
        a[i].clear();
        cin >> a[i];
        allOdd &= a[i].length()%2;
        allEven &= a[i].length()%2 == 0;
        //cout << a[i] << ' ';
    } //cout << "\n";
}

void dotask1() {
    string s;
    ll ans = 0;
    for(int i = 0; i < n; ++i) idx[i] = i;
    while (1) {
        s.clear();
        for(int i = 0; i < n; ++i) s += a[idx[i]];
        int s1 = 0, s2 = 0;
        for(int i = 0; i < s.length(); ++i) {
            if (i%2) s2 += s[i]-'0';
            else s1 += s[i]-'0';
        }
        if (abs(s1-s2)%11 == 0) ans++; ans %= MOD;
        if (!next_permutation(idx, idx+n)) break;
    }
    cout << ans;
}

void dotask2() {
    string s; s.clear();
    for(int i = 0; i < n; ++i) s += a[i];
    int s1 = 0, s2 = 0;
    for(int i = 0; i < s.length(); ++i) {
        if (i%2) s2 += s[i]-'0';
        else s1 += s[i]-'0';
    }
    if (abs(s1-s2)%11 == 0) {
        ll ans = 1;
        for(int i = 1; i <= n;++i) ans = (ans*i)%MOD;
        cout << ans;
    } else cout << 0;
}


ll DP(int i, ll posEven, ll posOdd, int r) { //cout << i << " " << posEven << " " << posOdd << " " << r << "\n";
    ll &res = dp[r][posEven][posOdd];
    if (~res) return res;
    if (i == n) return res = (r == 0);
    res = 0;
    if (posEven)
        res += (posEven*DP(i+1, posEven-1, posOdd, (r + r2[i] - r1[i] + 11) % 11)) % MOD;
    if (posOdd)
        res += (posOdd*DP(i+1, posEven, posOdd-1, (r + r1[i] - r2[i] + 11) % 11)) % MOD;
    res %= MOD;
    return res;
}


void dotask3() {
    for(int i = 0; i < 11; ++i) {
            dp[i].clear();
            dp[i].resize(n+5);
            dp[i].assign(n+5, vector<ll>(n+5, -1));
    }

    for(int i = 0; i < n; ++i) {
        r1[i] = r2[i] = 0;
        for(int j = 0; j < a[i].length(); ++j) {
            if (j%2) r2[i] = (r2[i]+a[i][j]-'0')%11;
            else r1[i] = (r1[i]+a[i][j]-'0')%11;
        }
    }

    cout << DP(0, n/2, n-n/2, 0);
}

void Solve() {
    if (allOdd) dotask3();
    else if (allEven) dotask2();
    else dotask1();
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("GIFT11.inp", "r", stdin);
    freopen("GIFT11.out", "w", stdout);
    int t; cin >> t;
    while (t--) {
        Input(), Solve();
    }
    return 0;
}
