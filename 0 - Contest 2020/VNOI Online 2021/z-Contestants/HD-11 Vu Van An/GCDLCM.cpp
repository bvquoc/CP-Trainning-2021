//
#include <bits/stdc++.h>

using namespace std;
#define task        "GCDLCM"
#define maxn        10005
#define maxm
#define maxs
#define p_b         push_back
#define fs          first
#define sc          second
#define oo          2000000000
#define mod         1000000007
#define ll          long long

typedef pair <int, int> II;
typedef pair <II, int> III;

int n, m;
int x[maxn], y[maxn];
string type[maxn];
long long L[maxn];
int k[5];
bool ok2 (int X, int Y){
    for (int i = 1; i <= m; ++i) {
        if (type[i] == "GCD") {
            if (__gcd(X,Y) == L[i]) continue;
            else return false;
        } else {
            if ((X * Y) / __gcd (X, Y) == L[i]) continue;
            else return false;
        }
    }
    return true;
}
bool xuly2() {
    for (int i = 1; i <= 200; ++i)
        for (int j = 1; j <= 200; ++j)
            if (ok2 (i, j))
                return true;
    return false;
}
bool ok3() {
    for (int i = 1; i <= m; ++i) {
        if (type[i] == "GCD") {
            ll h =__gcd (k[x[i]], k[y[i]]);
            if (h == L[i]) continue;
            else return false;
        } else {
            ll h = 1ll * (k[x[i]] * k[y[i]]) / __gcd (k[x[i]], k[y[i]]);
            if (h == L[i]) continue;
            else return false;
        }
    }
    return true;
}
bool xuly3() {
    for(int i=1;i<=200;++i)
        for(int j=1;j<=200;++j)
            for(int kh=1;kh<=200;++kh) {
                k[1]=i;
                k[2]=j;
                k[3]=kh;
                if (ok3())
                    return true;
            }
    return false;
}
void sub1() {
    if (n==1)
        cout << "N";
    if (n == 2) {
        if (xuly2()) {
            cout << "Y";
        } else cout << "N";
    }
    if (n == 3) {
        if (xuly3()) {
            cout << "Y";
        } else cout << "N";
    }
}
//
int main() {
    freopen (task".inp", "r", stdin);
    freopen (task".out", "w", stdout);
    ios::sync_with_stdio (false);
//    cin.tie(0);
//    cout.tie(0);
    int subtask;
    cin >> subtask;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            cin >> type[i] >> x[i] >> y[i] >> L[i];
        }
        if (n <= 3) sub1();
    }
}
