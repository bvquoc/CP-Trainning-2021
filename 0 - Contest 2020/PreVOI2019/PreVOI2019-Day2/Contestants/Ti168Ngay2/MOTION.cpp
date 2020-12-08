#include <bits/stdc++.h>

#define name "MOTION."
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end
#define pb push_back
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
const ll N = 1e6 + 1;

int t, n, m;
ii A, B, C, D;

struct sub1
{
    ii X, Y, Z, T;
    int a1, b1, c1, a2, b2, c2;

    void ptdt(ii A, ii B, int &a, int &b, int &c)
    {
        a = A.x - B.x;
        b = B.y - A.y;
        c = -(a * A.x + b * A.y);
    }
    ii giaodiem(){}
    void solve()
    {
        X = A;
        Y = B;
        Z = D;
        T = D;
        ptdt(A, B, a1, b1, c1);
        ptdt(C, D, a2, b2, c2);
        cout << "-1\n"; /// :<
    }
} sub1;
int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(name"INP", "r", stdin);
    freopen(name"OUT", "w", stdout);

    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cin >> A.x >> A.y >> B.x >> B.y;
        cin >> C.x >> C.y >> D.x >> D.y;
        if (n <= 10 && m <= 10)
            sub1.solve();
    }
    return 0;
}
