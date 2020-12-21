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

int n, m, k;
string s;
int f[limit], sum[limit];
pii edge[limit];
int root[limit], debt[limit];
int numNode[limit], numOn[limit];
bool mark[limit];
int tmp[limit];
pii ans1, ans2;

void sub1() {
    int l = -1, r = -1;
    int ans = 0;

    REP(i, 1, n) {
        f[i] = (s[i - 1] == '0') ? 0 : f[i - 1] + 1;
        if (ans < f[i]) {
            ans = f[i];
            r = i;
        }
    }

    REPD(i, r, 1) {
        if (s[i - 1] == '1') l = i;
        else break;
    }

    if (r == -1) cout << -1 << endl;
    else cout << l << " " << r << endl;
}

void sub2() {
    int ans = 0;
    int posL = -1, posR = -1;

    REP(i, 1, n) sum[i] = sum[i - 1] + s[i - 1] - '0';

    REP(i, 1, n) {
        int l = i, r = n;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if ((mid - i + 1) - (sum[mid] - sum[i - 1]) <= k) {
                if (ans < mid - i + 1) {
                    ans = mid - i + 1;
                    posL = i, posR = mid;
                }

                l = mid + 1;
            }

            else r = mid - 1;
        }
    }

    if (posL == -1) cout << -1 << endl;
    else cout << posL << " " << posR << endl;
}

int findRoot(int u) {
    return (root[u] < 0) ? u : root[u] = findRoot(root[u]);
}

bool mergeRoot(int u, int v) {
    u = findRoot(u);
    v = findRoot(v);

    if (u == v) return false;
    if (root[u] > root[v]) swap(u, v);

    numOn[u] += numOn[v];
    root[u] += root[v];
    root[v] = u;
    return true;
}

bool check(int l, int r) {
    int have = 0;
    REP(i, l, r) ++numNode[findRoot(i)];
    REP(i, l, r) {
        int anc = findRoot(i);
        if (!mark[anc]) {
            mark[anc] = true;
            have += min(numNode[anc], numOn[anc]);
        }

        numNode[anc] = 0;
    }

    REP(i, l, r) mark[findRoot(i)] = false;

    return (r - l + 1 - have <= k);
}

void sub3() {
    memset(root, -1, sizeof(root));
    REP(i, 1, n) numOn[i] = (s[i - 1] == '1');
    REP(i, 1, m) mergeRoot(edge[i].fi, edge[i].se);

    int ans = 0, posL = -1, posR = -1;
    REP(i, 1, n) {
        int l = i, r = n;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(i, mid)) {
                if (ans < mid - i + 1) {
                    ans = mid - i + 1;
                    posL = i, posR = mid;
                }

                l = mid + 1;
            }

            else r = mid - 1;
        }
    }

    if (posL == -1) cout << -1 << endl;
    else cout << posL << " " << posR << endl;
    ans1 = {posL, posR};
}

pair <bool, pii> canDecorate(int len) {
    int l = 1, r = len;
    int totalDebt = 0;
    pair <bool, pii> ans = {false, {-1, -1}};

    REP(i, 1, n) tmp[i] = numOn[i];

    REP(i, l, r) {
        int anc = findRoot(i);
        if (tmp[anc] > 0) --tmp[anc];
        else ++debt[anc], ++totalDebt;
    }

    if (totalDebt <= k) ans = {true, {l, r}};

    while (r < n) {
        int anc = findRoot(l);
        if (debt[anc] > 0) --debt[anc], --totalDebt;
        else ++tmp[anc];
        ++l;

        ++r;
        anc = findRoot(r);
        if (tmp[anc] > 0) --tmp[anc];
        else ++debt[anc], ++totalDebt;

        if (ans.fi == false && totalDebt <= k) ans = {true, {l, r}};
    }

    REP(i, 1, n) debt[i] = 0;

    return ans;
}

void sub4() {
    memset(root, -1, sizeof(root));
    REP(i, 1, n) numOn[i] = (s[i - 1] == '1');
    REP(i, 1, m) mergeRoot(edge[i].fi, edge[i].se);

    int ans = 0, posL = -1, posR = -1;
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;

        pair <bool, pii> res = canDecorate(mid);
        if (res.fi) {
            ans = mid;
            posL = res.se.fi;
            posR = res.se.se;
            l = mid + 1;
        }

        else r = mid - 1;
    }

    if (posL == -1) cout << -1 << endl;
    else cout << posL << " " << posR << endl;
    ans2 = {posL, posR};
}

void solveProblem() {
    if (m == 0 && k == 0) sub1();
    else if (m == 0) sub2();
    else if (n <= 2000) sub3();
    else sub4();
}

void fastInput() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void readInput() {
    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);

    cin >> n >> m >> k;
    cin >> s;
    REP(i, 1, m) {
        int u, v;
        cin >> u >> v;
        edge[i] = {u, v};
    }
}

int main() {
    fastInput();
    readInput();
    solveProblem();
//    gen();
}

