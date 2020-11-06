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
const ll limit1 = 2e6 + 5;
const ll limit2 = 1e3 + 5;
//If TLE let's use int instead of ll because it's as slow as your WPM :)))

/*----IMPORTANT THINGS----*/
pii dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
//right down left up rightdown leftdown rightup leftup
pii NON = {-1, -1};
/*------------------------*/

int t;
int miPrime[limit1];
int cnt[limit1];
int numDiv[limit1], sqrNumDiv[limit1];
set <int> cur;

void erathos() {
    for (int i = 2; i * i <= 1e6 + 10; ++i) {
        if (miPrime[i]) continue;

        for (int j = i * i; j <= 1e6 + 10; j += i) {
            if (!miPrime[j]) miPrime[j] = i;
        }
    }

    REP(i, 2, 1e6 + 10) if (!miPrime[i]) miPrime[i] = i;
}

pii cntDivi(int n) {
    int ans1 = 1, ans2 = 1;
    cur.clear();
    int m = n + 1, k = n + 2;
    while (n != 1) {
        cur.ins(miPrime[n]);
        ++cnt[miPrime[n]];
        n /= miPrime[n];
    }

    while (m != 1) {
        cur.ins(miPrime[m]);
        ++cnt[miPrime[m]];
        m /= miPrime[m];
    }

    while (k != 1) {
        cur.ins(miPrime[k]);
        ++cnt[miPrime[k]];
        k /= miPrime[k];
    }

    for (auto it : cur) ans1 *= cnt[it] + 1, ans2 *= cnt[it] * 2 + 1, cnt[it] = 0;
    return {ans1, ans2};
}

void solveProblem() {
    erathos();

    while (t--) {
        int n;
        cin >> n;
        pii cur = cntDivi(n);
        numDiv[n] = cur.fi;
        sqrNumDiv[n] = cur.se;
        int ans = sqrNumDiv[n] / 2 + (sqrNumDiv[n] % 2) - numDiv[n];
        cout << ans << endl;
    }
}

void fastInput() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void readInput() {
    cin >> t;
}

int main() {
    fastInput();
    readInput();
    solveProblem();
}

