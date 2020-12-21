#include <bits/stdc++.h>
#define task "COOLMAC"
typedef long long int ll;
using namespace std;

const int N = 100010;
int m, n, t;

struct Protect {
    int l, r;
    operator < (const Protect &other) const {
        if (l != other.l) return l < other.l;
        return r < other.r;
    }
} pro[N];

void sub1(void) {
    int res = 1e9;
    for (int mask = 1; mask < (1 << m); ++mask) {
        int preR = t, ok = 1, cnt = 0;
        for (int i = 1; i <= m; ++i) {
            if ((mask >> i-1) & 1) {
                ++cnt;
                if (pro[i].l <= preR) preR = max(preR, pro[i].r);
                else {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok == 1 && preR >= 100000) res = min(res, cnt);
    }
    cout << (res == 1e9 ? -1 : res);
}

int main() {
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> pro[i].l >> pro[i].r;
    cin >> n;
    t = 1e18;
    for (int i = 1; i <= n; ++i){
        int T; cin >> T;
        t = min(t, T);
    }
    sort (pro + 1, pro + m + 1);
    sub1();
    return 0;
}

