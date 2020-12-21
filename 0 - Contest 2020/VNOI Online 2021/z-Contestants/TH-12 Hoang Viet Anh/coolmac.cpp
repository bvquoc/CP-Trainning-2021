#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define tkn "coolmac"
#define X first
#define Y second
#define FORU(i, a, b) for (int i = a; i <= b; i++)
#define FFOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r){
    return uniform_int_distribution<ll> (l, r) (rng);
}
const int N = 1e5 + 7;
const int M = 6e6 + 3;
const int base = 1e9 + 7;
const ll mod = 1e9 + 7;
const int logmax = 25;
int m, n, mi;
ii a[N];
void input() {
    cin >> m;
    FORU(i, 1, m) cin >> a[i].X >> a[i].Y;
    cin >> n;
    int x; mi = N;
    FORU(i, 1, n){
        cin >> x;
        mi = min(mi, x);
    }
}
void init(){

}
bool cmp(ii a, ii b){
    if (a.X != b.X) return a.X < b.X;
    return a.Y < b.Y;
}
void sol() {
    sort(a + 1, a + m + 1, cmp);
    int ma = -1, i = 1;
    int res = 0;
    while (i <= m) {
        if (a[i].Y < mi) {i++; continue;}
        bool kt = 1;
        while (a[i].X <= mi && i <= m){
            kt = 0;
            ma = max(ma, a[i].Y);
            i++;
        }
        if (kt) {cout << -1; return;}
        mi = ma; res++;
    }
    if (ma < 100000) cout << -1;
    else cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(tkn".inp","r", stdin);
    freopen(tkn".out", "w", stdout);
    input();
    sol();

    return 0;
}
