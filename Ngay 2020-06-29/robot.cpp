/* http://lqdoj.edu.vn/problem/robot */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
using namespace std;

const int INF = INT_MAX;
const int dx[] = {-1, 1, 0, 0,-1,-1, 1,1}; 
const int dy[] = { 0, 0,-1, 1,-1, 1,-1,1};
using ii = pair <int,int>;
int m, n, k, res = INF;
vector <vector <int>> a;
vector <ii> robot;
vector <vector <int>> d;

bool sub1_2 = true;
int distance(int X1, int Y1, int X2, int Y2) {
    return max(abs(X1-X2),abs(Y1-Y2));
}

priority_queue <ii, vector<ii>, greater<ii>> pq;

bool valid(int X, int Y) {
    if (X<1 || m<X) return false;
    if (Y<1 || n<Y) return false;
    return true;
}
int cell(int X, int Y) {
    return (X-1)*n + Y;
}
int get_row(int u) {
    if (u%n==0) return u/n;
    return (u/n)+1;
}
int get_col(int u) {
    if (u%n==0) return n;
    return u%n;
}
ii get_xy(int u) {
    return ii(get_row(u),get_col(u));
}

void dijkstra(int robot_id, int robot_x, int robot_y) {
    int s = cell(robot_x, robot_y);
    d[robot_id][s] = 0;
    pq.push(ii(0,s));
    while (!pq.empty()) {
        int du = pq.top().fi, u = pq.top().se;
        pq.pop();
        if (du != d[robot_id][u]) continue;
        int x = get_row(u), y = get_col(u);
        for (int _=0; _<8; _++) {
            int v_x = x + dx[_], v_y = y + dy[_];
            if (!valid(v_x,v_y)) continue;
            int v = cell(v_x,v_y);
            int cur = max(a[v_x][v_y], du+1);
            if (cur < d[robot_id][v]) {
                d[robot_id][v] = cur;
                pq.push(ii(cur, v));
            }
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
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                int cur = 0;
                for (ii x: robot) {
                    cur = max(cur, distance(x.fi, x.se, i, j));
                }
                res = min(res, cur);
            }
        }
    } else {
        d.assign(k,vector <int> ((m*n)+1,INF));
        for (int i=0; i<k; i++) {
            dijkstra(i, robot[i].fi, robot[i].se);
        }
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                int cur = 0, idx = cell(i,j);
                for (int l=0; l<k; l++) {
                    cur = max(cur, d[l][idx]);
                }
                res = min(res, cur);
            }
        }
    }
    cout << res;
    return 0;
}