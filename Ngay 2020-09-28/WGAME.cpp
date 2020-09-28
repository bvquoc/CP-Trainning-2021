#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

int dx[] = {1, 0};
int dy[] = {0, 1};
int n, m, D;
string s;
vector < vector <char> > a;
ll res = 0;
vector <ii> path;


void Try(int x,int y) {
    if (a[x][y] == '#') return;
    path.push_back(ii(x,y));
    if (x == m && y == n) {
        string S;
        for(ii t: path) {
            S += a[t.first][t.second];
        }
        if (S.find(s) >= S.length()) return;
        int l = S.length()-1;
        FOR(i,0,l/2) {
            if (S[i]!=S[l-i]) return;
        }
        res++;
    }
    vector <ii> tmp = path;
    FOR(i,0,1) {
        int _x = x+dx[i], _y = y+dy[i];
        Try(_x,_y);
        path = tmp;
    }
}

signed main(void) {
    FastIO;
    freopen("WGAME.INP","r",stdin);
    freopen("WGAME.OUT","w",stdout);
    cin >> m >> n >> D;
    cin >> s;
    a.assign(m+2,vector <char>(n+2, '#'));
    FOR(i,1,m) FOR(j,1,n) cin >> a[i][j];
    if (m<=10 && n<=10) { // Subtask 1
        Try(1,1);
        cout << res;
        return 0;
    }
    return 0;
}