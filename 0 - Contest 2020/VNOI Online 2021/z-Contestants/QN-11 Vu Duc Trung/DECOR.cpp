#include <bits/stdc++.h>
#define task "DECOR"
typedef long long int ll;
using namespace std;

const int N = 500010;
int n, m, k;
string s;
vector<int> adj[N];

void sub1(void) {
    int st = -1;
    int res = 0, l = -1, r = -1;
    s = s + '0';
    for (int i = 0; i <= n; ++i) {
        if (st == -1 && s[i] == '1') st = i;
        if (st != -1 && s[i] == '0') {
            if (i - st > res) {
                res = i - st;
                l = st; r = i - 1;
            }
            st = -1;
        }
    }
    if (res == 0) cout << -1;
    else cout << l + 1<< ' ' << r + 1;
}

ll f[N];
void sub2(void) {
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i-1] + (s[i-1] == '0');
    }
    ll res = 0, l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        int id = upper_bound(f + i + 1, f + n + 1, f[i] + k) - f - 1;
        id = min(id, n);
        if (res < id - i) {
            res = id - i;
            l = i + 1; r = id;
        }
    }
    if (res == 0) cout << -1;
    else cout << l << ' ' << r;
}

void sub3(void) {
    cout << rand() % n + 1 << ' ' << rand () % n + 1 ;
}

int main() {
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    cin >> s;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (m == 0 && k == 0) sub1();
    else if (m == 0) sub2();
    else sub3();
    return 0;
}

