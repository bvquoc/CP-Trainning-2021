/**Yatogami**/
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FFOR(i, a, b) for(int i = a; i < b; i++)
#define DFOR(i, b, a) for(int i = b; i >= a; i--)
#define fi first
#define se second
#define mp make_pair
#define vi vector < int >
#define pb push_back
#define taskname "DECOR"
#define MAXN 500004
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
int n, m, k, ans;
string st;
vi adj[MAXN];
int f[MAXN], a[MAXN], cnt0[MAXN], rf[MAXN];
void input() {
    cin >> n >> m >> k;
    cin >> st;
    st = ' ' + st;
    FOR(i, 1, n)
        if(st[i] == '0') a[i] = 0;
        else a[i] = 1;
    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
}

void init() {
    f[0] = 0;
    rf[0] = 0;
    FOR(i, 1, n)
        if(a[i] == 1) {
            f[i] = f[i - 1] + 1;
            rf[i] = rf[i - 1];
            if(f[i] == 1) rf[i] = i;
        }
        else {
            f[i] = 0;
            rf[i] = 0;
        }
    cnt0[0] = 0;
    FOR(i, 1, n)
        cnt0[i] = cnt0[i - 1] + (a[i] == 0);
}

void sub1() {
    if(m != 0 || k != 0) return;
    ans = -1;
    int l, r;
    FOR(i, 1, n)
        if(ans < f[i]) {
            ans = f[i];
            l = rf[i];
            r = i;
        }
    if(ans < 1) cout << ans;
    else cout << l << ' ' << r;
    exit(0);
}

void sub2() {
    if(m != 0) return;
    ans = -1;
    int l, r, val, vt;
    FOR(i, 1, n - k + 1) {
        val = cnt0[i - 1] + k;
        vt = lower_bound(cnt0 + 1, cnt0 + 1 + n, val + 1) - cnt0;
        vt--;
        if(ans < vt - i + 1) {
            ans = vt - i + 1;
            l = i;
            r = vt;
        }
    }
    if(ans < 1) cout << ans;
    else cout << l << ' ' << r;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    input();
    init();
    if(cnt0[n] == n) {
        if(k == 0) cout << -1;
        else cout << 1 << ' ' << k;
        exit(0);
    }
    sub1();
    sub2();
    cout << 1 << ' ' << n;
    return 0;
}
