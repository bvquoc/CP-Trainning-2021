/* 𝙰𝚞𝚝𝚑𝚘𝚛: 𝙱𝚞𝚒 𝚅𝚒 𝚀𝚞𝚘𝚌 */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define testBit(n, bit) (((n) >> (bit)) & 1LL)
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
#define sqr(x) ((x)*(x))
#define endl '\n'
// #define int long long
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    }
    return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    }
    return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

/*
(\_/)
( •_•)
/ >?? */

const int N = 55, MAX = 128;
const int INF = 1e9 + 7;
int m, n;
char a[N][N];
string s;

int d[MAX][MAX];

void prepare() {
    REP(i,MAX) REP(j,MAX) d[i][j] = INF;
    
    auto dist = [&] (const int &u, const int &v, const int &x, const int &y) {
        return Abs(u - x) + Abs(v - y);
    };

    FOR(u,1,m) FOR(v,1,n) FOR(x,1,m) FOR(y,1,n) {
        int s = a[u][v], t = a[x][y];
        minimize(d[s][t], dist(u,v,x,y));
    }
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("keyboarding.inp","r",stdin);
    freopen("keyboarding.out","w",stdout);
    #endif
    cin >> m >> n;
    FOR(i,1,m) FOR(j,1,n) cin >> a[i][j];
    prepare();

    // cout << m << ' ' << n << endl;
    // FOR(i,1,m) {
    //     FOR(j,1,n) cout << a[i][j];
    //     cout << endl;
    // }

    cin >> s;
    int sz = s.size();
    s += '*';

    int res = d[a[1][1]][s[0]] + 1;
    REP(i,sz) {
        res += d[s[i]][s[i+1]]; // d[s[i]]['*'] + d[a[1][1]][s[i+1]] + 1
    }

    cout << res + sz;
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}