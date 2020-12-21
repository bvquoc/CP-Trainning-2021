/*          _
         __(.)< (cocc)
        \____)
    ~~~~~~~~~~~~~~~~
*/

#include <bits/stdc++.h>

#define FASTCIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define DEBUG freopen("_inp.inp", "r", stdin);
#define FILE(name) freopen(name".inp","r", stdin); freopen(name".out", "w", stdout);
#define runTime(num) cout << "\nTime: " << fixed << setprecision(num) << (double)(clock() - time)/CLOCKS_PER_SEC << "s\n";

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, b, a) for (int i = b; i >= a; i--)
#define PB push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define BIT(x) (1LL << (x))
#define GET(S, x) ((S >> x) & 1LL)

#define INF (int)(1e9+7)
#define LLINF (ll)(1e18+7)
#define N (ll)(1e5+1)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

struct Coat
{
    int l, r;

    bool operator < (const Coat& t) const {
        if (r == t.r) return (r - l + 1 < t.r - t.l + 1);
        return r < t.r;
    }
};
int n, m;
Coat coats[N];
int mnTemp = INF;
int mxTemp = 100000;

bool cmp(const pi &t1, const pi &t2) {
    if (t1.se == t2.se) return t1.fi < t2.fi;
    else return t1.se < t2.se;
}

void sub1() {
    int res = INF;
    FOR(i, 0, BIT(n)-1) {
        vector<pi> range;
        bitset<10> t = i;
        //cout << t << " I \n";
        FOR(j, 0, n-1) if (GET(i, j)) {
        //    cout << j << "\n";
            range.PB({-1, coats[j+1].l});
            range.PB({1, coats[j+1].r});
        }

        int no = (i == 0);
        sort(all(range), cmp);

        //cout << range[0].fi << "\n";
        if (range.size() && range[0].se > mnTemp) continue;
        if (range.size() && range[range.size() - 1].se < mxTemp) continue;

        int cnt = 0;
        for (auto v : range) {
            cnt += v.fi;
            //cout << cnt << ' ' << v.fi << ' ' << v.se << "\n";
            if (cnt == 0 && v.se < mxTemp) {
                    //cout << "?\n";
                no = 1;
                break;
            }
        }
        //cout << no << "\n";
        if (no) continue;
        //cout << t << ' ' << "\n";
        res = min(res, __builtin_popcount(i));
    }
    if (res == INF) cout << -1 << "\n";
    else cout << res << "\n";
}

int dp[N];
void subblah() {
    sort(coats+1, coats+1+n);
    //int cur = 0;
    //dp[n] = 1;
    //FOR(i, 1, n) dp[i] = 1;
    //if (dp[n])
    FOR(i, 1, n) dp[i] = INF;
    FORD(i, n, 1) {
        if (coats[i].r == mxTemp) dp[i] = 1;
        else if (coats[i].r < mxTemp) break;
    }
    FORD(i, n - 1, 1) {
        //cout << coats[i].l << ' ' << coats[i].r << "\n";
        dp[i] = INF;
        FOR(j, i+1, n) {
            if (coats[j].l <= coats[i].r) {
                dp[i] = min(dp[i], dp[j] + 1);
                break;
            }
        }
    }
    if (dp[n] == INF) {
        cout << "-1\n";
        return;
    }
    FOR(i, 1, n) {
        if (coats[i].l > mnTemp) {
            cout << dp[i] + 1 << "\n";
            return;
        }
    }
}

int main()
{
    auto time = clock();
    FASTCIN
    //DEBUG
    FILE("COOLMAC")

    cin >> n;
    FOR(i, 1, n) {
        int l, r;
        cin >> l >> r;
        coats[i] = {l, r};
    }
    cin >> m;
    FOR(i, 1, m) {
        int t;
        cin >> t;
        mnTemp = min(mnTemp, t);
    }
    if (n <= 10 && m <= 16) sub1();
    else subblah();
    //runTime(5);
    return 0;
}


