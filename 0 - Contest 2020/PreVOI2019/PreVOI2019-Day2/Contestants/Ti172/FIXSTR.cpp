// Ssusanoo

#include <bits/stdc++.h>
#define N 1010
#define mod
#define LL long long
#define fi first
#define se second
#define MP make_pair
#define pii pair <int, int>
#define endl "\n"
#define Task "FIXSTR"

using namespace std;

int n, q;
string s;
int a[N][N], b[N], t[3][4 * N * N], d[3][4 * N * N];

void sub1() {
    for (int test = 1; test <= q; test++) {
        for (int j = 1; j <= n; j++) {
            if ( s[j] == '(' ) a[test][j] = 1;
            else a[test][j] = -1;
            a[test][j] += a[test][j - 1];
        }
        char type; cin >> type;
        if ( type == 'C' ) {
            int vt; cin >> vt;
            if ( s[vt] == '(' ) s[vt] = ')';
            else s[vt] = '(';
        }
        if ( type == 'Q' ) {
            int l, r, res = 0, dem = 0; cin >> l >> r;
            for (int i = l; i <= r; i++)
                if ( s[i] == '(' ) dem ++;
                else {
                    if ( dem == 0 ) res ++;
                    else dem --;
                }
            cout << res + dem << endl;
        }
        if ( type == 'U' ) {
            int k; cin >> k;
            for (int j = 1; j <= n; j++)
                if ( a[k][j] - a[k][j - 1] == 1 ) s[j] = '(';
                else s[j] = ')';
        }
    }
}

void init(int id, int l, int r) {
    if ( l == r ) {
        t[0][id] = b[l];
        t[1][id] = b[l];
        return;
    }
    int mid = (r + l) >> 1;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
    t[0][id] = min(t[0][id * 2], t[0][id * 2 + 1]);
    t[1][id] = max(t[1][id * 2], t[1][id * 2 + 1]);
}

void update(int id, int l, int r, int u, int v, int val) {
    if ( l > v || r < u ) return;
    if ( l >= u && r <= v ) {
        t[0][id] += val;
        t[1][id] += val;
        d[0][id] += val;
        d[1][id] += val;
        return;
    }
    int mid = (r + l) >> 1;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    t[0][id] = min(t[0][id * 2], t[0][id * 2 + 1]) + d[0][id];
    t[1][id] = max(t[1][id * 2], t[1][id * 2 + 1]) + d[1][id];
}

int get(int id, int l, int r, int u, int v, int type) {
    if ( l > v || r < u ) {
        if ( !type ) return 1e9;
        return -1e9;
    }
    if ( l >= u && r <= v ) return t[type][id];
    int mid = (r + l) >> 1;
    int trai = get(id * 2, l, mid, u, v, type);
    int phai = get(id * 2 + 1, mid + 1, r, u, v, type);
    if ( !type ) return min(trai, phai) + d[type][id];
    return max(trai, phai) + d[type][id];
}

void sub2() {
    for (int i = 1; i <= n; i++) {
        if ( s[i] == '(' ) b[i] = 1;
        else b[i] = -1;
        b[i] += b[i - 1];
    }
    init(1, 1, n);
    while ( q-- ) {
        char type; cin >> type;
        if ( type == 'C' ) {
            int vt; cin >> vt;
            int x;
            if ( s[vt] == '(' ) s[vt] = ')', x = -2;
            else s[vt] = '(', x = 2;
            update(1, 1, n, vt, n, x);
        }
        else {
            int l, r, res = 0; cin >> l >> r;
            int x;
            if ( l - 1 == 0 ) x = 0;
            else x = get(1, 1, n, l - 1, l - 1, 0);
            int mn = get(1, 1, n, l, r, 0) - x;
            int mx = get(1, 1, n, r, r, 1) - x;
            if ( mn < 0 ) res -= mn, mx -= mn;
            if ( mx > 0 ) res += mx;
            cout << res << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    cin >> s >> q;
    n = s.size(); s = ' ' + s;
    if ( n <= 1000 && q <= 1000 ) {
        sub1();
        return 0;
    }
    sub2();

    return 0;
}
