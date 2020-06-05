#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N = 302;
int m, n, f[N][N];
bool a[N][N];
int res[N][N];

bool isZeroful(int x1, int y1, int x2, int y2) {
    if (x1>x2 || y1>y2) return false;
    int sum = f[x2][y2] - f[x1-1][y2] - f[x2][y1-1] + f[x1-1][y1-1];
    return (!sum);
}

void solveFrom(int x1, int y1) {
    for (int x2=x1; x2<=m; x2++) {
        for (int y2=y1; y2<=n; y2++) {
            if (a[x2][y2]) {
                break;
            }
            if (isZeroful(x1,y1,x2,y2)) {
                res[x2-x1+1][y2-y1+1]++;
            }
        }
    }
}

int32_t main(void) {
    FastIO;
    freopen("RECT.INP","r",stdin);
    freopen("RECT.OUT","w",stdout);
    cin >> m >> n;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
        }
    }
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (!a[i][j]) {
                solveFrom(i,j);
            }
        }
    }
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}