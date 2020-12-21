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

const int siz = 2e5 + 2;
const int SIZ = 1e6 + 2;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const int MAXX = 1e18;
const string file = "PERMEOW";

int n;
vector <int> a, b;

void solve_1() {
    int res = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                res++;
            }
        }
    }

    cout << res << "\n";
}

int quick_pow(int x, int n) {
    if (n == 0) {
        return 1;
    }

    int t = quick_pow(x, n / 2);
    (t *= t) %= mod;

    if (n % 2 == 0) {
        return t;
    }
    return ((t * x) % mod);
}

int inv(int x) {
    return quick_pow(x, mod - 2);
}

void solve_2() {
    int fact_n = 1;
    for (int i = 1; i <= n; i++) {
        (fact_n *= i) %= mod;
    }

    int res = (((((fact_n * n) % mod) * (n - 1)) % mod) * inv(4)) % mod;

    cout << res << "\n";
}

int fen[siz];

void pos_update(int pos, int val) {
    for (int i = pos; i > 0; i -= i & (-i)) {
        fen[i] += val;
    }
}

int suf_sum(int pos) {
    int res = 0;
    for (int i = pos; i <= n; i += i & (-i)) {
        res += fen[i];
    }
    return res;
}

void solve_3() {
    int res = 0;
    do {
        fill (fen + 1, fen + n + 1, 0);
        for (int i = 0; i < n; i++) {
            res += suf_sum(a[i]);
            pos_update(a[i], 1);
        }

        if (a == b) {
            break;
        }
    } while (next_permutation(all(a)));

    cout << res << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen ((file + ".inp").c_str(), "r", stdin);
    freopen ((file + ".out").c_str(), "w", stdout);

    cin >> n;

    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }

    b.resize(n);
    for (auto &x : b) {
        cin >> x;
    }

    bool sub_1 = true, sub_2 = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            sub_1 = false;
        }

        if (a[i] != i || b[i] != n - i + 1) {
            sub_2 = false;
        }
    }

    if (sub_1) {
        solve_1();
    } else if (sub_2) {
        solve_2();
    } else {
        solve_3();
    }

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";

    return 0;
}
