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
#define SPACE putchar(' ');
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
struct data {
    bool add;
    int t, c;
    data() { 
        add = false; 
        t = c = 0;
    }
    data(int _t, int _c) {
        add = true;
        t = _t;
        c = _c;
    }
};

const int INF = 1e9 + 7;
int q_sz, k;
vector <data> q;
int pos[10000007];
int val[Q_MAX];
struct Node {
    ll sumDeli; int cntDish, maxCalo;
    Node() { 
        sumDeli = cntDish = 0; 
        maxCalo = 0;
    }
    Node(int _s, int _v, int _d) {
        sumDeli = _s;
        maxCalo = _v;
        cntDish = _d;
    }
};
struct SegmentTree {
    int n; vector <Node> st;
    void assign(signed sz) {
        n = sz; 
        st.clear();
        st.resize(4 * n + 7);
    }

    SegmentTree() { n = 0; st.clear(); }
    SegmentTree(signed sz) { assign(sz); }

    void merge(int id, int id1, int id2) {
        st[id].maxCalo = max(st[id1].maxCalo, st[id2].maxCalo);
        st[id].cntDish = st[id1].cntDish + st[id2].cntDish;
        st[id].sumDeli = st[id1].sumDeli + st[id2].sumDeli;
    }
    void update(int id, int l, int r, int i, int T, int C) {
        if (i < l || r < i) return;
        if (l == r) {
            st[id].maxCalo = C;
            st[id].sumDeli = T;
            st[id].cntDish = (C != 0);
            return;
        }
        
        int mid = (l+r) >> 1, id1 = (id << 1), id2 = id1 + 1;
        update(id1, l, mid, i, T, C);
        update(id2, mid + 1, r, i, T, C);
        merge(id, id1, id2);
	}

    int res, K;

    void query(int id, int l, int r, int LIM) {
        if (K == 0) return;
        if (st[id].maxCalo < LIM && st[id].cntDish <= K) {
            res += st[id].sumDeli;
            K -= st[id].cntDish;
            return;
        }

        int mid = (l+r) >> 1, id1 = (id << 1), id2 = id1 + 1;
        query(id2, mid + 1, r, LIM);
        query(id1, l, mid, LIM);
    }

    int getAns(int LIM) {
        res = 0; K = k;
        query(1, 1, n, LIM);
        return res;
    }

} ST;

void Brute_force();

#define FILE_IO
signed main(void) {
    #ifdef FILE_IO
    freopen("B.INP","r",stdin);
    freopen("B.OUT","w",stdout);
    #endif

    auto compress = [&](vector<data> &A) {
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
    /* Read & compress inp */ { 
        Read(T);
        Read(q_sz); Read(k);    
        string type;
        int t, c;
        REP(i, q_sz) {
            cin >> type;
            if (type == "show") {
                Read(t); Read(c);
                q.push_back(data(t,c));
            } else q.push_back(data());
        }
        compress(q);
    }

    if (T <= 2) Brute_force();


    int n = 0;
    /* compress q[i].t pos */ {
        vector <int> a;
        REP(i,q_sz) if (q[i].add) a.push_back(q[i].t);
        sort(ALL(a));
        n = a.size();
        int p = 1;
        REP(i,n) pos[a[i]] = p++;
    }

    ST.assign(n);
    priority_queue <int> heap;

    REP(i,q_sz) {
        int mx = INF;
        if (q[i].add) {
            ST.update(1, 1, n, pos[q[i].t], q[i].t, q[i].c);
            heap.push(q[i].c);
            val[q[i].c] = q[i].t;
        } else {
            mx = heap.top(); heap.pop();
            signed p = pos[val[mx]];
            ST.update(1, 1, n, p, 0, 0);
        }
        Write(ST.getAns(mx)); SPACE;
    }
    return 0;
}

void Brute_force() {
    bool mark[q_sz + 2];
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
    }
    exit(0);
}