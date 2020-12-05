/* Author: Bui Vi Quoc */
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

/*
(\_/)
( •_•)
/ >?? */

const int N = 1003;
int n, k, m;
vector <int> dp[N][N];
string S;

int calc(int i, int del, int mod) {
    int &ans = dp[i][del][mod];
    if (ans) return ans;
    if (i == n) {
        if (del == k && mod == 0) return ans = 1;
        return ans = -1;
    }
    
    ans = -1;
    if (del < k && calc(i + 1, del + 1, mod) == 1) return ans = 1;
    if (calc(i + 1, del, (mod * 10 + S[i] - '0') % m) == 1) return ans = 1;

    return ans;
}

string findLargest() {
    int i = 0, del = 0, mod = 0;
    string res;

    while (res.size() + k < S.size()) {
        int j = i;
        int mx = -1, p = i;
        while (j < n && j - i + del <= k) {
            if (calc(j + 1, del + j - i, (mod * 10 + S[j] - '0') % m) == 1) {
                if (maximize(mx, S[j] - '0')) p = j;
            }
            ++j;
        }
        if (mx == -1 || (mx == 0 && i == 0)) return "-1";
        res += S[p];
        del += p - i; i = p + 1, mod = (mod * 10 + S[p] - '0') % m;
    }

    return (res.empty() ? "-1" : res);
}

string findSmallest() {
    int i = 0, del = 0, mod = 0;
    string res;
    while (res.size() + k < S.size()) {
        int j = i;
        int mn = 10, p = i;
        while (j < n && j - i + del <= k) {
            if (calc(j + 1, del + j - i, (mod * 10 + S[j] - '0') % m) == 1) {
                if ((S[j] != '0' || i != 0) && minimize(mn, S[j] - '0')) p = j;
            }
            ++j;
        }
        if (mn == 10) {
            return "-1";
        }
        res += S[p];
        del += p - i; i = p + 1, mod = (mod * 10 + S[p] - '0') % m;
    }

    return (res.empty() ? "-1" : res);
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("NUMBER.INP","r",stdin);
    freopen("NUMBER.OUT","w",stdout);
    #endif
    cin >> S; n = S.size();
    cin >> k >> m;
    FOR(i,0,n) FOR(j,0,k) dp[i][j].resize(m);
    cout << findSmallest() << endl;
    cout << findLargest();
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}