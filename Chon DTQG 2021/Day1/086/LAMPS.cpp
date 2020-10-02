#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

using ii = pair <int,int>;
using ll = long long;
using ld = long double;

const int N = 3003;
int n, T;
vector <int> ke[N];
bool x[N], ans[N], ok;
vector <bool> a, cur;

void Try(int i) {
    if (ok) return;
    for (int j=0; j<=1; j++) {
        x[i] = j;
        if (i == n) {
            cur = a;
            for (int k=1; k<=n; k++) if (x[k]) {
                cur[k] = !cur[k];
                for (int v: ke[k]) {
                    cur[v] = !cur[v];
                }
            }
            bool check = true;
            for (bool b: cur) {
                if (!b) {
                    check = false;
                    break;
                }
            }
            if (check) {
                ok = true;
                for (int k=1; k<=n; k++) ans[k] = x[k];
            }

        } else Try(i+1);
    }
}
signed main() {
    FastIO;
    freopen("LAMPS.INP","r",stdin);
    freopen("LAMPS.OUT","w",stdout);
    cin >> n >> T;
    for (int i=1; i<=n; i++) {
        int u, v; cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    while (T--) {
        bool b; a.clear(); a.push_back(-1);
        for (int i=1; i<=n; i++) {
            cin >> b;
            a.push_back(b);
        }
        ok = false;
        Try(1);
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        int cnt = 0;
        for (int i=1; i<=n; i++)
            if (ans[i]) cnt++;
        cout << cnt << ' ';
        for (int i=1; i<=n; i++)
            if (ans[i]) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
