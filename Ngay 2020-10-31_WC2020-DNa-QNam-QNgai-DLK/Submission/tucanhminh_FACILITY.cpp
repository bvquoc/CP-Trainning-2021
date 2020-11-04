#include <bits/stdc++.h>
#define fname "FACILITY"
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
const int N = 1000001;
int n;
ll dp[N];
struct customer {
    int s, t, r;
    bool operator <(const customer &other) const {
        return t < other.t;
    }
} arr[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int k;
    cin >> n >> k;
    REP1(i, n) {
        cin >> arr[i].s >> arr[i].t >> arr[i].r;
        arr[i].t += arr[i].s + k;
    }
    sort(arr + 1, arr + n + 1);
    int l, r, mid;
    REP1(i, n) {
        l = 0; r = i - 1;
        while(l != r) {
            mid = l + r + 1 >> 1;
            if(arr[mid].t <= arr[i].s) l = mid;
            else r = mid - 1;
        }
        dp[i] = max(dp[i - 1], dp[l] + arr[i].r);
    }
    cout << dp[n];
	return 0;
}
