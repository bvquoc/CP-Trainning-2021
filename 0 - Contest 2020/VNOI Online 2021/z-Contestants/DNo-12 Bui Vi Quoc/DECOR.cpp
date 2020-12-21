/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define sz(a) (int(a.size()))
#define BIT(a, i) (((a) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(a, i) ((a) | MASK(i))
#define turnOFF(a, i) ((a) & (~MASK(i)))
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
#define sqr(x) ((x)*(x))
#define endl '\n'
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

/*
(\_/)
( •_•)
/ >?? */

const int N = 500005;
int n, m, k;
string S;
int psum[N];
ii e[N];

int sum(const int &l, const int &r) {
    return psum[r] - psum[l-1];
}

vector <int> adj[N];

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    #endif
    
    cin >> n >> m >> k;
    cin >> S;
    FOR(i,1,m) {
        int u, v; 
        cin >> u >> v;
        u--; v--;
        e[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (m == 0 && k == 0) {
        int res = 0; ii ans;
        FOR(i,1,n) psum[i] = psum[i-1] + (S[i-1] - '0');
        FOR(l,1,n) {
            int lo = l, hi = n, mi;
            while (lo <= hi) {
                mi = lo + ((hi - lo) >> 1);
                if (sum(l, mi) == mi - l + 1) {
                    if (maximize(res, mi - l + 1)) ans = ii(l, mi);
                    lo = mi + 1;
                } else hi = mi - 1;
            }
        }

        if (res == 0) cout << "-1";
        else cout << ans.first << ' ' << ans.second;
        exit(0);
    }

    if (m == 0) {
        int res = 0; ii ans;
        FOR(i,1,n) psum[i] = psum[i-1] + (S[i-1] - '0');
        FOR(l,1,n) {
            int lo = l, hi = n, mi;
            while (lo <= hi) {
                mi = lo + ((hi - lo) >> 1);
                if (sum(l, mi) + k >= mi - l + 1) {
                    if (maximize(res, mi - l + 1)) ans = ii(l, mi);
                    lo = mi + 1;
                } else hi = mi - 1;
            }
        }

        if (res == 0) cout << "-1";
        else cout << ans.first << ' ' << ans.second;
        exit(0);
    }


    REP(i,n) {
        for (int j: adj[i]) {
            string tmp = S;
            swap(tmp[i], tmp[j]);
            if (S < tmp) S = tmp;
        }
    }

    int res = 0; ii ans;
    FOR(i,1,n) psum[i] = psum[i-1] + (S[i-1] - '0');
    FOR(l,1,n) {
        int lo = l, hi = n, mi;
        while (lo <= hi) {
            mi = lo + ((hi - lo) >> 1);
            if (sum(l, mi) + k >= mi - l + 1) {
                if (maximize(res, mi - l + 1)) ans = ii(l, mi);
                lo = mi + 1;
            } else hi = mi - 1;
        }
    }

    if (res == 0) cout << "-1";
    else cout << ans.first << ' ' << ans.second;

    return 0;
}