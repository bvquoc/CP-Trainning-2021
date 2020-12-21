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
#define taskname "PERMEOW"
#define MAXN 200004
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair < int , int > pii;
typedef pair < ll , ll > pll;
int n, cnta, cntb;
int a[MAXN], b[MAXN];
ll f[2004][2004];
ll mod = 1e9 + 7;
void input() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
}

void init() {
    cnta = cntb = 0;
    FOR(i, 1, n) FOR(j, i + 1, n) {
        if(a[i] > a[j]) cnta++;
        if(b[i] > b[j]) cntb++;
    }
}

void sub1() {
    FOR(i, 1, n)
        if(a[i] != b[i]) return;
    cout << cnta;
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
    sub1();
    return 0;
}
