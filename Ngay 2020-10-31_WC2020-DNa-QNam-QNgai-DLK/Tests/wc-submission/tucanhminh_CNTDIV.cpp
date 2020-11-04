#include <bits/stdc++.h>
#define fname "CNTDIV"
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
const int MAX = 1000002;
int n, minPrime[MAX + 1], expo[MAX + 1];

void prepare()
{
    for(int i = 2; i * i <= MAX; ++i)
        if(!minPrime[i])
            for(int j = i * i; j <= MAX; j += i)
                if(!minPrime[j])
                    minPrime[j] = i;
    FOR(i, 2, MAX) if(!minPrime[i]) minPrime[i] = i;
}
void input()
{
    cin >> n;
}
void solve()
{
    int x = n, d = -1;
    vi factor;
    while(x > 1) {
        if(d != minPrime[x]) {
            d = minPrime[x];
            if(!expo[d]) factor.pb(d);
        }
        ++expo[d];
        x /= d;
    }
    x = n + 1; d = -1;
    while(x > 1) {
        if(d != minPrime[x]) {
            d = minPrime[x];
            if(!expo[d]) factor.pb(d);
        }
        ++expo[d];
        x /= d;
    }
    x = n + 2; d = -1;
    while(x > 1) {
        if(d != minPrime[x]) {
            d = minPrime[x];
            if(!expo[d]) factor.pb(d);
        }
        ++expo[d];
        x /= d;
    }
    int T = 1, TT = 1, f;
    REP0(i, factor.size()) {
        f = factor[i];
        T *= expo[f] + 1;
        TT *= 2 * expo[f] + 1;
        expo[f] = 0;
    }
    cout << TT / 2 - T + 1 << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	prepare();
    int test;
    cin >> test;
    while(test--) {
        input();
        solve();
    }
	return 0;
}
