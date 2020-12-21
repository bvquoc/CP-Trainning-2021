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

int n;
int a[limit];
int b[limit];
int f[limit];
int fact[limit];
int BIT[limit];

void update(int x) {
    for (int i = x; i > 0; i -= i & -i) {
        ++BIT[i];
    }
}

int get(int x) {
    int ans = 0;
    for (int i = x; i <= n; i += i & -i)
        ans += BIT[i];

    return ans;
}

void sub1() {
    ll ans = 0;
    REP(i, 1, n) {
        ans += get(a[i]);
        if (ans > MOD) ans -= MOD;
        update(a[i]);
    }

    cout << ans << endl;
}

void sub2() {
    f[1] = 0; fact[0] = 1;
    REP(i, 1, n) fact[i] = (1LL * fact[i - 1] * i) % MOD;

    REP(i, 2, n) {
        f[i] = ((1LL * i * f[i - 1] % MOD) + (1LL * (1LL * i * (i - 1) / 2) % MOD * fact[i - 1] % MOD)) % MOD;
    }

    cout << f[n] << endl;
}

void solveProblem() {
    bool ok1 = true, ok2 = true;
    REP(i, 1, n) {
        if (a[i] != b[i]) ok1 = false;
        if (a[i] != i || b[i] != n - i + 1) ok2 = false;
    }

    if (ok1) sub1();
    else if (ok2) sub2();
    else cout << "DE KHO QUA HMU HMU :'(" << endl;
}

void fastInput() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void readInput() {
    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);

    cin >> n;
    REP(i, 1, n) cin >> a[i];
    REP(i, 1, n) cin >> b[i];
}

int main() {
    fastInput();
    readInput();
    solveProblem();
}

