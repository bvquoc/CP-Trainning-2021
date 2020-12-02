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

int n, k;
vector <int> S;
stack <int> tmp;

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("QN.INP","r",stdin);
    freopen("QN.OUT","w",stdout);
    #endif

    cin >> n >> k;

    S.push_back(0);
    S.push_back(1);

    FOR(i, 2, n) {
        for (int x: S) {
            int c = MASK(i-1) ^ x;
            tmp.push(c);
        }
        while (tmp.size()) {
            S.push_back(tmp.top());
            tmp.pop();
        }
    }

    int p; 
    REP(i,S.size()) if (S[i] == k) {
        p = i;
        break;
    }

    FOR(i, p+1, MASK(n) - 1) cout << S[i] << endl;
    REP(i, p) cout << S[i] << endl;

    return 0;
}