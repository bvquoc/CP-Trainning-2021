#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define F first
#define S second
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define VanLoi "fixstr"
#define gb(i, j) ((i >> j) & 1)
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int, int>
#define Block 400

using namespace std;

int n, m, a[maxn], res;
pii st[10000005];
string s[maxn];

void sub1() {
    fi(j, 1, m) {
        string tg;
        char x;
        int y, z;
        cin >> x;
        if (x == 'C') {
            cin >> y;
            y--;
            tg = s[j - 1];
            if (tg[y] == '(') tg[y] = ')';
                else tg[y] = '(';
            s[j] = tg;
        }
        if (x == 'U') {
            cin >> y;
            s[j] = s[y - 1];
        }
        if (x == 'Q') {
            cin >> y >> z;
            y--;
            z--;
            tg = s[j - 1];
            int tong = 0, dem = 0;
            fi(i, y, z) {
                if (tg[i] == '(') tong++; else tong--;
                while (tong < 0) {
                    tong++;
                    dem++;
                }
            }
            cout << dem + abs(tong - 0) << '\n';
            s[j] = s[j - 1];
        }
    }
}

void lazy(int id) {
    int t = st[id].S;
    st[id * 2].S += t;
    st[id * 2].F += t;
    st[id * 2 + 1].S += t;
    st[id * 2 + 1].F += t;
    st[id].S = 0;
    return;
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id].F = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id].F = min(st[id * 2].F, st[id * 2 + 1].F);
}

void ud(int id, int l, int r, int d, int c, int val) {
    if (l > c || r < d) return;
    if (d <= l && r <= c) {
        st[id].F += val;
        st[id].S += val;
        return;
    }
    int m = (l + r) / 2;
    lazy(id);
    ud(id * 2, l, m, d, c, val);
    ud(id * 2 + 1, m + 1, r, d, c, val);
    st[id].F = min(st[id * 2].F, st[id * 2 + 1].F);
}

int get(int id, int l, int r, int d, int c) {
    if (l > c || r < d) return 1e9;
    if (d <= l && r <= c) return st[id].F;
    lazy(id);
    int m = (l + r) / 2;
    return min(get(id * 2, l, m, d, c), get(id * 2 + 1, m + 1, r, d, c));
}

void get1(int id, int l, int r, int vt) {
    if (l > vt || r < vt) return;
    if (l == r) {
        res = st[id].F;
        return;
    }
    lazy(id);
    int m = (l + r) / 2;
    get1(id * 2, l, m, vt);
    get1(id * 2 + 1, m + 1, r, vt);
    return;
}

void sub2() {
    string tg = " " + s[0];
    fi(i, 1, n) if (tg[i] == '(') a[i] = a[i - 1] + 1; else a[i] = a[i - 1] - 1;
    build(1, 1, n);
    fi(j, 1, m) {
        char x;
        int y, z;
        cin >> x;
        if (x == 'C') {
            cin >> y;
            if (tg[y] == '(') ud(1, 1, n, y, n, -2);
                else ud(1, 1, n, y, n, 2);
        } else {
            cin >> y >> z;
            res = 0;
            get1(1, 1, n, y - 1);
            int tg = res;
            int tong = get(1, 1, n, y, z) - tg, kq = 0;
            if (tong < 0) kq += abs(tong);
            get1(1, 1, n, z);
            tong = res - tg;
            cout << kq + abs(tong + kq) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(VanLoi".inp", "r", stdin);
    freopen(VanLoi".out", "w", stdout);
    cin >> s[0];
    n = s[0].length();
    cin >> m;
    if (n <= 1000 && m <= 1000) sub1();
        else sub2();
    return 0;
}
