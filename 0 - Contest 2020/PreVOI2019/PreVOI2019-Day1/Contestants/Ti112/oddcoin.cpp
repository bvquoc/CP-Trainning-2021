#include <bits/stdc++.h>
#define ll long long
#define maxn 50000005
#define F first
#define S second
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define VanLoi "oddcoin"
#define gb(i, j) ((i >> j) & 1)
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int, int>
#define Block 400

using namespace std;

int n, q, dem = 0, x, t, res, y[maxn], a[100], b[10], dem1, l[maxn];

void chuanbi() {
    int tg = 1;
    fi(i, 1, 5) {
        a[++dem] = tg;
        tg *= 10;
    }
    tg = 3;
    fi(i, 1, 5) {
        a[++dem] = tg;
        tg *= 10;
    }
    tg = 5;
    fi(i, 1, 5) {
        a[++dem] = tg;
        tg *= 10;
    }
    sort(a + 1, a + dem + 1);
    b[1] = 1;
    b[2] = 3;
    b[3] = 5;
    b[4] = 10;
}

void no() {
    int tong = 0, d = 0;
    fi(i, 1, dem1) {
        tong += y[i] * b[i];
        d += y[i];
    }
    if (tong == t) res = min(res, d);
}

void xuli(int i) {
    fi(j, 0, t / b[i]) {
        y[i] = j;
        if (i == dem1) no(); else xuli(i + 1);
    }
}

void sub1() {
    dem1 = 4;
    res = 1e9;
    if (x != 0) b[++dem1] = x;
    xuli(1);
    cout << res << '\n';
}

void sub2() {
    a[++dem] = x;
    fi(i, 0, t) l[i] = 1e9;
    l[0] = 0;
    fi(i, 0, t)
        fi(j, 1, dem) if (i + a[j] <= t) l[i + a[j]] = min(l[i + a[j]], l[i] + 1);
    cout << l[t] << '\n';
    dem--;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(VanLoi".inp", "r", stdin);
    freopen(VanLoi".out", "w", stdout);
    chuanbi();
    cin >> q;
    fi(i, 1, q) {
        cin >> x >> t;
        if (x <= 20 && t <= 20) sub1();
            else  sub2();
    }
    return 0;
}
