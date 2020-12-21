#include <bits/stdc++.h>
#define fname "GIFT11"
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
const int MOD = 998244353, N = 2002;
int n, arr[N];

void subtask1()
{
    //BUG;
    static int idx[N];
    REP1(i, n) idx[i] = i;
    int d, x, odd, even, ans = 0;
    do {
        string s;
        REPB1(i, n) {
            x = arr[idx[i]];
            while(x) {
                d = x % 10;
                x /= 10;
                s.pb(char(d + 48));
            }
        }
        odd = even = 0;
        for(int i = 0; i < s.size(); i += 2)
            even += s[i] - 48;
        for(int i = 1; i < s.size(); i += 2)
            odd += s[i] - 48;
        //bug(odd); bug(even);
        if(abs(odd - even) % 11 == 0) ++ans;
    } while(next_permutation(idx + 1, idx + n + 1));
    cout << ans << '\n';
}
void subtask2()
{
    int odd = 0, even = 0;
    REP1(i, n) {
        int x = arr[i], d, cnt = 0;
        while(x) {
            d = x % 10;
            x /= 10;
            if(cnt & 1) odd += d;
            else even += d;
            ++cnt;
        }
    }
    if(abs(odd - even) % 11 == 0) {
        int ans = 1;
        REP1(i, n) ans = 1LL * ans * i % MOD;
        cout << ans << '\n';
    }
    else cout << 0 << '\n';
}

int main()
{
	freopen(fname".INP", "r", stdin);
    freopen(fname".OUT", "w", stdout);
    //freopen("input", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        REP1(i, n) cin >> arr[i];
        if(n <= 9) subtask1();
        else subtask2();
    }
	return 0;
}
