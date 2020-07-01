#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
using namespace std;

const int INF = INT_MAX;
using ii = pair <int,int>;
int m, n, k, res = INF;
vector <vector <int>> a;
vector <ii> robot;
bool sub1_2 = true;

int distance(int X1, int Y1, int X2, int Y2) {
    return max(abs(X1-X2),abs(Y1-Y2));
}

void solve_sub_1_2() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            int cur = 0;
            for (ii x: robot) {
                cur = max(cur, distance(x.fi, x.se, i, j));
            }
            res = min(res, cur);
        }
    }
}

int32_t main(void) {
    FastIO;
    freopen("robot.inp","r",stdin);
    freopen("robot.out","w",stdout);
    cin >> m >> n >> k;
    a.assign(m+2, vector <int> (n+2,0));
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
            if (a[i][j]>0) {
                sub1_2 = false;
            }
            if (a[i][j] == -1) {
                robot.push_back(ii(i,j));
            }
        }
    }

    if (sub1_2) {
        solve_sub_1_2();
    } else {
        res = 0;
    }
    cout << res;
    return 0;
}