#include <bits/stdc++.h>
#define Task "DECOR"
#define F first
#define S second

using namespace std;

const int maxn = 100005;

int n, m, k;
int a[maxn], s[maxn];
pair<int, int> sw[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++ i) {
        char c; cin >> c;
        a[i] = c - '0';
        s[i] = s[i - 1] + a[i];
    }
    if(s[n] == 0) {
        if(k != 0) cout << 1 << " " << min(k, n);
        else cout << -1;
        return 0;
    }
    for(int i = 1; i <= m; ++ i) cin >> sw[i].F >> sw[i].S;
    if(m == k && k == 0) {
        int ans = -1, dem = 0, l = 2e9, r = 0, posl = 0, posr = 0;
        for(int i = 1; i <= n + 1; ++ i) {
            if(a[i] == 1) dem ++, r = i, l = min(l, i);
            else {
                if(ans < dem) {
                    ans = dem;
                    posl = l, posr = r;
                    dem = 0;
                    l = 2e9;
                    r = 0;
                }
            }
        }
        cout << posl << " " << posr;
        return 0;
    }
    if(m == 0) {
        int l = 0, r = 0, ans = -1, j = 1;
        for(int i = 1; i <= n; ++ i) {
            while(j < i && s[i] - s[j - 1] + k < i - j + 1) {
                ++ j;
            }
            if(ans < i - j + 1) {
                ans = i - j + 1;
                l = j, r = i;
            }
        }
        cout << l << " " << r;
        return 0;
    }
}
