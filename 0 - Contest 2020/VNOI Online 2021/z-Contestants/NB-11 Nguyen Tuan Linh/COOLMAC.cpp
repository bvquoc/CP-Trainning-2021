#include <bits/stdc++.h>
#define TASK "COOLMAC"
#define fast ios::sync_with_stdio(0)
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const ll MOD = 1e9 + 7;
const int maxn = 1e5;

int m, cnt, s, t, n;
pii x[maxn + 5];

int main()
{
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);

    fast;

    cin >> m;

    t = s = 1e9;

    for (int i = 1; i <= m; i++) {
        cin >> x[i].S >> x[i].F;
        if (x[i].F == 1e5) t = min(t, x[i].S);
    }

    if (t == 1e9) {
        cout << -1;
        return 0;
    }

    sort(x + 1, x + 1 + m);

    cin >> n;

    while (n--) {
        int u;
        cin >> u;
        s = min(s, u);
    }

    cnt = 1;

    for (int i = m; i > 0; i--) {
        if (t <= s) break;
        int k = 1e9;
        int j;
        for (j = i - 1; j > 0; j--) {
            if (x[j].F < t) break;
            k = min(k, x[j].S);
        }
        if (k == 1e9) {
            cout << -1;
            return 0;
        }
        cnt++;
        t = k;
        i = j + 1;
    }

    cout << cnt;

    return 0;
}
