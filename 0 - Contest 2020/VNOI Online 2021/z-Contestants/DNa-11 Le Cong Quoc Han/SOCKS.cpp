#include <bits/stdc++.h>
#define fi first
#define se second
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i > (b); --i)
#define REPD(i, a, b) for(int i = (a); i >=(b); --i)
#define TR(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define endl '\n'
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ins insert
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define unmap unordered_map
#define pq priority_queue
#define minEle min_element
#define maxEle max_element
#define lb lower_bound //first pos >= val
#define ub upper_bound // first pos > val
#define bp __builtin_popcount
#define debug(a) cout << a << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
typedef pair <int, pii> pip;
typedef pair <ll, ld> pld;
typedef pair <ll, pll> pllp;
typedef pair <pll, ll> ppll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pll> vpll;
typedef vector <pii> vpii;
typedef map <int, int> mii;
typedef map <ll, ll> mll;
typedef string BigNum;

const ll maxN = 1e18;
const ll minN = -1e18;
const int INF = 2e9;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998244353;
const int baseHash = 331;
const int bigNumLength = 5000;
const ld PI = acos(-1);

//Remember limit for IT, etc..., and +1 in limit of any array
const ll limit = 5e5 + 5;
const ll limit1 = 1e6 + 5;
const ll limit2 = 1e3 + 5;
//If TLE let's use int instead of ll because it's as slow as your WPM :)))

/*----IMPORTANT THINGS----*/
pii dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
//right down left up rightdown leftdown rightup leftup
pii NON = {-1, -1};
/*------------------------*/

int n, q;
vi g[limit];
int numRed = 0;
pii col[limit];
int mark[limit];
int depth[limit];
int par[limit];
int root;

void sub1() {
    if (numRed > 1) cout << 1 << endl;
    else cout << 0 << endl;

    while (q--) {
        int x; cin >> x;
        col[x].fi ^= 1;
        numRed += (col[x].fi == 0 ? -1 : 1);
        cout << (numRed > 1 ? 1 : 0) << endl;
    }
}

void dfs(int u, int par, int group) {
    if (group != -1) mark[u] = group;

    int cnt = -1;
    for (auto v : g[u]) {
        if (v != par) {
            ++cnt;
            int nxt = (u == root) ? cnt : group;
            dfs(v, u, nxt);
        }
    }
}

void sub2() {
    root = 0;
    int group[3];
    bool isRoot = false;
    group[0] = group[1] = group[2] = 0;

    REP(i, 1, n) if (g[i].size() == 3) root = i;
    dfs(root, 0, -1);

    REP(i, 1, n) {
        if (i == root) continue;
        if (col[i].fi == 1) ++group[mark[i]];
    }

    isRoot = col[root].fi;
    int sum = (group[0] ? 1 : 0) + (group[1] ? 1 : 0) + (group[2] ? 1 : 0);
    if (sum > 2) cout << 2 << endl;
    else if (sum == 2) cout << 1 << endl;
    else if (sum == 1) {
        int num = group[0] + group[1] + group[2] + isRoot;
        if (num >= 2) cout << 1 << endl;
        else cout << 0 << endl;
    }

    while (q--) {
        int x; cin >> x;
        col[x].fi ^= 1;
        if (x != root) group[mark[x]] += (col[x].fi == 0 ? -1 : 1);

        isRoot = col[root].fi;
        int sum = (group[0] ? 1 : 0) + (group[1] ? 1 : 0) + (group[2] ? 1 : 0);

        if (sum > 2) cout << 2 << endl;
        else if (sum == 2) cout << 1 << endl;
        else if (sum == 1) {
            int num = group[0] + group[1] + group[2] + isRoot;
            if (num >= 2) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}

bool cmp(pii a, pii b) {
    return depth[a.se] > depth[b.se];
}

void dfs1(int u, int parent) {
    depth[u] = depth[parent] + 1;

    for (auto v : g[u]) {
        if (v != parent) {
            par[v] = u;
            dfs1(v, u);
        }
    }
}

void jump(int u) {
    if (u == 0) return;
    ++mark[u];
    jump(par[u]);
}

void sub3() {
    dfs1(1, 0);

    sort(col + 1, col + n + 1, cmp);
    REP(i, 1, n) {
        if (col[i].fi && mark[col[i].se] == 0) jump(col[i].se);
    }

    bool ok = false;
        for (auto it : g[1]) {
            if (mark[it] == mark[1]) {
                ok = true;
                int sum = mark[1] + col[root].fi;
                cout << sum / 2 + (sum % 2) << endl;
            }
        }
    if (!ok) {
        if (mark[1] == 1 && numRed > 1) cout << 1 << endl;
        else if (mark[1] == 1 && numRed == 1) cout << 0 << endl;
        else cout << mark[1] / 2 + (mark[1] % 2) << endl;
    }

    while (q--) {
        int x; cin >> x;
        int choose, root;
        REP(i, 1, n) if (col[i].se == x) choose = i;

        col[choose].fi ^= 1;
        numRed += (col[choose].fi == 0 ? -1 : 1);
//        if (q == 1) REP(i, 1, n) cout << col[i].fi << " " << col[i].se << endl;

        REP(i, 1, n) mark[i] = 0;
        REP(i, 1, n) {
            if (col[i].se == 1) root = i;
            if (col[i].fi && mark[col[i].se] == 0) {
//                if (q == 1) cout << col[i].se << endl;
                jump(col[i].se);
            }
        }

        bool ok = false;
        for (auto it : g[1]) {
            if (mark[it] == mark[1]) {
                ok = true;
                int sum = mark[1] + col[root].fi;
                cout << sum / 2 + (sum % 2) << endl;
            }
        }

        if (ok) continue;

        if (mark[1] == 1 && numRed > 1) cout << 1 << endl;
        else if (mark[1] == 1 && numRed == 1) cout << 0 << endl;
        else cout << mark[1] / 2 + (mark[1] % 2) << endl;
    }
}

void solveProblem() {
    int ans = 0;
    int num = 0;
    REP(i, 1, n) {
        ans = max(ans, (int)g[i].size());
        if (g[i].size() == 3) ++num;
    }

    if (ans <= 2) sub1();
    else if (ans <= 3 && num == 1) sub2();
    else sub3();
}

void fastInput() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void readInput() {
    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);

    cin >> n >> q;
    REP(i, 1, n) {
        cin >> col[i].fi;
        col[i].se = i;
        if (col[i].fi == 1) ++numRed;
    }

    REP(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

int main() {
    fastInput();
    readInput();
    solveProblem();
}

/*
6 5
1 0 0 0 0 1
1 2
1 4
1 5
5 6
2 3
1
3
4
3
1
*/
