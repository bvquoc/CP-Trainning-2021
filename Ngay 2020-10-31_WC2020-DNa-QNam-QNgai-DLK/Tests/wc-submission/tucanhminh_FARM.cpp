#include <bits/stdc++.h>
#define fname "FARM"
#define cerr if(false)cerr
#define bug(x) cerr << (#x) << " = " << (x) << endl
#define ll long long
#define REP0(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define REP1(i, n) for(int i = 1, _n = (n); i <= _n; ++i)
#define REPB0(i, n) for(int i = (n) - 1; i >= 0; --i)
#define REPB1(i, n) for(int i = (n); i > 0; --i)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORB(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define ARR0(a, n) {cerr <<(#a)<< ": ["; REP0(i, n) cerr<< ' ' << a[i] <<','; cerr<<']'<<endl;}
#define ARR1(a, n) {cerr <<(#a)<< ": ["; REP1(i, n) cerr<< ' ' << a[i] <<','; cerr<<']'<<endl;}
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
inline void bugp(const pair<T, V> &x) {cerr << '{' << x.X << ", " << x.Y << '}' << endl;}
template<typename T, typename U, typename V>
inline void bugpp(const pair<T, pair<U, V> > &x) {cerr << '{' << x.X << ", {" << x.Y.X << ", " << x.Y.Y << "}}" << endl;}
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, int> li;
typedef pair<ll, ii> lii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 10001;
int arr[N];

int main()
{
    //freopen(fname".INP", "r", stdin);
    //freopen(fname".OUT", "w", stdout);
    //freopen("input", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, q, p;
    cin >> n >> k >> q >> p;
    int m = q / p, val;
    vvi L(n + 1, vi(m + 1, 0));
    REP1(i, n) {
        bug(i);
        cin >> arr[i];
        REP1(j, m) {
            bug(j);
            L[i][j] = L[i - 1][j];
            val = arr[i] * p;
            if(i > k) val += L[i - k][j - 1];
            L[i][j] = max(L[i][j], val);
            bug(L[i][j]);
        }
    }
    int r = q % p;
    if(!r) {
        cout << L[n][m];
        return 0;
    }
    vvi R(n + 2, vi(m + 1, 0));
    REPB1(i, n) {
        bug(i);
        REP1(j, m) {
            bug(j);
            R[i][j] = R[i + 1][j];
            val = arr[i] * p;
            if(i + k <= n) val += R[i + k][j - 1];
            R[i][j] = max(R[i][j], val);
            bug(R[i][j]);
        }
    }
    int l, rr, ans = L[n][m];
    REP1(i, n) {
        REP0(j, m + 1) {
            if(i > k) l = L[i - k][j];
            else l = 0;
            if(i + k <= n) rr = R[i + k][m - j];
            else rr = 0;
            ans = max(ans, l + rr + r * arr[i]);
        }
    }
    cout << ans;
	return 0;
}
