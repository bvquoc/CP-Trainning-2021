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

const int siz = 2e3 + 2;
const int SIZ = 1e6 + 2;
const int mod = 998422353;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "GIFT11";

string a[siz];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen ((file + ".inp").c_str(), "r", stdin);
    freopen ((file + ".out").c_str(), "w", stdout);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector <int> perm(n);
        iota(all(perm), 1);

        int ans = 0;
        do {
            string s;
            for (int i = 1; i <= n; i++) {
                s += a[perm[i - 1]];
            }

            int sum_odd = 0, sum_even = 0;
            for (int i = 0; i < sz(s); i++) {
                if (i % 2 == 0) {
                    sum_even += (s[i] - '0');
                } else {
                    sum_odd += (s[i] - '0');
                }
            }

            (ans += (abs(sum_odd - sum_even) % 11 == 0)) %= mod;
        } while (next_permutation(all(perm)));

        cout << ans << "\n";
    }

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";

    return 0;
}
