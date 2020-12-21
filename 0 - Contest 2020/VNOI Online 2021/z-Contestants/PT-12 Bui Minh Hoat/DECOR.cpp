#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORV(v, H) for (auto &v: H)

#define ii pair <int, int>
#define fi first
#define se second
#define ll long long

#define vi vector <int>
#define vii vector <ii>
#define pb push_back

#define reset(f, val) memset(f, val, sizeof(f))

#define MASK(i) (1ll << (i))
#define BIT(mask, i) (((mask) >> (i)) & 1ll)
#define ONBIT(mask, i) ((mask) | (1ll << (i)))
#define OFFBIT(mask, i) ((mask) &~ (1ll << (i)))

const int MAXN = 5e5 + 1005;

struct DATA {
    int a, b;
} A[MAXN];

int N, M, K;
int S[MAXN];

namespace SubtaskTRAU {
    #define left(id) (id << 1)
    #define right(id) (id << 1 | 1)
    #define mid(l, r) ((l + r) >> 1)
    int ST[4 * MAXN];
    struct SegmentTree {
        void build(int id, int l, int r) {
            if (l == r) {
                ST[id] = S[l];
                return;
            }
            int mid = (l + r) / 2;
            build(left(id), l, mid);
            build(right(id), mid + 1, r);
            ST[id] = ST[left(id)] + ST[right(id)];
        }

        int get(int id, int l, int r, int u, int v) {
            if (v < l || r < u) return 0;
            if (u <= l && r <= v) return ST[id];
            int mid = mid(l, r);
            return get(left(id), l, mid, u, v)
                    + get(right(id), mid + 1, r, u, v);
        }
    } IT;

    void SOLVE() {
        int ANS = 0, TRACEL, TRACER;
        IT.build(1, 1, N);
        FOR(i, 1, N) {
            int l = i - 1;
            int r = N + 1;
            while (r - l > 1) {
                int mid = mid(l, r);
                if (IT.get(1, 1, N, i, mid) + K >= (mid - i + 1))
                    l = mid;
                else
                    r = mid;
            }
            if (l - i + 1 > ANS) {
                ANS = l - i + 1;
                TRACEL = i;
                TRACER = l;
            }
        }
        if (ANS <= 0) {
            cout << -1 << '\n';
            return;
        }
        cout << TRACEL << ' ' << TRACER << '\n';
    }
}

namespace SubtaskFULL {
    struct DSU {
        int par[MAXN], k[MAXN];
        void INIT(int N) {
            FOR(i, 0, N) {
                par[i] = -1;
                k[i] = S[i];
            }
        }

        int FIND(int u) {
            return (par[u] < 0 ? u : par[u] = FIND(par[u]));
        }

        bool MERGE(int u, int v) {
            u = FIND(u);
            v = FIND(v);
            if (u == v) return 0;
            if (par[v] < par[u]) swap(u, v);
            par[u] += par[v];
            k[u] += k[v];
            par[v] = u;
            return 1;
        }
    } DSU;

    int cnt[MAXN];

    int check(int mid) {
        int sum = 0;
        FOR(i, 1, N) cnt[i] = 0;

        FOR(i, 1, mid) {
            int u = DSU.FIND(i);
            cnt[u]++;
            sum += (cnt[u] > DSU.k[u]);
        }

        if (sum <= K)
            return 1;

        int l = 1;

        FOR(i, mid + 1, N) {
            int u = DSU.FIND(l);
            ++l;
            sum -= (cnt[u] > DSU.k[u]);
            --cnt[u];

            u = DSU.FIND(i);
            ++cnt[u];
            sum += (cnt[u] > DSU.k[u]);
            if (sum <= K)
                return l;
        }
        return 0;
    }

    void SOLVE() {
        DSU.INIT(N + 5);
        FOR(i, 1, M)
        DSU.MERGE(A[i].a, A[i].b);
        int l = -1, r = N + 1, TRACEl, ok = 0;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int CHECK = check(mid);
            if (CHECK) {
                l = mid;
                TRACEl = CHECK;
                ok = 1;
            } else r = mid;
        }
        if (!ok) {
            cout << -1 << '\n';
            return;
        }

        cout << TRACEl << ' ' << TRACEl + l - 1 << '\n';
    }
}

void PROCESS() {
    if (M == 0) {
        SubtaskTRAU :: SOLVE();
        exit(0);
    }
    SubtaskFULL :: SOLVE();
    exit(0);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);

    cin >> N >> M >> K;
    FOR(i, 1, N) {
        char ch;
        cin >> ch;
        S[i] = ch - '0';
    }
    FOR(i, 1, M) {
        cin >> A[i].a >> A[i].b;
    }

    PROCESS();
//    SubtaskTRAU :: SOLVE();
//    SubtaskFULL :: SOLVE();
    return 0;
}
