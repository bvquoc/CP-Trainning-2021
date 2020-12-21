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
const ll MOD1 = 1e9 + 7;
const ll MOD = 998244353;
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

int t, n;
string s[2005];
int a[2005];
int visit[15];
int ans;
bool ok = false;
int ans1, ans2;

int cal(string s) {
    int ans = 0;
    FOR(i, 0, s.length()) {
        ans += (i % 2 == 0 ? s[i] - '0' : -(s[i] - '0'));
    }

    return ans;
}

void process() {
    string cur = "";
    REP(i, 1, n) {
        cur += s[visit[i]];
    }

    int res = cal(cur);
    if (abs(res) % 11 == 0) {
//        if (!ok) {
//            ok = true;
//            REP(i, 1, n) cout << visit[i] << " "; cout << endl;
//        }
        ++ans;
    }
}

void backtrack(int i) {
    if (i > n) {
        process();
        return;
    }

    REP(j, 1, n) {
        if (visit[j] == 0) {
            visit[j] = i;
            backtrack(i + 1);
            visit[j] = 0;
        }
    }
}

void sub1() {
    REP(i, 1, n) visit[i] = 0;
    ans = 0;
    backtrack(1);
    ans1 = ans;
    cout << ans << endl;
}

void sub2() {
    int ans = 0;
    REP(i, 1, n) {
        ans += a[i];
    }

    if (ans % 11 != 0) {cout << 0 << endl; return;}
    int res = 1;
    REP(i, 1, n) res = (1LL * res * i) % MOD;
    ans2 = res;

    cout << res << endl;
}

void solveProblem() {
    bool ok = true;
    REP(i, 1, n) if ((int)s[i].size() % 2 != 0) ok = false;
    if (ok) sub2();
    else sub1();
}

void fastInput() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void readInput() {
    freopen("GIFT11.inp", "r", stdin);
    freopen("GIFT11.out", "w", stdout);

    cin >> t;
    while (t--) {
        cin >> n;
        REP(i, 1, n) {
            cin >> s[i];
            a[i] = cal(s[i]);
        }

        solveProblem();
    }
}

int main() {
    fastInput();
    readInput();
//    solveProblem();
}

