#include <bits/stdc++.h>
#define fname "SOCKS"
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
const int N = 500005;
int n, q;
int branch[N], red_sub2;
bool col[N];
vi G[N];

void subtask1()
{
    int numred = 0;
    REP1(i, n) if(col[i]) ++numred;
    if(numred < 2) cout << 0 << '\n';
    else cout << 1 << '\n';
    while(q--) {
        int u;
        cin >> u;
        if(col[u]) --numred;
        else ++numred;
        col[u] = 1 ^ col[u];
        if(numred < 2) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
}
void DFS_sub2(int u, int par, int id)
{
    branch[u] = id;
    if(col[u]) ++red_sub2;
    for(const int &v : G[u])
        if(v != par)
            DFS_sub2(v, u, id);
}
void subtask2(int root)
{
    vi numred(3, 0);
    int total_red = 0;
    REP0(i, G[root].size()) {
        red_sub2 = 0;
        DFS_sub2(G[root][i], root, i);
        numred[i] = red_sub2;
        if(red_sub2) ++total_red;
    }
    if(numred[0] + numred[1] + numred[2] < 2) cout << 0 << '\n';
    else if(total_red <= 2) cout << 1 << '\n';
    else cout << 2 << '\n';
    while(q--) {
        int u, id;
        cin >> u;
        id = branch[u];
        if(col[u]) {
            --numred[id];
            if(!numred[id]) --total_red;
        }
        else {
            ++numred[id];
            if(numred[id] == 1) ++total_red;
        }
        col[u] = 1 ^ col[u];
        if(numred[0] + numred[1] + numred[2] < 2) cout << 0 << '\n';
        else if(total_red <= 2) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}

int main()
{
	freopen(fname".INP", "r", stdin);
    freopen(fname".OUT", "w", stdout);
    //freopen("input", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    REP1(i, n) cin >> col[i];
    bool sub1 = 1, sub2 = 1;
    int deg3 = 0, node3;
    vi deg(n + 1, 0);
    REP1(i, n - 1) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
        ++deg[u]; ++deg[v];
        if(deg[u] > 2 || deg[v] > 2) {
            sub1 = 0;
            if(deg[u] > 3 || deg[v] > 3) sub2 = 0;
            else {
                if(deg[u] == 3) {
                    ++deg3;
                    node3 = u;
                }
                if(deg[v] == 3) {
                    node3 = v;
                    ++deg3;
                }
            }
        }
    }
    if(deg3 != 1) sub2 = 0;
    if(sub1) subtask1();
    else if(sub2) subtask2(node3);
	return 0;
}
