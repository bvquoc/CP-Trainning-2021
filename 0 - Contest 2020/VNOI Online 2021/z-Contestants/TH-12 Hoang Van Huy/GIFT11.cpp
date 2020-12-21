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
#define taskname "GIFT11"
#define MAXN 2004
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
int t, n;
int a[MAXN], x[14];
vi digit;
bool kt[14];
ll ans;
ll mod = 998244353;

//mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
//ll Rand(ll l, ll r){
//    return uniform_int_distribution<ll> (l, r) (rng);
//}
//void mt(){
//    freopen(taskname".inp", "w", stdout);
//    cout << 1 << '\n';
//    cout << 8 << '\n';
//    FOR(i, 1, 8) cout << Rand(10, 99) << ' ';
//}

void check() {
    digit.clear();
    DFOR(i, n, 1) {
        int u = a[x[i]];
        while(u != 0) {
            digit.pb(u % 10);
            u /= 10;
        }
    }
    int cnt = 0;
    int sum0, sum1;
    sum0 = sum1 = 0;
    for(auto i : digit) {
        cnt++;
        if(cnt % 2 == 0) sum0 += i;
        else sum1 += i;
    }
    int sum = abs(sum0 - sum1);
    if(sum % 11 == 0) ans++;
}

void shv(int i) {
    FOR(j, 1, n)
        if(kt[j] == true) {
            x[i] = j;
            kt[j] = false;
            if(i == n) check();
            else shv(i + 1);
            kt[j] = true;
        }
}

void sub1() {
    FOR(i, 1, n) kt[i] = true;
    ans = 0;
    shv(1);
    cout << ans << '\n';
}

bool checksub2() {
    int cnt = 0;
    FOR(i, 1, n) {
        int u = a[i];
        cnt = 0;
        while(u != 0) {
            cnt++;
            u /= 10;
        }
        if(cnt % 2 == 1) return false;
    }
}

void sub2() {
    int sum, sum0, sum1;
    sum0 = sum1 = 0;
    digit.clear();
    DFOR(i, n, 1) {
        int u = a[i];
        while(u != 0) {
            digit.pb(u % 10);
            u /= 10;
        }
    }
    reverse(digit.begin(), digit.end());
    int cnt = 0;
    for(auto i : digit) {
        cnt++;
        if(cnt % 2 == 0) sum0 += i;
        else sum1 += i;
    }
    sum = abs(sum0 - sum1);
    ans = 0;
    if(sum % 11 == 0) {
        ans = 1;
        FOR(i, 1, n) {
            ans *= i;
            ans %= mod;
        }
    }
    cout << ans << '\n';
}

int main()
{
//    mt();
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
        if(n <= 8) {
            sub1();
            continue;
        }
        if(checksub2() == true) {
            sub2();
            continue;
        }
        cout << 0 << '\n';
    }
    return 0;
}
