#include <bits/stdc++.h>
#define fname "SPIRIT"
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

int calc(int a, int b)
{
    int c = (b - a) / 2;
    if((b - a) & 1) ++c;
    return c;
}

int main()
{
    //freopen(fname".INP", "r", stdin);
    //freopen(fname".OUT", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int fi = (a/c + 1) * c;
    int se = (b/c) * c;
    if(se < fi) {
        cout << calc(a, b);
        return 0;
    }
    int num = (se - fi)/c + 1;
    cout << calc(a, fi - 1) + calc(1, c - 1) * (num - 1) + calc(se + 1, b) + num;
	return 0;
}
