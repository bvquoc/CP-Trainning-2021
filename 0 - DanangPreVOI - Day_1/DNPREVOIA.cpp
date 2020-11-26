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
#define int long long
using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}
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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0, 1, 0,-1};

/*
(\_/)
( •_•)
/ >?? */

int n, R[64];
vector<ii> ans;

int pw(int x, unsigned int y) {
    if (y == 0) return 1; 
    int cur = pw(x, (y >> 1));
    if (y % 2 == 0) return cur * cur;
    return x * cur * cur; 
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("A.INP","r",stdin);
    freopen("A.OUT","w",stdout);
    #endif

    R[2] = 1000000000; R[3] = 1000000; R[4] = 31622; R[5] = 3981; R[6] = 1000; R[7] = 372; R[8] = 177; R[9] = 100; R[10] = 63; R[11] = 43; R[12] = 31; R[13] = 24; R[14] = 19; R[15] = 15; R[16] = 13; R[17] = 11; R[18] = 10; R[19] = 8; R[20] = 7; R[21] = 7; R[22] = 6; R[23] = 6; R[24] = 5; R[25] = 5; R[26] = 4; R[27] = 4; R[28] = 5; R[29] = 4; R[30] = 3; R[31] = 3; R[32] = 3; R[33] = 3; R[34] = 3; R[35] = 3; R[36] = 3; R[37] = 3; R[38] = 2; R[39] = 2; R[40] = 2; R[41] = 2; R[42] = 2; R[43] = 2; R[44] = 2; R[45] = 2; R[46] = 2; R[47] = 2; R[48] = 2; R[49] = 2; R[50] = 2; R[51] = 2; R[52] = 2; R[53] = 2; R[54] = 2; R[55] = 2; R[56] = 3; R[57] = 2; R[58] = 2; R[59] = 2; R[60] = 2; 

    signed T; Read(T); while (T--) {
        Read(n); ans.clear();
        
        FOR(i,2,60) {
            int l = 2, r = R[i], mi;
            while (l <= r) {
                mi = (l + r) / 2;
                int cur = pw(mi,i);
                if (cur == n) {
                    if (!(i & 1)) ans.push_back({-mi, i});
                    ans.push_back({mi, i});
                    break;
                }
                if (cur > n) {
                    r = mi - 1;
                } else l = mi + 1;
            }
        }

        ans.push_back({n,1});
        sort(ALL(ans));
        FORE(it, ans) {
            Write(it -> first);
            putchar(' ');
            Write(it -> second);
            putchar(endl);
        }
        putchar(endl);
    }
    return 0;
}