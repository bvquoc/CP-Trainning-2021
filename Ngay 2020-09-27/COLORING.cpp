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

const int MN = 1005;
int m, n, a[MN][MN], X, Y, res;
bool cx[MN][MN];
set <int> d;
int MaxLT = 0, tmp = 0;

void Loang(int x, int y) {
    if (!cx[x][y]) return;
    tmp++;
    cx[x][y] = false;
    if (a[x][y] == a[x+1][y]) Loang(x+1,y);
    if (a[x][y] == a[x][y+1]) Loang(x,y+1);
    if (a[x][y] == a[x-1][y]) Loang(x-1,y);
    if (a[x][y] == a[x][y-1]) Loang(x,y-1);
}
void DFS(int x, int y, int k) {
    if (!cx[x][y]) return;
    tmp++;
    cx[x][y] = false;
    if (a[X][Y] == a[x+1][y] || a[x+1][y] == k) DFS(x+1,y,k);
    if (a[X][Y] == a[x][y+1] || a[x][y+1] == k) DFS(x,y+1,k);
    if (a[X][Y] == a[x-1][y] || a[x-1][y] == k) DFS(x-1,y,k);
    if (a[X][Y] == a[x][y-1] || a[x][y-1] == k) DFS(x,y-1,k);
}

int32_t main() {
    FastIO;
    freopen("COLORING.INP","r",stdin);
    freopen("COLORING.OUT","w",stdout);
    cin >> m >> n;
    FOR(i,1,m) FOR(j,1,n) {
        cin >> a[i][j];
        d.insert(a[i][j]);
    }

    FOR(i,1,m) FOR(j,1,n) cx[i][j] = true;
    FOR(i,1,m) FOR(j,1,n) {
        if (cx[i][j]) {
            tmp = 0;
            Loang(i,j);
            if (MaxLT < tmp) {
                X = i; Y = j;
                MaxLT = tmp;
            }
        }
    }

    res = MaxLT; d.erase(a[X][Y]);
    for (set <int>::iterator it = d.begin(); it != d.end(); ++it) {
        FOR(i,1,m) FOR(j,1,n) cx[i][j] = true;
        tmp = 0;
        DFS(X,Y,*it);
        res = max(res,tmp);
    }
    cout << res;
    return 0;
}