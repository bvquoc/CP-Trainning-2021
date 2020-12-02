/* 𝙰𝚞𝚝𝚑𝚘𝚛: 𝙱𝚞𝚒 𝚅𝚒 𝚀𝚞𝚘𝚌 */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
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

const int N = 502, K = 200302;
int n, m, k;
vector <vector <int>> a;
bool mark[N][N];
bool flag[K];

struct Domino {
    int x[2], y[2];
} d[K];
struct State {
    int x, y;
};

bool isValid(const int &x, const int &y, const bool &isSPACE) {
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= m) return false;
    if (isSPACE && mark[x][y]) return false;
    return true;
}

void bfs(const State &ST) {
    queue <State> q;
    q.push(ST);

    while (q.size()) {
        int x = q.front().x, y = q.front().y; q.pop();
        if (mark[x][y]) continue;
        mark[x][y] = true;
        
        int x1, y1, x2, y2;
        
        // Case 1: LEFT
        x1 = x; x2 = x; 
        y1 = y - 2; y2 = y1 + 1;
        if (isValid(x1, y1, 0) && isValid(x2, y2, 0) && a[x1][y1] == a[x2][y2] && !flag[a[x1][y1]]) {
            // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
            flag[a[x1][y1]] = true;
            int new_x, new_y;
            new_x = x1; new_y = y1;
            if (isValid(new_x, new_y, 1)) q.push({new_x, new_y});
        }

        // cout << x << ' ' << y << endl;

        // Case 2: RIGHT
        x1 = x; x2 = x; 
        y1 = y + 1; y2 = y1 + 1;
        if (isValid(x1, y1, 0) && isValid(x2, y2, 0) && a[x1][y1] == a[x2][y2] && !flag[a[x1][y1]]) {
            // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
            flag[a[x1][y1]] = true;
            int new_x, new_y;
            new_x = x2; new_y = y2;
            if (isValid(new_x, new_y, 1)) q.push({new_x, new_y});
        }

        // Case 3: TOP
        x1 = x - 2; x2 = x1 + 1;
        y1 = y; y2 = y;
        if (isValid(x1, y1, 0) && isValid(x2, y2, 0) && a[x1][y1] == a[x2][y2] && !flag[a[x1][y1]]) {
            // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
            flag[a[x1][y1]] = true;
            int new_x, new_y;
            new_x = x1; new_y = y1;
            if (isValid(new_x, new_y, 1)) q.push({new_x, new_y});
        }

        // Case 4: BOTTOM
        x1 = x + 1; x2 = x1 + 1;
        y1 = y; y2 = y;
        if (isValid(x1, y1, 0) && isValid(x2, y2, 0) && a[x1][y1] == a[x2][y2] && !flag[a[x1][y1]]) {
            // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
            flag[a[x1][y1]] = true;
            int new_x, new_y;
            new_x = x2; new_y = y2;
            if (isValid(new_x, new_y, 1)) q.push({new_x, new_y});
        }

        // cout << "--------------------------------------\n";
    }
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("DOMINO.INP","r",stdin);
    freopen("DOMINO.OUT","w",stdout);
    #endif
    cin >> n >> m; k = (n * m - 1) / 2;
    a.resize(n, vector <int> (m));
    FOR(i, 1, k) REP(j, 2) {
        cin >> d[i].x[j] >> d[i].y[j];
        d[i].x[j]--; d[i].y[j]--;
        a[d[i].x[j]][d[i].y[j]] = i;
    }

    REP(i, n) REP(j, m) if (!a[i][j]) {
        bfs({i, j});
        break;
    }

    int res = 0;
    FOR(i,1,k) if (flag[i]) res++;
    cout << res;
    
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}