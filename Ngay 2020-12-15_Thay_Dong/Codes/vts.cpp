#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int dp[1 << N][10];
vector <pair <int, int>> str[10];

int main() {
    freopen("vts.inp", "r", stdin);
    freopen("vts.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int x = s[0] - '0';
        int y = s.back() - '0';
        str[x].emplace_back(i, y);
        if (x != y)
            str[y].emplace_back(i, x);
        dp[1 << i][x] = 1 << y;
        dp[1 << i][y] = 1 << x;
    }
    int res = 0;
    for (int i = 1; i < (1 << n); i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += i >> j & 1;
        for (int x = 0; x < 10; x++) {
            for (auto p : str[x]) {
                int j, y; tie(j, y) = p;
                if (!(i >> j & 1))
                    dp[i + (1 << j)][y]
                    |= dp[i][x];
            }
            if (dp[i][x] >> x & 1)
                res = max(res, cnt);
        }
    }
    cout << res << '\n';
}