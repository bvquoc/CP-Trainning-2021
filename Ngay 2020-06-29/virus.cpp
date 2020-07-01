#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int K = 402;
// const int dx[] = {0, -1, 1,  0, 0, -1, -1,  1, 1};
// const int dy[] = {0,  0, 0, -1, 1, -1,  1, -1, 1};
int n, m, k, x, y, q_cnt;
int cur_t = 0, cur_s = 1, res = 0;
int X1, Y1, X2, Y2;
vector < vector <int> > a;
vector < vector <bool> > mark;

struct data 
{
    int a, b, c, d;
} dt[K];
struct query 
{
    int t, id, ans;
} q[1000006];


void fill(int x, int y, int cnt_x, int cnt_y) {
    for (int i=0; i<cnt_x; i++) {
        a[x+i][y]++;
        a[x+i][y+cnt_y]--;
    }
}

void upper() {
    for (int j=Y1; j<=Y2; j++) {
        if (X1>1) {
            if (a[X1-1][j] != 0) {
                res++;
            }
        }
        if (X2<m) {
            if (a[X2+1][j] != 0) {
                res++;
            }
        }
    }
    for (int i=X1; i<=X2; i++) {
        if (Y1>1) {
            if (a[i][Y1-1] != 0) {
                res++;
            }
        }
        if (Y2<n) {
            if (a[i][Y2+1] != 0) {
                res++;
            }
        }
    }
    if (X1>1 && Y1>1) {
        if (a[X1-1][Y1-1] != 0) {
            res++;
        }
    }
    if (X2<m && Y2<n) {
        if (a[X2+1][Y2+1] != 0) {
            res++;
        }
    }
    if (X1 > 1) X1--;
    if (Y1 > 1) Y1--;
    if (X2 < m) X2++;
    if (Y2 < n) Y2++;
}

void solve(int t) {
    if (cur_t == t) {
        cout << res << ' ';
        return;
    }
    cur_s += (t-cur_t)*2;
    // cerr << cur_s << endl;
    for (int step=1; step<=t-cur_t; step++) {
        upper();
    }
    // cerr << endl;
    cur_t = t;
}

int32_t main(void) {
    FastIO;
    freopen("virus.inp","r",stdin);
    freopen("virus.out","w",stdout);
    cin >> n >> m >> k;
    a.assign(m+2, vector <int> (n+2,0));
    mark.assign(m+2, vector <bool> (n+2,false));
    cin >> x >> y;
    X1 = x; Y1 = y;
    X2 = x; Y2 = y;
    for (int i=1; i<=k; i++) {
        cin >> dt[i].a >> dt[i].b >> dt[i].c >> dt[i].d;
        int r = dt[i].c-dt[i].a+1, c = dt[i].d-dt[i].b+1;
        fill(dt[i].a,dt[i].b,r,c);
    }

    for (int i=1; i<=m; i++) {
        mark[i][0] = true;
        mark[i][n+1] = true;
    }
    for (int i=1; i<=m; i++) {
        mark[0][0] = true;
        mark[m+1][n+1] = true;
    }
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            a[i][j] += a[i][j-1];
        }
    }

    // for (int i=1; i<=m; i++) {
    //     for (int j=1; j<=n; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cin >> q_cnt;
    for (int i=1; i<=q_cnt; i++) {
        cin >> q[i].t;
        q[i].id = i;
    }
    sort(q+1,q+1+q_cnt, [](const query &x, const query &y) {
        return x.t<y.t;
    });

    if (a[x][y]!=0) {
        res = 1;
    }

    for (int i=1; i<=q_cnt; i++) {
        // cerr << "curr_ans " << res << endl;
        // cerr << "time " << q[i].t << endl;
        solve(q[i].t);
        q[i].ans = res;
    }

    sort(q+1,q+1+q_cnt, [](const query &x, const query &y) {
        return x.id<y.id;
    });
    for (int i=1; i<=q_cnt; i++) {
        cout << q[i].ans << ' ';
    }
    return 0;
}