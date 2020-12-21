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
const ll limit = 2e5 + 5;
const ll limit1 = 1e6 + 5;
const ll limit2 = 1e3 + 5;
//If TLE let's use int instead of ll because it's as slow as your WPM :)))

/*----IMPORTANT THINGS----*/
pii dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
//right down left up rightdown leftdown rightup leftup
pii NON = {-1, -1};
/*------------------------*/

struct Data {
    int l, r;
};

bool cmp(const Data &a, const Data &b) {
    return (a.r == b.r) ? (a.l < b.l) : (a.r > b.r);
}

struct Node {
    int val, lazy;
};

int n, m;
Data a[limit];
int f[limit];
int minTem = 1e5;
Node node[4 * limit];

void down(int id) {
    int t = node[id].lazy;

    node[id << 1].val = min(node[id << 1].val, t);
    node[id << 1 | 1].val = min(node[id << 1 | 1].val, t);

    node[id << 1].lazy = min(node[id << 1].lazy, t);
    node[id << 1 | 1].lazy = min(node[id << 1 | 1].lazy, t);

    node[id].lazy = INF;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        node[id].val = min(node[id].val, val);
        node[id].lazy = min(node[id].lazy, val);
        return;
    }

    int mid = (l + r) >> 1; down(id);
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);

    node[id].val = min(node[id << 1].val, node[id << 1 | 1].val);
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return INF;
    if (u <= l && r <= v) return node[id].val;

    int mid = (l + r) >> 1; down(id);
    return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

void solveProblem() {
    int lim = 1e5 + 5;
    sort(a + 1, a + n + 1, cmp);
    REP(i, 1, 5e5) node[i] = {INF, INF};

    update(1, 1, lim, 1e5 + 1, 1e5 + 1, 0);
    REP(i, 1, n) {
//        cout << a[i].l << " " << a[i].r << endl;
        int minVal = get(1, 1, lim, a[i].l, a[i].r + 1);
        update(1, 1, lim, a[i].l, a[i].r, minVal + 1);
    }

//    cout << minTem << endl;
    int ans = get(1, 1, lim, 1, minTem);
    cout << (ans == INF ? -1 : ans) << endl;
}

void fastInput() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void readInput() {
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);

    cin >> n;
    REP(i, 1, n) {
        cin >> a[i].l >> a[i].r;
    }

    cin >> m;
    REP(i, 1, m) {
        int x; cin >> x;
        minTem = min(minTem, x);
    }
}

int main() {
    fastInput();
    readInput();
    solveProblem();
}

