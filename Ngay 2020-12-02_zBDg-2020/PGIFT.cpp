/* 𝙰𝚞𝚝𝚑𝚘𝚛: 𝙱𝚞𝚒 𝚅𝚒 𝚀𝚞𝚘𝚌 */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define L first
#define W second
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
#define int long long
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

const ll INF = 1e18 + 7;
const int N = 5;

int n = 4;
int result = INF;
ii a[N]; bool mark[N];

struct rect { int x1, y1, x2, y2; };
vector <rect> D;
vector <int> X(1), Y(1);

bool isValid(const rect &A, const rect &B) {
    if (min(A.x2,B.x2) <= max(A.x1,B.x1)) return true;
    if (min(A.y2,B.y2) <= max(A.y1,B.y1)) return true;
    return false;
}

void back_tracking(int i) {
    if (i == 5) {
        int cur = (*max_element(ALL(X))) * (*max_element(ALL(Y)));
        minimize(result, cur);
        return;
    }
    
    FOR(id,1,4) {
        if(mark[id]) continue;
        mark[id] = 1;
        vector <int> X_tmp = X, Y_tmp = Y;
        for(int x: X_tmp) {
            for(int y: Y_tmp) {
                rect cur = {x, y, x+a[id].L, y+a[id].W};
                bool ok = true;
                for(rect H2: D) {
                    if(!isValid(cur,H2)) {
                        ok = false;
                        break;
                    }
                }
                if(!ok) continue;
                D.push_back(cur);
                X.push_back(cur.x2);
                Y.push_back(cur.y2);
                back_tracking(i+1);
                D.pop_back();
                X.pop_back();
                Y.pop_back();
            }
        }
        mark[id] = false;
    }
}

void Try(int i) {
    if (i > n) {
        back_tracking(1);
        return;
    }
    REP(isRotate, 2) {
        if (isRotate) swap(a[i].W, a[i].L);
        Try(i+1);
        if (isRotate) swap(a[i].W, a[i].L);
    }
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("PGIFT.INP","r",stdin);
    freopen("PGIFT.OUT","w",stdout);
    #endif
    FOR(i,1,n) cin >> a[i].L >> a[i].W;
    Try(1);
    cout << result;
    cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}