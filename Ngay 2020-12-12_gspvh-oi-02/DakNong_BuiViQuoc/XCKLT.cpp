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

const int MAX_LEN = 502;
string A, B, C;
int sz_A, sz_B;
string ans = "";

bool x[30];
int n;

bool isSubStr(const string &S, const string &T) {
    int pos = 0;
    REP(i, sz(T)) {
        int p = S.find(T[i], pos);
        if (p == string::npos) return false;
        else pos = p + 1;
    }
    return true;
}

void Try(const int &id) {
    if (id > n) {

        string S = "";
        FOR(i, 1, sz_A) if (x[i]) S += A[i - 1];
        FOR(i, sz_A+1, n) if (x[i]) S += B[i - sz_A - 1];

        bool check = bool(isSubStr(S, A) && isSubStr(S, B) && !isSubStr(S, C));

        if (!check) {
            S = "";
            FOR(i, sz_A+1, n) if (x[i]) S += B[i - sz_A - 1];
            FOR(i, 1, sz_A) if (x[i]) S += A[i - 1];
            check = bool(isSubStr(S, A) && isSubStr(S, B) && !isSubStr(S, C));
        }

        if (check) if (ans.empty() || ans.size() > S.size()) ans = S;
        return;
    }
    REP(j,2) {
        x[id] = j;
        Try(id + 1);
    }
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("XCKLT.INP","r",stdin);
    freopen("XCKLT.OUT","w",stdout);
    #endif
    cin >> A >> B >> C;
    sz_A = A.size();
    sz_B = B.size();

    #define subtask_1_2 (sz_A + sz_B <= 20 && sz(C) <= 10)

    if (subtask_1_2) {
        n = sz_A + sz_B;
        Try(1);
        if (ans.empty()) cout << "TRETRAU";
        else {
            cout << sz(ans) << endl;
            cout << ans;
        }
        exit(0);
    }

    cout << "TRETRAU";

    return 0;
}