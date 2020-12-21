#include<bits/stdc++.h>
using namespace std;

vector<int> adj[500005];

void sub1(int n, string &s) {
    int res = 0, l = 0, r = 0;
    int cnt = 0, curL = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt++;
            if (curL == 0) curL = i + 1;
        }
        else {
            if (res < cnt) {
                res = cnt;
                l = curL;
            }
            cnt = 0;
            curL = 0;
        }
    }

    if (s[n - 1] == '1') {
        if (res < cnt) {
            res = cnt;
            l = curL;
        }
    }

    if (res == 0) {
        cout << 0;
    }
    else {
        r = l + res  - 1;
        cout << l << ' ' << r;
    }
}

int main() {
    freopen("DECOR.INP", "r", stdin);
    freopen("DECOR.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (m == 0) {
        if (k == 0) {
            sub1(n, s);
        }
        else {
            cout << -1;
        }
    }
    else cout << -1;



    return 0;
}

