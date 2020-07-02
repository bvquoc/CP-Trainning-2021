#include <bits/stdc++.h>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
} rec[405];

bool isContained(int x, int y, Rectangle r) {
    if (r.x1 <= x && x <= r.x2 && r.y1 <= y && y <= r.y2) {
        return 1;
    }
    return 0;
}

long long sum[805][805];

long long getSum(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m, k, x, y; 
    cin >> n >> m >> k >> x >> y;

    vector<int> px, py;

    px.push_back(1); px.push_back(n + 1);
    py.push_back(1); py.push_back(m + 1);

    for (int i = 1; i <= k; i++) {
        cin >> rec[i].x1 >> rec[i].y1 >> rec[i].x2 >> rec[i].y2;
        px.push_back(rec[i].x1);
        px.push_back(rec[i].x2 + 1);
        
        py.push_back(rec[i].y1);
        py.push_back(rec[i].y2 + 1);
    }

    sort(px.begin(), px.end());
    px.erase(unique(px.begin(), px.end()), px.end());

    sort(py.begin(), py.end());
    py.erase(unique(py.begin(), py.end()), py.end());

    int lx = px.size() - 1;
    int ly = py.size() - 1;

    vector<vector<int>> good(lx + 1, vector<int>(ly + 1));
    
    for (int i = 1; i <= lx; i++) {
        for (int j = 1; j <= ly; j++) {
            int curX = px[i - 1];
            int curY = py[j - 1];

            for (int z = 1; z <= k; z++) {
                if (isContained(curX, curY, rec[z])) {
                    good[i][j] = 1;
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= lx; i++) {
        for (int j = 1; j <= ly; j++) {
            int val = (px[i] - px[i - 1]) * 1ll * (py[j] - py[j - 1]);
            val *= good[i][j];

            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + val - sum[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;

    auto query = [&](int x, int y) {
        if (!x || !y) return 0LL;
        int nx = upper_bound(px.begin(), px.end(), x) - px.begin() - 1;
        int ny = upper_bound(py.begin(), py.end(), y) - py.begin() - 1;
        x++; y++;

        long long res = getSum(1, 1, nx, ny);
        long long topArea = (x - px[nx]) * 1ll * getSum(nx + 1, 1, nx + 1, ny) / (px[nx + 1] - px[nx]);
        long long rightArea = (y - py[ny]) * 1ll * getSum(1, ny + 1, nx, ny + 1) / (py[ny + 1] - py[ny]);
        long long rest = (x - px[nx]) * 1ll * (y - py[ny]) * good[nx + 1][ny + 1];

        return res + topArea + rightArea + rest;
    };

    for (int z = 1; z <= q; z++) {
        int t;
        cin >> t;
        int x1 = max(1, x - t), x2 = min(n, x + t);
        int y1 = max(1, y - t), y2 = min(m, y + t);
        int res = query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
        cout << res << " ";
    }
    return 0;
}