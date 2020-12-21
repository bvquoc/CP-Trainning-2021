#include <bits/stdc++.h>
#define fname "DECOR"
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
const int N = 500005, M = 500005;
int n, k, s = 0, Min[N][21], S[N], idx[N];
bool vis[N];
string str;
vi G[N], ccomp[N];

void build()
{
    REP0(i, n + 1) Min[i][0] = S[i];
    for(int j = 1; 1 << j <= n + 1; ++j) {
        for(int i = 0; i + (1 << j) - 1 <= n; ++i) {
            Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int getMin(int l, int r)
{
    int lg = 32 - __builtin_clz(r - l + 1) - 1;
    return min(Min[l][lg], Min[r - (1 << lg) + 1][lg]);
}
int Find(int l, int r, int val)
{
    if(l == r) return l;
    int mid = l + r >> 1;
    if(getMin(l, mid) <= val) return Find(l, mid, val);
    return Find(mid + 1, r, val);
}
void subtask12()
{
    static int ps[N];
    memset(ps, 0, sizeof ps);
    REP1(i, n) {
        ps[i] = ps[i - 1] + (str[i] == '1');
        S[i] = ps[i] - i;
    }
    build();
    int l, ans = 0;
    REP1(i, n) {
        int pos = Find(0, i, S[i] + k);
        if(maximize(ans, i - pos))
            l = pos + 1;
    }
    if(!ans) cout << -1;
    else cout << l << ' ' << l + ans - 1;
}
void DFS(int u)
{
    vis[u] = 1;
    ccomp[s].pb(u);
    idx[u] = s;
    for(const int &v : G[u])
        if(!vis[v])
            DFS(v);
}
void bruteforce()
{
    REP1(i, n) {
        if(!vis[i]) {
            ++s;
            DFS(i);
        }
    }
    int l, ans = 0;
    REP1(i, n) {
        bug(i);
        FOR(j, i, n) {
            bug(j);
            memset(vis, 0, sizeof(vis[0]) * (n + 1));
            int one = 0, one_out, zero_in;
            FOR(u, i, j) {
                bug(u);
                if(str[u] == '0') {
                    if(vis[u]) continue;
                    zero_in = one_out = 0;
                    for(const int &v : ccomp[idx[u]]) {
                        vis[v] = 1;
                        if(i <= v && v <= j && str[v] == '0') ++zero_in;
                        else if((v < i || v > j) && str[v] == '1') ++one_out;
                    }
                    bug(one_out); bug(zero_in);
                    one += min(zero_in, one_out);
                }
                else ++one;
            }
            bug(one);
            if(one + k >= j - i + 1 && maximize(ans, j - i + 1))
                l = i;
        }
    }
    if(!ans) cout << -1;
    else cout << l << ' ' << l + ans - 1;
}

int main()
{
	freopen(fname".INP", "r", stdin);
    freopen(fname".OUT", "w", stdout);
    //freopen("input", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int m;
    cin >> n >> m >> k >> str;
    str = ' ' + str;
    REP1(i, m) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    if(!m) subtask12();
    else if(n <= 500) bruteforce();
    else cout << -1;
	return 0;
}
