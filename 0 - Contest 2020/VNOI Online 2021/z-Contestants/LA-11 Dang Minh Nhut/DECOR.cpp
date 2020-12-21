#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

int n, m, k;
const int N = 5e5+5;
string a;
vector<pair<int, int>> s;

void Input() {
    cin >> n >> m >> k;
    cin >> a;
    for(int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        s.pb(mp(x, y));
    }
}

void Solve() {
    if (m) {
        cout << -1;
        return;
    }
    int j = 0;
    int cnt = 0;
    int L = 0, R = 0;
    for(int i = 0; i < n; ++i) {
        cnt += a[i]-'0';
        while ((i-j+1) - cnt > k) cnt -= a[j++]-'0';
        if (i-j+1 > R-L+1) R = i, L = j;
    }
    cout << L+1 << " " << R+1 << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);
    Input(), Solve();
    return 0;
}
