#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 100005;

struct data {
    int X,Y;
    data() {X=0; Y=0;}
    data(int tmp1, int tmp2) {
        X=tmp1;
        Y=tmp2;
    }
} a[N];
int n; vector <int> id;
int T, res = 0;

bool ch[50];
void Solve() {
    int vt = 0, time = 0, t = 0;
    FOR(i,1,n) {
        if (!ch[i]) continue;
        if (time + abs(vt-a[i].X) + a[i].Y > T) break;
        t++;
        time += abs(vt-a[i].X) + a[i].Y;
        vt = a[i].X;
    }
    res = max(res,t);
}
void Try(int i) {
    if (i>n) {
        Solve();
        return;
    }
    ch[i]=true; Try(i+1);
    ch[i]=false; Try(i+1);
}

signed main() {
    FastIO;
    freopen("FREEFOOD.INP","r",stdin);
    freopen("FREEFOOD.OUT","w",stdout);
    cin >> n >> T;
    FOR(i,1,n) {
        id.push_back(i);
        cin >> a[i].X >> a[i].Y;
    }

    if (n<=18) {
        Try(1);
        cout << res;
        return 0;
    }

    sort(a+1,a+1+n,[](const data &a, const data &b) {
        return a.X+b.X < b.X+b.Y;
    });
    int vt = 0, time = 0;
    FOR(i,1,n) {
        if (time + abs(vt-a[i].X) + a[i].Y > T) break;
        res++;
        time += abs(vt-a[i].X) + a[i].Y;
        vt = a[i].X;
    }
    cout << res;
    return 0;
}