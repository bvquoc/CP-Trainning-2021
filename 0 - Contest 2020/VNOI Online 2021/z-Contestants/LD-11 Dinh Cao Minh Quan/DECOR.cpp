#include <bits/stdc++.h>
/// kitsune
using namespace std;

#define int long long
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define yn(x) ((x) ? "YES" : "NO")

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef array <int, 3> ar3;

template <typename _Tp, typename _Up> bool maximize(_Tp &__a, _Up __b) { if (__a < __b) { __a = __b; return true; } return false; }
template <typename _Tp, typename _Up> bool minimize(_Tp &__a, _Up __b) { if (__a > __b) { __a = __b; return true; } return false; }

const int siz = 5e5 + 2;
const int SIZ = 1e6 + 2;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "DECOR";

int n, m, k;
int a[siz];
ii s[siz];

void solve_1() {
    iii res;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            int j;
            for (j = i + 1; j <= n; j++) {
                if (a[j] == 0) {
                    break;
                }
            }
            j--;

            if (maximize(res.fi, j - i + 1)) {
                res.se = ii(i, j);
            }

            i = j;
        }
    }

    cout << res.se.fi << " " << res.se.se << "\n";
}

void solve_2() {
    iii res;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            int j, h = k;
            for (j = i + 1; j <= n; j++) {
                if (a[j] == 0) {
                    if (h == 0) {
                        break;
                    } else {
                        h--;
                    }
                }
            }
            j--;

            if (maximize(res.fi, j - i + 1)) {
                res.se = ii(i, j);
            }

            i = j;
        }
    }

    cout << res.se.fi << " " << res.se.se << "\n";
}

void solve_3() {
    cout << 1 << " " << n << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen ((file + ".inp").c_str(), "r", stdin);
    freopen ((file + ".out").c_str(), "w", stdout);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;

        a[i] = c - '0';
    }

    for (int i = 1; i <= m; i++) {
        cin >> s[i].fi >> s[i].se;
    }

    if (m == 0 && k == 0) {
        solve_1();
    } else if (m == 0) {
        solve_2();
    } else {
        solve_3();
    }

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";

    return 0;
}
