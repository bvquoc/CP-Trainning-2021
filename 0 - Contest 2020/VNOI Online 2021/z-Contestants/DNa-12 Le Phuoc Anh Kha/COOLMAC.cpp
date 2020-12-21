#include<bits/stdc++.h>
using namespace std;

#define cntBit __builtin_popcount
const int ROOT = 1e5;

struct Object {
    int a, b;

    bool operator < (const Object &other) const {
        if (a == other.a) return b < other.b;
        else return a < other.a;
    }
};

Object x[100005];

int getBit(int bit, int k) {
    return bit & (1 << k);
}

int main() {
    freopen("COOLMAC.INP", "r", stdin);
    freopen("COOLMAC.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i].a >> x[i].b;
    }

    int m;
    cin >> m;

    int t = ROOT;
    for (int i = 1; i <= m; i++) {
        int val;
        cin >> val;
        t = min(t, val);
    }

    sort(x + 1, x + n + 1);

    if (n <= 10) {
        int res = 1e6;
        for (int bit = 0; bit < (1 << n); bit++) {
            int minT = ROOT, maxT = 0;
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (getBit(bit, i) == 0) continue;
                minT = min(minT, x[i + 1].a);
                if (maxT < x[i + 1].a && maxT > 0) {
                    ok = false;
                }
                else {
                    maxT = max(maxT, x[i + 1].b);
                }
            }

//            cout << minT << ' ' << maxT << endl;
            if (ok && minT <= t && maxT == ROOT) {
                res = min(res, cntBit(bit));
            }
        }

        if (res == 1e6) res = -1;
        cout << res;
    }
    else {
        cout << -1;
    }


    return 0;
}
