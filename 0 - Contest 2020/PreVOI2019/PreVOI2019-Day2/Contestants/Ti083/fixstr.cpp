#include <bits/stdc++.h>

using namespace std;

const string TASK = "fixstr";

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()

using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
#define fi first
#define se second

const int MAXN = 1000007, INF = MAXN * 2;

int N, no_queries;

// segment tree

struct Node
{
    int cur_min, lazy;
    Node (int _a = 0, int _b = 0): cur_min(_a), lazy(_b) {}
} st[MAXN << 2];

void push(int root, int lo, int hi)
{
    int lz = st[root].lazy;
    if (lo < hi && lz != 0) {
        st[root << 1].cur_min += lz;
        st[root << 1].lazy += lz;

        st[root << 1 | 1].cur_min += lz;
        st[root << 1 | 1].lazy += lz;
    }
    st[root].lazy = 0;
}

void upd_add(int l, int r, int x, int root = 1, int lo = 0, int hi = N)
{
//    cerr << "upd " << l << ' ' << r << ' ' << x << ' ' << root << ' ' << lo << ' ' << hi << endl;
    if (r < lo || hi < l) return;
    if (l <= lo && hi <= r) {
        st[root].cur_min += x;
        st[root].lazy += x;
        return;
    }
//    cerr << "+   " << l << ' ' << hi << endl;

    push(root, lo, hi);
    int mid = (lo + hi) >> 1;
    upd_add(l, r, x, root << 1, lo, mid);
    upd_add(l, r, x, root << 1 | 1, mid + 1, hi);
    st[root].cur_min = min(st[root << 1].cur_min, st[root << 1 | 1].cur_min);
}

void get_pos(int id, int &cur_sum, int root = 1, int lo = 0, int hi = N)
{
    if (lo == hi) {
        cur_sum += st[root].cur_min;
        return;
    }

    cur_sum += st[root].lazy;
    int mid = (lo + hi) >> 1;
    if (id <= mid) get_pos(id, cur_sum, root << 1, lo, mid);
    else get_pos(id, cur_sum, root << 1 | 1, mid + 1, hi);
}

int get(int l, int r, int &cur_sum, int root = 1, int lo = 0, int hi = N) // get sum[l] + sum[r] - min(sum[l .. r])
{
//        cerr << "get " << l << ' ' << r << " | " << lo << ' ' << hi << endl;
    if (r < lo || hi < l) return INF;

    int mid = (lo + hi) >> 1;

    if (l <= lo && hi <= r) {
        if (l == lo) get_pos(l, cur_sum, root, lo, hi);
        if (r == hi) get_pos(r, cur_sum, root, lo, hi);
        return st[root].cur_min;
    }

    push(root, lo, hi);
    return min(get(l, r, cur_sum, root << 1, lo, mid), get(l, r, cur_sum, root << 1 | 1, mid + 1, hi));
}

// main

string S;
struct Query
{
    int nxt = -1, start = -1, type, i, j, ans;

    void type1(int _i) { type = 1, i = _i; }
    void type2(int _i, int _j) { type = 2, i = _i, j = _j; }
    void type3() { type = 3; }
} Q[MAXN];


void solve(int q)
{
//    cerr << "solve " << q << endl;
    if (Q[q].type == 1) {
        if (S[Q[q].i] == '(') {
//            cerr << "change " << Q[q].i << ": ( --> )" << endl;
            S[Q[q].i] = ')';
            upd_add(Q[q].i, N, -2);
        } else {
//            cerr << "change " << Q[q].i << ": ( --> )" << endl;
            S[Q[q].i] = '(';
            upd_add(Q[q].i, N, +2);
        }
    } else if (Q[q].type == 2) {
//        cerr << "query " << Q[q].i << ' ' << Q[q].j << " ++ " << q << endl;
        int x = 0;
        int min_val = get(Q[q].i - 1, Q[q].j, x);
        Q[q].ans = x - min_val * 2;

//        cerr << x << ' ' << min_val << endl;
//        for (int i = 1; i <= N; ++i) cerr << get(i, i, x) << ' '; cerr << endl;
//        x = 0;
//        get(Q[q].i - 1, Q[q].j, x);
//        cerr << x << ' ';
//        cerr << endl;
    }

    for (int p = Q[q].start; p >= 0; p = Q[p].nxt) {
        solve(p);
    }

    if (Q[q].type == 1) {
        if (S[Q[q].i] == '(') {
//            cerr << "change " << Q[q].i << ": ( --> )" << endl;
            S[Q[q].i] = ')';
            upd_add(Q[q].i, N, -2);
        } else {
//            cerr << "change " << Q[q].i << ": ( --> )" << endl;
            S[Q[q].i] = '(';
            upd_add(Q[q].i, N, +2);
        }
    }
}

void add_edge(int from, int to)
{
//    cerr << from << " --> " << to << endl;
    Q[to].nxt = Q[from].start;
    Q[from].start = to;
}

int main()
{
    freopen((TASK + ".inp").c_str(), "r", stdin);
    freopen((TASK + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> S >> no_queries;
    N = (int) S.size();
    S = "-" + S;

    Q[0].type3();
    for (int q = 1; q <= no_queries; ++q) {
        char type;
        cin >> type;
        if (type == 'U') {
            int k;
            cin >> k;

            add_edge(k - 1, q);
            Q[q].type3();
        } else {
            add_edge(q - 1, q);
            if (type == 'C') {
                int i;
                cin >> i;

                Q[q].type1(i);
            } else {
                int i, j;
                cin >> i >> j;

                Q[q].type2(i, j);
            }
        }
    }


    for (int i = 1; i <= N; ++i) upd_add(i, N, (S[i] == '(' ? 1 : -1));
//    int x;
//    for (int i = 1; i <= N; ++i) cerr << get(i, i, x) << ' '; cerr << endl;
//    for (int i = 1; i <= N; ++i) {
//        x = 0; get_pos(i, x);
//        cerr << x << ' ';
//    }
//    cerr << endl;
//    cerr << "So far, so good" << endl;
//    return 0;
    solve(0);
    for (int q = 1; q <= no_queries; ++q) {
        if (Q[q].type == 2) cout << Q[q].ans << '\n';
    }
}

/*
((()))
10
C 1
Q 2 5
C 5
Q 1 6
U 3
C 4
Q 3 6
U 5
C 1
Q 1 5
*/
