#include <bits/stdc++.h>

#define N 555

using namespace std;

int n, m, k;
int indexing[N][N], vid[N][N];
int x_1[N * N], y_1[N * N], x_2[N * N], y_2[N * N];
vector<int> edges[N * N];
int mark[N * N];

int main() {
    freopen("domino.inp", "r", stdin);
    freopen("domino.out", "w", stdout);

    cin >> n >> m;
    k = (n * m) / 2;
    for (int i = 1; i <= k; i++) {
        cin >> x_1[i] >> y_1[i] >> x_2[i] >> y_2[i];
        indexing[x_1[i]][y_1[i]] = indexing[x_2[i]][y_2[i]] = i;
        vid[x_1[i]][y_1[i]] = i;
        vid[x_2[i]][y_2[i]] = i + k;
    }
    for (int i = 1; i <= k; i++) {
        if (x_1[i] == x_2[i]) {
            if (y_1[i] > y_2[i]) {
                swap(y_1[i], y_2[i]);
            }
            if (y_1[i] > 1) {
                edges[vid[x_1[i]][y_1[i] - 1]].push_back(vid[x_1[i]][y_2[i]]);
            }
            if (y_2[i] < m) {
                edges[vid[x_1[i]][y_2[i] + 1]].push_back(vid[x_1[i]][y_1[i]]);
            }
        } else {
            if (x_1[i] > x_2[i]) {
                swap(x_1[i], x_2[i]);
            }
            if (x_1[i] > 1) {
                edges[vid[x_1[i] - 1][y_1[i]]].push_back(vid[x_2[i]][y_1[i]]);
            }
            if (x_2[i] < n) {
                edges[vid[x_2[i] + 1][y_1[i]]].push_back(vid[x_1[i]][y_1[i]]);
            }
        }
    }

    queue<int> que;
    que.push(0);
    mark[0] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : edges[u]) {
            if (mark[v] == 0) {
                que.push(v);
                mark[v] = 1;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= k; i++) {
        res += mark[i] | mark[i + k];
    }
    cout << res;
}