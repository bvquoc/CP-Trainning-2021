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

const int siz = 1e5 + 2;
const int SIZ = 1e6 + 2;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "COOLMAC";

ii a[siz];
int b[siz];
bool vis[siz];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen ((file + ".inp").c_str(), "r", stdin);
    freopen ((file + ".out").c_str(), "w", stdout);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    int m;
    cin >> m;

    int min_tpr = maxx;
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;

        minimize(min_tpr, t);
    }

    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        b[i] = a[i].fi;
        maximize(a[i].se, a[i - 1].se);
    }

    int cur = min_tpr - 1;
    int ans = 0;
    while (true) {
        int i = upper_bound(b + 1, b + n + 1, cur + 1) - b - 1;
        int nxt = a[i].se;
        ans++;

        if (i == 0 || vis[i] == true) {
            ans = -1;
            break;
        }
        vis[i] = true;

        if (nxt == 1e5) {
            break;
        }

        cur = nxt;
    }

    cout << ans << "\n";

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";

    return 0;
}
