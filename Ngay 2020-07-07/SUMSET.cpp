#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
vector <int> a, b;
set <int> c;

int32_t main(void) {
    FastIO;
    freopen("SUMSET.INP","r",stdin);
    freopen("SUMSET.OUT","w",stdout);
    cin >> n;
    a.resize(n);
    for (int &x:a) cin >> x;
    cin >> m;
    for (int i=1; i<=m; i++) {
        int x; cin >> x;
        c.insert(x);
    }

    for (int e=1; e<=100; e++) {
        bool inB = true;
        for (int x:a) {
            if (!c.count(e+x)) {
                inB = false;
                break;
            }
        }
        if (inB) {
            b.push_back(e);
        }
    }
    for (int x: b) cout << x << ' ';
    return 0;
}