#include <bits/stdc++.h>
#define fname "PERMEOW"
#define cerr if(0)cerr
#define bug(x) cerr << (#x) << " = " << (x) << endl
#define bug01(x) cerr << "binary(" << (#x) << ") = " << bitset<16>((x)) << endl
#define BUG cerr << "PASSED AT LINE " << __LINE__ << endl
#define ll long long
#define REP0(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define REP1(i, n) for(int i = 1, _n = (n); i <= _n; ++i)
#define REPB0(i, n) for(int i = (n) - 1; i >= 0; --i)
#define REPB1(i, n) for(int i = (n); i > 0; --i)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORB(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define ARR0(a, n) {cerr << (#a) << ": ["; REP0(i, n) cerr << ' ' << a[i] << ','; cerr << ']' << endl;}
#define ARR1(a, n) {cerr << (#a) << ": ["; REP1(i, n) cerr << ' ' << a[i] << ','; cerr << ']' << endl;}
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define LB lower_bound
#define UB upper_bound
#define X first
#define Y second

using namespace std;
template<typename T, typename V>
void bugp(const pair<T, V> &x) {cerr << '{' << x.X << ", " << x.Y << '}' << endl;}
template<typename T, typename U, typename V>
void bugpp(const pair<T, pair<U, V> > &x) {cerr << '{' << x.X << ", {" << x.Y.X << ", " << x.Y.Y << "}}" << endl;}
template<typename T>
bool maximize(T &x, const T &y) {if(x < y) {x = y; return 1;} return 0;}
template<typename T>
bool minimize(T &x, const T &y) {if(x > y) {x = y; return 1;} return 0;}
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, int> li;
typedef pair<ll, ii> lii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
const int N = 200002, MOD = 1000000007;
int n, A[N], B[N], fen[N];

void update(int pos)
{
    for(int i = pos; i <= n; i += i&-i)
        ++fen[i];
}
int query(int pos)
{
    int ans = 0;
    for(int i = pos; i; i &= i - 1)
        ans += fen[i];
    return ans;
}
void subtask1()
{
    ll ans = 0;
    REPB1(i, n) {
        ans += query(A[i]);
        update(A[i]);
    }
    cout << ans % MOD << '\n';
}
void subtask2()
{
    static int fact[N], dp[N];
    fact[0] = 1;
    REP1(i, n) fact[i] = 1LL * fact[i - 1] * i % MOD;
    dp[n] = 0;
    REPB1(i, n - 1) {
        dp[i] = (1LL * dp[i + 1] * (n - i + 1) + 1LL * fact[n - i] * ((n - i) * (n - i + 1) / 2 % MOD)) % MOD;
    }
    cout << dp[1] << '\n';
}

int main()
{
	freopen(fname".INP", "r", stdin);
    freopen(fname".OUT", "w", stdout);
    //freopen("input", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    bool sub1 = 1;
    REP1(i, n) cin >> A[i];
    REP1(i, n) {
        cin >> B[i];
        if(B[i] != A[i]) sub1 = 0;
    }
    if(sub1) subtask1();
    else subtask2();
	return 0;
}
