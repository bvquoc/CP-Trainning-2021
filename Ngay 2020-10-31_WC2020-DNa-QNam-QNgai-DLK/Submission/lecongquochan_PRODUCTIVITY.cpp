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
const ll limit2 = 2e3 + 5;
//If TLE let's use int instead of ll because it's as slow as your WPM :)))

/*----IMPORTANT THINGS----*/
pii dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
//right down left up rightdown leftdown rightup leftup
pii NON = {-1, -1};
/*------------------------*/

int n;
int a[limit2][limit2], isUsed[limit2];
int match[limit2];
vi g[limit2];
set <int> s;

bool dfs(int u, int turn) {
    if (isUsed[u] == turn) return false;
    isUsed[u] = turn;

    for (auto v : g[u]) {
        if (!match[v] || dfs(match[v], turn)) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }

    return false;
}

bool check(int val) {
    REP(i, 1, 2 * n) g[i].clear();
    REP(i, 1, 2 * n) match[i] = 0, isUsed[i] = 0;
    REP(i, 1, n) {
        REP(j, 1, n) {
            if (a[i][j] >= val) {
                g[i].pb(j + n);
                g[j + n].pb(i);
            }
        }
    }

    int ans = 0;
    REP(i, 1, n) if (!match[i]) ans += dfs(i, i);
    if (ans == n) return true;
    return false;
}

void solveProblem() {
    vi v(all(s));
    int l = 0, r = v.size() - 1, ans = 0;

    while (l <= r) {
        int mid = (l + r) >> 1;
        //cout << mid << endl;
        if (check(v[mid])) {
            ans = v[mid];
            l = mid + 1;
        }

        else r = mid - 1;
    }

    cout << ans << endl;
}

void fastInput() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void readInput() {
    cin >> n;
    REP(i, 1, n) {
        REP(j, 1, n) {
            cin >> a[i][j];
            s.ins(a[i][j]);
        }
    }
}

int main() {
    fastInput();
    readInput();
    solveProblem();
}

