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

/*
(\_/)
( •_•)
/ >?? */

const int MAX = -1;
const int MOD = 1000000007;

string div2(string s) {
    string res;
    res.resize(s.size());
    int carry = 0;
    for (int i = 0; i < s.size(); i++) {
        res[i] = char((carry * 10 + s[i] - '0') / 2 + '0');
        if ((s[i] - '0') & 1) carry = 1;
        else carry = 0;
    }
    int pos = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
            pos = i;
            break;
        }
    }
    return res.substr(pos, res.size());
}

string query_1(string s) {
    string res;
    while (s != "1") {
        int m = s.size() - 1;
        int last = s[m] - '0';
        if (last & 1) {
            s[m]--;
            s = div2(s);
            res.push_back('f');
        } else {
            int ke = 0;
            if (m >= 1)
                ke = s[m - 1] - '0';
            int last2 = ke * 10 + last;
            if (last2 % 4 == 0) {
                s = div2(s);
                s = div2(s);
                res.push_back('g');
            } else {
                string mf = "NO";
                return mf;
            }
        }
    }
    return res;
}

void multiply(int F[2][2], int M[2][2]) {
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x % MOD;
    F[0][1] = y % MOD;
    F[1][0] = z % MOD;
    F[1][1] = w % MOD;
}

void power(int F[2][2], int n) {
    if (n == 0 || n == 1) return;
    int M[2][2] = { { 1, 1 }, { 1, 0 } };

    power(F, n / 2);
    multiply(F, F);

    if (n & 1) multiply(F, M);
}

int Fib(int n) {
    if (n == 1) return 1;
    int F[2][2] = { { 1, 1 }, { 1, 0 } };
    power(F, n - 1);
    return F[0][0];
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("MATH.INP","r",stdin);
    freopen("MATH.OUT","w",stdout);
    #endif
    
    int T; cin >> T;
    while (T--) {
        int type;
        cin >> type;
        if (type == 1) {
            string s;
            cin >> s;
            cout << query_1(s) << endl;
        } else if (type == 2) {
            int x;
            cin >> x; x++;
            cout << Fib(x) << endl;
        } else {
            int x;
            cin >> x; x++;
            cout << (Fib(x + 2) - 1 + MOD) % MOD << endl;
        }
    }

    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}