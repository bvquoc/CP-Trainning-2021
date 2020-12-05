/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, Stack, b) for(int i=(Stack); i<=(b); i++)
#define FORD(i, Stack, b) for(int i=(Stack); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define sz(Stack) (int(Stack.size()))
#define BIT(Stack, i) (((Stack) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(Stack, i) ((Stack) | MASK(i))
#define turnOFF(Stack, i) ((Stack) & (~MASK(i)))
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
#define sqr(x) ((x)*(x))
#define endl '\n'
// #define int long long
using namespace std;

template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

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

bool check(const string &S) {
    int n = sz(S);
    stack <char> Stack;
    REP(i,n) if (S[i] == '(') Stack.push('(');
    else {
        if(!Stack.empty()) Stack.pop();
        else return false;
    }
    return true;
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("BRORDER.INP","r",stdin);
    freopen("BRORDER.OUT","w",stdout);
    #endif
    int T; cin >> T;

    string S; int res;
    while (T--) {
        cin >> S;
        res = 1;
        while (prev_permutation(ALL(S))) if (check(S)) res++;
        Write(res);
        putchar(endl);
    }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}