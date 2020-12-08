#include<bits/stdc++.h>

#define maxn 100005

using namespace std;
typedef long long ll;

int n, m;

struct Oxy{
    int x, y;
    Oxy(int _x = 0, int _y = 0) : x(_x), y(_y) {};

    void read(){
        cin >> x >> y;
    }

    Oxy operator - (const Oxy& op) const{
        return Oxy(x - op.x, y - op.y);
    }

    int operator * (const Oxy& op) const{
        return x * op.y - y * op.x;
    }

} A, B, C, D;

void xuli(int a, int b)  {
    if (a == 0&& b == 0) return;
    int d = __gcd(a, b);
    a /= d;
    b /= d;
}

void solve(){
    int n, m;
    cin >> n >> m;
    A.read(); B.read(); C.read(); D.read();
    Oxy AB = B - A;
    Oxy CD = D - C;

    int ta = abs(A.x - C.x), tb = abs(AB.x - CD.x);

    xuli(ta, tb);

    int tc = abs(A.y - C.y),
    td = abs(AB.y - CD.y);

    xuli(tc, td);

    int a = ta - tc, b = td - tb;

    xuli(a, b);

    if (tb != td || b <= 1) cout << "-1\n";
    else cout << ta + a * tb << ' ' << tb << '\n';


}

int main(){
    #define TASK "MOTION"
    freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
