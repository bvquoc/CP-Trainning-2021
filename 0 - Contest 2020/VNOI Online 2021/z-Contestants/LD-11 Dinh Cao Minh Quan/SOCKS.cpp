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
const string file = "SOCKS";

int n, q;
int a[siz];
vector <vector <int> > adj_list;

void solve_1() {
    bitset <siz> stt;
    for (int u = 1; u <= n; u++) {
        if (a[u] == 1) {
            stt[u] = 1;
        }
    }

    cout << (stt.count() > 1) << "\n";

    while (q--) {
        int u;
        cin >> u;

        if (stt[u] == 0) {
            stt[u] = 1;
        } else {
            stt[u] = 0;
        }

        cout << (stt.count() > 1) << "\n";

    }
}

void solve_2() {

}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen ((file + ".inp").c_str(), "r", stdin);
    freopen ((file + ".out").c_str(), "w", stdout);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    adj_list.resize(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int max_deg = 0;
    for (int u = 1; u <= n; u++) {
        maximize(max_deg, sz(adj_list[u]));
    }

    if (max_deg <= 2) {
        solve_1();
    } else if (max_deg <= 3) {
        solve_2();
    }

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";

    return 0;
}
