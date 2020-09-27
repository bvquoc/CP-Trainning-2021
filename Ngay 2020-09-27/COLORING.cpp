#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;

int dx[] = {0, 0, 1, 0,-1};
int dy[] = {0, 1, 0,-1, 0};

const int MN = 1005;
int m, n, a[MN][MN];
bool mark[MN][MN];
int res = 0;
set <int> ke[1000006];
set <int> col;

bool isValid(int x, int y) {
    if (x<1 || x>m) return false;
    if (y<1 || y>n) return false;
    if (mark[x][y]) return false;
    return true;
}

int cur; 
void DFS(int x, int y, int col1, int col2) {
    cur++;
    mark[x][y] = true;
    FOR(i,1,4) {
        int _x = x + dx[i], _y = y + dy[i];
        if (!isValid(_x,_y)) continue;
        if (a[_x][_y] == col1 || a[_x][_y] == col2) {
            DFS(_x,_y, col1, col2);
        }
    }
}

int32_t main() {
    FastIO;
    freopen("COLORING.INP","r",stdin);
    freopen("COLORING.OUT","w",stdout);
    cin >> m >> n;
    FOR(i,1,m) FOR(j,1,n) {
        cin >> a[i][j];
        col.insert(a[i][j]);
    }

    FOR(i,1,m) FOR(j,1,n) {
        FOR(k,1,2) {
            if (isValid(i+dx[k],j+dy[k] && a[i][j]<a[i+dx[k]][j+dy[k]])) {
                ke[a[i][j]].insert(a[i+dx[k]][j+dy[k]]);
            }
        }
    }
    
    for(int col1: col) {
        for(int col2: ke[col1]) {
            
            FOR(i,1,m) FOR(j,1,n) mark[i][j] = 0;
            FOR(i,1,m) FOR(j,1,n) 
                if (!mark[i][j] && (a[i][j]==col1 || a[i][j]==col2)) {
                    cur = 0;
                    DFS(i, j, col1, col2);
                    res = max(res, cur);
                }
        }
    }

    cout << res;
    return 0;
}