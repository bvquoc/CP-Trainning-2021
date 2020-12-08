#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define name "ODDCOIN."
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define pb push_back
#define all(X) X.begin(), X.end()

using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;

vector <ll> v;
int q;
ll x, t;

struct sub1
{
    int res;
    int a[6], h[6];

    void update()
    {
        int sum = 0, cnt = 0;
        fu(i, 1, 5) sum += h[i] * a[i], cnt += h[i];
        if (sum < t) cnt += t - sum, sum = t;
        if (sum == t) res = min (res, cnt);
    }
    void Try(int i)
    {
        fu(j, 0, t / a[i])
        {
            h[i] = j;
            if (i == 4) update();
            else Try(i + 1);
        }
    }
    void solve()
    {
        res = x;
        a[1] = 3; a[2] = 5;
        a[3] = 10; a[4] = x;
        Try(1);
        cout << res << '\n';
    }
} sub1;
struct sub2
{
    int n;
    int a[18];
    int f[18][100007];

    void solve()
    {
        a[n = 1] = x;
        int tmp = 1;
        fu(i, 1, 5)
        {
            a[++n] = tmp;
            a[++n] = tmp * 3;
            a[++n] = tmp * 5;
            tmp *= 10;
        }
        sort (a + 1, a + n + 1);
        //reverse (a + 1, a + n + 1);

        fu(i, 2, n)
            fu(j, 0, t) f[i][j] = inf;
        fu(i, 0, t) f[1][i] = i;
        fu(i, 2, n)
        {
            fu(s, 0, t)
            {
                fu(k, 0, s / a[i - 1])
                    f[i][s] = min (f[i][s], f[i - 1][s - k * a[i - 1]] + k);
            }
        }
        cout << f[n][t] << '\n';
    }
} sub2;
int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(name"INP", "r", stdin);
    freopen(name"OUT", "w", stdout);
    cin >> q;

    while (q--)
    {
        cin >> x >> t;
        if (x <= 20 && t <= 20) sub1.solve();
        else sub2.solve();
    }
    return 0;
}
