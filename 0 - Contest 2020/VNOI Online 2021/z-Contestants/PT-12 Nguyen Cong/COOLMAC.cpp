#include <bits/stdc++.h>
#define MASK(i) (1LL << (i))
#define BIT(mask, i) (((mask) >> (i)) & 1LL)
using namespace std;

struct Tnode {
    int l, r;
};

int n, m;
Tnode A[100010];
int T[100010];


namespace SUBTRAU {

    void process (void) {
        int Ans = 21;
        for(int mask = 0; mask < MASK(m); mask ++) {
            int Ck = 1;
            for(int i = 1; i <= n; i ++) {
                int ok = 0;
                for(int j = 1; j <= m; j ++) {
                    if(BIT(mask, j - 1)) {
                        if(A[j].l <= T[i] && T[i] <= A[j].r) {
                            ok = 1;
                            break;
                        }
                    }
                }
                if(ok) continue;
                Ck = 0;
                break;
            }
            if(Ck == 1) {
                Ans = min(Ans, (int)__builtin_popcount(mask));
            }
        }
        if(Ans == 21) cout << -1;
        else
            cout << Ans;
    }
}

namespace SUBFULL {

    bool cmp (const Tnode &a, const Tnode &b) {
        return (a.r == b.r) ? (a.l < b.l) : (a.r < b.r);
    }

    const int INF = 1e9 + 7;
    int numNode;
    int Tree[800010];

    void Update(int i, int l, int r, int pos, int val) {
        if (l > r) return;
        if(l == r && l == pos) {
            Tree[i] = min(Tree[i], val);
            return;
        }

        int mid = (l + r )/ 2;
        if(pos <= mid)
            Update(2 * i, l, mid, pos, val);
        else
            Update(2 * i + 1, mid + 1, r, pos, val);

        Tree[i] = min(Tree[2 * i], Tree[2 * i + 1]);
    }

    int Get(int i, int l, int r, int u, int v) {
        if(l > r) return INF;
        if(v < l || r < u) return INF;
        if(u <= l && r <= v) return Tree[i];
        int mid = (l + r) / 2;
        return min(Get(2 * i, l, mid, u, v), Get(2 * i + 1, mid + 1, r , u, v));
    }

    void process (void) {
        if(n == 0) {
            cout << 0;
            exit(0);
        }
        int ok = 0;
        for(int i = 1; i <= m; i ++) {
            A[i].l ++;
            A[i].r ++;
        }
        for(int i = 1; i <= m; i ++) {
            if(A[i].r == 100001) {
                ok = 1;
                break;
            }
        }
        if(ok == 0) {
            cout << -1;
            exit(0);
        }

        int Tmin = 1e5 + 2;
        for(int i = 1; i <= n; i ++) {
            T[i] ++;
            Tmin = min(Tmin, T[i]);
        }
        sort(A + 1, A + 1 + m, cmp);

        memset(Tree, 0x3f, sizeof Tree);
        /// M
        Update(1, 1, 100001, 100001, 0);
        for(int i = m; i >= 1; i --) {
            int tmp = Get(1,1,100001, A[i].l, A[i].r);
            Update(1,1,100001,A[i].l,tmp + 1);
        }
        if(Tmin == 100001)
            cout << 1;
        else {
            int Cur = Get(1, 1, 100001, 1, Tmin);
            if(Cur == INF ) {
                cout << -1;
            } else {
                cout << Cur;
            }
        }
    }
}

main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);

    cin >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> A[i].l >> A[i].r;
    }
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> T[i];
    }

//    if(n <= 10 && m <= 16) SUBTRAU::process();
    SUBFULL::process();
}
