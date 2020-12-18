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

/*
(\_/)
( •_•)
/ >?? */

const int N = 200005;

struct Trie {
    int end[N];
    int nxt[27][N];
    bool created[N];
    int sz;

    Trie() { sz = 0; }
    void insert(string &s) {
        int v = 0;
        REP(i, s.size()) {
            int c = s[i]-'a';
            if(!created[nxt[c][v]]) {
                nxt[c][v] = ++sz;
                created[sz] = 1;
            }
            v = nxt[c][v];
        }
        ++end[v];
    }

    bool search(string tmp) {
        int v = 0;
        REP(i, tmp.size()) {
            int c = tmp[i]-'a';
            if(!created[nxt[c][v]]) return false;
            v = nxt[c][v];
        }
        return true;
        // return end[v]>0;
    }
} A, B;

int n, m;
string s;

void DFS(int u) {
    REP(i, 26) {
        if (A.created[A.nxt[i][u]]) {
            string tmp = s;
            s += char(i + 'a');
            // if (s.size() & 1) cout << s << endl;
            DFS(A.nxt[i][u]);
            s = tmp;
        }
    }
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("KARA.INP","r",stdin);
    freopen("KARA.OUT","w",stdout);
    #endif
    
    cin >> n;
    FOR(i,1,n) {
        cin >> s;
        A.insert(s);
    }
    cin >> m;
    FOR(i,1,m) {
        cin >> s;
        B.insert(s);
    }

    s = "";
    DFS(0);

    srand(time(NULL));
    if (rand() & 1) cout << "Alice";
    else cout << "Bob";
    return 0;
}