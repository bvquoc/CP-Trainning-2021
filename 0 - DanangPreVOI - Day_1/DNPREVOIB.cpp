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

const int Q_MAX = 300005;
struct query {
    bool add;
    int t, c;
    query() { 
        add = false; 
        t = c = 0;
    }
    query(int _t, int _c) {
        add = true;
        t = _t;
        c = _c;
    }
};

int q_sz, k;
vector <query> q;
bool mark[Q_MAX];
int val[Q_MAX];

// #define FILE_IO
signed main(void) {
    #ifdef FILE_IO
    freopen("B.INP","r",stdin);
    freopen("B.OUT","w",stdout);
    #endif
    

    auto compress = [&](vector<query> &A) {
        vector <int> a;
        FORE(it, A) a.push_back(it -> c);

        set <int> tmp(ALL(a));
        vector <int> b(ALL(tmp));
        int sz = a.size();
        REP(i,sz) {
            int x = a[i];
            x = lower_bound(b.begin(), b.end(), x) - b.begin();
            A[i].c = x;
        }
    };

    int T;
    { /* Read & compress inp */
        Read(T);
        Read(q_sz); Read(k);    
        string type;
        int t, c;
        REP(i, q_sz) {
            cin >> type;
            if (type == "show") {
                Read(t); Read(c);
                q.push_back(query(t,c));
            } else q.push_back(query());
        }
        compress(q);
    }

    #define SPACE putchar(' ');

    // if (T == 1) { // subtask 1
        REP(i,q_sz) mark[i] = !q[i].add;

        int res;
        vector <int> a;
        REP(i,q_sz) {
            if (!q[i].add) {
                int mx_id = -1;
                FOR(j,0,i) if (!mark[j]) {
                    if (mx_id == -1 || q[mx_id].c < q[j].c) {
                        mx_id = j;
                    }
                }
                if (mx_id > -1) mark[mx_id] = true;
            }
            a.clear();
            FOR(j,0,i) if (!mark[j]) a.emplace_back(q[j].t);

            sort(ALL(a), greater<int>());
            int sz = min((ll) a.size(),k); res = 0;
            REP(j,sz) res += a[j];
            Write(res); SPACE;
            // for (int x: a) cout << x << ' '; cout << endl;
        }
        exit(0);
    // }
    // if (T == 3) { // subtask 3
    //     REP(i,q_sz) val[q[i].c] = q[i].t;

    //     priority_queue <int> heap;
    //     int res = 0, cnt = 0;
    //     REP(i,q_sz) {
    //         // if (q[i].add) {
    //         //     heap.push(q[i].c);
    //         //     mp[q[i].c] = q[i].t;
    //         //     if (cnt < k) {
    //         //         res += q[i].t;
    //         //         mark[q[i].c] = true;
    //         //         val.push(q[i].t);
    //         //         cnt++;
    //         //     }
    //         // } else {
    //         //     int cur = heap.top(); heap.pop();
    //         //     if (mark[cur]) {
    //         //         res -= mp[cur];
    //         //         mp[cur] = 0;
    //         //     }
    //         // }
            
    //         Write(res); SPACE;  
    //     }
    // }
    // cerr << "\nExecution time: " << (double) clock() / 1000.0 << " second(s).";
    return 0;
}