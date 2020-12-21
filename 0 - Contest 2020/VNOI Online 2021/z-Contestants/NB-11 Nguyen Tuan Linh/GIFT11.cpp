#include <bits/stdc++.h>
#define TASK "GIFT11"
#define fast ios::sync_with_stdio(0)
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const ll MOD = 998244353;
const int maxn = 5e3;

int q, n;
ll a[maxn + 5], gt[maxn + 5], h[maxn + 5], f[maxn + 5][50][50];

ll x(ll a)
{
    a %= 11;
    if (a < 0) a += 11;
    return a;
}

void subtask3()
{
    gt[0] = 1;
    for (int i = 1; i <= n; i++) {
        gt[i] = (gt[i - 1] * i) % MOD;
    }
    f[0][0][0] = 1;
    int cnt = (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        int k = 1;
        ll m = a[i];
        h[i] = 0;
        while (m) {
            h[i] += ((m % 10) * k);
            k = -k; m /= 10;
        }
        h[i] = x(h[i]);
        for (int j = 0; j < 11; j++) {
            for (int k = 0; k <= cnt; k++) {
                f[i][j][k] = 0;
            }
        }
        for (int j = 0; j < 11; j++) {
            int u = x(j + h[i]), v = x(j - h[i]);
            for (int k = 0; k <= cnt; k++) {
                f[i][j][k] = (f[i][j][k] + f[i - 1][u][k]) % MOD;
                if (k > 0) f[i][j][k] = (f[i][j][k] + f[i - 1][v][k - 1]) % MOD;
            }
        }
    }
    cout << (((f[n][0][cnt] * gt[cnt]) % MOD) * gt[n - cnt]) % MOD << '\n';
}

void subtask2()
{
    gt[0] = 1;
    for (int i = 1; i <= n; i++) {
        gt[i] = (gt[i - 1] * i) % MOD;
    }
    int cnt = (n + 1) / 2;
    ll u = 0;
    for (int i = 1; i <= n; i++) {
        int k = -1;
        ll m = a[i];
        h[i] = 0;
        while (m) {
            h[i] += ((m % 10) * k);
            k = -k; m /= 10;
        }
        u += h[i];
    }
    if (u % 11 == 0) cout << gt[n] << '\n';
    else cout << "0\n";
}

bool dd[maxn + 5];
ll res;
vector <int> vec;

void backtrack(int pos, int k, ll sum)
{
    if (pos > n) {
        if (sum % 11 == 0) res++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (dd[i]) continue;
        dd[i] = 1;
        ll m = a[i];
        vec.clear();
        while (m) {
            vec.pb(m % 10);
            m /= 10;
        }
        int type = k;
        for (int j = vec.size() - 1; j >= 0; j--) {
            m += (vec[j] * type);
            type = -type;
        }
        backtrack(pos + 1, type, sum + m);
        dd[i] = 0;
    }
}

void subtask1()
{
    res = 0;
    for (int i = 1; i <= n; i++) {
        dd[i] = 0;
    }
    backtrack(1, 1, 0);
    cout << res << '\n';
}

int main()
{
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);

    fast;

    cin >> q;

    while (q--) {
        cin >> n;
        bool ok1 = 1, ok2 = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ll m = a[i];
            ll cnt = 0;
            while (m) {
                cnt++;
                m /= 10;
            }
            if (cnt % 2 == 1) ok1 = 0;
            else ok2 = 0;
        }
        if (ok1 == 1) subtask2();
        else if (ok2 == 1) subtask3();
        else subtask1();
    }

    return 0;
}
