#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define X first
#define Y second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 502;
int n, r, q_sz;
int a[N][N], p[N][N];
ii q[100005];
int res = 0;

signed main(void) {
    FastIO;
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.ANS","w",stdout);
    cin >> n >> r >> q_sz; r--;
    FOR(i,1,n) {
        FOR(j,1,n) {
            cin >> a[i][j];
        }
    }
    FOR(i,1,q_sz) {
        cin >> q[i].X >> q[i].Y;
        FOR(x,q[i].X,q[i].X+r) {
            p[x][q[i].Y]++; p[x][q[i].Y+r+1]--;
        }
    }
    FOR(i,1,n) {
        FOR(j,1,n) {
            p[i][j] += p[i][j-1];
            if (p[i][j]) res += a[i][j];
        }
    }
    cout << res;
    return 0;
}