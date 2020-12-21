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
#define N (ll)(5e5+5)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, m, k;
string s;

pi pRep[N];

int pre[N];

int cnt = 0;
vi g[N];
int ones[N];
int onesTmp[N];
int num[N];

void sub1() {
    int cnt = 0;
    int l = 0;
    int rl = 0;
    int rr = 0;
    int mx = 0;
    FOR(i, 1, n+1) {
        if (i == n+1 || s[i] == '0') {
            if (cnt > mx) {
                mx = cnt;
                rl = l;
                rr = i-1;
            }
            cnt = 0;
        }
        else cnt++;
    }
    cout << rr - mx + 1 << ' ' << rr << "\n";
}

void sub2() {
    int l = 1;
    int r = 1;
    int use = 0;
    int mx = 0;
    int rl = 0;
    int rr = 0;
    FOR(i, 1, n) {
        pre[i] = pre[i-1];
        if (s[i] == '0') {
            pre[i] += 1;
        }
        //cout << pre[i] << ' ';
    }


    while (r <= n) {
        //cout << l << ' ' << r << "\n";
        //cout << pre[r] << ' ' << pre[l-1] << "\n";
        if (r - l + 1 > mx) {
            mx = r - l + 1;
            rl = l;
            rr = r;
        }
        r++;
        while (pre[r] - pre[l-1] > k) {
            l++;
        }
    }
    cout << rl << ' ' << rr << "\n";
}

void dfs(int u, int p) {
    num[u] = cnt;
    if (s[u] == '1') ones[cnt]++;
    s[u] = '0';
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

void sub3() {
    FOR(i, 1, n) {
        if (!num[i]) {
            ++cnt;
            dfs(i, 0);
        }
    }
    FOR(i, 1, cnt) onesTmp[i] = ones[i];
    //cout << "\n";
    //FOR(i, 1, n)
    int mx = 0;
    int resr = 0;
    FOR(r, 1, n) {
        int l = r;
        int used = k;
        FOR(i, 1, cnt) onesTmp[i] = ones[i];
        for (l; l >= 1; l--) {
            if (onesTmp[num[l]] > 0) {
                onesTmp[num[l]]--;
            }
            else if (used > 0) {
                used--;
            }
            else break;
        }
        //cout << l + 1 << ' ' << r << "\n";
        if (r - l + 1 > mx) {
            //cout << l+1 << ' ' << r << "\n";
            l++;
            mx = r - l + 1;
            resr = r;
        }
    }
    cout << resr - mx + 1 << ' ' << resr << "\n";
}

int main()
{
    auto time = clock();
    FASTCIN
    //DEBUG
    FILE("DECOR")

    cin >> n >> m >> k;
    cin >> s;
    s = '*' + s;
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        pRep[i] = {u, v};
        g[u].PB(v);
        g[v].PB(u);
    }
    if (m == 0 && k == 0) sub1();
    else if (m == 0) sub2();
    else if (n <= 2000) sub3();
    else cout << 1 << ' ' << n << "\n";

    //runTime(5);
    return 0;
}


