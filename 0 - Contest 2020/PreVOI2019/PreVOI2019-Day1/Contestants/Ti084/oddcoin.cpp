#include <bits/stdc++.h>
using namespace std;

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 12;
const int Mod = 1e9 + 7;
const int oo = 1e9;

typedef pair<int, int> ii;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

//emsiHD
#define file "oddcoin"
#define fi first
#define se second
#define y1 Dinh
#define y0 Huy
#define yn Is
#define j1 Me
#define bit(mask, i) ((mask>>(i - 1))&1)

int nquery;
int a[N], d[N], b[N];

void InOut(){
    freopen (file ".inp", "r", stdin);
    freopen (file ".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int Get1(int m){
    if (m == 0) return 0;
    int t = 0;
    for (int i = 15; i >= 1; i--){
        int tmp = m / a[i];
        m -= tmp * a[i];
        t += tmp;
    }
    return t;
}

int Get(int m, int x){
    if (m == 0) return 0;
    int ret = oo;
    int mx = m;
    for (int mask = 1; mask < (1<<15); mask++){
        int t = 0, len = 0;
        for (int i = 1; i <= 15; i++)
            if (bit(mask, i)) b[++len] = a[i];

        for (int i = len; i >= 1; i--){
            int val = b[i];
            int tmp = m / val;
            m -= tmp * val;
            t += tmp;
        }
        if (m == 0) ret = min(ret, t);
        m = mx; t = 0;

        for (int i = len; i >= 1; i--){
            int val = b[i];
            bool ktr = true;
            if (b[i] < x && ktr) {
                int tm = m / x;
                m -= tm * x;
                t += tm;
                ktr = false;
            }
            int tmp = m / val;
            m -= tmp * val;
            t += tmp;
        }
        if (m == 0) ret = min(ret, t);
        m = mx;
    }
    return ret;
}

void Solve(){
    cin >> nquery;
    a[1] = 1, a[2] = 3, a[3] = 5;
    d[1] = 1, d[3] = 1, d[5] = 1;
    for (int i = 4; i <= 15; i++){
        a[i] = a[i - 3] * 10;
        d[a[i]] = 1;
    }
    while (nquery--){
        int x, m, ans = oo;
        bool kt = true;
        cin >> x >> m;
        if (x <= a[15]) if (d[x] == 1) kt = false;
        ans = Get1(m);
        if (kt) ans = min(ans, Get(m, x));
        cout << ans << "\n";
    }
}

main(){
    InOut();

    Solve();

}

