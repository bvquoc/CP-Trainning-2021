#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
#define int         int64_t

using namespace std;

const int N = int(1e5) + 7;
const int oo = int(1e9) + 9;
typedef pair<int, int> pii;

int n, m, a[N], cmd, l, r, k;

struct Sub2 {
    vector<int> t, b, bit2;
    Sub2() {}
    Sub2(int n, int m): n(n), m(m) {t.resize(n + 5, 0); b.resize(n + 5, 0); bit2.resize(n + 5, 0);}
    int n, m;
    void Update(int x, int val) {for(; x < int(t.size()); x += (x & -x)) t[x] += val;}
    void Update2(int x, int val) {for(; x < int(bit2.size()); x += (x & -x)) bit2[x] += val;}
    int Get(int x) {int res = 0; for(; x > 0; x -= (x & -x)) res += t[x]; return res;}
    int Get2(int x) {int res = 0; for(; x > 0; x -= (x & -x)) res += bit2[x]; return res;}
    void FUpdate(int x, int oval, int nval) {
        if(oval < 0) {
            if(nval > 0) Update(x, nval); return;
        } else {
            if(nval < 0) Update(x, -oval);
            else Update(x, nval - oval);
        }
    }
    void Solve() {
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            b[i] = a[i] - a[i - 1];
            FUpdate(i, 0, b[i]);
            Update2(i, a[i]);
            Update2(i + 1, -a[i]);
        }
        for(int i = 1; i <= m; ++i) {
            cin >> cmd >> l >> r;
            if(cmd == 1) {
                cin >> k;
                FUpdate(l, b[l], b[l] + k); b[l] += k;
                FUpdate(r + 1, b[r + 1], b[r + 1] -k); b[r + 1] -= k;
                Update2(l, k); Update2(r + 1, -k);
            } else cout << Get(r) - Get(l) + Get2(l) << '\n';
        }
    }
};

void Solve() {
    cin >> n >> m;
    if(n * m <= int(1e8)) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= m; ++i) {
            cin >> cmd >> l >> r;
            if(cmd == 1) {
               cin >> k;
               for(int j = l; j <= r; ++j) a[j] += k;
            } else {
               int res = a[l];
               for(int j = l + 1; j <= r; ++j) res += max(a[j] - a[j - 1], 0ll);
               cout << res << '\n';
            }
        }
    } else {
        Sub2 irene = Sub2(n, m);
        irene.Solve();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "construct"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    int nTest; cin >> nTest;
    while(nTest --) Solve();
}
