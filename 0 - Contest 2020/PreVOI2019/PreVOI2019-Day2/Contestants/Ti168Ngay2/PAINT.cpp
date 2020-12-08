#include <bits/stdc++.h>

#define name "PAINT."
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end
#define pb push_back
#define f first
#define s second

using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
const ll N = 1e6 + 7;

int n, k, sub;
char a[N];

void inp()
{
    cin >> n;
    if (n <= 10000) sub = 1;
}
struct sub1
{
    void solve()
    {
        fu(i, 1, n)
        {
            int type;
            char x, y;
            cin >> type;
            if (type == 1)
            {
                cin >> x;
                a[++k] = x;
            }
            else
            {
                cin >> x >> y;
                if (x == y) continue;
                fu(j, 1, k) if (a[j] == x)
                    a[j] = y;
            }
        }
        fu(i, 1, k) cout << a[i];
    }
} sub1;
struct sub2
{
    int par[N], last[300];
    bool d[300];

    int root(int x)
    {
        while (x != par[x])
            x = par[x] = par[par[x]];
        return x;
    }
    void solve()
    {
        fu(i, 'a', 'z') par[i] = last[i] = 0;
        fu(i, 1, n)
        {
            int type;
            char x, y;
            cin >> type;
            if (type == 1)
            {
                cin >> x;
                a[++k] = x;
                if (!d[x]) par[k] = k, d[x] = 1;
                else par[k] = last[x];
                last[x] = k;
            }
            else
            {
                cin >> x >> y;
                if (x == y) continue;
                if (!d[x]) continue;

                int R1 = root(last[x]);
                int R2 = root(last[y]);

                if (!R2) par[R1] = R1;
                else par[R1] = par[R2] = min (R1, R2);

                a[par[R1]] = y;
                d[y] = 1;
                last[y] = max(last[x], last[y]);
                last[x] = d[x] = 0;
            }
        }
        fu(i, 1, k) if (root(i))
            cout << a[root(i)];
    }
} sub2;
int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(name"INP", "r", stdin);
    freopen(name"OUT", "w", stdout);

    inp();
    if (sub == 1) sub1.solve();
    else sub2.solve();
    return 0;
}
