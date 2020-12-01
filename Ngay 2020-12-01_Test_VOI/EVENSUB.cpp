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

const int N = 100005, INF = 1e9 + 7;
int n, a[N];
ll res = 0;

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("EVENSUB.INP","r",stdin);
    freopen("EVENSUB.OUT","w",stdout);
    #endif
    Read(n);
    FOR(i,1,n) Read(a[i]);

    if (n <= 1000) {
        res = 0;
        FOR(l, 1, n) {
            int Min = a[l], Max = a[l];
            FOR(r, l, n) {
                minimize(Min, a[r]);
                maximize(Max, a[r]);
                if ((Max - Min) % 2 == 0) {
                    res++;
                    if (l == r) continue;
                }
            }
        }
        Write(res);
        exit(0);
    }
    
    bool subtask_2 = true;
    /* check subtask 2 */ {
        FOR(i,1,n) {
            if (a[i] > 3 || a[i] < 0) {
                subtask_2 = false;
                break;
            }
        }
    }

    if (subtask_2) {
        vector <int> pos[4];
        FOR(i,1,n) pos[a[i]].emplace_back(i);
        FOR(i,1,3) reverse(ALL(pos[i]));

        auto find = [&](const int i) {
            if (pos[i].empty()) return INF;
            return pos[i].back();
        };

        res = n;
        FOR(i,1,n) {
            while (pos[a[i]].size() && pos[a[i]].back() <= i) pos[a[i]].pop_back();
            
            if (a[i] == 1) {
                int p;
                
                p = find(3);
                if (p < INF) res += (ll) n - p + 1;
                
                int j = i + 1;
                while (j <= n && a[i] == a[j] && j < p) {
                    res++;
                    j++;
                }
                
                continue;
            }

            if (a[i] == 3) {
                int p;
                
                p = find(1);
                if (p < INF) res += (ll) n - p + 1;
                
                int j = i + 1;
                while (j <= n && a[i] == a[j] && j < p) {
                    res++;
                    j++;
                }

                continue;
            }

            if (a[i] == 2) {
                int p = max(find(1), find(3));
                if (p < INF) res += (ll) n - p + 1;

                int j = i+1;
                while (j <= n && a[i] == a[j] && j < p) {
                    res++;
                    j++;
                }

                continue;
            }
        }

        Write(res);
        exit(0);
    }

    res = 0;
    FOR(l, 1, n) {
        int Min = a[l], Max = a[l];
        FOR(r, l, n) {
            minimize(Min, a[r]);
            maximize(Max, a[r]);
            if ((Max - Min) % 2 == 0) {
                res++;
                if (l == r) continue;
            }
        }
    }
    Write(res);

    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}