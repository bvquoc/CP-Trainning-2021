#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 998244353

void solve2() {
    int n; cin >> n;
    int tmp = 0;
    bool isSub2 = true;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        if (s.size() % 2 != 0) { isSub2 = false; continue; }
        for (int i = 0; i < (int)s.size(); i++) {
            if (i & 1) tmp -= s[i] - '0';
            else tmp += s[i] - '0';
        }
    }
    if (!isSub2 || abs(tmp) % 11 != 0) {
        cout << 0 << '\n';
    } else {
        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = (ans * i) % MOD;
        }
        cout << ans << '\n';
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("gift11.inp", "r", stdin);
	freopen("gift11.out", "w", stdout);

    int t; cin >> t;
    while (t--) solve2();

	return 0;
}
