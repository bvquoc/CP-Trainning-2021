#include <bits/stdc++.h>

using namespace std;

const string TASK = "oddcoin";

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define fi first
#define se second

const int MAXV = 199999, INF = 2e9 + 8;
const array<int, 15> VALS = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int min_coins[MAXV];

int main()
{
    freopen((TASK + ".inp").c_str(), "r", stdin);
    freopen((TASK + ".out").c_str(), "w", stdout);
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // prep
    fill_n(min_coins, MAXV, MAXV + 100);
    min_coins[0] = 0;
    FOR(i, 1, MAXV - 1) {
        for (int x : VALS) {
            if (i >= x && min_coins[i - x] + 1 < min_coins[i]) {
                min_coins[i] = min_coins[i - x] + 1;
            }
        }
    }

    int Q;
    scanf("%d", &Q);
    FOR(q, 0, Q - 1) {
        int x, t;
        scanf("%d %d", &x, &t);
        int y = VALS.back();
        assert(y == 50000);
        int ans = INF;
        int d = y / __gcd(x, y);
//        cerr << x << ' ' << y << endl;

        for (ll a = 0; a < y && a * x <= t; ++a) {
            for (ll z = (t - (a * x)) % y; z <= min(t - a * x, MAXV - 1ll); z += y) {
                int a0 = a;
//                cerr << a << ' ' << z << endl;
                assert((t - z - a * x) % y == 0);
                if (x > y) {
//                    cerr << (t - z - a * x) << endl;
                    a0 += (t - z - a * x) / (1ll * x * d) * d;
                    assert((t - z - a0 * x - 1ll * d * x) < 0);
                }
                assert((t - z - a0 * x) % y == 0);
                int b0 = (t - z - a0 * x) / y;
                ans = min(ans, a0 + b0 + min_coins[z]);
            }
        }

        printf("%d\n", ans);
    }
}

/*
4
4700 53
4700 9400
4700 9401
4700 30000
*/
