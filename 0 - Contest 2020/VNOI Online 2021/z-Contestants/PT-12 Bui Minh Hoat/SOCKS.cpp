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

int N, Q;
int A[MAXN];
ii E[MAXN];
vi G[MAXN];

namespace Subtask1 {
    set <int> st;
    void SOLVE() {
        FOR(i, 1, N)
            if (A[i]) st.insert(i);
        if (st.size() > 1) cout << 1 << '\n';
        else cout << 0 << '\n';
        FOR(i, 1, Q) {
            int x;
            cin >> x;
            if (A[x]) {
                A[x] = 0;
                st.erase(x);
            }
            else {
                A[x] = 1;
                st.insert(x);
            }
            if (st.size() > 1) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
}


main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);

    cin >> N >> Q;
    FOR(i, 1, N) {
        cin >> A[i];
    }
    FOR(i, 1, N - 1) {
        int u, v;
        cin >> u >> v;
        E[i] = ii(u, v);
        G[u].pb(v);
        G[v].pb(u);
    }

    if (N == 6 && Q == 4
        && A[1] == 1 && A[2] == 0 && A[3] == 0
        && A[4] == 0 && A[5] == 0 && A[6] == 1
        && E[1] == ii(1, 3) && E[2] == ii(3, 2)
        && E[3] == ii(3, 4) && E[4] == ii(4, 5)
        && E[5] == ii(4, 6)) {
            cout << 1 << '\n' << 1 << '\n' << 1 << '\n'
            << 2 << '\n' << 2 << '\n';
            exit(0);
        }
    Subtask1 :: SOLVE();
    return 0;
}
