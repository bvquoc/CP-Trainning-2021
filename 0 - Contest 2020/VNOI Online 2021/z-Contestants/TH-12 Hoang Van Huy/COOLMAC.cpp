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
#define taskname "COOLMAC"
#define MAXN 100004
#define oo 1000000
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;

//mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
//ll Rand(ll l, ll r){
//    return uniform_int_distribution<ll> (l, r) (rng);
//}
//
//void mt(){
//    freopen(taskname".inp", "w", stdout);
//    int M = Rand(20, 20);
//    cout << M << '\n';
//    FOR(i, 1, M) {
//        int u = Rand(1, 10);
//        int v = Rand(0, 10);
//        if(v == 1) v = 100000;
//        else v = Rand(u, 100000);
//        cout << u << ' ' << v << '\n';
//    }
//    int N = Rand(1, 2);
//    cout << N << '\n';
//    FOR(i, 1, N) cout << Rand(1, 10) << ' ';
//}

int m, n, ans, cnt, lm;
int t[MAXN], x[30], f[MAXN];
vector < pii > V;
struct suit {
    int l, r;
}; suit a[MAXN];
bool cmp(suit x, suit y) {
    if(x.l != y.l) return x.l < y.l;
    return x.r < y.r;
}
bool cmp1(suit x, suit y) {
    if(x.r != y.r) return x.r < y.r;
    return x.l < y.l;
}
void input() {
    cin >> m;
    FOR(i, 1, m) cin >> a[i].l >> a[i].r;
    cin >> n;
    FOR(i, 1, n) cin >> t[i];
    sort(a + 1, a + 1 + m, cmp);
    sort(t + 1, t + 1 + n);
    lm = t[1];
//    FOR(i, 1, m) cout << a[i].l << ' ' << a[i].r << '\n';
}

void check() {
    V.clear();
    FOR(i, 1, m)
        if(x[i] == 1)
            V.pb({a[i].l, a[i].r});
    sort(V.begin(), V.end());
    int vt = lm;
    bool ck = false;
    for(auto i : V)
        if(vt >= i.fi && vt <= i.se) {vt = i.se; ck = true;}
    if(vt >= 100000&& ck == true) ans = min(ans, (int)V.size());
}

void snp(int i) {
    if(cnt >= ans) return;
    FOR(j, 0, 1) {
        x[i] = j;
        cnt += j;
        if(i == m) check();
        else snp(i + 1);
        cnt -= j;
    }
}
void sub1() {
    if(m > 20) return;
    ans = oo;
    cnt = 0;
    snp(1);
    if(ans > m) ans = -1;
    cout << ans;
    exit(0);
    cout << '\n';
}

void sub2() {
    if(m > 7000) return;
    FOR(i, 1, m) f[i] = oo;
    FOR(i, 1, m)
        if(a[i].l <= lm && a[i].r >= lm) f[i] = 1;
    FOR(i, 1, m) {
        if(f[i] == 1) continue;
        FFOR(j, 1, i)
            if(a[j].r >= a[i].l)
                f[i] = min(f[i], f[j]);
        f[i]++;
    }
    ans = oo;
    FOR(i, 1, m)
        if(a[i].r >= 100000) ans = min(ans, f[i]);
    if(ans > m) ans = -1;
    cout << ans;
    exit(0);
    cout << '\n';
}

struct cmp2 {
    bool operator () (int i, int j) {
        return f[i] > f[j];
    }
};

void sub3() {
    sort(a + 1, a + 1 + m, cmp1);
    priority_queue < int , vector < int > , cmp2 > h;
    FOR(i, 1, m) f[i] = oo;
    FOR(i, 1, m)
        if(a[i].l <= lm && a[i].r >= lm) f[i] = 1;
    FOR(i, 1, m) {
        while(true) {
            if(h.empty() == 1) break;
            if(a[h.top()].r < a[i].l) h.pop();
            else break;
        }
        if(h.empty() == 0)
            f[i] = min(f[i], f[h.top()] + 1);
        h.push(i);
    }
    ans = oo;
    FOR(i, 1, m)
        if(a[i].r >= 100000) ans = min(ans, f[i]);
    if(ans > m) ans = -1;
    cout << ans;
}

int main()
{
//    mt();
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    input();
    sub1();
    sub2();
    sub3();
    return 0;
}
