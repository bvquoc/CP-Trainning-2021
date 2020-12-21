#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e5+5;

int n, m, k;
int a[MAX];
int group[MAX];
int val[MAX];
vector<int> adj[MAX];
bool fre[MAX];

string str;

void solveSub12() {
    int sMax = 0, lMax, rMax;
    str= " " + str;
    int s = 0, l = 1, r;
    for (int i = 1; i <= n; i++) {
        if (str[i] == '0') s++;
        while (s > k) {
            if (str[l] == '0') s--;
            l++;
        }
        if (sMax < i - l + 1) {
            sMax = i - l + 1;
            lMax = l;
            rMax = i;
        }
    }
    if (sMax != 0) cout << lMax << ' ' << rMax;
    else cout << "-1";
}

void loang(int u0) {
    queue<int> q;
    q.push(u0);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        fre[u] = false;
        group[u] = u0;
        if (u != u0) {
            val[u0] += val[u];
            val[u] = 0;
        }

        for (int v : adj[u]) if (fre[v])
            q.push(v);
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("decor.inp", "r", stdin);
	freopen("decor.out", "w", stdout);

    cin >> n >> m >> k;
    cin >> str;
    for (int i = 1; i <= n; i++) {
        char c = str[i-1];
        val[i] = c - '0';
        group[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (m == 0) {
        solveSub12();
        return 0;
    }

    memset(fre, true, sizeof fre);
    for (int i = 1; i <= n; i++) if (fre[i])
        loang(i);

    int sMax = 0, lMax, rMax;
    int s = 0, l = 1, r;
    for (int i = 1; i <= n; i++) {
        if (val[group[i]] > 0) {
            a[i] = 1;
            val[group[i]]--;
        } else s++;
        while (s > k) {
            if (a[l] == 1) {
                a[l] = 0;
                val[group[l]]++;
            } else s--;
            l++;
        }
        if (sMax < i - l + 1) {
            sMax = i - l + 1;
            lMax = l;
            rMax = i;
        }
    }
    if (sMax != 0) cout << lMax << ' ' << rMax;
    else cout << "-1";

	return 0;
}
