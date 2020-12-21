#include <bits/stdc++.h>
#define fname "COOLMAC"
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
const int M = 100001, MAX = 100000;
int m, Max[M][21];
ii segment[M];

void build()
{
    REP1(i, m) Max[i][0] = i;
    for(int j = 1; 1 << j <= m; ++j) {
        for(int i = 1; i + (1 << j) - 1 <= m; ++i) {
            if(segment[Max[i][j - 1]].Y > segment[Max[i + (1 << (j - 1))][j - 1]].Y)
                Max[i][j] = Max[i][j - 1];
            else Max[i][j] = Max[i + (1 << (j - 1))][j - 1];
        }
    }
}
int getMax(int l, int r)
{
    int lg = 32 - __builtin_clz(r - l + 1) - 1;
    if(segment[Max[l][lg]].Y > segment[Max[r - (1 << lg) + 1][lg]].Y)
        return Max[l][lg];
    return Max[r - (1 << lg) + 1][lg];
}

int main()
{
	freopen(fname".INP", "r", stdin);
    freopen(fname".OUT", "w", stdout);
    //freopen("input", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> m;
    REP1(i, m) cin >> segment[i].X >> segment[i].Y;
    int start = MAX, n;
    cin >> n;
    REP1(i, n) {
        int t;
        cin >> t;
        minimize(start, t);
    }
    bug(start);
    sort(segment + 1, segment + m + 1);
    build();
    int ans = 0;
    int Time = 0;
    while(1) {
        if(start > MAX) break;
        ++Time;
        if(Time > 2*m) {
            cout << -1;
            return 0;
        }
        int pos = UB(segment + 1, segment + m + 1, ii(start, MAX)) - segment - 1;
        if(!pos) {
            cout << -1;
            return 0;
        }
        int mxpos = getMax(1, pos);
        if(segment[mxpos].Y < start) {
            cout << -1;
            return 0;
        }
        start = segment[mxpos].Y + 1;
        ++ans;
    }
    cout << ans;
	return 0;
}
