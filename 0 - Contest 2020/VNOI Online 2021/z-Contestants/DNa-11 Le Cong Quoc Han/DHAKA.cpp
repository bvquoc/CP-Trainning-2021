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
    int u, msk;
    ll dist;
};

struct CMP {
    bool operator () (const Data &a, const Data &b) {
        return a.dist > b.dist;
    }
};

int n, m, numType, needType;
int num[limit];
vi type[limit];
vpii g[limit];
ll dist[limit][33];

int onBit(int msk, int k) {
    return msk | (1 << k);
}

void dijkstra() {
    pq <Data, vector <Data>, CMP> heap;

    REP(i, 1, n) REP(j, 0, 32) dist[i][j] = maxN;
    int curMsk = 0;
    for (auto it : type[1]) curMsk = onBit(curMsk, it - 1);
    dist[1][curMsk] = 1;

    heap.push({1, curMsk, 0});

    while (!heap.empty()) {
        int u = heap.top().u;
        int curMsk = heap.top().msk;
        ll curDist = heap.top().dist;
        heap.pop();

        if (curDist > dist[u][curMsk]) continue;

        for (auto ite : g[u]) {
            int v = ite.fi, w = ite.se;
            int nxtMsk = curMsk;
            for (auto it : type[v]) nxtMsk = onBit(nxtMsk, it - 1);

            if (dist[v][nxtMsk] > curDist + w) {
                dist[v][nxtMsk] = curDist + w;
                heap.push({v, nxtMsk, dist[v][nxtMsk]});
            }
        }
    }

    ll ans = maxN;
    FOR(msk, 0, (1 << numType)) if (bp(msk) >= needType) ans = min(ans, dist[n][msk]);

    cout << (ans == maxN ? -1 : ans) << endl;
}

void solveProblem() {
    dijkstra();
}

void fastInput() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void readInput() {
    freopen("DHAKA.inp", "r", stdin);
    freopen("DHAKA.out", "w", stdout);

    cin >> n >> m >> numType >> needType;
    REP(i, 1, n) {
        cin >> num[i];
        REP(j, 1, num[i]) {
            int x; cin >> x;
            type[i].pb(x);
        }
    }

    REP(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
}

int main() {
    fastInput();
    readInput();
    solveProblem();
}

