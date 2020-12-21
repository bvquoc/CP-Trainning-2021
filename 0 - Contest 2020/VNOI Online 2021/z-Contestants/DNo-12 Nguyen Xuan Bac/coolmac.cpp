#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second
const int MAX = 1e5 + 5;

int n, mxA;
pii a[MAX];

int solve_bfs() {
    if (a[0].fi != 0) return -1;

    queue<int> q;
    vector<int> d(n, 0);
    q.push(0);
    d[0] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        int i = a[u].fi, j = a[u].se;
        if (j >= mxA) return d[u];

        for (int v = u + 1; v < n; v++) {
            int x = a[v].fi, y = a[v].se;
            if (x > j) break;
            if (y <= j) continue;

            if (d[v] == 0 || d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("coolmac.inp", "r", stdin);
	freopen("coolmac.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].se >> a[i].fi;
        a[i].fi = 1e5 - a[i].fi;
        a[i].se = 1e5 - a[i].se;
    }
    /* cin >> mxA */ {
        mxA = 1e5;
        int n; cin >> n;
        while (n--) {
            int a; cin >> a;
            mxA = min(mxA, a);
        }
        mxA = 1e5 - mxA;
    }
    sort(a, a + n);

    cout << solve_bfs();

	return 0;
}
